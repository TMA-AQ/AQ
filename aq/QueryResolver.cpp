#include "QueryResolver.h"
#include "SQLPrefix.h"
#include "QueryAnalyzer.h"
#include "parser/Parser.hpp"

#include "RowProcesses.h"
#include "RowWritter.h"
#include "RowTableWritter.h"
#include "RowBinaryWritter.h"
#include "NodeWritter.h"
#include "RowVerbProcess.h"
#include "RowTemporaryWritter.h"
#include "RowSolver.h"
#include "UpdateResolver.h"

#include "verbs/Verb.h"
#include "parser/JeqParser.h"
#include "engine/AQEngine_Intf.h"
#include "Column2Table.h"
#include "ExprTransform.h"
#include "TreeUtilities.h"
#include "Optimizations.h"
#include "ColumnMapper.h"
#include "DumpVisitor.h"

#include <aq/util/Base.h>
#include <aq/util/Table.h>
#include <aq/util/Exceptions.h>
#include <aq/util/Logger.h>
#include <aq/util/DateConversion.h>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>

#include <deque>
#include <algorithm>
#include <fstream>

#include <boost/scoped_array.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace fs = boost::filesystem;

#ifdef AQ_TRACE
std::string sql_query; // FIXME : should belong to class QueryResolver
#endif

boost::mutex aq::QueryResolver::parserMutex;

namespace aq
{

//------------------------------------------------------------------------------
QueryResolver::QueryResolver(
  aq::tnode * _sqlStatement,
  Settings::Ptr _settings,
  aq::engine::AQEngine_Intf::Ptr  _aqEngine,
  Base::Ptr  _baseDesc,
  unsigned int& _id,
  unsigned int _level)
  :  settings(_settings),
     baseDesc(_baseDesc),
     aqEngine(_aqEngine),
     sqlStatement(_sqlStatement),
     originalSqlStatement(nullptr),
     outerSelect(nullptr),
     id_generator(_id),
     id(_id),
     nestedId(0),
     level(_level),
     nested(id > 1),
     inWhereClause(false),
     hasGroupBy(false),
     hasOrderBy(false),
hasPartitionBy(false),
compressable(boost::none)
{
  this->sqlStatement->to_upper();
  this->originalSqlStatement = this->sqlStatement->clone_subtree();
  memset(szBuffer, 0, STR_BUF_SIZE);
  timer.start();
}

//------------------------------------------------------------------------------
QueryResolver::~QueryResolver()
{
  aq::tnode::delete_subtree(this->originalSqlStatement);
  for (auto& v : this->aliases) { aq::tnode::delete_subtree(v.second); }
  aq::Logger::getInstance().log(AQ_INFO, "Query Resolver: Time elapsed = %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());
}

//-------------------------------------------------------------------------------
Table::Ptr QueryResolver::solve(boost::shared_ptr<aq::RowWritter_Intf> rowWritter)
{
  this->resultHandler = rowWritter;
  this->preProcess();
  this->solveNested(this->sqlStatement, this->level, nullptr, false, false);
  aq::verb::VerbNode::Ptr spTree = this->postProcess();
  spTree->changeQuery();
  if (spTree != nullptr)
  {
    this->resolve(spTree);
  }
  return this->result;
}

//-------------------------------------------------------------------------------
void QueryResolver::preProcess()
{
  if (!this->sqlStatement || (this->sqlStatement->tag != K_SELECT))
  {
    throw aq::generic_error(aq::generic_error::INVALID_QUERY, "");
  }

  // post processing before solving nested queries
  aq::util::generateParent(this->sqlStatement, nullptr);
  aq::util::addAlias(this->sqlStatement->left);

#if defined(AQ_TRACE)
  sql_query = "";
  std::cout << *this->sqlStatement << std::endl;
  std::cout << aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query) << std::endl;
#endif

  this->hasGroupBy = this->sqlStatement->find_main( K_GROUP) != nullptr;
  this->hasOrderBy = this->sqlStatement->find_main(K_ORDER) != nullptr;

  std::list<tnode*> columns;
  aq::util::toNodeListToStdList(this->sqlStatement, columns);
  for (auto& col : columns)
  {
    if (col->tag != K_STAR)
      this->aliases.insert(std::make_pair(col->right->getData().val_str, col->left->clone_subtree()));
  }

  if (this->hasGroupBy)
  {
    tnode * grpNode = this->sqlStatement->find_main(K_GROUP);
    std::vector<tnode*> cl;
    aq::util::getColumnsList(grpNode->left, cl);
    for (auto& n : cl)
    {
      this->groupBy.push_back(n->clone_subtree());
    }

    cl.clear();
    aq::util::getColumnsList(this->sqlStatement->left, cl);
    for (auto& n : cl)
    {
      if ((n->tag == K_AS) && (n->left->tag == K_MIN)) // TODO : for all aggregate function
      {
        // FIXME : this suppose that the min aggregate function is applied to only one column
        this->orderBy.push_back(n->left->left->clone_subtree());
      }
    }
  }

  if (this->hasOrderBy)
  {
    tnode * grpNode = this->sqlStatement->find_main(K_ORDER);
    std::vector<tnode*> cl;
    aq::util::getColumnsList(grpNode->left, cl);
    for (auto& n : cl)
    {
      this->orderBy.push_back(n->clone_subtree());
    }
  }

  std::vector<tnode*> partitionsNodes;
  this->sqlStatement->left->find_nodes(K_PARTITION, partitionsNodes);
  if (!partitionsNodes.empty())
  {
    // to solve a partition by we must perform an order on result
    // so we get all the column defining the partition
    this->hasPartitionBy = true;
    for (auto& n : partitionsNodes)
    {
      this->partitions.push_back(std::vector<tnode*>());
      std::vector<tnode*>& v = *(this->partitions.rbegin());
      std::vector<tnode*> cl;
      aq::util::getColumnsList(n->left->left, cl);
      for (auto& n : cl)
      {
        v.push_back(n->clone_subtree());
      }
    }
    // add order
    tnode * orderNode = this->sqlStatement->left->find_first(K_ORDER);
    if (orderNode)
    {
      std::vector<tnode*> orderByNodes;
      aq::util::getColumnsList(orderNode->left->left, orderByNodes);
      for (auto& n : orderByNodes)
      {
        this->orderBy.push_back(n->clone_subtree());
      }
    }
  }
  aq::util::removePartitionBy(this->sqlStatement);

  if (!this->hasGroupBy && !this->hasPartitionBy/* && hasWhere*/) // FIXME : why where is needed ?
  {
    std::list<tnode*> aggregateColumns;
    aq::util::findAggregateFunction(columns, aggregateColumns);
    if (!aggregateColumns.empty())
    {
      aq::util::addEmptyGroupBy(this->sqlStatement);
      this->hasGroupBy = true;
    }
  }
}

//-------------------------------------------------------------------------------
aq::verb::VerbNode::Ptr QueryResolver::postProcess()
{
  aq::verb::VerbNode::Ptr spTree;

  aq::util::solveIdentRequest(this->sqlStatement, this->baseDesc);

#if defined(AQ_TRACE)
  sql_query = "";
  std::cout << *this->sqlStatement << std::endl;
  std::cout << aq::multiline_query(aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query)) << std::endl;
#endif

