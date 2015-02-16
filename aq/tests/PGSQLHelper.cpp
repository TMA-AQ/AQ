#include "PGSQLHelper.h"
#include <aq/util/Exceptions.h>

using namespace aq;

PGSQLDatabase::PGSQLDatabase(const std::string& _host, const std::string& _user, const std::string& _pass, const std::string& _name)
    : host(_host), user(_user), pass(_pass), name(_name)
{
    connection = new pqxx::connection("dbname=" + name + " user=" + user);
}

PGSQLDatabase::~PGSQLDatabase()
{
    delete connection;
}

void PGSQLDatabase::createTable(const DatabaseGenerator::handle_t::tables_t::key_type& table)
{
    pqxx::work txn(*connection);

    query.str("");
    query << "drop table if exists " << table << ";";
    txn.exec(query.str());

    query.str("");
    query << "create table " << table << " (id serial primary key, v1 int)";
    txn.exec(query.str());

    txn.commit();
}

void PGSQLDatabase::insertValues(const DatabaseGenerator::handle_t::tables_t::value_type& values)
{
    if (values.second.empty())
    {
        return;
    }
    query.str("");
    query << "insert into " << values.first << " (v1) values ";
    for (auto it = values.second.begin(); it != values.second.end();)
    {
        query << "(" << *it << ")";
        ++it;
        if (it != values.second.end())
            query << ",";
    }
    query << ";";
    pqxx::work txn(*connection);
    txn.exec(query.str());
    txn.commit();
}

bool PGSQLDatabase::execute(const aq::core::SelectStatement& ss, DatabaseIntf::result_t& result)
{
    return true;
}
