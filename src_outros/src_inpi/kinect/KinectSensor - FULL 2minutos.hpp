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
#include <pcl/point_traits.h>
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
                   const unsigned int pointIndex,
                   const int pointSize,
                   const unsigned int fieldIdx,
                   const unsigned int fieldsCount)
    {
      Type value;
      int typeSize = sizeof(Type);

      memcpy(&value, &cloud.data[
            pointIndex * pointSize +
            cloud.fields[fieldIdx].offset +
            fieldsCount * typeSize], typeSize);

      if (!pcl_isfinite(value))
      {
        return (false);
      }
      else
      {
        return (true);
      }
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
    //std::string _fileName = "_kinectCloud.pcv";
    //std::string _fileName = "c:/data/bio_10cmx2mSub.pcv";
    std::string _fileName = "c:/data/bio_10cmx1.75MovElev.pcv";


    const long _HDR_OFFSET = 185;
    const long _QTD_BYTES = 3473408;
    const long _FRM_POINTS = 217088;
    LARGE_INTEGER _fileSize = {0};
    LARGE_INTEGER _fileStart = {184};

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

    void writeBinary(KinectCloud &cloud)
    {
      if (handler != INVALID_HANDLE_VALUE)
      {
//        LARGE_INTEGER frameStart;
//        frameStart.QuadPart = _fileSize.QuadPart;
//        _fileSize.QuadPart = _fileSize.QuadPart + 3473408;

//        HANDLE fm = CreateFileMapping(handler, NULL, PAGE_READWRITE, _fileSize.u.HighPart, _fileSize.u.LowPart, NULL);
//        char *map = static_cast<char*>(MapViewOfFile(fm, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, _fileSize.QuadPart));
//        CloseHandle(fm);

//        for (size_t i = 0; i < cloud.points.size(); ++i)
//        {
//          int offs[4] = {0, 4, 8, 16};
//          for (size_t j = 0; j < 4; ++j)
//          {
//            int offset = offs[j];
//            memcpy(map, reinterpret_cast<const char*>(&cloud.points[i]) + offset, 4);
//            map += 4;
//          }
//        }
//        UnmapViewOfFile(map);
      }
    }

    bool readBinary(KinectCloud &cloud)
    {
      clearCloud();
      pcl::PCLPointCloud2 blob;
      blob.width = 512;
      blob.height = 424;
      blob.point_step = 16;
      blob.row_step = 16 * 512;

      blob.data.clear();
      blob.data.resize(_QTD_BYTES);

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

      MMF::Reader reader(_fileName.c_str());
      const char *map = reader.data();

      blob.is_dense = true;
      memcpy(&blob.data[0], &map[_fileStart.QuadPart], _QTD_BYTES);
      _fileStart.QuadPart = _fileStart.QuadPart + _QTD_BYTES + _HDR_OFFSET;

      if (_fileStart.QuadPart > reader.fileSize()) // - (_QTD_BYTES + 1000))
      {
        return false;
      }

      uint32_t cloudSize = _FRM_POINTS;
      int pointsSize = static_cast<int>(blob.data.size() / (cloudSize));
      for (uint32_t cloudIdx = 0; cloudIdx < cloudSize; ++cloudIdx)
      {
        unsigned int fiedsSize = static_cast<unsigned int>(blob.fields.size());
        for (unsigned int fIndex = 0; fIndex < fiedsSize; ++fIndex)
        {
          uint32_t fieldsCount = blob.fields[fIndex].count;
          for (uint32_t fCount = 0; fCount < fieldsCount; ++fCount)
          {
            switch (blob.fields[fIndex].datatype)
            {
              case pcl::PCLPointField::UINT32:
              {
                blob.is_dense = !isValueFinite<pcl::traits::asType<pcl::PCLPointField::UINT32>::type>
                    (blob, cloudIdx, pointsSize, fIndex, fCount);
                break;
              }
              case pcl::PCLPointField::FLOAT32:
              {
                blob.is_dense = !isValueFinite<pcl::traits::asType<pcl::PCLPointField::FLOAT32>::type>
                    (blob, cloudIdx, pointsSize, fIndex, fCount);
                break;
              }
            }
          }
        }
      }

      pcl::MsgFieldMap fieldMap;

      pcl::detail::FieldMapping fm1;
      fm1.serialized_offset = 0;
      fm1.struct_offset = 0;
      fm1.size = 4;
      fieldMap.push_back(fm1);

      pcl::detail::FieldMapping fm2;
      fm2.serialized_offset = 4;
      fm2.struct_offset = 4;
      fm2.size = 4;
      fieldMap.push_back(fm2);

      pcl::detail::FieldMapping fm3;
      fm3.serialized_offset = 8;
      fm3.struct_offset = 8;
      fm3.size = 4;
      fieldMap.push_back(fm3);

      pcl::detail::FieldMapping fm4;
      fm4.serialized_offset = 12;
      fm4.struct_offset = 16;
      fm4.size = 4;
      fieldMap.push_back(fm4);

      cloud.header   = blob.header;
      cloud.width    = blob.width;
      cloud.height   = blob.height;
      cloud.is_dense = blob.is_dense == 1;

      uint32_t numPoints = blob.width * blob.height;
      cloud.points.resize(numPoints);
      uint8_t* data = reinterpret_cast<uint8_t*>(&cloud.points[0]);

      for (uint32_t row = 0; row < blob.height; ++row)
      {
        const uint8_t* rowData = &blob.data[row * blob.row_step];
        for (uint32_t col = 0; col < blob.width; ++col)
        {
          const uint8_t* bData = rowData + col * blob.point_step;
          for(const pcl::detail::FieldMapping& fm : fieldMap)
          {
            memcpy(data + fm.struct_offset, bData + fm.serialized_offset, fm.size);
          }
          data += sizeof(KinectXYZRGB);
        }
      }
      return true;
    }

    void read()
    {
      int count = 1;

      while(true)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();

        if (!readBinary(*_cloud))
        {
          break;
        }

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
      while(count < 6)
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
