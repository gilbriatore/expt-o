#pragma once
#ifndef KINECTSENSOR_H
#define KINECTSENSOR_H

#define NOMINMAX
#include <QObject>
#include <ppl.h>
#include <thread>
#include <vector>
#include <sstream>
#include <string>
#include <pcl/io/pcd_io.h>
#include "Kinect/KinectCloud.hpp"
#include "util/MMF.hpp"

template<class Interface>
inline void SafeRelease(Interface *& IRelease)
{
  if(IRelease != NULL)
  {
    IRelease->Release();
    IRelease = NULL;
  }
}

class KinectSensor : public QObject
{
    Q_OBJECT

  public:
    template <typename Type> inline bool
    isValueFinite (const pcl::PCLPointCloud2 &cloud,
                   const unsigned int point_index,
                   const int point_size,
                   const unsigned int field_idx,
                   const unsigned int fields_count)
    {
      Type value;
      memcpy (&value, &cloud.data[point_index * point_size + cloud.fields[field_idx].offset + fields_count * sizeof (Type)], sizeof (Type));
      if (!pcl_isfinite (value))
        return (false);
      return (true);
    }

    void readBinaryData(const unsigned char *map, pcl::PCLPointCloud2 &cloud)
    {
      cloud.is_dense = true;
      memcpy(&cloud.data[0], &map[0], cloud.data.size());

      int point_size = static_cast<int>(cloud.data.size() / (cloud.height * cloud.width));
      for (uint32_t i = 0; i < cloud.width * cloud.height; ++i)
      {
        for (unsigned int d = 0; d < static_cast<unsigned int> (cloud.fields.size()); ++d)
        {
          for (uint32_t c = 0; c < cloud.fields[d].count; ++c)
          {
            switch (cloud.fields[d].datatype)
            {
              case pcl::PCLPointField::UINT32:
              {
                if (!isValueFinite<pcl::traits::asType<pcl::PCLPointField::UINT32>::type>(cloud, i, point_size, d, c))
                  cloud.is_dense = false;
                break;
              }
              case pcl::PCLPointField::FLOAT32:
              {
                if (!isValueFinite<pcl::traits::asType<pcl::PCLPointField::FLOAT32>::type>(cloud, i, point_size, d, c))
                  cloud.is_dense = false;
                break;
              }
            }
          }
        }
      }
    }

