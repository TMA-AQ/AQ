#include "AQEngineBasic.h"
#include <aq/util/Logger.h>
#include <aq/util/AQLQuery.h>
#include <aq/util/AQLParser.h>
#include <iostream>

using namespace aq;

AQEngineBasic::AQEngineBasic(aq::Base::Ptr _base, aq::Settings::Ptr _settings)
  : base(_base), settings(_settings)
{
}

void AQEngineBasic::prepare() const
{
}

void AQEngineBasic::clean() const
{
}

void AQEngineBasic::call(const std::string& query, aq::engine::AQEngine_Intf::mode_t mode)
{

  std::string aql_query = query;
  if (query.find(";") == std::string::npos)
  {
    aql_query += ";";
  }

  aq::core::SelectStatement stmt;
  aq::parser::parse(aql_query, stmt);

  aq::Logger::getInstance().log(AQ_INFO, stmt.to_string(aq::core::SelectStatement::output_t::AQL).c_str());
  aq::Logger::getInstance().log(AQ_INFO, stmt.to_string(aq::core::SelectStatement::output_t::SQL).c_str());

  this->call(stmt, mode);
}

void AQEngineBasic::call(const aq::core::SelectStatement& stmt, aq::engine::AQEngine_Intf::mode_t mode)
{
  this->matrix.reset(new aq::engine::AQMatrix(this->settings, this->base));
  auto& mtx = this->matrix->getMatrix();

  for (const auto& table : stmt.fromTables)
  {
    auto t = this->base->getTable(table.name);
    struct aq::engine::AQMatrix::column_t c;
    c.table_id = t->getID();
    c.tableName = t->getName();
    c.baseTableName = t->getName();
    mtx.push_back(c);
  }

  std::map<size_t, std::vector<aq::Column::Ptr> > joins;
  for (const auto& join : stmt.joinConditions)
  {
    { // left
      const auto& table = this->base->getTable(join.left.table.name);
      const auto& column = table->getColumn(join.left.name);
      joins[table->getID()].push_back(column);
    }
    { // right
      const auto& table = this->base->getTable(join.right.table.name);
      const auto& column = table->getColumn(join.right.name);
      joins[table->getID()].push_back(column);
    }
  }


}

void AQEngineBasic::renameResult(unsigned int id, std::vector<std::pair<std::string, std::string> >& tables)
{
}

aq::engine::AQMatrix::Ptr AQEngineBasic::getAQMatrix()
{
  return this->matrix;
}

const std::vector<llong>& AQEngineBasic::getTablesIDs() const
{
  return this->tableIDs;
}
