#include "MMF.hpp"
#include <iostream>
#include <boost/filesystem.hpp>

namespace MMF
{
  unsigned int granularity()
  {
    SYSTEM_INFO SystemInfo;
    GetSystemInfo(&SystemInfo);
    return SystemInfo.dwAllocationGranularity;
  }

  Base::Base():
    _data(0),
    _offSet(0),
    _mappedSize(0),
    _fileSize(0),
    _granularity(granularity()),
    _fileHandle(INVALID_HANDLE_VALUE),
    _fileMappingHandle(INVALID_HANDLE_VALUE)
  {
  }

  Base::~Base()
  {
    close();
  }

  void Base::close()
  {
    unMap();
    ::CloseHandle(_fileHandle);
    _fileHandle = (void*)-1;
    _fileSize = 0;
  }

  void Base::unMap()
  {
    if (_data)
    {
      char* realData = _data - (_offSet - _offSet / _granularity * _granularity);
      ::UnmapViewOfFile(realData);
      ::CloseHandle(_fileMappingHandle);
      _fileMappingHandle = INVALID_HANDLE_VALUE;
    }
    _data = 0;
    _offSet = 0;
    _mappedSize = 0;
  }

  size_t Base::queryFileSize()
  {
    DWORD highSize;
    DWORD lowSize = GetFileSize(_fileHandle, &highSize);
    return (size_t(highSize) << 32) | lowSize;
  }

  Reader::Reader(char const* pathName, bool mapAll)
  {
    open(pathName, mapAll);
  }

  void Reader::open(char const* pathName, bool mapAll)
  {
    if (!pathName)
    {
      return;
    }

    if (isOpen())
    {
      close();
    }

    DWORD dwDesiredAccess = GENERIC_READ;
    DWORD dwShareMode = FILE_SHARE_READ | FILE_SHARE_WRITE;
    LPSECURITY_ATTRIBUTES lpSecurityAttributes = 0;
    DWORD dwCreationDisposition = OPEN_EXISTING;
    DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
    HANDLE hTemplateFile = 0;

    _fileHandle = ::CreateFile(
          pathName,
          dwDesiredAccess,
          dwShareMode,
          lpSecurityAttributes,
          dwCreationDisposition,
          dwFlagsAndAttributes,
          hTemplateFile
          );

    if (_fileHandle == INVALID_HANDLE_VALUE)
    {
      return;
    }

    _fileSize = queryFileSize();
    if (mapAll)
    {
      map();
    }
  }

  void Reader::map(
      size_t offSet, size_t requestedSize)
  {
    unMap();

    if (offSet >= _fileSize)
    {
      return;
    }

    size_t mappingSize = requestedSize && offSet + requestedSize
        < _fileSize ? requestedSize : _fileSize - offSet;

    if (mappingSize <= 0)
    {
      return;
    }

    size_t realOffSet = offSet / _granularity * _granularity;

    LPSECURITY_ATTRIBUTES lpFileMappingAttributes = 0;
    DWORD flProtect = PAGE_READONLY;
    DWORD dwMaximumSizeHigh = (offSet + mappingSize) >> 32;
    DWORD dwMaximumSizeLow = (offSet + mappingSize) & 0xFFFFFFFF;
    LPCSTR lpName = 0;

    _fileMappingHandle = ::CreateFileMapping(
          _fileHandle,
          lpFileMappingAttributes,
          flProtect,
          dwMaximumSizeHigh,
          dwMaximumSizeLow,
          lpName);

    if (_fileMappingHandle == INVALID_HANDLE_VALUE)
    {
      return;
    }


    DWORD dwDesiredAccess = FILE_MAP_READ;
    DWORD dwFileOffsetHigh = static_cast<DWORD>(realOffSet >> 32);
    DWORD dwFileOffsetLow = static_cast<DWORD>(realOffSet & 0xFFFFFFFF);
    SIZE_T dwNumberOfBytesToMap = offSet - realOffSet + mappingSize;

    LPVOID mapView = ::MapViewOfFile(
          _fileMappingHandle,
          dwDesiredAccess,
          dwFileOffsetHigh,
          dwFileOffsetLow,
          dwNumberOfBytesToMap);

    char* realData = static_cast<char*>(mapView);
    if (!realData)
    {
      return;
    }
    _data = realData + (offSet - realOffSet);
    _mappedSize = mappingSize;
    _offSet = offSet;
  }

