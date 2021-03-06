#include "AQManager.h"
#include "AQEngineSimulate.h"

#include <aq/engine/AQRawMatrix.h>

#include <aq/util/Database.h>
#include <aq/util/FileMapper.h>
#include <aq/util/Timer.h>

#include <aq/parser/SQLParser.h>
#include <aq/parser/Parser.hpp>
#include <aq/parser/ID2Str.h>

#include <aq/verbs/VerbNode.h>

#include <aq/db_loader/DatabaseLoader.h>

#include <aq/QueryResolver.h>
#include <aq/UpdateResolver.h>
#include <aq/ThesaurusReader.h>
#include <aq/TreeUtilities.h>
#include <aq/AQFunctor.h>

#include <fstream>

#include <boost/array.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/filesystem.hpp>

static boost::mutex parserMutex;

namespace fs = boost::filesystem;

// -------------------------------------------------------------------------------------------------
int check_database(const aq::Settings::Ptr settings)
{
  int rc = 0;
  std::vector<std::string> errors;

  aq::Logger::getInstance().log(AQ_NOTICE, "check base [%s]", settings->rootPath.c_str());

  aq::Database db(settings->rootPath);
  if (!db.isValid())
  {
    aq::Logger::getInstance().log(AQ_ERROR, "invalid database [%s]\n", settings->rootPath.c_str());
    return EXIT_FAILURE;
  }

  aq::base_t b = db.getBaseDesc();

  //aq::ColumnItem item;
  //std::string value;
  //boost::shared_ptr<aq::columnmapper_intf> m;
  //boost::shared_ptr<aq::columnmapper_intf> tr;

  for (auto& t : b.table)
  {
    aq::Logger::getInstance().log(AQ_NOTICE, "check table [id:%u;name:%s;cols:%u;records:%u]\n",
      t.id, t.name.c_str(), t.colonne.size(), t.nb_record);
    for (auto& c : t.colonne)
    {
      aq::Logger::getInstance().log(AQ_NOTICE, "check table [%u;%s] column [%u;%s] [records:%u]\n",
        t.id, t.name.c_str(), c.id, c.name.c_str(), t.nb_record);
      for (int p = 0; p <= (t.nb_record / settings->packSize); p++)
      {
        auto thefilename = settings->dataPath / aq::Database::getThesaurusFileName(t.id, c.id, p);
        aq::Logger::getInstance().log(AQ_NOTICE, "check thesaurus [%s]\n", thefilename.c_str());

  //      switch (c.type)
  //      {
  //      case aq::symbole::t_char:
  //        tr.reset(new aq::thesaurusreader<char, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, p, false));
  //        break;
  //      case aq::symbole::t_double:
  //        tr.reset(new aq::thesaurusreader<double, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, p, false));
  //        break;
  //      case aq::symbole::t_int:
  //        tr.reset(new aq::thesaurusreader<uint32_t, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, p, false));
  //        break;
  //      case aq::symbole::t_long_long:
  //      case aq::symbole::t_date1:
  //        tr.reset(new aq::thesaurusreader<uint64_t, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, p, false));
  //        break;
  //      default:
  //        aq::logger::getinstance().log(aq_error, "type not supported [%s]\n", c.type);
  //      }
  //      size_t i = 0;
  //      bool duplicatedvalues = false;
  //      std::set<std::string> values;
  //      while (tr->loadvalue(i++, item) != -1)
  //      {
  //        value = item.tostring(tr->gettype());
  //        if (values.find(value) != values.end())
  //        {
  //          duplicatedvalues = true;
  //          aq::logger::getinstance().log(aq_error, "duplicated values [%s] in thesaurus [%s]\n", value.c_str(), thefilename.c_str());
  //        }
  //        values.insert(value);
  //      }
  //      if (duplicatedvalues)
  //      {
  //        std::stringstream ss;
  //        ss << "duplicated values found in thesaurus [" << thefilename << "]";
  //        errors.push_back(ss.str());
  //      }
  //      aq::logger::getinstance().log(aq_notice, "%u unique values read in thesaurus [%s]\n", values.size(), thefilename.c_str());
  //    }
  //    aq::logger::getinstance().log(aq_notice, "read full column\n");
  //    switch (c.type)
  //    {
  //    case aq::symbole::t_char:
  //      m.reset(new aq::columnmapper<char, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, false));
  //      break;
  //    case aq::symbole::t_double:
  //      m.reset(new aq::columnmapper<double, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, false));
  //      break;
  //    case aq::symbole::t_int:
  //      m.reset(new aq::columnmapper<uint32_t, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, false));
  //      break;
  //    case aq::symbole::t_long_long:
  //    case aq::symbole::t_date1:
  //      m.reset(new aq::columnmapper<uint64_t, aq::filemapper>(settings.datapath.c_str(), t.id, c.id, c.size, settings.packsize, false));
  //      break;
  //    default:
  //      aq::logger::getinstance().log(aq_error, "type not supported [%s]\n", c.type);
  //    }
  //    for (size_t i = 0; i < t.nb_record; i++)
  //    {
  //      if (m->loadvalue(i, item) != 0)
  //      {
  //        rc = exit_failure;
  //        aq::logger::getinstance().log(aq_error, "bad index %u on table [%u;%s] column [%u;%s]\n", i, t.id, t.name.c_str(), c.id, c.name.c_str());
  //        std::stringstream ss;
  //        ss << "bad index " << i << " on table [" << t.id << ";" << t.name << "] column [" << c.id << ";" << c.name << "]";
  //        errors.push_back(ss.str());
  //      }
  //      else if ((value = item.tostring(m->gettype())) == "")
  //      {
  //        rc = exit_failure;
  //        aq::logger::getinstance().log(aq_error, "bad value on index %u on table [%u;%s] column [%u;%s]\n", i, t.id, t.name.c_str(), c.id, c.name.c_str());
  //        std::stringstream ss;
  //        ss << "bad value on index " << i << " on table [" << t.id << ";" << t.name << "] column [" << c.id << ";" << c.name << "]";
  //        errors.push_back(ss.str());
  //      }
  //      else if ((i % ((t.nb_record / 10) + 1)) == 0)
  //      {
  //        aq::logger::getinstance().log(aq_info, "%s\n", value.c_str());
  //      }

      }
    }
  }

  //aq::logger::getinstance().log(aq_error, "");
  //aq::logger::getinstance().log(aq_error, "errors:\n");

  //for (auto& error : errors)
  //{
  //  aq::logger::getinstance().log(aq_error, "%s\n", error.c_str());
  //}

  return rc;
}