  aq::util::dateNodeToBigInt(this->sqlStatement);
  aq::util::transformExpression(this->baseDesc, this->settings, this->sqlStatement);

#if defined(AQ_TRACE)
  sql_query = "";
  std::cout << *this->sqlStatement << std::endl;
  std::cout << aq::multiline_query(aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query)) << std::endl;
#endif

  // if transform expression result to a K_FALSE in WHERE statement => the query answer is empty
  aq::tnode * whereNode = this->sqlStatement->find_main(K_WHERE);
  if ((whereNode != nullptr) && (whereNode->left->tag == K_FALSE))
  {
    return spTree;
  }

  //
  // Query Pre Processing (TODO : optimize tree by detecting identical subtrees)
  timer.start();
  boost::array<uint32_t, 6> categories_order =  { { K_FROM, K_WHERE, K_SELECT, K_GROUP, K_HAVING, K_ORDER } };
  spTree = aq::verb::VerbNode::BuildVerbsTree(this->sqlStatement, categories_order, this->baseDesc, this->settings);

#if defined(AQ_TRACE)
  sql_query = "";
  std::cout << aq::multiline_query(aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query)) << std::endl;
#endif

  // spTree->changeQuery();

#if defined(AQ_TRACE)
  sql_query = "";
  // std::cout << *this->sqlStatement << std::endl;
  std::cout << aq::multiline_query(aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query)) << std::endl;
