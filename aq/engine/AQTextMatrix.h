#pragma once

#include "AQMatrix.h"

namespace aq
{

namespace engine
{

/// \brief representation of aq engine result. See aq engine specification for more explanations.
class AQTextMatrix : public AQMatrix
{
public:
  AQENGINE_API AQTextMatrix(const Settings::Ptr settings, const Base::Ptr baseDesc);
  AQENGINE_API ~AQTextMatrix();

  AQENGINE_API AQTextMatrix(const AQTextMatrix& source) = delete;
  AQENGINE_API AQTextMatrix& operator=(const AQTextMatrix& source) = delete;

  /// \brief load full aq matrix
  /// \param filePath
  /// \param tableIds
  AQENGINE_API void load(const char * filePath, std::vector<long long>& tableIDs);

  /// \brief load only head aq matrix
  /// \param filePath
  /// \param tableIDs
  AQENGINE_API void loadHeader(const char * filePath, std::vector<long long>& tableIDs);

  /// \brief load only full data aq matrix
  /// \param filePath
  AQENGINE_API void loadData(const char * filePath);

  /// \brief prepare data file to be read by row
  /// \param filePath
  AQENGINE_API void prepareData(const char * filePath);

  /// \brief load next packet
  AQENGINE_API void loadNextPacket();

private:

  std::string filePath;

};

}
}
