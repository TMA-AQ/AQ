#ifndef __DATABASE_LOADER_H__
#define __DATABASE_LOADER_H__

#include <cstddef>
#include <string>
#include <set>
#include <vector>
#include <list>
#include <aq/util/BaseDesc.h>
#include <aq/util/DateConversion.h>
#include <boost/filesystem.hpp>

namespace aq
{

/// \brief database loader
///
/// Use this class to load table files into a predefined database.
/// The database must have already been created, and have a valid database description containing future loaded tables.
/// There is 5 type of files : PRM, THESAURUS, VDG, NMO, PRD
class DatabaseLoader
{
public:
  class item_cmp_t
  {
  public:
    item_cmp_t(size_t _size) : size(_size) {}
    bool operator()(const void * buf1, const void * buf2) const
      {
        return ::memcmp(buf1, buf2, size) < 0;
      }
  private:
    size_t size;
  };

  typedef std::set<void*, item_cmp_t> thesaurus_t;
  typedef std::vector<uint32_t>       prm_t;

  struct column_info_t
  {
    aq::base_t::table_t::col_t   col;
    std::string                  filename;
    FILE                       * fd;
    prm_t                      * prm;
    thesaurus_t                * thesaurus;
  };

  /// \brief initialize a database loader without using AlgoQuest Loader
  /// \param _bd
  /// \param _path
  /// \param _packet_size
  /// \param _end_of_field_c
  /// \param _csv_format
  /// the database loader will generate only PRM and THESAURUS files
  DatabaseLoader(const aq::base_t _bd, const std::string& _path, const size_t _packet_size, const char _end_of_field_c, bool _csv_format);

  void load(); ///< load from table_name.txt file (can be a csv file)
  void load(const size_t table_id); ///< load from table_name.txt file (can be a csv file)
  void loadAllColumns() const; ///< load from column prepared files
  void loadColumn(const size_t table_id, const size_t column_id) const; ///< load from column prepared file
  void loadColumn(const size_t table_id, const size_t column_id, const std::list<int32_t>& values);

protected:

  void buildPrmThesaurus(const column_info_t& ci, size_t table_id, size_t col_id, size_t packet) const;
  void loadTable(const aq::base_t::table_t& table, const std::string& filename) const;
  void writeRecord(std::vector<column_info_t>& columns_infos, const char * record) const;
  void FileWriteEnreg(column_info_t& ci, char *my_field) const;
  bool endOfField(unsigned char c) const;

private:
  const aq::base_t my_base;
  mutable aq::DateConversion dateConverter;
  boost::filesystem::path k_rep_racine;
  boost::filesystem::path k_rep_param;
  boost::filesystem::path ini_filename;
  boost::filesystem::path rep_source;
  boost::filesystem::path rep_cible;
  boost::filesystem::path base_desc_file;
  std::string format_file_name;
  size_t packet_size;
  unsigned char end_of_field_c;
  bool csv_format;

};

}

#endif