#endif

  aq::tnode::checkTree(this->sqlStatement);
  aq::util::cleanQuery(this->sqlStatement);
  aq::Logger::getInstance().log(AQ_INFO, "Query Preprocessing: Time elapsed = %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());

  //
  // Solve Optimal Min/Max : FIXME
  timer.start();
  this->result = solveOptimalMinMax(spTree, this->baseDesc, this->settings);
  if (this->result)
  {
    aq::Logger::getInstance().log(AQ_INFO, "Solve Optimal Min/Max: Time elapsed = %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());
    return nullptr;
  }

  return spTree;
}

//-------------------------------------------------------------------------------
void QueryResolver::resolve(aq::verb::VerbNode::Ptr spTree)
{
  aq::engine::AQEngine_Intf::mode_t mode;
  analyze::type_t type;
  if (!this->nested || this->inWhereClause)
  {
    mode = aq::engine::AQEngine_Intf::mode_t::REGULAR;
    type = analyze::type_t::REGULAR;
  }
  else
  {
    if (this->hasGroupBy || this->hasPartitionBy)
    {
      mode = aq::engine::AQEngine_Intf::mode_t::NESTED_1;
      type = this->isCompressable() ? analyze::type_t::TEMPORARY_TABLE : analyze::type_t::TEMPORARY_COLUMN;
    }
    else
    {
      mode = aq::engine::AQEngine_Intf::mode_t::NESTED_2;
      type = analyze::type_t::FOLD_UP_QUERY;
    }
  }

  // update table name for aq engine
  this->updateTableName();

  // Generate AQEngine Query
  std::string query;
  std::vector<std::string> joinPath;
  this->generateAQEngineQuery(query, joinPath);

  // Call AQEngine
  this->aqEngine->call(query, mode);
  auto aqMatrix = this->aqEngine->getAQMatrix();
  if (aqMatrix != 0)
  {
    assert(joinPath.size() >= aqMatrix->getNbColumn());
    std::vector<std::string> jp;
    if (joinPath.size() >= aqMatrix->getNbColumn())
    {
      for (auto& tname : joinPath)
      {
        aq::Table::Ptr table = this->baseDesc->getTable(tname);
        for (auto& tm : aqMatrix->getMatrix())
        {
          if (tm.table_id == table->getID())
          {
            jp.push_back(tname);
            break;
          }
        }
      }
    }
    else
    {
      std::copy(joinPath.begin(), joinPath.end(), std::back_inserter(jp));
    }
    aqMatrix->setJoinPath(jp);
  }
  // aq::MakeBackupFile(pSettings->szOutputFN, aq::backup_type_t::Empty, this->level, this->id);

  // parse result
  if (this->settings->computeAnswer)
  {
    timer.start();
    switch (type)
    {
    case analyze::type_t::REGULAR:
    case analyze::type_t::TEMPORARY_COLUMN:
      this->solveAQMatrix(spTree);
      aq::Logger::getInstance().log(AQ_INFO, "solve aq matrice in %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());
      break;
    case analyze::type_t::FOLD_UP_QUERY:
      this->resultTables.clear();
      this->renameResultTable();
      aq::Logger::getInstance().log(AQ_INFO, "result table renamed in %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());
      break;
    case analyze::type_t::TEMPORARY_TABLE:
      this->resultTables.clear();
      this->generateTemporaryTable();
      aq::Logger::getInstance().log(AQ_INFO, "generate temporary table in %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());
      break;
    }
  }
}

//------------------------------------------------------------------------------
void QueryResolver::addInnerQuery(const char * id, boost::shared_ptr<QueryResolver> qr)
{
  this->nestedTables[id] = qr;
}

//------------------------------------------------------------------------------
void QueryResolver::solveNested()
{

  // solve from nested first
  aq::tnode * from = this->sqlStatement->find_main(K_FROM);
  std::list<aq::tnode*> l;
  aq::util::toNodeListToStdList(from, l);
  for (auto& f : l)
  {
    if ((f->tag == K_AS) && (f->left && (f->left->tag == K_SELECT)))
    {
      std::string alias = f->right->to_string();
      this->executeNested(f->left);
    }
  }

  // then solve where nested
  // aq::tnode * where = this->sqlStatement->find_main_node(K_WHERE);
  // todo
}

//------------------------------------------------------------------------------
void QueryResolver::solveNested(aq::tnode*& pNode, unsigned int nSelectLevel, aq::tnode* pLastSelect, bool inFrom, bool inIn)
{
  if((pNode == nullptr) || (pNode->tag == K_DELETED))
    return;

  aq::tnode* pNewLastSelect = pLastSelect;
  bool newInFrom = inFrom;
  bool newInIn = inIn;
  switch( pNode->tag )
  {
  case K_SELECT:
    pNewLastSelect = pNode;
    newInFrom = false;
    newInIn = false;
    break;
  case K_FROM:
    newInFrom = true;
    break;
  case K_IN:
    newInIn = true;
    break;
  default:
    break;
  }

  if ((pNode->tag == K_SELECT) && (nSelectLevel > this->level))
  {
    if( inFrom )
    {
      this->executeNested(pNode);
    }
    else // inIn
    {
      assert(inIn);
      QueryResolver queryResolver(pNode, this->settings, this->aqEngine, this->baseDesc, nSelectLevel, ++this->nestedId);
      queryResolver.setInWereClause();
      aq::tnode * result = new aq::tnode(K_IN_VALUES);
      boost::shared_ptr<aq::NodeWritter> writter(new aq::NodeWritter(*result));
      queryResolver.solve(writter);
      aq::tnode::delete_subtree(pNode); // delete old subtree and add new subtree containing answer
      pNode = result;
      std::cout << *pNode << std::endl;
    }
  }
  else
  {
    if ( pNode->tag == K_SELECT)
      ++nSelectLevel;

    solveNested(pNode->left, nSelectLevel, pNewLastSelect, newInFrom, newInIn);

    solveNested(pNode->right, nSelectLevel, pNewLastSelect, newInFrom, newInIn);

    if( pNode->tag == K_FROM )
      newInFrom = false;

    solveNested(pNode->next, nSelectLevel, pNewLastSelect, newInFrom, newInIn);

    if( (pNode->tag == K_IN) && (pNode->right == nullptr) )
    {
      /* If subquery evaluates to an empty set, IN evaluates to FALSE. */
      aq::tnode::delete_subtree(pNode);
      pNode = new aq::tnode( K_FALSE );
    }
  }

}

//------------------------------------------------------------------------------
void QueryResolver::executeNested(aq::tnode * pNode)
{

  std::string alias;
  aq::tnode * as = pNode->parent;
  if ((as != nullptr) && (as->tag == K_AS) && (as->right != nullptr) && (as->right->getDataType() == aq::tnode::tnodeDataType::NODE_DATA_STRING))
  {
    alias = pNode->parent->right->getData().val_str;
  }
  else
  {
#if defined(AQ_TRACE)
    std::cout << *pNode << std::endl;
#endif
    throw aq::generic_error(aq::generic_error::INVALID_QUERY, "bad nested query: missing as keyword");
  }

  // build table
  this->id_generator += 1;
  boost::shared_ptr<QueryResolver> interiorQuery(new QueryResolver(pNode->clone_subtree(), this->settings, this->aqEngine, this->baseDesc, this->id_generator, this->level + 1));
  interiorQuery->setOuterSelect(this->sqlStatement);
  interiorQuery->setResultName(alias.c_str(), ""); // FIXME
  interiorQuery->solve();
  this->nestedTables.insert(std::make_pair(alias, interiorQuery));

  // update base desc
  if (interiorQuery->result)
  {
    interiorQuery->result->setOriginalName(alias);
    this->baseDesc->getTables().push_back(interiorQuery->result);
  }

  // update node tree
  aq::tnode::delete_subtree(as->left);
  aq::tnode::delete_subtree(as->right);
  as->tag = K_IDENT;
  as->set_string_data(alias.c_str());
  as->left = nullptr;
  as->right = nullptr;
  as->next = nullptr;
}

//------------------------------------------------------------------------------
void QueryResolver::generateAQEngineQuery(std::string& query, std::vector<std::string>& joinPath) const
{
  std::string group;
  std::string order;
  std::string group_and_order;

#if defined (AQ_TRACE)
  std::cout << *this->sqlStatement << std::endl;
#endif

  aq::syntax_tree_to_aql_form(this->sqlStatement, query);

  std::string::size_type posOrder = query.find("ORDER");
  std::string::size_type posGroup = query.find("GROUP");
  if ((posOrder != std::string::npos) || (posGroup != std::string::npos))
  {
    std::string::size_type pos = std::min(posOrder, posGroup);
    group_and_order = query.substr(pos);
    query = query.substr(0, pos);
  }

  joinPath = aq::parser::ParseJeq(query); // TODO : manage active/neutral/filter option

  if (!this->groupBy.empty())
  {
    group = "GROUP ";
    for (size_t i = 0; i < this->groupBy.size() - 1; ++i)
      group += " , ";
    for (auto it = this->groupBy.begin(); it != this->groupBy.end(); ++it)
    {
      aq::syntax_tree_to_aql_form(*it, group);
    }
  }

  if (!this->orderBy.empty())
  {
    order = "ORDER ";
    for (size_t i = 0; i < this->orderBy.size() - 1; ++i)
      order += " , ";
    for (auto it = this->orderBy.begin(); it != this->orderBy.end(); ++it)
    {
      aq::syntax_tree_to_aql_form(*it, order);
    }
  }

  if (!this->partitions.empty() && !this->partitions[0].empty() && (group == ""))
  {
    group = "GROUP ";
    for (size_t i = 0; i < this->partitions[0].size() - 1; ++i)
      group += " , ";
    for (auto it = this->partitions[0].begin(); it != this->partitions[0].end(); ++it)
    {
      aq::syntax_tree_to_aql_form(*it, group);
    }
  }

  boost::algorithm::trim(query);
  boost::algorithm::trim(group);
  boost::algorithm::trim(order);
  if (!group.empty())
  {
    query += "\n" + group;
  }
  if (!order.empty())
  {
    query += "\n" + order;
  }
}

//------------------------------------------------------------------------------
void getSelectVerbs(aq::verb::VerbNode::Ptr spTree, std::vector<aq::verb::VerbNode::Ptr>& selectVerbs)
{
  aq::verb::SelectVerb::Ptr select = boost::dynamic_pointer_cast<aq::verb::SelectVerb>(spTree);
  while ((select == 0) && (spTree->getBrother()))
  {
    spTree = spTree->getBrother();
    select = boost::dynamic_pointer_cast<aq::verb::SelectVerb>(spTree);
  }
  spTree = spTree->getLeftChild();
  while (spTree)
  {
    if (boost::dynamic_pointer_cast<aq::verb::CommaVerb>(spTree) != 0)
    {
      selectVerbs.push_back(spTree->getRightChild());
      spTree = spTree->getLeftChild();
      assert(spTree);
    }
    else
    {
      selectVerbs.push_back(spTree);
      spTree = 0;
    }
  }
}

//------------------------------------------------------------------------------
void QueryResolver::solveAQMatrix(aq::verb::VerbNode::Ptr spTree)
{
  aq::Timer timer;

  // Prepare Columns
  std::vector<Column::Ptr> columnTypes;
  aq::util::getColumnTypes(this->sqlStatement, columnTypes, this->baseDesc);

  // build process to apply on each row
  boost::shared_ptr<aq::RowProcesses> processes(new aq::RowProcesses);

  assert(!(this->hasGroupBy && this->hasPartitionBy));
  std::vector<aq::tnode*> columnNodes;
  if (this->hasGroupBy)
  {
    aq::tnode * nodeGroup = this->sqlStatement->find_main(K_GROUP);
    aq::util::getAllColumnNodes(nodeGroup, columnNodes);
  }
  else if (this->hasPartitionBy)
  {
    std::copy(this->partitions[0].begin(), this->partitions[0].end(), std::back_inserter(columnNodes));
    assert(!this->partitions.empty());
    assert(!this->partitions[0].empty());
  }

  //
  // Aggregate Verbs Processing
  std::vector<aq::verb::VerbNode::Ptr> aggregateVerbs;
  getSelectVerbs(spTree, aggregateVerbs);
  boost::shared_ptr<aq::RowVerbProcess> aggregateVerbProcess(new aq::RowVerbProcess(spTree, aggregateVerbs));
  processes->addProcess(aggregateVerbProcess);

  //
  // Algebric Verbs Processing
  std::vector<aq::verb::VerbNode::Ptr> algebricVerbs;
  boost::shared_ptr<aq::RowVerbProcess> algebricVerbProcess(new aq::RowVerbProcess(spTree, algebricVerbs));
  processes->addProcess(algebricVerbProcess);

  ////
  //// Output Processing
  if (this->resultHandler == nullptr)
  {
    if (this->nested)
    {
      if (this->inWhereClause)
      {
        this->result.reset(new Table("tmp", static_cast<unsigned>(this->baseDesc->getTables().size() + 1), true));
        this->resultHandler.reset(new aq::RowTableWritter(this->result));
        processes->addProcess(this->resultHandler);
      }
      else
      {
        this->resultHandler.reset(new aq::RowTemporaryWritter(static_cast<unsigned>(this->baseDesc->getTables().size() + 1), this->settings->tmpPath.c_str(), this->settings->packSize));
        processes->addProcess(this->resultHandler);
      }
    }
    else
    {
      resultHandler.reset(new aq::RowWritter(this->settings->outputFile == "stdout" ? this->settings->outputFile.string() : this->settings->answerFile.string()));
    }
  }
  this->resultHandler->setColumn(columnTypes);
  processes->addProcess(this->resultHandler);

  //
  // build joinPath

  //
  // build result from aq matrix
  timer.start();
  aq::RowSolver solver(this->aqEngine->getAQMatrix(), columnTypes, columnNodes, this->settings, this->baseDesc);
  solver.solve(processes, this->settings->process_thread, this->hasGroupBy || this->hasPartitionBy);
  aq::Logger::getInstance().log(AQ_INFO, "build result from aq matrix: Time Elapsed = %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());

  //
  // build table result (need by nested query)
  if (this->nested && !this->inWhereClause)
  {
    std::string name = (this->resultTables.size() == 1) ? this->resultTables[0].first : "tmp";
    this->result.reset(new Table(name, static_cast<unsigned>(this->baseDesc->getTables().size() + 1), this->resultHandler->getTotalCount(), true));

    // const std::vector<Column::Ptr>& columnsWritter = this->resultHandler->getColumns();
    // std::copy(columnsWritter.begin(), columnsWritter.end(), std::back_inserter(this->columns));

    //for (const auto& col : this->columns)
    //{
    //  Column::Ptr column(new Column(*col));
    //  column->setTableName(name);
    //  this->result->Columns.push_back(column);
    //}

    for (const auto& alias : this->aliases)
    {
      auto s = this->getOriginalColumn(alias.first);
      if (s == "")
        s = alias.first;
      for (auto& c : columnTypes)
      {
        if (s == c->getName())
        {
          Column::Ptr column(new Column(*c));
          column->setName(alias.first);
          column->setTableName(name);
          this->result->Columns.push_back(column);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
size_t QueryResolver::getNbRows()
{
  if (this->aqEngine && this->aqEngine->getAQMatrix())
    return this->aqEngine->getAQMatrix()->getCount().size();
  return 0;
}

//------------------------------------------------------------------------------
void QueryResolver::generateTemporaryTable()
{
  boost::shared_ptr<aq::engine::AQMatrix> matrix = this->aqEngine->getAQMatrix();
  matrix->compress();
  matrix->writeTemporaryTable();

  // the table is compress and refer to a physical table so the alias table must be rename by real table name
  assert(this->resultTables.empty());

  const auto& m = matrix->getMatrix();
  assert(m.size() == 1);
  for (auto& c : m)
  {
    this->resultTables.push_back(std::make_pair(c.tableName, c.baseTableName));
  }

  aq::Table::Ptr table(new Table(this->resultTables[0].first, static_cast<unsigned>(this->baseDesc->getTables().size() + 1), true));
  table->setReferenceTable(this->resultTables[0].second);

  // TODO : add column according to query
  aq::Table::Ptr refTable = this->baseDesc->getTable(this->resultTables[0].second);

  for (const auto& alias : this->aliases)
  {
    auto name = this->getOriginalColumn(alias.first);
    if (name == "")
      name = alias.first;
    auto col = refTable->getColumn(name);
    aq::Column::Ptr newCol(new aq::Column(*col));
    newCol->setOriginalName(alias.first);
    table->Columns.push_back(newCol);
  }

  //for (auto& column : refTable->Columns)
  //{
  //  table->Columns.push_back(new aq::Column(*column));
  //}

  //unsigned int columnId = 1;
  //for (auto& a : this->aliases)
  //{
  //  // FIXME
  //  std::string columnName = a.first;
  //  std::string::size_type pos = columnName.find(".");
  //  if (pos != std::string::npos)
  //  {
  //    columnName = columnName.substr(pos + 1);
  //  }
  //  aq::Column::Ptr c(new aq::Column(columnName, columnId++, 0, aq::ColumnType::COL_TYPE_INT));
  //  table->Columns.push_back(c);
  //}

  // this->BaseDesc.getTables().push_back(table);
  this->result = table;
}

//------------------------------------------------------------------------------
void QueryResolver::renameResultTable()
{

  this->aqEngine->renameResult(this->id, this->resultTables);

  for (auto& e : this->resultTables)
  {
    aq::Table::Ptr table(new Table(e.first, 1, true));
    table->setReferenceTable(e.second);

    aq::Table::Ptr refTable = this->baseDesc->getTable(e.second);
    for (auto& column : refTable->Columns)
    {
      Column::Ptr c(new aq::Column(*column));
      table->Columns.push_back(c);
    }

    this->baseDesc->getTables().push_back(table);
  }


  // copy WHERE's conditions to outer select WHERE
  aq::tnode* whereNode = this->sqlStatement->find_main(K_WHERE);
  if (whereNode)
  {
    // keep only join
    aq::tnode * joinNode = whereNode->left->clone_subtree(); // FIXME : possible memory leak
    joinNode = aq::util::getJoin(joinNode);
    if (joinNode)
    {
      // rename table in join by temporary table

      // look for K_IDENT (should be K_TABLE)
      std::vector<tnode*> ltables;
      joinNode->find_nodes(K_IDENT, ltables);
      for (auto& n : ltables)
      {
        aq::Table::Ptr table = this->baseDesc->getTable(n->getData().val_str);
        for (auto& rt : this->resultTables)
        {
          if (rt.second == table->getName())
          {
            n->set_string_data(rt.first.c_str());
          }
        }
      }

      aq::util::addConditionsToWhere(joinNode, this->outerSelect);
    }
  }
  // aq::addInnerOuterNodes(whereNode->left, K_INNER, K_INNER);
}

//------------------------------------------------------------------------------
void QueryResolver::updateTableName()
{
#if defined(AQ_TRACE)
  sql_query = "";
  std::cout << aq::multiline_query(aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query)) << std::endl;
#endif
  this->changeTemporaryTableName(this->sqlStatement);
  for (auto& n : this->groupBy)
  {
    this->changeTemporaryTableName(n);
  }
  for (auto& n : this->orderBy)
  {
    this->changeTemporaryTableName(n);
  }
  for (auto& v : this->partitions)
  {
    for (auto& n : v)
    {
      this->changeTemporaryTableName(n);
    }
  }
  this->updateBaseDesc();
#if defined(AQ_TRACE)
  sql_query = "";
  std::cout << aq::multiline_query(aq::syntax_tree_to_sql_form(this->sqlStatement, sql_query)) << std::endl;
#endif
}

//------------------------------------------------------------------------------
void QueryResolver::changeTemporaryTableName(aq::tnode * pNode)
{
  if (pNode == nullptr) return;
  if (pNode->tag == K_PERIOD)
  {
    aq::tnode * table = pNode->left;
    aq::tnode * column = pNode->right;
    assert((table != nullptr) && (table->tag == K_IDENT) && (table->getDataType() == aq::tnode::tnodeDataType::NODE_DATA_STRING));
    assert((column != nullptr) && (table->tag == K_IDENT) && (table->getDataType() == aq::tnode::tnodeDataType::NODE_DATA_STRING));

    // !!!!!!!!!!! FIXME !!!!!!!!!!!!! Hacking for testing (DEMO July 4 2013) !!!!!!!!!!!!!!!
    //if ((strcmp("B", table->getData().val_str) == 0) &&
    //  (strcmp("MIN_SEM_COURT", column->getData().val_str) == 0))
    //{
    //  column->set_string_data("SEQ_SEM_COURT");
    //  table->set_string_data("B001REG0001TMP0003P000000000007");
    //}

    for (auto& nestedTable : this->nestedTables)
    {
      if (nestedTable.first == table->getData().val_str)
      {
        auto tmp = nestedTable.second->getResult();
        if (tmp)
        {
          auto col = tmp->getColumn(column->getData().val_str);
          char * buf = static_cast<char*>(malloc(128 * sizeof(char)));
          std::string type_str = columnTypeToStr(col->getType());
          sprintf(buf, "C%.4lu%s%.4lu", col->getID(), type_str.c_str(), col->getSize());
          aq::Logger::getInstance().log(AQ_DEBUG, "change column name '%s' by '%s'\n", column->getData().val_str, buf);
          column->set_string_data(buf);
          free(buf);
          changeTemporaryTableName(table); // FIXME
        }
        else
        {
          assert(nestedTable.second->isCompressable());
          if (!nestedTable.second->isCompressable())
            throw aq::generic_error(aq::generic_error::INVALID_TABLE, "empty result on a non compressable nested result");
          for (auto& baseTable : nestedTable.second->getResultTables())
          {
            aq::Table::Ptr tableBase = this->baseDesc->getTable(baseTable.first);
            aq::Table::Ptr tableDesc = this->baseDesc->getTable(baseTable.first);

            //while (tableBase->isTemporary())
            //{
            //  tableBase = this->BaseDesc.getTable(tableBase->getReferenceTable());
            //}

            // check if the column belong to the table
            bool isPresent = false;
            for (auto& col : tableDesc->Columns)
            {
              if (col->getName() == column->getData().val_str)
              {
                // nothing to do
                isPresent = true;
                break;
              }
            }

            // if the column doesn't belong to the table, it should be an alias
            if (!isPresent)
            {
              // find the original column and change alias name
              std::string new_column_name = nestedTable.second->getOriginalColumn(column->getData().val_str);
              if (new_column_name != "")
              {
                isPresent = true;
                column->set_string_data(new_column_name.c_str());
              }
            }

            if (isPresent)
            {
              if (tableDesc->isTemporary())
              {
                // even is the column isPresent, it can be an alias
                std::string new_column_name = nestedTable.second->getOriginalColumn(column->getData().val_str);
                if (new_column_name != "")
                {
                  isPresent = true;
                  column->set_string_data(new_column_name.c_str());
                }
              }
              table->set_string_data(baseTable.first.c_str());
            }

          }
        }
      }
    }
    assert(!pNode->next);
    return;
  }
  else if ((pNode->tag == K_IDENT) && (pNode->getDataType() == aq::tnode::tnodeDataType::NODE_DATA_STRING))
  {
    for (auto& nestedTable : this->nestedTables)
    {
      if (nestedTable.first == pNode->getData().val_str)
      {
        if (nestedTable.second->isCompressable())
        {
          const auto& v = nestedTable.second->getResultTables();
          assert(!v.empty());
          if (v.size() == 1)
          {
            pNode->set_string_data(v[0].first.c_str());
          }
          else
          {
            pNode->set_string_data(v[0].first.c_str());
            tnode * comma = pNode->parent;
            tnode * p = comma->left;
            assert(comma->tag == K_COMMA);
            for (auto itTableFrom = v.begin() + 1; itTableFrom != v.end(); ++itTableFrom)
            {
              tnode * n = new aq::tnode(K_COMMA);
              n->right = new aq::tnode(K_IDENT);
              n->right->set_string_data(itTableFrom->first.c_str());
              n->left = p;
              p = n;
            }
            assert(p);
            comma->left = p;
          }
        }
        else
        {
          char * buf = static_cast<char*>(malloc(128 * sizeof(char)));
          sprintf(buf, "TMP%.4luSIZE%.10lu", nestedTable.second->getResult()->getID(), nestedTable.second->getResult()->getTotalCount());
          aq::Logger::getInstance().log(AQ_DEBUG, "change table name '%s' by '%s'\n", pNode->getData().val_str, buf);
          pNode->set_string_data(buf);
          free(buf);
        }
      }
    }
  }
  changeTemporaryTableName(pNode->left);
  changeTemporaryTableName(pNode->right);
  changeTemporaryTableName(pNode->next);
}

void QueryResolver::updateBaseDesc()
{
  // change table and column name in BaseDesc
  for (auto& nestedTable : this->nestedTables)
  {
    if (!nestedTable.second->result)
    {
      assert(nestedTable.second->isCompressable());
      if (!nestedTable.second->isCompressable())
      {
        throw aq::generic_error(aq::generic_error::INVALID_TABLE, "");
      }
      continue;
    }

    char * name = static_cast<char*>(malloc(128 * sizeof(char)));
    sprintf(name, "TMP%.4luSIZE%.10lu", nestedTable.second->result->getID(), nestedTable.second->result->getTotalCount());
    nestedTable.second->result->setName(name);
    free(name);

    Table::Ptr tmp = nestedTable.second->getResult();
    for (std::vector<Column::Ptr>::iterator itCol = tmp->Columns.begin(); itCol != tmp->Columns.end(); ++itCol)
    {
      char * buf = static_cast<char*>(malloc(128 * sizeof(char)));
      std::string type_str = columnTypeToStr((*itCol)->getType());
      sprintf(buf, "C%.4lu%s%.4lu", (*itCol)->getID(), type_str.c_str(), (*itCol)->getSize());
      (*itCol)->setName(buf);
      free(buf);
    }
  }
}

bool isColumn(const tnode * const n) // TODO : TO COMPLETE
{
  return (n->tag == K_PERIOD) || (n->tag == K_COLUMN) || ((n->tag == K_AS) && (isColumn(n->left)));
}

bool isMinMax(const tnode * const n) // TODO : TO COMPLETE
{
  return (n->tag == K_AS) && ((n->left->tag == K_MIN) || (n->left->tag == K_MAX));
}

bool QueryResolver::isCompressable()
{
  // check function select
  // if only column table and min/max occur, the AQMatrix of this query can be compressed
  if (this->compressable.indeterminate_value) // already compute
  {
    if (this->hasPartitionBy)
    {
      this->compressable = false;
    }
    else
    {
      bool c = true;
      tnode * select = this->originalSqlStatement->find_main(K_SELECT);
      std::vector<tnode*> nodes;
      aq::util::getColumnsList(select->left, nodes);
      for (auto it = nodes.begin(); (it != nodes.end()) && c; ++it)
      {
        c = isColumn(*it) || isMinMax(*it);
      }
      this->compressable = c;
    }
  }
  return this->compressable;
}

std::string QueryResolver::getOriginalColumn(const std::string& alias) const
{
  for (auto it = this->aliases.begin(); it != this->aliases.end(); ++it)
  {
    if (it->first == alias)
    {
      // TODO : check if tnode structure refer to only one column
      tnode * n = it->second->find_deeper(K_COLUMN);
      assert(n);
      if (strcmp(n->getData().val_str, alias.c_str()) != 0)
      {
        return n->getData().val_str;
      }
      else
      {
        return "";
      }
    }
  }
  std::string res = "";
  for (auto it = this->nestedTables.begin(); (it != this->nestedTables.end()) && (res == ""); ++it)
  {
    res = it->second->getOriginalColumn(alias);
  }
  return res;
}

// -------------------------------------------------------------------------------------------------
int QueryResolver::prepareQuery(const std::string& query, const std::string & ident, aq::Settings::Ptr settings, bool force)
{
  //
  // generate ident and ini file
  std::string queryIdent = ident;
  if (queryIdent == "")
  {
    boost::uuids::uuid qi = boost::uuids::random_generator()();
    std::ostringstream oss;
    oss << qi;
    queryIdent = oss.str();
  }
  settings->changeIdent(queryIdent);

  //
  // create directories
  std::list<fs::path> lpaths;
  lpaths.push_back(settings->rootPath / fs::path("calculus") / fs::path(queryIdent));
  lpaths.push_back(settings->tmpPath);
  lpaths.push_back(settings->dpyPath);
  for (std::list<fs::path>::const_iterator dir = lpaths.begin(); dir != lpaths.end(); ++dir)
  {
    if (fs::exists(*dir))
    {
      aq::Logger::getInstance().log(AQ_WARNING, "directory already exist '%s'\n", (*dir).string().c_str());
      if (!force)
      {
        return EXIT_FAILURE;
      }
    }
    else if (!fs::create_directory(*dir))
    {
      aq::Logger::getInstance().log(AQ_WARNING, "cannot create directory '%s'\n", (*dir).string().c_str());
      if (!force)
      {
        return EXIT_FAILURE;
      }
    }
  }

  //
  // write request file
  auto queryFilename = settings->rootPath / fs::path("calculus") / fs::path(queryIdent) / fs::path("Request.sql");
  std::ofstream queryFile(queryFilename.c_str());
  queryFile << query;
  queryFile.close();

  //
  // write ini file (it is needed for now by AQEngine)
  std::ofstream iniFile(settings->iniFile.c_str());
  settings->writeAQEngineIni(iniFile);
  iniFile.close();

  return EXIT_SUCCESS;
}

// -------------------------------------------------------------------------------------------------
int QueryResolver::processQuery(const std::string& query,
                                boost::shared_ptr<aq::Settings> settings,
                                boost::shared_ptr<aq::Base> baseDesc,
                                boost::shared_ptr<aq::engine::AQEngine_Intf> aqEngine,
                                boost::shared_ptr<aq::RowWritter_Intf> resultHandler,
                                bool keepFiles)
{
  int rc = EXIT_SUCCESS;

  try
  {

    aq::Logger::getInstance().log(AQ_INFO, "processing sql query\n");

    aq::tnode  *pNode  = nullptr;
    int  nRet;

    //
    // Parse SQL request
    {

      boost::mutex::scoped_lock lock(parserMutex);
      aq::Logger::getInstance().log(AQ_INFO, "parse sql query %s\n", query.c_str());
      if ((nRet = SQLParse(query.c_str(), pNode)) != 0 )
      {
        aq::Logger::getInstance().log(AQ_ERROR, "error parsing sql request '%s'\n", query.c_str());
        return EXIT_FAILURE;
      }

#if defined(_DEBUG) && defined(_TRACE)
      std::cout << *pNode << std::endl;
#endif

    }

    //
    // Transform SQL request in prefix form,
    if (pNode->tag == K_SELECT)
    {
      unsigned int id_generator = 1;
      aq::Timer timer;
      aq::QueryResolver queryResolver(pNode, settings, aqEngine, baseDesc, id_generator);
      aq::Table::Ptr result = queryResolver.solve(resultHandler);
      timer.stop();
      if (settings->cmdLine)
      {
        std::cout << queryResolver.getNbRows() << " rows processed in " << aq::Timer::getString(timer.getTimeElapsed()) << std::endl;
        std::cout << std::endl;
      }
    }
    else if (pNode->tag == K_UPDATE)
    {
      aq::UpdateResolver updateResolver(pNode, settings, aqEngine, baseDesc);
      updateResolver.solve();
    }
    else
    {
      aq::Logger::getInstance().log(AQ_INFO, "[%s] is not supported", aq::id_to_string(pNode->tag));
    }

    delete pNode;
  }
  catch (const aq::generic_error& ge)
  {
    aq::Logger::getInstance().log(AQ_ERROR, "%s\n", ge.what());
    rc = EXIT_FAILURE;
  }
  catch (const std::exception& ex)
  {
    aq::Logger::getInstance().log(AQ_ERROR, "%s\n", ex.what());
    rc = EXIT_FAILURE;
  }
  catch (...)
  {
    aq::Logger::getInstance().log(AQ_ERROR, "unknown exception\n");
    rc = EXIT_FAILURE;
  }

  if (!keepFiles)
  {
    aq::Logger::getInstance().log(AQ_NOTICE, "remove temporary directory '%s'\n", settings->tmpPath.c_str());
    aq::util::DeleteFolder(settings->tmpPath.c_str());
    aq::Logger::getInstance().log(AQ_NOTICE, "remove working directory '%s'\n", settings->workingPath.c_str());
    aq::util::DeleteFolder(settings->workingPath.c_str());
  }

  return rc;
}

}