    void readBinary(KinectCloud &cloud)
    {
      clearCloud();
      pcl::PCLPointCloud2 blob;
      blob.width = 512;
      blob.height = 424;
      blob.point_step = 16;
      blob.row_step = 16 * 512;

      blob.data.clear();
      blob.data.resize(217088 * 16);

      blob.fields.resize(4);
      blob.fields[0].name = "x";
      blob.fields[0].offset = 0;
      blob.fields[0].datatype = pcl::PCLPointField::FLOAT32;
      blob.fields[0].count = 1;

      blob.fields[1].name = "y";
      blob.fields[1].offset = 4;
      blob.fields[1].datatype = pcl::PCLPointField::FLOAT32;
      blob.fields[1].count = 1;

      blob.fields[2].name = "z";
      blob.fields[2].offset = 8;
      blob.fields[2].datatype = pcl::PCLPointField::FLOAT32;
      blob.fields[2].count = 1;

      blob.fields[3].name = "rgb";
      blob.fields[3].offset = 12;
      blob.fields[3].datatype = pcl::PCLPointField::UINT32;
      blob.fields[3].count = 1;

      HANDLE fh = ::CreateFile(_fileName.c_str(), GENERIC_READ,
                               FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
                               OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

      if (fh == INVALID_HANDLE_VALUE)
      {
        return;
      }

      HANDLE fm = CreateFileMapping(fh, NULL, PAGE_READONLY, 0, 0, NULL);

      LPVOID mapView = MapViewOfFile (fm, FILE_MAP_READ, 0, 0, 0);
      unsigned char *map = static_cast<unsigned char*>(mapView);
      readBinaryData(map, blob);
      UnmapViewOfFile(map);
      CloseHandle(fm);

      pcl::fromPCLPointCloud2(blob,cloud);
    }

  private:
    IKinectSensor* _sensor;
    ICoordinateMapper* _mapper;
    IMultiSourceFrameReader* _msReader;
    CameraSpacePoint* _cameras;
    ColorSpacePoint* _colors;
    KinectCloud::Ptr _cloud;

    BYTE* _cBuffer;

    long _timeElapsed = 0;
    const long _miliseconds = 33;
    const int _dWidth  = 512;
    const int _dHeight = 424;
    const int _cWidth  = 1920;
    const int _cHeight = 1080;

    HANDLE handler;
    std::string _fileName = "_kinectCloud.pcv"; //"../data/pcd_full.pcd";
    LARGE_INTEGER _fileSize = {0};

  public:
    KinectSensor() :
      _cBuffer(NULL),
      _cameras(NULL),
      _colors(NULL),
      _cloud(NULL),
      _sensor(NULL),
      _msReader(NULL),
      _mapper(NULL)
    {
      initializeSensor();
      _cBuffer = new BYTE[_cWidth * _cHeight * 4];
      _cameras = new CameraSpacePoint[_dWidth * _dHeight];
      _colors = new ColorSpacePoint[_dWidth * _dHeight];
      _cloud = boost::make_shared<KinectCloud>();
      clearCloud();
    }

    ~KinectSensor()
    {
      finalize();
    }

    inline int getFieldSize(const int datatype)
    {
      switch (datatype)
      {
        case pcl::PCLPointField::INT8:
        case pcl::PCLPointField::UINT8:
          return (1);

        case pcl::PCLPointField::INT16:
        case pcl::PCLPointField::UINT16:
          return (2);

        case pcl::PCLPointField::INT32:
        case pcl::PCLPointField::UINT32:
        case pcl::PCLPointField::FLOAT32:
          return (4);

        case pcl::PCLPointField::FLOAT64:
          return (8);

        default:
          return (0);
      }
    }

    void writeBinary(KinectCloud &cloud)
    {
      if (handler != INVALID_HANDLE_VALUE)
      {
        LARGE_INTEGER frameStart;
        frameStart.QuadPart = _fileSize.QuadPart;
        _fileSize.QuadPart = _fileSize.QuadPart + 3473408;

        HANDLE fm = CreateFileMapping(handler, NULL, PAGE_READWRITE, _fileSize.u.HighPart, _fileSize.u.LowPart, NULL);
        char *map = static_cast<char*>(MapViewOfFile(fm, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, _fileSize.QuadPart));
        CloseHandle(fm);

        for (size_t i = 0; i < cloud.points.size(); ++i)
        {
          int offs[4] = {0, 4, 8, 16};
          for (size_t j = 0; j < 4; ++j)
          {
            int offset = offs[j];
            memcpy(map, reinterpret_cast<const char*>(&cloud.points[i]) + offset, 4);
            map += 4;
          }
        }
        UnmapViewOfFile(map);
      }
    }

    void read()
    {
      int count = 1;
      while(true)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();

        readBinary(*_cloud);

        auto time = std::chrono::high_resolution_clock::now() - start;
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
        _timeElapsed += elapsed;
        _cloud->timeElapsed = _timeElapsed / count++;

        emit send(_cloud);

        if (elapsed < _miliseconds)
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(_miliseconds - elapsed));
        }
        else
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
      }
      std::cout << "Frames lidos!" << std::endl;
    }

    void write()
    {
      handler = CreateFile(_fileName.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
      if (handler == INVALID_HANDLE_VALUE)
      {
        throw pcl::IOException ("Error during CreateFile!");
        return;
      }

      int count = 1;
      while(count < 2)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();
        if (update())
        {
          writeBinary(*_cloud);

          auto time = std::chrono::high_resolution_clock::now() - start;
          elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
          _timeElapsed += elapsed;
          _cloud->timeElapsed = _timeElapsed / count++;
          emit send(_cloud);
          if (elapsed < _miliseconds)
          {
            std::this_thread::sleep_for(std::chrono::milliseconds(_miliseconds - elapsed));
          }
        }
        else
        {
          std::this_thread::sleep_for(std::chrono::milliseconds(5));
        }
      }
      std::cout << "Frames gravados!" << std::endl;
    }

  public slots:
    void run()
    {
      //write();
      read();
    }

  private:
    HRESULT initializeSensor()
    {
      HRESULT hr;
      hr = GetDefaultKinectSensor(&_sensor);
      if (FAILED(hr))
      {
        return hr;
      }

      if (_sensor)
      {
        if (SUCCEEDED(hr))
        {
          hr = _sensor->get_CoordinateMapper(&_mapper);
        }

        hr = _sensor->Open();

        if (SUCCEEDED(hr))
        {
          hr = _sensor->OpenMultiSourceFrameReader(
                FrameSourceTypes::FrameSourceTypes_Depth |
                FrameSourceTypes::FrameSourceTypes_Color,
                &_msReader);
        }
      }
      if (!_sensor || FAILED(hr))
      {
        std::cout << "No ready Kinect found!" << std::endl;
        return E_FAIL;
      }
      return hr;
    }

    bool update()
    {
      bool updated = false;
      if (!_msReader)
      {
        return updated;
      }

      IDepthFrame* frmDepth = NULL;
      IColorFrame* frmColor = NULL;
      IMultiSourceFrame* msFrame = NULL;

      HRESULT hr = _msReader->AcquireLatestFrame(&msFrame);

      if (SUCCEEDED(hr))
      {
        IDepthFrameReference* frmDepthRef = NULL;
        hr = msFrame->get_DepthFrameReference(&frmDepthRef);
        if (SUCCEEDED(hr))
        {
          hr = frmDepthRef->AcquireFrame(&frmDepth);
        }
        SafeRelease(frmDepthRef);
      }

      if (SUCCEEDED(hr))
      {
        IColorFrameReference* frmColorRef = NULL;
        hr = msFrame->get_ColorFrameReference(&frmColorRef);
        if (SUCCEEDED(hr))
        {
          hr = frmColorRef->AcquireFrame(&frmColor);
        }
        SafeRelease(frmColorRef);
      }

      if (SUCCEEDED(hr))
      {
        UINT dSize = 0;
        int dWidth = 0, dhHeight = 0;
        IFrameDescription* frmDepthDesc = NULL;
        UINT16 *dBuffer = NULL;

        UINT cSize = 0;
        int cWidth = 0, cHeight = 0;
        IFrameDescription* frmColorDesc = NULL;
        ColorImageFormat format = ColorImageFormat_None;
        BYTE *cBuffer = NULL;

        hr = frmDepth->get_FrameDescription(&frmDepthDesc);

        if (SUCCEEDED(hr))
        {
          hr = frmDepthDesc->get_Width(&dWidth);
        }

        if (SUCCEEDED(hr))
        {
          hr = frmDepthDesc->get_Height(&dhHeight);
        }

        if (SUCCEEDED(hr))
        {
          hr = frmDepth->AccessUnderlyingBuffer(&dSize, &dBuffer);
        }

        if (SUCCEEDED(hr))
        {
          hr = frmColor->get_FrameDescription(&frmColorDesc);
        }

        if (SUCCEEDED(hr))
        {
          hr = frmColorDesc->get_Width(&cWidth);
        }

        if (SUCCEEDED(hr))
        {
          hr = frmColorDesc->get_Height(&cHeight);
        }

        if (SUCCEEDED(hr))
        {
          hr = frmColor->get_RawColorImageFormat(&format);
        }

        if (SUCCEEDED(hr))
        {
          if (format == ColorImageFormat_Bgra)
          {
            hr = frmColor->AccessRawUnderlyingBuffer(&cSize, &cBuffer);
          }
          else if (_cBuffer)
          {
            cBuffer = _cBuffer;
            cSize = cWidth * cHeight * 4;
            ColorImageFormat bgra = ColorImageFormat_Bgra;
            hr = frmColor->CopyConvertedFrameDataToArray(cSize, cBuffer, bgra);
          }
          else
          {
            hr = E_FAIL;
          }
        }

        if (SUCCEEDED(hr))
        {
          updated = process(dBuffer, dWidth, dhHeight, cBuffer, cWidth, cHeight);
        }
        SafeRelease(frmDepthDesc);
        SafeRelease(frmColorDesc);
      }
      SafeRelease(frmDepth);
      SafeRelease(frmColor);
      SafeRelease(msFrame);
      return updated;
    }

    bool process(const UINT16* dBuffer, int dWidth, int dHeight,
                 const BYTE* cBuffer, int cWidth, int cHeight)
    {
      bool updated = false;
      if (_mapper && _cameras && _colors &&
          dBuffer && (dWidth == _dWidth) && (dHeight == _dHeight) &&
          cBuffer && (cWidth == _cWidth) && (cHeight == _cHeight))
      {
        UINT size = _dWidth * _dHeight;
        HRESULT hr1 = _mapper->MapDepthFrameToCameraSpace(size, dBuffer, size , _cameras);
        HRESULT hr2 = _mapper->MapDepthFrameToColorSpace(size, dBuffer, size, _colors);

        if (SUCCEEDED(hr1) && SUCCEEDED(hr2))
        {
          clearCloud();
          for (int dIdx = 0; dIdx < size; ++dIdx)
          {
            CameraSpacePoint camera = _cameras[dIdx];
            if (camera.X != -std::numeric_limits<float>::infinity() &&
                camera.Y != -std::numeric_limits<float>::infinity() &&
                camera.Z != -std::numeric_limits<float>::infinity())
            {
              _cloud->points[dIdx].x = camera.X;
              _cloud->points[dIdx].y = camera.Y;
              _cloud->points[dIdx].z = camera.Z;

              ColorSpacePoint color = _colors[dIdx];
              int x = static_cast<int>(color.X + 0.5f);
              int y = static_cast<int>(color.Y + 0.5f);

              if( (0 <= x) && (x < cWidth) &&
                  (0 <= y) && (y < cHeight))
              {
                unsigned int cIdx = ( y * cWidth + x) * 4;
                _cloud->points[dIdx].b = cBuffer[cIdx + 0];
                _cloud->points[dIdx].g = cBuffer[cIdx + 1];
                _cloud->points[dIdx].r = cBuffer[cIdx + 2];
              }
            }
          }
          updated = true;
        }
      }
      return updated;
    }

    void clearCloud()
    {
      _cloud->clear();
      _cloud->width = static_cast<uint32_t>(_dWidth);
      _cloud->height = static_cast<uint32_t>(_dHeight);
      _cloud->points.resize(_dWidth * _dHeight);
      _cloud->is_dense = false;
    }

    void finalize()
    {
      if(_sensor != nullptr){
        _sensor->Close();
      }
      CloseHandle(handler);
    }

  signals:
    void send(KinectCloud::Ptr _cloud);
};

#endif // KINECTSENSOR_H
