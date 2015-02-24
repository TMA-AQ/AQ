#include "AQTextMatrix.h"
#include <aq/util/Logger.h>
#include <aq/util/Utilities.h>
#include <aq/util/Exceptions.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <list>
#include <aq/util/FileMapper.h>
#include <boost/scoped_array.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>
#include <boost/filesystem.hpp>

using namespace aq::engine;

#define STR_BIG_BUF_SIZE 128

namespace
{

struct inner_column_cmp_t
{
public:
  inner_column_cmp_t(const std::vector<size_t>& lessThanColumn)
    : m_lessThanColumn(lessThanColumn)
    {
    }
  bool operator()(size_t idx1, size_t idx2)
    {
      return m_lessThanColumn[idx1] < m_lessThanColumn[idx2];
    }
private:
  const std::vector<size_t>& m_lessThanColumn;
};

}

AQTextMatrix::AQTextMatrix(const aq::Settings::Ptr _settings, const aq::Base::Ptr _baseDesc)
  : AQMatrix(_settings, _baseDesc)
{
}

AQTextMatrix::~AQTextMatrix()
{
}

void AQTextMatrix::load(const char * filePath, std::vector<long long>& tableIDs)
{
  this->loadHeader(filePath, tableIDs);
  if (this->nbRows > 0)
  {
    this->loadData(filePath);
  }
}

void AQTextMatrix::loadHeader(const char * filePath, std::vector<long long>& tableIDs)
{
  auto header_name = boost::filesystem::path(filePath) / boost::filesystem::path("AnswerHeader00000_TXT.a_h");
  if (!boost::filesystem::exists(header_name))
  {
    aq::Logger::getInstance().log(AQ_ERROR, "can't find %s", header_name.c_str());
  }

  std::ifstream header(header_name.string());

  uint64_t nbTable, tableId;
  header >> nbTable;
  for (uint32_t i = 0; i < nbTable; ++i)
  {
    this->matrix.push_back(column_t());
    header >> tableId;
    this->matrix[this->matrix.size() - 1].table_id = tableId;
    tableIDs.push_back(tableId);
  }

  header >> this->totalCount;
  header >> this->nbRows;

  aq::Logger::getInstance().log(AQ_ERROR, "aq matrix: [table:%u;count:%u;rows:%u]\n", nbTable, totalCount, nbRows);

  uint64_t countCheck = 0;
  uint64_t rowCheck = 0;
  uint64_t nbGroups = 0, grpCount, grpRows;

  // group by not managed yet
  countCheck = grpCount = this->totalCount;
  rowCheck = grpRows = this->nbRows;
  this->groupByIndex.push_back(std::make_pair(grpCount, grpRows));

  if ((this->totalCount != countCheck) || (this->nbRows != rowCheck))
    throw aq::generic_error(aq::generic_error::AQ_ENGINE, "mismatch values in result [%u != %u] [%u != %u]", this->totalCount, countCheck, this->nbRows, rowCheck);

  this->hasCount = true;
}

void AQTextMatrix::loadData(const char * filePath)
{
  this->prepareData(filePath);
  for (uint64_t packet = 0; packet < this->nbPacket; ++packet)
  {
    this->loadNextPacket();
  }
  if (this->nbRows != this->count.size())
  {
    throw aq::generic_error(aq::generic_error::AQ_ENGINE, "bad matrix data file");
  }
}

void AQTextMatrix::prepareData(const char * filePath)
{
  this->filePath = filePath;
}

static std::string get_paquet_format(unsigned int paquet)
{
  std::ostringstream oss;
  oss << std::setfill('5') << std::setw(5) << std::right << paquet;
  return oss.str();
}

void AQTextMatrix::loadNextPacket()
{
  auto data_c_file = boost::filesystem::path(filePath) / boost::filesystem::path("AnsewerData" + get_paquet_format(this->packet) + "_TXT.a_c");
  auto data_p_file = boost::filesystem::path(filePath) / boost::filesystem::path("AnsewerData" + get_paquet_format(this->packet) + "_TXT.a_p");
  if (!boost::filesystem::exists(data_c_file))
  {
    aq::Logger::getInstance().log(AQ_ERROR, "can't find %s", data_c_file.c_str());
  }
  if (!boost::filesystem::exists(data_p_file))
  {
    aq::Logger::getInstance().log(AQ_ERROR, "can't find %s", data_p_file.c_str());
  }

  std::ifstream data_c(data_c_file.string());
  std::ifstream data_p(data_p_file.string());

  uint32_t index;
  uint64_t value;
  for (size_t i = 0; (i < aq::packet_size) && this->count.size() < this->nbRows; ++i)
  {
    for (size_t c = 0; c < this->matrix.size(); ++c)
    {
      data_p >> index;
      this->matrix[c].indexes.push_back(index);
    }
    data_c >> value;
    this->count.push_back(value);
    this->rowCountCheck += value;
  }

}