// -------------------------------------------------------------------------------------------------
int process_aq_matrix(const std::string& query, const std::string& aqMatrixFileName, const std::string& answerFileName, aq::Settings::Ptr settings, aq::Base::Ptr baseDesc)
{
  aq::tnode  *pNode;
  int  nRet;

  //
  // Parse SQL request
  {

    boost::mutex::scoped_lock lock(parserMutex);
    aq::Logger::getInstance().log(AQ_INFO, "parse sql query: '%s'\n", query.c_str());
    if ((nRet = SQLParse(query.c_str(), pNode)) != 0 )
    {
      aq::Logger::getInstance().log(AQ_ERROR, "error parsing sql request '%s'\n", query.c_str());
      return EXIT_FAILURE;
    }

  }

  boost::array<aq::tnode::tag_t, 6> categories_order = { { K_FROM, K_WHERE, K_SELECT, K_GROUP, K_HAVING, K_ORDER } };
  aq::verb::VerbNode::Ptr spTree = aq::verb::VerbNode::BuildVerbsTree(pNode, categories_order, baseDesc, settings );
  spTree->changeQuery();
  aq::util::cleanQuery( pNode );

  settings->answerFile = aqMatrixFileName;

  boost::shared_ptr<aq::engine::AQRawMatrix> aqMatrix(new aq::engine::AQRawMatrix(settings, baseDesc));
  std::vector<llong> tableIDs;

  aq::Timer timer;
  std::vector<std::string> answerFile;
  answerFile.push_back(aqMatrixFileName);
  for (std::vector<std::string>::const_iterator it = answerFile.begin(); it != answerFile.end(); ++it)
  {
    aqMatrix->load((*it).c_str(), tableIDs);
  }
  // aqMatrix->simulate(113867938, 2);
  // aqMatrix->simulate(10, 2);
  // tableIDs.push_back(8);
  aq::Logger::getInstance().log(AQ_INFO, "Load AQ Matrix: Elapsed Time = %s\n", aq::Timer::getString(timer.getTimeElapsed()).c_str());

  boost::shared_ptr<aq::AQEngineSimulate> aqEngine(new aq::AQEngineSimulate(baseDesc, settings));
  aqEngine->setAQMatrix(aqMatrix);
  aqEngine->setTablesIDs(tableIDs);

  unsigned int id_generator = 1;
  aq::QueryResolver queryResolver(pNode, settings, aqEngine, baseDesc, id_generator);
  queryResolver.solveAQMatrix(spTree);

  return 0;
}

