#include "AQRawMatrix.h"
#include <aq/util/Logger.h>
#include <aq/util/Utilities.h>
#include <aq/util/Exceptions.h>
#include <iostream>
#include <set>
#include <list>
#include <aq/util/FileMapper.h>
#include <boost/scoped_array.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/bind.hpp>

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

AQRawMatrix::AQRawMatrix(const aq::Settings::Ptr _settings, const aq::Base::Ptr _baseDesc)
  : AQMatrix(_settings, _baseDesc)
{
}

AQRawMatrix::~AQRawMatrix()
{
}

void AQRawMatrix::load(const char * filePath, std::vector<long long>& tableIDs)
{
  this->loadHeader(filePath, tableIDs);
  if (this->nbRows > 0)
  {
    this->loadData(filePath);
  }
}

void AQRawMatrix::loadHeader(const char * filePath, std::vector<long long>& tableIDs)
{
  std::string answertHeader(filePath);
  answertHeader += "/AnswerHeader.a_h";
  FILE * fd = fopen(answertHeader.c_str(), "rb");
  if (fd == nullptr)
  {
    // try old name
    std::string answertHeader(filePath);
    answertHeader += "/AnswerHeader00000.a_h";
    fd = fopen(answertHeader.c_str(), "rb");
    if (fd == nullptr)
    {
      throw aq::generic_error(aq::generic_error::AQ_ENGINE, "cannot find aq matrix header file");
    }
  }

  uint64_t nbTable, tableId; // , nbGroups = 0;
  aq::util::unused(fread(&nbTable, sizeof(uint64_t), 1, fd));
  for (uint32_t i = 0; i < nbTable; ++i)
  {
    this->matrix.push_back(column_t());
    aq::util::unused(fread(&tableId, sizeof(uint64_t), 1, fd));
    this->matrix[this->matrix.size() - 1].table_id = tableId;
    tableIDs.push_back(tableId);
  }

  aq::util::unused(fread(&this->totalCount, sizeof(uint64_t), 1, fd));
  aq::util::unused(fread(&this->nbRows, sizeof(uint64_t), 1, fd));
  // fread(&nbGroups, sizeof(uint64_t), 1, fd);

  aq::Logger::getInstance().log(AQ_ERROR, "aq matrix: [table:%u;count:%u;rows:%u]\n", nbTable, this->totalCount, nbRows);

  uint64_t countCheck = 0;
  uint64_t rowCheck = 0;
  uint64_t grpCount, grpRows;

  /*
    for (uint64_t i = 0; i < nbGroups; ++i)
    {
    fread(&grpCount, sizeof(uint64_t), 1, fd);
    fread(&grpRows, sizeof(uint64_t), 1, fd);

    if ((grpCount == 0) || (grpRows == 0))
    throw aq::generic_error(aq::generic_error::AQ_ENGINE, "bad value in result");

    this->groupByIndex.push_back(std::make_pair(grpCount, grpRows));
    countCheck += grpCount;
    rowCheck += grpRows;
    assert(grpCount);
    assert(grpRows);
    }
  */

  // group by not managed yet
  countCheck = grpCount = this->totalCount;
  rowCheck = grpRows = this->nbRows;
  this->groupByIndex.push_back(std::make_pair(grpCount, grpRows));

  if ((this->totalCount != countCheck) || (this->nbRows != rowCheck))
    throw aq::generic_error(aq::generic_error::AQ_ENGINE, "mismatch values in result [%u != %u] [%u != %u]", this->totalCount, countCheck, this->nbRows, rowCheck);

  fclose(fd);

  this->hasCount = true;
}

void AQRawMatrix::loadData(const char * filePath)
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

void AQRawMatrix::prepareData(const char * filePath)
{
  this->nbRowsParsed = 0;
  this->packet = 0;
  this->nbPacket = (this->nbRows / aq::packet_size) + 1;
  this->answerFormatC = std::string(filePath);
  this->answerFormatC += "/AnswerData%.5u.a_c";
  this->answerFormatP = std::string(filePath);
  this->answerFormatP += "/AnswerData%.5u.a_p";
}

void AQRawMatrix::loadNextPacket()
{
  boost::scoped_array<char> answerDataC(new char[this->answerFormatC.size() + 128]); // FIXME
  sprintf(answerDataC.get(), this->answerFormatC.c_str(), this->packet);
  FILE * fdc = fopen(answerDataC.get(), "rb");
  if (fdc == nullptr)
  {
    throw aq::generic_error(aq::generic_error::AQ_ENGINE, "cannot find aq matrix data file %s", answerDataC.get());
  }

  boost::scoped_array<char> answerDataP(new char[this->answerFormatP.size() + 128]); // FIXME
  sprintf(answerDataP.get(), this->answerFormatP.c_str(), this->packet);
  FILE * fdp = fopen(answerDataP.get(), "rb");
  if (fdp == nullptr)
  {
    throw aq::generic_error(aq::generic_error::AQ_ENGINE, "cannot find aq matrix data file %s", answerDataP.get());
  }

  uint32_t index;
  uint64_t value;
  for (size_t i = 0; (i < aq::packet_size) && this->count.size() < nbRows; ++i)
  {
    for (size_t c = 0; c < this->matrix.size(); ++c)
    {
      aq::util::unused(fread(&index, sizeof(uint32_t), 1, fdp));
      this->matrix[c].indexes.push_back(index);
    }
    aq::util::unused(fread(&value, sizeof(uint64_t), 1, fdc));
    this->count.push_back(value);
    this->rowCountCheck += value;
  }

  fclose(fdc);
  fclose(fdp);

  this->packet += 1;

  if (this->packet == nbPacket)
  {
    assert(this->totalCount == this->rowCountCheck);
    assert(this->nbRows == this->count.size());
    if (this->totalCount != this->rowCountCheck)
    {
      Logger::getInstance().log(AQ_WARNING, "bad matrix data file [count_expected:%u] [count_get:%u]", this->totalCount, this->rowCountCheck);
      // exit(EXIT_FAILURE);
      // throw aq::generic_error(aq::generic_error::AQ_ENGINE, "bad matrix data file [count_expected:%u] [count_get:%u]", this->totalCount, this->rowCountCheck);
    }
    if (this->nbRows != this->count.size())
    {
      Logger::getInstance().log(AQ_WARNING, "bad matrix data file [nb_rows:%u] [nb_count:%u]", this->nbRows, this->count.size());
      // throw aq::generic_error(aq::generic_error::AQ_ENGINE, "bad matrix data file [nb_rows:%u] [nb_count:%u]", this->nbRows, this->count.size());
    }
  }
}
