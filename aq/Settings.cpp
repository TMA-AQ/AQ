#include "Settings.h"
#include <aq/util/Utilities.h>
#include <aq/util/Exceptions.h>
#include <aq/util/BaseDesc.h>
#include <aq/util/Logger.h>
#include <fstream>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace aq
{

Settings::Settings()
  :
  queryIdent(""),
  iniFile(""),
  outputFile(""),
  answerFile(""),
  dbDesc(""),
  aqEngine("aq-engine"),
  aqHome(""),
  aqName(""),
  rootPath(""),
  workingPath(""),
  tmpRootPath(""),
  dataPath(""),
  tmpPath(""),
  dpyPath(""),
  fieldSeparator(';'),
  worker(1),
  group_by_process_size(100000),
  process_thread(1),
  packSize(aq::packet_size),
  computeAnswer(true),
  csvFormat(true),
  skipNestedQuery(false),
  useBinAQMatrix(true),
  displayCount(false),
  cmdLine(false),
  trace(false),
  keepFiles(false)
{
}

Settings::Settings(const Settings& obj)
  :
  queryIdent(obj.queryIdent),
  iniFile(obj.iniFile),
  outputFile(obj.outputFile),
  answerFile(obj.answerFile),
  dbDesc(obj.dbDesc),
  aqEngine(obj.aqEngine),
  aqHome(obj.aqHome),
  aqName(obj.aqName),
  rootPath(obj.rootPath),
  workingPath(obj.workingPath),
  tmpRootPath(obj.tmpRootPath),
  dataPath(obj.dataPath),
  tmpPath(obj.tmpPath),
  dpyPath(obj.dpyPath),
  fieldSeparator(obj.fieldSeparator),
  worker(obj.worker),
  group_by_process_size(obj.group_by_process_size),
process_thread(obj.process_thread),
packSize(obj.packSize),
computeAnswer(obj.computeAnswer),
skipNestedQuery(obj.skipNestedQuery),
useBinAQMatrix(obj.useBinAQMatrix),
displayCount(obj.displayCount),
cmdLine(obj.cmdLine),
trace(obj.trace),
keepFiles(obj.keepFiles)
{
}

Settings::~Settings()
{
}

Settings& Settings::operator=(const Settings& obj)
{
  if (this != &obj)
  {
    queryIdent = obj.queryIdent;
    iniFile = obj.iniFile;
    outputFile = obj.outputFile;
    answerFile = obj.answerFile;
    dbDesc = obj.dbDesc;
    aqEngine = obj.aqEngine;
    aqHome = obj.aqHome;
    aqName = obj.aqName;
    rootPath = obj.rootPath;
    workingPath = obj.workingPath;
    tmpRootPath = obj.tmpRootPath;
    dataPath = obj.dataPath;
    tmpPath = obj.tmpPath;
    dpyPath = obj.dpyPath;
    fieldSeparator = obj.fieldSeparator;
    worker = obj.worker;
    group_by_process_size = obj.group_by_process_size;
    process_thread = obj.process_thread;
    packSize = obj.packSize;
    computeAnswer = obj.computeAnswer;
    computeAnswer = obj.computeAnswer;
    skipNestedQuery = obj.skipNestedQuery;
    useBinAQMatrix = obj.useBinAQMatrix;
    displayCount = obj.displayCount;
    cmdLine = obj.cmdLine;
    trace = obj.trace;
    keepFiles = obj.keepFiles;
  }
  return *this;
}

void Settings::load(const std::string& iniFile, const std::string& queryIdent)
{
  this->load(iniFile);
  this->changeIdent(queryIdent);
}

template <class T>
T get_opt_value(boost::property_tree::ptree& pt, const char * key, T default_value)
{
  boost::optional<T> opt = pt.get_optional<T>(boost::property_tree::ptree::path_type(key));
  if (opt.is_initialized()) return opt.get();
  else return default_value;
}

bool get_opt_value(boost::property_tree::ptree& pt, const char * key, bool default_value)
{
  boost::optional<std::string> opt = pt.get_optional<std::string>(boost::property_tree::ptree::path_type(key));
  if (opt.is_initialized())
  {
    std::string s = opt.get();
    boost::to_upper(s);
    return s == "TRUE" || s == "YES" || s == "1";
  }
  else return default_value;
}

void Settings::load(const std::string& iniFile)
{
  this->load(fs::path(iniFile));
}

void Settings::load(const boost::filesystem::path& iniFile)
{
  this->iniFile = fs::path(iniFile);
  std::ifstream fin(iniFile.c_str(), std::ifstream::in);
  if (fin.is_open())
  {
    this->load(fin);
  }
}

void Settings::load(std::istream& is)
{
  try
  {
    boost::property_tree::ptree pt;
    boost::property_tree::ini_parser::read_ini(is, pt);

    // all option are optional
    this->aqHome = get_opt_value(pt, "aq-home", this->aqHome);
    this->aqName = get_opt_value(pt, "aq-name", this->aqName);
    this->tmpRootPath = get_opt_value(pt, "tmp-folder", this->rootPath / fs::path("data_orga/tmp/"));
    this->fieldSeparator = get_opt_value(pt, "field-separator", ';');
    this->aqEngine = get_opt_value(pt, "aq-engine", this->aqEngine);
    this->worker = get_opt_value(pt, "worker", this->worker);
    this->group_by_process_size = get_opt_value(pt, "group-by-process-size", this->group_by_process_size);
    this->process_thread = get_opt_value(pt, "process-thread", this->process_thread);
    this->displayCount = get_opt_value(pt, "display-count", this->displayCount);
    this->trace = get_opt_value(pt, "trace", this->trace);
    this->keepFiles = get_opt_value(pt, "keep-files", this->keepFiles);

    //
    //
    this->initPath(this->aqHome / this->aqName);
  }
  catch (const boost::property_tree::ptree_error& e)
  {
    std::ostringstream oss;
    oss << "invalid properties file: " << iniFile << " [" << e.what() << "]" << std::endl;
    throw aq::generic_error(aq::generic_error::INVALID_FILE, oss.str());
  }
}

void Settings::initPath(const std::string& root)
{
  this->initPath(fs::path(root));
}

void Settings::initPath(const boost::filesystem::path& root)
{
  this->rootPath = root.string();

  //
  // tmp
  this->tmpRootPath = (root / fs::path("data_orga/tmp")).string();

  //
  // base desc file
  this->dbDesc = root / fs::path("base_struct/base.xml");
  if (!boost::filesystem::exists(this->dbDesc))
  {
    this->dbDesc = root / fs::path("base_struct/base.aqb");
  }

  //
  // data path
  this->dataPath = root / fs::path("data_orga/vdg/data/");
}

void Settings::changeIdent(const std::string& _queryIdent)
{
  this->queryIdent = _queryIdent;

  this->workingPath = fs::path(this->rootPath) / fs::path("calculus") / fs::path(queryIdent);
  this->answerFile = fs::path(this->workingPath) / fs::path("Answer.txt");

  //
  // tempory path
  this->tmpPath = fs::path(this->tmpRootPath) / fs::path(queryIdent);
  this->dpyPath = fs::path(this->tmpPath) / fs::path("dpy");

  //
  // change ini file
  this->iniFile = fs::path(this->rootPath) / fs::path("calculus") / fs::path(queryIdent) / fs::path("aqengine.ini");
}

void Settings::dump(std::ostream& os) const
{
  os << "root-path:            ['" << rootPath             << "']" << std::endl;
  os << "working-path:         ['" << workingPath          << "']" << std::endl;
  os << "tmp-root-path:        ['" << tmpRootPath          << "']" << std::endl;
  os << "dataPath:             ['" << dataPath             << "']" << std::endl;
  os << "tmpPath:              ['" << tmpPath              << "']" << std::endl;
  os << "dpyPath:              ['" << dpyPath              << "']" << std::endl;
  os << "db-desc:              ['" << dbDesc               << "']" << std::endl;
  os << "aq-engine:            ['" << aqEngine             << "']" << std::endl;
  os << "output:               ['" << outputFile           << "']" << std::endl;
  os << "answer:               ['" << answerFile           << "']" << std::endl;
  os << "fieldSeparator:       ['" << fieldSeparator       << "']" << std::endl;
  os << "MAX_COLUMN_NAME_SIZE: ["  << MAX_COLUMN_NAME_SIZE <<  "]" << std::endl;
  os << "packSize:             ["  << packSize             <<  "]" << std::endl;
  os << "computeAnswer:        ["  << computeAnswer        <<  "]" << std::endl;
  os << "displayCount:         ["  << displayCount         <<  "]" << std::endl;
  os << "cmdLine:              ["  << cmdLine              <<  "]" << std::endl;
  os << "trace:                ["  << trace                <<  "]" << std::endl;
  os << "keep-files:           ["  << keepFiles            <<  "]" << std::endl;
}

std::string Settings::to_string() const
{
  this->dump(this->output);
  return this->output.str();
}

void Settings::writeAQEngineIni(std::ostream& os) const
{
  os << "export.filename.final=" << dbDesc.string() << std::endl;
  os << "step1.field.separator=" << fieldSeparator << std::endl;
  os << "k_rep_racine=" << rootPath.string() << "/" << std::endl;
  // FIXME
  auto str = tmpRootPath.string();
  std::string::size_type pos = str.find("data_orga/tmp");
  if (pos != std::string::npos)
  {
    os << "k_rep_racine_tmp=" << str.substr(0, pos) << std::endl;
  }
  else
  {
    os << "k_rep_racine_tmp=" << str << "/" << std::endl;
  }
}

}
