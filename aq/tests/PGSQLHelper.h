#include "DatabaseHelper.h"
#include <pqxx/pqxx>

namespace aq
{

class PGSQLDatabase : public DatabaseIntf
{
public:
    PGSQLDatabase(const std::string& _host, const std::string& _user, const std::string& _pass, const std::string& _name);
    virtual ~PGSQLDatabase();
    void clean() {};
    void createTable(const DatabaseGenerator::handle_t::tables_t::key_type& table);
    void insertValues(const DatabaseGenerator::handle_t::tables_t::value_type& values);
    bool execute(const aq::core::SelectStatement& ss, DatabaseIntf::result_t& r1);
    std::string get_name() const { return "postgresql"; }
private:
    std::string              host;
    std::string              user;
    std::string              pass;
    std::string              name;
    std::stringstream        query;
    std::list<std::string>   columns;
    pqxx::connection       * connection;
};

}
