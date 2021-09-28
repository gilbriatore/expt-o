#ifndef MEMORYMAPPEDFILE_HPP
#define MEMORYMAPPEDFILE_HPP

//Memory-Mapped File C++ Library Tutorial and Reference
//https://github.com/carlomilanesi/cpp-mmf

#include <cstddef> // for size_t
#include <boost/interprocess/sync/file_lock.hpp>
#include <windows.h>

namespace MMF
{
  unsigned int granularity();

  class Base
  {
    public:
      explicit Base();
      ~Base();

      size_t offset() const
      {
        return _offSet;
      }

      size_t mappedSize() const
      {
        return _mappedSize;
      }

      size_t fileSize() const
      {
        return _fileSize;
      }

      void unMap();
      void close();

      bool isOpen() const
      {
        return _fileHandle != (void*) -1;
      }

      typedef void* HANDLE;
      HANDLE fileHandle() const
      {
        return _fileHandle;
      }

    protected:
      size_t queryFileSize();
      char* _data;
      size_t _offSet;
      size_t _mappedSize;
      size_t _fileSize;
      int _granularity;
      HANDLE _fileHandle;
      HANDLE _fileMappingHandle;
      boost::interprocess::file_lock _fileLock;
  };

  class Reader: public Base
  {
    public:
      explicit Reader(char const* pathName = 0, bool mapAll = true);
      void open(char const* pathName, bool mapAll = true);
      void map(size_t offSet = 0, size_t requestedSize = 0);
      char* getData()
      {
        return _data;
      }
  };

  enum existsMode
  {
    ifExistsFail,
    ifExistsJustOpen,
    ifExistsMapAll,
    ifExistsTruncate,
  };

  enum doesntExistsMode
  {
    ifDoesntExistsFail,
    ifDoesntExistsCreate,
  };

  class Writer: public Base
  {
    public:
      void openOrCreate(char const* filename);
      char* getMap(size_t offset, size_t size);
      bool flush();
  };
}

#endif // MEMORYMAPPEDFILE_HPP