  void Writer::openOrCreate(char const* filename)
  {
    if (!filename)
    {
      std::cout << "Writer::openOrCreate(): filename invalid!"  << std::endl;
      return;
    }

    int openMode;

    if (!boost::filesystem::exists(filename))
    {
      openMode = CREATE_NEW;
    }
    else
    {
      openMode = OPEN_EXISTING;
    }

    DWORD dwDesiredAccess = GENERIC_READ | GENERIC_WRITE;
    DWORD dwShareMode = FILE_SHARE_READ | FILE_SHARE_WRITE;
    LPSECURITY_ATTRIBUTES lpSecurityAttributes = 0;
    DWORD dwCreationDisposition = openMode;
    DWORD dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
    HANDLE hTemplateFile = 0;

    _fileHandle = ::CreateFile(
          filename,
          dwDesiredAccess,
          dwShareMode,
          lpSecurityAttributes,
          dwCreationDisposition,
          dwFlagsAndAttributes,
          hTemplateFile
          );

    if (_fileHandle == INVALID_HANDLE_VALUE)
    {
      std::cout << "Writer::openOrCreate(): _fileHandle invalid!"  << std::endl;
      return;
    }

    _fileSize = queryFileSize();
  }

  char* Writer::getMap(size_t offset, size_t size)
  {
    unMap();

    if (offset > _fileSize)
    {
      std::cout << "Writer::getMap(): offset > _fileSize"  << std::endl;
      return NULL;
    }

    if (_fileHandle == INVALID_HANDLE_VALUE)
    {
      std::cout << "Writer::getMap(): _fileHandle invalid!"  << std::endl;
      return NULL;
    }

    size_t mappingSize = size ? size : _fileSize - offset;
    size_t realOffSet = offset / _granularity * _granularity;

    LPSECURITY_ATTRIBUTES lpFileMappingAttributes = NULL;
    DWORD flProtect = PAGE_READWRITE;
    DWORD dwMaximumSizeHigh = (offset + mappingSize) >> 32;
    DWORD dwMaximumSizeLow = (offset + mappingSize) & 0xFFFFFFFF;
    LPCSTR lpName = NULL;

    _fileMappingHandle = ::CreateFileMapping(
          _fileHandle,
          lpFileMappingAttributes,
          flProtect,
          dwMaximumSizeHigh,
          dwMaximumSizeLow,
          lpName
          );

    if (_fileMappingHandle == INVALID_HANDLE_VALUE)
    {
      std::cout << "Writer::getMap(): _fileMappingHandle invalid!"  << std::endl;
      return NULL;
    }

    DWORD dwDesiredAccess = FILE_MAP_READ | FILE_MAP_WRITE;
    DWORD dwFileOffsetHigh = realOffSet >> 32;
    DWORD dwFileOffsetLow = realOffSet & 0xFFFFFFFF;
    SIZE_T dwNumberOfBytesToMap = offset - realOffSet + mappingSize;

    LPVOID map= ::MapViewOfFile(
          _fileMappingHandle,
          dwDesiredAccess,
          dwFileOffsetHigh,
          dwFileOffsetLow,
          dwNumberOfBytesToMap
          );

    char* realData = static_cast<char*>(map);
    if (!realData)
    {
      std::cout << "Writer::getMap(): realData NULL!"  << std::endl;
      return NULL;
    }

    if (offset + mappingSize > _fileSize)
    {
      _fileSize = offset + mappingSize;
    }

    _data = realData + (offset - realOffSet);
    _mappedSize = mappingSize;
    _offSet = offset;
    return _data;
  }

  bool Writer::flush()
  {
    if (_data)
    {
      char* realData = _data - (_offSet - _offSet / _granularity * _granularity);
      size_t real_mapped_size = _mappedSize + (_data - realData);

      return ::FlushViewOfFile(realData, real_mapped_size) != 0
          && FlushFileBuffers(_fileHandle) != 0;

      if (::FlushViewOfFile(realData, real_mapped_size) == 0)
      {
        return false;
      }
    }
    return FlushFileBuffers(_fileHandle) != 0;
  }
}
