#include "Database.h"
#include "Exceptions.h"
#include "Utilities.h"
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/replace.hpp>

namespace fs = boost::filesystem;

namespace aq
{

Database::Database(const boost::filesystem::path& _path)
  : path(_path.string())
{
  this->load();
}

bool Database::isValid() const
{
  if (baseDesc.name == "")
    return false;

  if (!boost::filesystem::exists(this->getBaseDescFile()))
    return false;

  if (!boost::filesystem::exists(this->getWorkingPath()))
    return false;

  if (!boost::filesystem::exists(this->getDataPath()))
    return false;

  return true;
}

void Database::create(aq::base_t& base)
{
  boost::filesystem::path paths[] =
    {
      this->path,
      this->path / fs::path("base_struct"),
      this->getWorkingPath(),
      this->getDataPath(),
      this->getTemporaryColumnLoadPath(),
      this->getTemporaryTableLoadPath(),
      this->getTemporaryWorkingPath(),
    };

  for (auto& p : paths)
  {
    if (!boost::filesystem::exists(p))
    {
      boost::filesystem::create_directories(p);
    }
  }

  std::ofstream f(this->getBaseDescFile().filename().string().c_str(), std::ios::trunc);
  aq::base_t::dump_raw_base(f, base);
  f.close();

}

void Database::erase()
{
  boost::filesystem::remove_all(this->path);
}

std::string Database::getName() const
{
  std::string name;
  std::ifstream f(this->getBaseDescFile().filename().string().c_str(), std::ios::in);
  if (f.is_open())
  {
    std::getline(f, name);
  }
  return name;
}

aq::base_t Database::getBaseDesc() const
{
  return baseDesc;
}

int Database::load()
{
  int rc = 0;
  auto bdFname = this->getBaseDescFile().filename().string();
  std::ifstream fin(bdFname.c_str(), std::ios::in);
  if (!fin.is_open())
    return -1;
  if (bdFname.find(".aqb") != std::string::npos)
    aq::base_t::build_base_from_raw(fin, baseDesc);
  else if (bdFname.find(".xml") != std::string::npos)
    aq::base_t::build_base_from_xml(fin, baseDesc);
  else
    rc = -1;
  return rc;
}

fs::path Database::getRootPath() const
{
  return this->path;
}

fs::path Database::getWorkingPath() const
{
  return this->path / fs::path("calculus");
}

fs::path Database::getDataPath() const
{
  return this->path / fs::path("data_orga/vdg/data/");
}

fs::path Database::getBaseDescFile() const
{
  return this->path / fs::path("base_struct/base.aqb");
}

fs::path Database::getTemporaryWorkingPath() const
{
  return this->path / fs::path("data_orga/tmp/");
}

fs::path Database::getTemporaryTableLoadPath() const
{
  return this->path / fs::path("data_orga/tables/");
}

fs::path Database::getTemporaryColumnLoadPath() const
{
  return this->path / fs::path("data_orga/columns/");
}

void Database::dump(std::ostream& os) const
{
  os << this->getName() << std::endl;
  os << this->path << std::endl;
  os << this->getBaseDescFile() << std::endl;
  os << this->getWorkingPath() << std::endl;
  os << this->getDataPath() << std::endl;
  aq::base_t::dump_raw_base(os, this->baseDesc);
}

fs::path Database::getPrmFilePath(size_t tableIdx, size_t columnIdx, size_t partIdx)
{
  return this->getDataPath() / Database::getPrmFileName(tableIdx, columnIdx, partIdx);
}

fs::path Database::getThesaurusFilePath(size_t tableIdx, size_t columnIdx, size_t partIdx )
{
  return this->getDataPath() / Database::getThesaurusFileName(tableIdx, columnIdx, partIdx);
}

// static
fs::path Database::getPrmFileName(size_t tableIdx, size_t columnIdx, size_t partIdx)
{
  return fs::path(Database::getDataFileName(tableIdx, columnIdx, partIdx, "prm"));
}

// static
fs::path Database::getThesaurusFileName(size_t tableIdx, size_t columnIdx, size_t partIdx)
{
  return fs::path(Database::getDataFileName(tableIdx, columnIdx, partIdx, "the"));
}

// static
std::string Database::getDataFileName(size_t tIdx, size_t cIdx, size_t pIdx, const char * ext)
{
  char szFN[ _MAX_PATH ];
  sprintf(szFN, "B001T%.4luC%.4luV01P%.12lu.%s", tIdx, cIdx, pIdx, ext);
  return szFN;
}

// static
std::string Database::getTemporaryFileName(size_t tableIdx, size_t columnIdx, size_t partIdx, const char * type, size_t size)
{
  char szFN[ _MAX_PATH ];
  sprintf(szFN, "B001TMP%.4luC%.4lu%s%.4luP%.12lu.TMP", tableIdx, columnIdx, type, size, partIdx);
  return szFN;
}

}
