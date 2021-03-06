#include "AQEngineSimulate.h"
#include <aq/engine/AQRawMatrix.h>
#include <aq/util/AQLParser.h>
#include <aq/util/Exceptions.h>
#include <aq/TreeUtilities.h>

namespace aq
{

  AQEngineSimulate::AQEngineSimulate(const aq::Base::Ptr _baseDesc, const aq::Settings::Ptr _settings)
    : baseDesc(_baseDesc), settings(_settings)
  {
    srand( static_cast<unsigned int>( time( NULL ) ) ); //temporaire
  }

  void AQEngineSimulate::call(const std::string& query, aq::engine::AQEngine_Intf::mode_t mode)
  {
    aq::core::SelectStatement ss;
    aq::parser::parse(query + ";", ss);

    std::cout << "Execute:" << std::endl;
    std::cout << ss.to_string(aq::core::SelectStatement::output_t::AQL) << std::endl;

    //std::cout << "TableIDs value =" << std::endl;
    //for (auto& tid : this->tableIDs)
    //{
    //  std::cout << "[" << tid << "]" << std::endl;
    //}
    // this->aqMatrix->simulate( rand() % 1000, this->tableIDs );

    if (mode != aq::engine::AQEngine_Intf::mode_t::NESTED_2)
    {
      this->aqMatrix.reset(new aq::engine::AQRawMatrix(this->settings, this->baseDesc));
      this->createTableIDs(query);
      auto& matrix = aqMatrix->getMatrix();
      for (const auto& col : ss.selectedTables)
      {
        const auto& tname = col.table.name;
        bool find = false;
        for (const auto& table : matrix)
        {
          if (table.tableName == tname)
          {
            find = true;
            break;
          }
        }
        if (!find)
        {
          const auto& table = baseDesc->getTable(tname);
          matrix.push_back(aq::engine::AQMatrix::matrix_t::value_type());
          auto& t = *matrix.rbegin();
          t.baseTableName = t.tableName = table->getName();
          t.table_id = table->getID();
        }
      }
    }

  }

  void AQEngineSimulate::call(const aq::core::SelectStatement& query, aq::engine::AQEngine_Intf::mode_t mode)
  {
  }

  void AQEngineSimulate::renameResult(unsigned int id, std::vector<std::pair<std::string, std::string> >& resultTables)
  {
    // TODO
    (void)id;
    (void)resultTables;
    std::for_each(this->tableIDs.begin(), this->tableIDs.end(), [&] (uint64_t tid) {
      std::ostringstream oss;
      oss << "REG" << tid << "TMP" << id;
      resultTables.push_back(std::make_pair(oss.str(), this->baseDesc->getTable(id)->getName()));
    });
  }

  void AQEngineSimulate::setAQMatrix(aq::engine::AQMatrix::Ptr _aqMatrix)
  {
    this->aqMatrix = _aqMatrix;
  }

  void AQEngineSimulate::setTablesIDs(std::vector<llong>& _tableIDs)
  {
    this->tableIDs.resize(_tableIDs.size());
    std::copy(_tableIDs.begin(), _tableIDs.end(), this->tableIDs.begin());
  }

  aq::engine::AQMatrix::Ptr AQEngineSimulate::getAQMatrix()
  {
    return this->aqMatrix;
  }

  const std::vector<llong>& AQEngineSimulate::getTablesIDs() const
  {
    return this->tableIDs;
  }

  void AQEngineSimulate::createTableIDs(aq::tnode* pNode)
  {
    if ( !pNode )
      return;

    if ( (pNode->tag == K_IDENT)
      && (std::find( this->tableIDs.begin(), this->tableIDs.end(), this->baseDesc->getTable( pNode->getData().val_str )->getID() ) == this->tableIDs.end()) )
      this->tableIDs.push_back( this->baseDesc->getTable( pNode->getData().val_str )->getID() );

    this->createTableIDs( pNode->left );
    this->createTableIDs( pNode->right );
    this->createTableIDs( pNode->next );
  }

  void AQEngineSimulate::createTableIDs(const std::string& query)
  {
    std::list<std::string> tableNames;
    std::stringstream querySS;
    std::string::size_type b = query.find("FROM");
    if (b == std::string::npos)
      throw aq::generic_error(aq::generic_error::INVALID_QUERY, "");
    querySS << query.substr(b + 4);

    std::string s;
    do
    {
      querySS >> s;
    } while (s == ",");

    do
    {
      tableNames.push_back(s);
      querySS >> s;
    } while ((s != "") && (s != ";") && (s != "WHERE") && (s != "GROUP") && (s != "ORDER"));

    for (const auto& tname : tableNames)
    {
      this->tableIDs.push_back(this->baseDesc->getTable(tname)->getID());
    }

  }
}
