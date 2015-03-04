#ifndef __AQ_SETTINGS_H__
#define __AQ_SETTINGS_H__

#if defined (WIN32)
# ifdef AQENGINE_EXPORTS
// #  define AQENGINE_API __declspec(dllexport)
# else
// #  define AQENGINE_API __declspec(dllimport)
# endif
#else
// # define AQENGINE_API __stdcall
// # define AQENGINE_API
#endif

#define AQENGINE_API

#include <string>
#include <sstream>
#include <boost/shared_ptr.hpp>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>

#define STR_BUF_SIZE 4096

#ifndef _MAX_PATH
#define _MAX_PATH 1024
#endif

namespace aq
{

/// \brief AlgoQuest Settings
struct Settings
{
  typedef boost::shared_ptr<Settings> Ptr;

  mutable std::stringstream output;

  std::string queryIdent; ///< query ident. each query should have an unique identification (as uuid)
  boost::filesystem::path iniFile; ///< settings ini absolute file name
  boost::filesystem::path outputFile; ///< the output file where result are written
  boost::filesystem::path answerFile; ///< the answer file where result are written \deprecated
  boost::filesystem::path dbDesc; ///< the database description file
  boost::filesystem::path aqEngine; ///< aq engine file name executable
  boost::filesystem::path aqHome; ///< algoquest databases root directory (path containing the directory database)
  std::string aqName; ///< algoquest database name
  boost::filesystem::path rootPath; ///< algoquest dabtabase root directory (aqHome/aqName/)
  boost::filesystem::path workingPath; ///< working directory for aq engine
  boost::filesystem::path tmpRootPath; ///< temporary root working directory for aq engine
  boost::filesystem::path dataPath; ///< data files directory (PRM, THESAURUSE, VDG, NMO and PRD files)
  boost::filesystem::path tmpPath; ///< temporary directory for aq engine (containing temporary table from nested queries)
  boost::filesystem::path dpyPath; ///< tempoaray display directory for aq engine (containing dpy/aq-matrix files)

  char fieldSeparator; ///< field separator of table loading files
  static const int MAX_COLUMN_NAME_SIZE = 255;

  size_t worker; ///< number of pool thread to resolve several queries
  size_t group_by_process_size; ///< number of thread to resolve aq matrix when a group by occur
  size_t process_thread; ///< number of thread to resolve a query

  int packSize; ///< packet size of the database (see aq-engine specification for more explanation)
  // int maxRecordSize; ///< \deprecated

  /// \name settings_flags settings flags
  /// \todo use mask
  /// \{
  bool computeAnswer;
  bool csvFormat;
  bool skipNestedQuery;
  bool useBinAQMatrix;
  bool displayCount;
  bool cmdLine;
  bool trace;
  bool keepFiles;
  /// \}

  AQENGINE_API Settings();
  AQENGINE_API Settings(const Settings&);
  AQENGINE_API ~Settings();
  AQENGINE_API Settings& operator=(const Settings&);

  /// \brief initialize path
  /// \param root
  AQENGINE_API void initPath(const std::string& root);

  /// \brief initialize path
  /// \param root
  AQENGINE_API void initPath(const boost::filesystem::path& root);

  /// \brief load ini file and set query ident
  /// \param iniFile
  /// \param queryIdent
  AQENGINE_API void load(const std::string& iniFile, const std::string& queryIdent);

  /// \brief load ini file
  /// \param iniFile
  AQENGINE_API void load(const std::string& iniFile);

  /// \brief load ini file
  /// \param iniFile
  AQENGINE_API void load(const boost::filesystem::path& iniFile);

  /// \brief load ini stream
  /// \param is
  AQENGINE_API void load(std::istream& is);

  /// \brief change query ident
  /// \param queryIdent
  AQENGINE_API void changeIdent(const std::string& queryIdent);

  /// \brief dump settings
  /// \param os
  AQENGINE_API void dump(std::ostream& os) const;

  /// \brief dump settings
  /// \return a string representing settings
  AQENGINE_API std::string to_string() const;

  /// \brief write the aq engine ini file
  /// \param os
  AQENGINE_API void writeAQEngineIni(std::ostream& os) const;
};

}

#endif
