#ifndef __FILE_CLOSER_H__
#define __FILE_CLOSER_H__

#include <cstdio>

namespace aq {

/// \brief file closer helper
/// to enable a file to be closed relatively to his scope.
class FileCloser
{
public:
  FileCloser(FILE *& _pFile) : pFile(_pFile) {}
  ~FileCloser() {
    if (pFile != nullptr)
      fclose(pFile);
  }
private:
  FileCloser(const FileCloser& o) = delete;
  FileCloser(const FileCloser&& o) = delete;
  FileCloser& operator=(const FileCloser& o) = delete;
  FileCloser& operator=(const FileCloser&& o) = delete;
  FILE *& pFile;
};

}

#endif