// -------------------------------------------------------------------------------------------------
int transform_query(const std::string& query, aq::Settings::Ptr settings, aq::Base::Ptr baseDesc)
{
  aq::tnode  *pNode;
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

  }

  boost::array<uint32_t, 6> categories_order = { { K_FROM, K_WHERE, K_SELECT, K_GROUP, K_HAVING, K_ORDER } };
  aq::verb::VerbNode::Ptr spTree = aq::verb::VerbNode::BuildVerbsTree(pNode, categories_order, baseDesc, settings);
  spTree->changeQuery();
  aq::util::cleanQuery( pNode );

  std::string str;
  aq::syntax_tree_to_aql_form(pNode, str);
  aq::parser::ParseJeq( str );

  std::cout << str << std::endl;

  return 0;
}

// -------------------------------------------------------------------------------------------------
int load_database(const aq::Settings::Ptr settings, aq::base_t& baseDesc, const std::string& tableNameToLoad)
{
  aq::DatabaseLoader loader(baseDesc, settings->rootPath.string(), settings->packSize, ',', settings->csvFormat);
  if (tableNameToLoad != "")
  {
    for (size_t t = 0; t < baseDesc.table.size(); ++t)
    {
      if (tableNameToLoad != baseDesc.table[t].name)
      {
        continue;
      }
      aq::Logger::getInstance().log(AQ_INFO, "loading table %d\n", t + 1);
      assert(baseDesc.table[t].id = (int)(t + 1));
      loader.load(t + 1);
    }
  }
  else
  {
    loader.load();
  }
  return EXIT_SUCCESS;
}

// -------------------------------------------------------------------------------------------------
int generate_tmp_table(const aq::Settings::Ptr settings, aq::base_t& baseDesc, unsigned int nbValues, unsigned int minValue, unsigned int maxValue)
{
  if (minValue > maxValue)
    return -1;
  size_t tableIndex = baseDesc.table.size() + 1;
  size_t columnIndex = 1;
  size_t partIndex = 0;
  size_t size = 0;
  std::string type;
  unsigned int range = maxValue - minValue;
  unsigned int value = 0;
  switch (sizeof(value))
  {
  case 4:  type = "INT"; size = 4; break;
  case 8:  type = "LON"; size = 8; break;
  default: type = "INT"; size = 4; break;
  }
  ::srand((unsigned int)::time(NULL));
  FILE * fd = NULL;
  for (size_t i = 0; i < nbValues; i++)
  {
    if ((i % settings->packSize) == 0)
    {
      if (fd != NULL)
        fclose(fd);
      auto tmpFilename = settings->rootPath / aq::Database::getTemporaryFileName(tableIndex,  columnIndex,  partIndex, type.c_str(),  size);
      fd = fopen(tmpFilename.c_str(), "w");
      if (fd == NULL)
        return -1;
    }
    value = minValue + (::rand() % range);
    fwrite(&value, sizeof(value), 1, fd);
  }
  fclose(fd);
  baseDesc.table.push_back(aq::base_t::table_t());
  auto& table = *baseDesc.table.rbegin();
  std::stringstream ss;
  ss << "TMP" << tableIndex;
  table.name = ss.str();
  table.id = (unsigned int)tableIndex;
  table.nb_record = nbValues;
  table.colonne.push_back(aq::base_t::table_t::col_t());
  auto& col = *table.colonne.rbegin();
  col.name = "V1";
  col.id = 1;
  col.size = 1;
  col.type = aq::symbole::t_long_long;
  return 0;
}

