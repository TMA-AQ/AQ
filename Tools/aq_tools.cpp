#include "AQEngineSimulate.h"

#include <aq/util/Exceptions.h>
#include <aq/util/Logger.h>
#include <aq/util/Timer.h>
#include <aq/util/QueryReader.h>
#include <aq/engine/AQEngine_Intf.h>
#include "VerbBuilder.h"
#include "AQManager.h"
#include "CommandHandler.h"
#include "AQEngineSimulate.h"
#include "AQEngineBasic.h"

// #include <aq/AQThreadRequest.h>

#if defined (WIN32)
#  include <io.h>
#else
#  include <unistd.h>
#  define _isatty isatty
#  define _fileno fileno
#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/thread.hpp>
#include <boost/filesystem.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>

#define AQ_TOOLS_VERSION "0.1.0"

namespace po = boost::program_options;
namespace fs = boost::filesystem;

size_t failedQueries = 0;
boost::mutex parserMutex;

// -------------------------------------------------------------------------------------------------
int processSQLQueries(const std::string       & query,
                      const aq::Settings::Ptr   settingsBase,
                      const std::string         queryIdent,
                      aq::Base::Ptr             baseDesc,
                      bool                      simulateAQEngine,
                      bool                      basicAQEngine,
                      bool                      force)
{

  aq::Logger::getInstance().log(AQ_INFO, "%s\n", query.c_str());
  aq::Timer timer;

  //
  // Settings
  aq::Settings::Ptr settings(new aq::Settings(*settingsBase));

  //
  // Load AQ engine
  aq::engine::AQEngine_Intf::Ptr aq_engine;
  if (simulateAQEngine)
  {
    aq::Logger::getInstance().log(AQ_INFO, "Do not use aq engine\n");
    aq_engine.reset(new aq::AQEngineSimulate(baseDesc, settings));
  }
  else if (!basicAQEngine)
  {
    aq_engine.reset(aq::engine::getAQEngineSystem(baseDesc, settings));
    if (aq_engine->check())
    {
      aq::Logger::getInstance().log(AQ_INFO, "Use aq engine: '%s'\n", settings->aqEngine.c_str());
    }
    else
    {
      aq::Logger::getInstance().log(AQ_WARNING, "cannot find aq engine: '%s'\n", settings->aqEngine.c_str());
      basicAQEngine = true;
    }
  }

  if (basicAQEngine)
  {
    aq::Logger::getInstance().log(AQ_INFO, "Use basic aq engine\n");
    aq_engine.reset(new aq::AQEngineBasic(baseDesc, settings));
  }

  //
  // prepare and process query
  std::string answer;

  if (!((prepareQuery(query, settingsBase, baseDesc, settings, answer, queryIdent, force) == EXIT_SUCCESS) &&
    (processQuery(query, settings, baseDesc, aq_engine, answer) == EXIT_SUCCESS)))
  {
    aq::Logger::getInstance().log(AQ_DEBUG, "QUERY FAILED:\n%s\n", query.c_str());
  }
  else
  {
    aq::Logger::getInstance().log(AQ_NOTICE, "Query Time elapsed: %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());
  }

  return EXIT_SUCCESS;
}

// -------------------------------------------------------------------------------------------------
int parse_queries(const std::string & aqHome,
                  const std::string & aqName,
                  const std::string & queryIdent,
                  aq::QueryReader   & queryReader,
                  const std::string & aqMatrixFileName,
                  aq::Settings::Ptr   settings,
                  aq::Base::Ptr       baseDesc,
                  bool                transform,
                  bool                simulateAQEngine,
                  bool                basicAQEngine,
                  bool                force)
{
  //
  // print info if use as command line tool
  if (settings->cmdLine)
  {
    std::cout << "Welcome to AlgoQuest Monitor version " << AQ_TOOLS_VERSION << std::endl;
    std::cout << "Copyright (c) 2013, AlgoQuest System. All rights reserved." << std::endl;
    std::cout << std::endl;
    if (settings->rootPath != "")
    {
      std::cout << "Connected to database " << settings->rootPath << std::endl;
      std::cout << std::endl;
    }
  }

  //
  // Get current database name from settings if set
  if (aqName == "")
  {
    std::string databaseName = settings->rootPath.filename().string();
    if (databaseName == ".")
      databaseName = settings->rootPath.parent_path().string();
  }
  else
  {
    settings->initPath(fs::path(aqHome) / fs::path(aqName));
  }

  std::string query;
  aq::CommandHandler cmdHandler(aqHome, aqName, settings, baseDesc);
  while ((query = queryReader.next()) != "")
  {
    if (transform)
    {
      transform_query(query, settings, baseDesc);
    }
    else if (aqMatrixFileName != "")
    {
      process_aq_matrix(query, aqMatrixFileName, settings->outputFile.string(), settings, baseDesc);
    }
    else
    {
      if (cmdHandler.process(query) == -1)
      {
        processSQLQueries(query, settings, queryIdent, baseDesc, simulateAQEngine, basicAQEngine, force);
      }
    }
  }
  return EXIT_SUCCESS;
}

// -------------------------------------------------------------------------------------------------
int main(int argc, char**argv)
{

  try
  {

    // Settings
    aq::Settings::Ptr settings(new aq::Settings);
    settings->outputFile = "stdout";

    // log options
    std::string mode;
    std::string ident;
    unsigned int level;
    bool lock_mode = false;
    bool date_mode = false;
    bool pid_mode = false;

    // aq options
    std::string aqHome;
    std::string aqName;
    std::string propertiesFile;
    std::string queryIdent;
    std::string sqlQuery;
    std::string sqlQueriesFile;
    std::string baseDescr;
    std::string DLLFunction;
    unsigned int worker;
    bool displayCount = false;
    bool trace = false;
    bool loadDatabase = false;
    bool force = false;
    bool useTextAQMatrix = false;

    // testing purpose options
    std::string aqMatrixFileName;
    bool transform = false;
    bool checkDatabase = false;
    bool simulateAQEngine = false;
    bool basicAQEngine = false;
    bool testPlugins = false;

    // load option
    std::string tableNameToLoad;

    // generate tmp table option
    unsigned int nbValues = 100;
    unsigned int minValue = 0;
    unsigned int maxValue = 100;
    unsigned int nbTables = 1;
    bool generateTmpTable = false;

    char * s = ::getenv("AQ_HOME");
    if (s != NULL)
      aqHome = s;

    std::cout << "AQ_HOME=" << aqHome << std::endl;

    //
    // initialize verb builder
    boost::shared_ptr<const aq::VerbBuilder> vb(new aq::VerbBuilder);
    aq::verb::VerbFactory::GetInstance().setBuilder(vb);

    //
    // if aq.ini exists in current directory, use it as default settings
    settings->iniFile = fs::path("aq.ini");
    if (fs::exists(settings->iniFile))
    {
        settings->load(settings->iniFile);
    }
    else if (fs::exists(fs::path(aqHome) / fs::path("aq.ini")))
    {
      settings->iniFile = aqHome + "/aq.ini";
      std::cout << "load configuration from " << settings->iniFile << std::endl;
      settings->load(settings->iniFile.string());
    }

    //
    // look for properties file in args
    for (int i = 1; i < argc; i++)
    {
      //
      // read ini file
      if ((strcmp(argv[i], "-s") == 0) || (strcmp(argv[i], "--settings") == 0))
      {
        if ((i + 1) < argc)
        {
          propertiesFile = argv[i+1];
          settings->load(propertiesFile);
        }
      }

    }

    //
    // command line arguments are prior to settings file
    po::options_description all("Allowed options");
    all.add_options()
      ("help,h", "produce help message")
      ;

    po::options_description log_options("Logging");
    log_options.add_options()
#if defined (__SYSLOG__)
      ("log-output", po::value<std::string>(&mode)->default_value("SYSLOG"), "[STDOUT|LOCALFILE|SYSLOG]")
#else
      ("log-output", po::value<std::string>(&mode)->default_value("STDOUT"), "[STDOUT|LOCALFILE]")
#endif
      ("log-level,v", po::value<unsigned int>(&level)->default_value(AQ_LOG_WARNING), "CRITICAL(2), ERROR(3), WARNING(4), NOTICE(5), INFO(6), DEBUG(7)")
      ("log-lock", po::bool_switch(&lock_mode), "for multithread program")
      ("log-date", po::bool_switch(&date_mode), "add date to log")
      ("log-pid", po::bool_switch(&pid_mode), "add thread id to log")
      ("log-ident", po::value<std::string>(&ident)->default_value("aq_query_resolver"), "")
      ;

    po::options_description engine("Engine");
    engine.add_options()
      ("settings,s", po::value<std::string>(&propertiesFile), "")
      ("aq-engine,e", po::value<boost::filesystem::path>(&settings->aqEngine))
      ("aq-home,r", po::value<std::string>(&aqHome)->default_value(aqHome), "set AQ Home (AQ_HOME environment variable)")
      ("aq-name,n", po::value<std::string>(&aqName), "")
      ("query-ident,i", po::value<std::string>(&queryIdent), "")
      ("query", po::value<std::string>(&sqlQuery), "")
      ("queries-file,f", po::value<std::string>(&sqlQueriesFile), "")
      ("output,o", po::value<boost::filesystem::path>(&settings->outputFile), "")
      ("worker,w", po::value<unsigned int>(&worker), "number of thread assigned to resolve the bunch of sql queries")
      ("parralellize,p", po::value<size_t>(&settings->process_thread)->default_value(settings->process_thread), "number of thread assigned resolve one sql queries")
      ("display-count", po::bool_switch(&displayCount), "")
      ("force", po::bool_switch(&force), "force use of directory if it already exists")
      ("keep-file,k", po::bool_switch(&settings->keepFiles), "")
      ("trace,t", po::bool_switch(&trace), "")
      ;

    po::positional_options_description positionalOptions;
    positionalOptions.add("aq-name", -1);

    po::options_description testing("Testing");
    testing.add_options()
      ("simulate-aq-engine,z", po::bool_switch(&simulateAQEngine), "")
      ("basic-aq-engine", po::bool_switch(&basicAQEngine), "")
      ("transform", po::bool_switch(&transform), "")
      ("skip-nested-query", po::value<bool>(&settings->skipNestedQuery), "")
      ("aq-matrix", po::value<std::string>(&aqMatrixFileName), "")
      ("check-database", po::bool_switch(&checkDatabase), "")
      ("test-plugins", po::bool_switch(&testPlugins), "")
      ;

    po::options_description external("External");
    external.add_options()
      ("use-dll-function", po::value<std::string>(&DLLFunction), "Choise your own .dll to use your function")
      ("use-bin-aq-matrix", po::bool_switch(&useTextAQMatrix), "")
      ;

    po::options_description loader("Loader");
    loader.add_options()
      ("load-db", po::bool_switch(&loadDatabase), "")
      ("load-table", po::value<std::string>(&tableNameToLoad), "")
      ;

    po::options_description genTmpTable("GenerateTmpTable [TESTING PURPOSE]");
    genTmpTable.add_options()
      ("gen-tmp-table", po::bool_switch(&generateTmpTable), "")
      ("nb-values", po::value<unsigned int>(&nbValues), "")
      ("min-value", po::value<unsigned int>(&minValue), "")
      ("max-value", po::value<unsigned int>(&maxValue), "")
      ("nb-tables", po::value<unsigned int>(&nbTables), "")
      ;

    all.add(log_options).add(engine).add(testing).add(external).add(loader).add(genTmpTable);

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(all).positional(positionalOptions).run(), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
      std::cout << all << "\n";
      return 1;
    }

    // parse positional options
    if (vm.count("aq-name"))
    {
      aqName = vm["aq-name"].as<std::string>();
    }

    //
    // settings flags bool
    settings->trace = trace || settings->trace;
    settings->displayCount = displayCount || settings->displayCount;
    settings->cmdLine = _isatty(_fileno(stdin)) != 0;

    //
    //
    boost::replace_all(aqHome, "\\", "/");
    boost::replace_all(aqHome, "//", "/");
    if ((!aqHome.empty()) && (*aqHome.rbegin() != '/'))
    {
      aqHome = aqHome + "/";
    }

    //
    //
    if (aqName == "")
    {
      aqName = settings->aqName;
    }
    if ((aqHome != "") && (aqName != ""))
    {
      settings->initPath(fs::path(aqHome) / fs::path(aqName));
    }

    //
    // Initialize Logger
    aq::Logger::getInstance(ident.c_str(), mode == "STDOUT" ? STDOUT : mode == "LOCALFILE" ? LOCALFILE : mode == "SYSLOG" ? SYSLOG : STDOUT);
    aq::Logger::getInstance().setLevel(level);
    aq::Logger::getInstance().setLockMode(lock_mode);
    aq::Logger::getInstance().setDateMode(date_mode);
    aq::Logger::getInstance().setPidMode(pid_mode);

    //
    // print Project Settings
    {
      auto settings_str = settings->to_string();
      std::vector<std::string> vsettings;
      boost::split(vsettings, settings_str, boost::is_any_of("\n"));
      aq::Logger::getInstance().log(AQ_DEBUG, "Settings:\n");
      for (const auto & line : vsettings)
      {
        aq::Logger::getInstance().log(AQ_DEBUG, (line + "\n").c_str());
      }
    }

    //
    // If Load database is invoked
    if (loadDatabase)
    {
      aq::base_t bd;
      if (aq::base_t::build_base_from_raw(settings->dbDesc.c_str(), bd) != -1)
      {
        return load_database(settings, bd, tableNameToLoad);
      }
      else
      {
        aq::Logger::getInstance().log(AQ_CRITICAL, "cannot find database desc file '%s'\n", settings->dbDesc.c_str());
        return EXIT_FAILURE;
      }
      assert(false);
    }

    //
    // Check Database
    if (checkDatabase)
    {
      return check_database(settings);
    }

    //
    // If generated temporary table is invoked
    if (generateTmpTable)
    {
      aq::base_t bd;
      if (aq::base_t::build_base_from_raw(settings->dbDesc.c_str(), bd) != -1)
      {
        int rc = 0;
        while ((nbTables-- > 0) && ((rc = generate_tmp_table(settings, bd, nbValues, minValue, maxValue)) == 0));
        return rc;
      }
      else
      {
        aq::Logger::getInstance().log(AQ_CRITICAL, "cannot find database desc file '%s'\n", settings->dbDesc.c_str());
        return EXIT_FAILURE;
      }
    }

    //
    // Test plugins
    if (testPlugins)
    {
      aq::Base::Ptr bd(new aq::Base(settings->dbDesc.string()));
      std::string plugins_path = "C:/Users/AlgoQuest/Documents/Visual Studio 2012/Projects/AQPlugin/x64/Debug/AQPlugin.dll";
      std::string query = "select aq_func1(t1.id), aq_func2(t1.v1) from t1;";
      return test_plugins(plugins_path, query, settings, bd);
    }

    //
    // parse inpout
    aq::QueryReader * reader = 0;
    std::fstream * fileQueries = 0;
    std::stringstream * streamQueries = 0;

    if (sqlQueriesFile != "")
    {
      fs::path p(sqlQueriesFile);
      if (!fs::exists(p))
      {
        std::cerr << "cannot find file " << p << std::endl;
        return -1;
      }

      fileQueries = new std::fstream(sqlQueriesFile.c_str(), std::ifstream::in);
      reader = new aq::QueryReader(*fileQueries);
    }
    else if (sqlQuery != "")
    {
      streamQueries = new std::stringstream();
      *streamQueries << sqlQuery;
      reader = new aq::QueryReader(*streamQueries);
    }
    else
    {
      reader = new aq::QueryReader(std::cin, settings->cmdLine ? "aq" : "");
    }

    //
    // Solve Queries
    aq::Base::Ptr bd(new aq::Base(settings->dbDesc.string()));
    auto rc = parse_queries(
      aqHome, aqName, queryIdent, *reader, aqMatrixFileName,
      settings, bd,
      transform, simulateAQEngine, basicAQEngine, force);

    delete reader;
    if (fileQueries)
      delete fileQueries;
    if (streamQueries)
      delete streamQueries;

    return rc;

  }
  catch (const aq::generic_error& error)
  {
    aq::Logger::getInstance().log(AQ_CRITICAL, error.what());
    std::cerr << "generic error: " << error.what() << std::endl;
    return error.getType();
  }
  catch (const std::exception& ex)
  {
    std::cerr << "standard exception" << ex.what() << std::endl;
    return EXIT_FAILURE;
  }
  catch (...)
  {
    std::cerr << "UNHANDLE EXCEPTION" << std::endl;
    return EXIT_FAILURE;
  }

  if (failedQueries) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
