#ifndef __AQ_TEST_RUNNER_H__
#define __AQ_TEST_RUNNER_H__

#include <list>
#include <string>
#include <memory>

#include <boost/shared_ptr.hpp>

#include "DatabaseHelper.h"
#include "Report.h"

namespace aq 
{
  class TestCase : public DatabaseIntf
  {
  public:
    typedef boost::shared_ptr<TestCase> Ptr;
    struct opt_t
    {
      opt_t();
      void parse(std::istream& is);
      std::string generator_filename;
      size_t nb_tables;
      size_t nb_rows;
      int min_value;
      int max_value;
      DatabaseGenerator::point_mode_t point_mode;
      DatabaseGenerator::gen_mode_t gen_mode;
      DatabaseGenerator::value_mode_t value_mode;
      std::string aq_path;
      std::string aq_name;
      std::string aq_engine;
      std::string aq_loader;
      std::string mysql_host;
      std::string mysql_user;
      std::string mysql_pass;
      std::string mysql_name;
	  bool stop_on_error;
	  bool check_result;
    };
  public:
    TestCase(boost::shared_ptr<Report> report);
    ~TestCase();
    void add(boost::shared_ptr<DatabaseIntf> db) { this->databases.push_back(db); }
    void clean();
    void createTable(const DatabaseGenerator::handle_t::tables_t::key_type& table);
    void insertValues(const DatabaseGenerator::handle_t::tables_t::value_type& values);
    bool execute(const aq::core::SelectStatement& ss, DatabaseIntf::result_t& r1);
	std::string get_name() const { return "test_case"; }
    size_t getNbResult() const { return nb_result / (2 * nb_tests); }
    size_t getNbTests() const { return nb_tests; }
    size_t getNbSuccess() const { return nb_success; }
    size_t getNbFailure() const { return nb_failure; }
  protected:
    bool compare(const DatabaseIntf::result_t& r1, const DatabaseIntf::result_t& r2);
	void dump_result(const DatabaseIntf::result_t& result);
  private:
    TestCase(const TestCase& o);
    TestCase& operator=(const TestCase& o);
    std::list<boost::shared_ptr<DatabaseIntf> > databases;
    size_t nb_result;
    size_t nb_tests;
    size_t nb_success;
    size_t nb_failure;
	boost::shared_ptr<Report> report;
  };
}

#endif