// -------------------------------------------------------------------------------------------------
int prepareQuery(const std::string& query, const aq::Settings::Ptr settingsBase, aq::Base::Ptr baseDesc, aq::Settings::Ptr settings, std::string& displayFile, const std::string queryIdentStr, bool force)
{
  //
  // generate ident and ini file
  std::string queryIdentTmp = queryIdentStr;
  if (queryIdentTmp == "")
  {
    boost::uuids::uuid queryIdent = boost::uuids::random_generator()();
    std::ostringstream queryIdentOSS;
    queryIdentOSS << queryIdent;
    queryIdentTmp = queryIdentOSS.str();
    settings->changeIdent(queryIdentOSS.str());
  }
  else
  {
    settings->changeIdent(queryIdentTmp);
  }

  //
  // create directories
  std::list<fs::path> lpaths;
  lpaths.push_back(settings->rootPath / fs::path("calculus") / fs::path(queryIdentTmp));
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
  auto queryFilename = settings->rootPath / fs::path("calculus") / fs::path(queryIdentTmp) / fs::path("Request.sql");
  std::ofstream queryFile(queryFilename.c_str());
  queryFile << query;
  queryFile.close();

  //
  // write ini file (it is needed for now by AQEngine)
  std::ofstream iniFile(settings->iniFile.c_str());
  settings->writeAQEngineIni(iniFile);
  iniFile.close();

  // generate answer file
  // displayFile = settings.szRootPath + "/calculus/" + queryIdentStr + "/display.txt"; // TODO
  displayFile = (settings->rootPath / fs::path("calculus") / fs::path(queryIdentStr) / fs::path("answer.txt")).string(); // TODO
  aq::Logger::getInstance().log(AQ_INFO, "save answer to %s\n", displayFile.c_str());

  return EXIT_SUCCESS;
}

// -------------------------------------------------------------------------------------------------
int processQuery(const std::string& query, aq::Settings::Ptr settings, aq::Base::Ptr baseDesc, aq::engine::AQEngine_Intf::Ptr aq_engine,
                 const std::string& answer)
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
      aq::QueryResolver queryResolver(pNode, settings, aq_engine, baseDesc, id_generator);
      aq::Table::Ptr result = queryResolver.solve();
      timer.stop();
      if (settings->cmdLine)
      {
        std::cout << queryResolver.getNbRows() << " rows processed in " << aq::Timer::getString(timer.getTimeElapsed()) << std::endl;
        std::cout << std::endl;
      }
    }
    else if (pNode->tag == K_UPDATE)
    {
      aq::UpdateResolver updateResolver(pNode, settings, aq_engine, baseDesc);
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

  if (!settings->keepFiles)
  {
    aq::Logger::getInstance().log(AQ_NOTICE, "remove temporary directory '%s'\n", settings->tmpPath.c_str());
    aq::util::DeleteFolder(settings->tmpPath.c_str());
    aq::Logger::getInstance().log(AQ_NOTICE, "remove working directory '%s'\n", settings->workingPath.c_str());
    aq::util::DeleteFolder(settings->workingPath.c_str());
  }

  return rc;
}

// -------------------------------------------------------------------------------------------------
int test_plugins(const std::string& plugins_path, const std::string& query, const aq::Settings::Ptr settings, const aq::Base::Ptr base)
{

  aq::tnode * tree = nullptr;
  if (SQLParse(query.c_str(), tree) != 0 )
  {
    return EXIT_FAILURE;
  }

  std::cout << *tree << std::endl;

  try
  {
    aq::AQFunctor test(tree, plugins_path);
    test.dump(std::cout);
    test.callFunctor();
  }
  catch (const aq::generic_error& ge)
  {
    std::cerr << ge.what() << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cerr << ex.what() << std::endl;
  }
  catch (...)
  {
    std::cerr << "UNCATCHED EXCEPTION" << std::endl;
    throw;
  }

  return EXIT_SUCCESS;
}
