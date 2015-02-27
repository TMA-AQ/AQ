#ifndef __AQ_DATABASE_H__
#define __AQ_DATABASE_H__

#include <string>
#include <sstream>
#include "BaseDesc.h"
#include <boost/filesystem.hpp>

namespace aq
{

/// \brief Database management
/// all database are stored on disk
/// \todo add a handle to manage storage
class Database
{
public:

  explicit Database(const boost::filesystem::path& _path);
  void dump(std::ostream& os) const;

  /// \brief check if database is valid (ready to use)
  bool isValid() const;

  /// \brief create database on disk from a database description
  /// \param base the base description of the database to create
  /// \todo handle errors
  void create(aq::base_t& base);

  /// \brief remove database from disk
  /// \todo handle errors
  void erase();

  /// \brief get database name
  /// \return database name
  std::string getName() const;

  /// \brief get database description
  /// \return database description
  aq::base_t getBaseDesc() const;

  /// \brief get database root path
  /// \return database root path
  boost::filesystem::path getRootPath() const;

  /// \brief get database working path
  /// \return database working path
  boost::filesystem::path getWorkingPath() const;

  /// \brief get database data path
  /// \return database data path
  boost::filesystem::path getDataPath() const;

  /// \deprecated
  /// \brief get database base description file
  /// \return database description file
  boost::filesystem::path getBaseDescFile() const;

  /// \brief get database temporary working path
  /// \return database temporary working path
  boost::filesystem::path getTemporaryWorkingPath() const;

  /// \brief get database temporary table load path
  /// \return database temporary table load path
  boost::filesystem::path getTemporaryTableLoadPath() const;

  /// \brief get database temporary column load path
  /// \return database temporary column load path
  boost::filesystem::path getTemporaryColumnLoadPath() const;

  /// \brief get prm filename
  /// \param tableIdx table's index
  /// \param columnIdx column's index
  /// \param partIdx paquet's index
  /// \return prm filename
  boost::filesystem::path getPrmFilePath(size_t tableIdx, size_t columnIdx, size_t partIdx);

  /// \brief get thesaurus filename
  /// \param tableIdx table's index
  /// \param columnIdx column's index
  /// \param partIdx paquet's index
  /// \return thesaurus filename
  boost::filesystem::path getThesaurusFilePath(size_t tableIdx, size_t columnIdx, size_t partIdx );

  static boost::filesystem::path getPrmFileName(size_t tableIdx, size_t columnIdx, size_t partIdx);
  static boost::filesystem::path getThesaurusFileName(size_t tableIdx, size_t columnIdx, size_t partIdx);
  static std::string getTemporaryFileName(size_t tableIdx, size_t columnIdx, size_t partIdx, const char * type, size_t size);

private:
  int load();
  static std::string getDataFileName(size_t tIdx, size_t cIdx, size_t pIdx, const char * ext);

  boost::filesystem::path path;
  aq::base_t baseDesc;
};

}

#endif
