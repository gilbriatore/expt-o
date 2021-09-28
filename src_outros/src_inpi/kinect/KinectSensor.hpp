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
#include "util/MMF.hpp"
#include "Kinect/KinectCloud.hpp"
#include "track/PassthroughFilter.hpp"
#include "track/EuclideanCluster.hpp"

#include <pcl/kdtree/kdtree_flann.h>

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

      memcpy(&value, &cloud.data[pointIndex * pointSize + cloud.fields[fieldIdx].offset + fieldsCount * typeSize], typeSize);

      if (!pcl_isfinite(value))
      {
        return false;
      }
      else
      {
        return true;
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
    bool _hasData = true;

    long _timeElapsed = 0;
    const long _miliseconds = 33;
    const int _dWidth  = 512;
    const int _dHeight = 424;
    const int _cWidth  = 1920;
    const int _cHeight = 1080;

    const long _HDR_OFFSET = 185;
    const long _QTD_BYTES = 3473408;
    const long _FRM_POINTS = 217088;
    LARGE_INTEGER _fileWrite = {0};

    const long _limiteWrite = 3900;
    LARGE_INTEGER _fileRead = {0};

    //std::string _fileName = "c:/data/bio_10cmx1.5mSubCopy.pcv";
    //std::string _fileName = "c:/data/bio_10cmx1.75MovElevCopy.pcv";
    //std::string _fileName = "c:/data/bio_10cmx1.75MovSubCopy.pcv";
    //std::string _fileName = "c:/data/bio_10cmx1.75ParElevCopy.pcv";



    std::string _fileName = "c:/data/bio_26cmx1.77_full_mergulho.pcv";

  public slots:
    void run()
    {
      read();
      //write();
      //copy("c:/data/bio_10cmx2mSubCopy.pcv");
    }

  public:

    KinectCloud::Ptr filterDiameter(
        KinectCloud &cloud, KinectXYZRGB point, float radiusCm, float zLimitCm)
    {
      KinectCloud::Ptr filtered(new KinectCloud);
      for(const KinectXYZRGB p : cloud.points)
      {
        if //(p.z > (point.z - (zLimitCm / 100)) && p.z < (point.z + (zLimitCm / 100)) &&  // && p.z > (zLimit * -1)) // &&
        (pow(p.x - point.x, 2) + pow(p.y - point.y, 2) < pow(radiusCm / 100, 2))
        {
          filtered->push_back(p);
        }
      }

      return filtered;

      //      for(int i = 0; i < _cloud->points.size(); i++)
      //      {
      //        if ((_cloud->points[i].x * 100) > radiusCm ||
      //            (_cloud->points[i].x * 100) < (radiusCm * -1) ||
      //            (_cloud->points[i].y * 100) > radiusCm ||
      //            (_cloud->points[i].y * 100) < (radiusCm * -1))
      //        {
      //          _cloud->points[i].r = 0;
      //          _cloud->points[i].g = 0;
      //          _cloud->points[i].b = 0;
      //        }
      //      }



      //(x - center_x)^2 + (y - center_y)^2 < radius^2


      //      pcl::KdTreeFLANN<KinectXYZRGB> kdtree;
      //      kdtree.setInputCloud (_cloud);
      //      KinectXYZRGB searchPoint;
      //      searchPoint.x = 0;
      //      searchPoint.y = 0;
      //      searchPoint.z = 2;

      //      KinectCloud::Ptr filtered(new KinectCloud);
      //      //double rad = 0.100; // search radius
      //      std::vector<int> pointIndicesOut;
      //      std::vector<float> pointRadiusSquaredDistance;
      //      kdtree.radiusSearch(searchPoint, radiusCm, pointIndicesOut, pointRadiusSquaredDistance);
      //      for (size_t i = 0; i < pointIndicesOut.size(); ++i)
      //      {
      //        filtered->push_back(_cloud->points[pointIndicesOut[i]]);
      //      }



      //      pcl::KdTreeFLANN<KinectXYZRGB> kdtree;
      //      kdtree.setInputCloud(_cloud);

      //      KinectXYZRGB searchPoint;
      //      searchPoint.x = 0;
      //      searchPoint.y = 0;
      //      searchPoint.z = 0;

      //      std::vector<int> index; //to store index of surrounding points
      //      std::vector<float> distance; // to store distance to surrounding points

      //      if (kdtree.radiusSearch(searchPoint, radiusCm, index, distance) > 0)
      //      {
      //        for (size_t i = 0; i < index.size(); ++i)
      //        {
      //          std::cout << " " << _cloud->points[index[i]].x
      //                    << " " << _cloud->points[index[i]].y
      //                    << " " << _cloud->points[index[i]].z
      //                    << " (squared distance: " << distance[i] << ")" << std::endl;
      //        }
      //      }


      //      for(int i = 0; i < _cloud->points.size(); i++)
      //      {
      //        if ((_cloud->points[i].x * 100) > radiusCm ||
      //            (_cloud->points[i].x * 100) < (radiusCm * -1) ||
      //            (_cloud->points[i].y * 100) > radiusCm ||
      //            (_cloud->points[i].y * 100) < (radiusCm * -1))
      //        {
      //          _cloud->points[i].r = 0;
      //          _cloud->points[i].g = 0;
      //          _cloud->points[i].b = 0;
      //        }
      //      }
    }

    void read()
    {
      int count = 0;
      while(_hasData)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();

        readBinary(*_cloud);

        //        KinectCloud::Ptr filtered(new KinectCloud);
        //        KinectXYZRGB centroid;
        //        centroid.x = -0.02;
        //        centroid.y = 0.02;
        //        centroid.z = 1.70;
        //        filtered = filterDiameter(*_cloud, centroid, 81, 5);

        //std::vector<KinectCloud::Ptr> clusters = EuclideanCluster::extract(filtered);

        //pcl::removeNaNFromPointCloud(_cloud, _cloud);

        //KinectCloud::Ptr cloud = boost::make_shared<KinectCloud>();
        //cloud = PassthroughFilter::x(_cloud, 10, -10); //, 1, 1, 1, 1);

        //_cloud = PassthroughFilter::x(_cloud, 85, 85); //, 1, 1, 1, 1);
        //_cloud = PassthroughFilter::y(_cloud, 85, 85);
        //_cloud = PassthroughFilter::z(_cloud, 100, 150);

        //_cloud = PassthroughFilter::xyz(_cloud, 85, 85, 85, 85, 0, 200);

        auto time = std::chrono::high_resolution_clock::now() - start;
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
        _timeElapsed += elapsed;


        _cloud->timeElapsed = _timeElapsed / ++count;
        emit send(_cloud);

        //std::cout << "Clusters.size() " << clusters.size() << std::endl;
        //        if (clusters.size() > 0)
        //        {
        //          clusters[0]->timeElapsed = _timeElapsed / ++count;
        //          std::cout << "Clusters.size() " << clusters[0]->points.size() << std::endl;
        //          emit send(clusters[0]);
        //        }

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

    void readBinary(KinectCloud &cloud)
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
      const char *map = reader.getData();

      blob.is_dense = true;
      memcpy(&blob.data[0], &map[_fileRead.QuadPart], _QTD_BYTES);
      _fileRead.QuadPart = _fileRead.QuadPart + _QTD_BYTES;

      if (_fileRead.QuadPart >= reader.fileSize())
      {
        _hasData = false;
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
    }

    void write()
    {
      int count = 0;
      while(count < _limiteWrite)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();

        if (update())
        {
          writeBinary(*_cloud);

          auto time = std::chrono::high_resolution_clock::now() - start;
          elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
          _timeElapsed += elapsed;
          _cloud->timeElapsed = _timeElapsed / ++count;

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
    }

    void writeBinary(KinectCloud &cloud)
    {
      LARGE_INTEGER frameStart;
      frameStart.QuadPart = _fileWrite.QuadPart;
      _fileWrite.QuadPart = _fileWrite.QuadPart + _QTD_BYTES;

      MMF::Writer writer;
      writer.openOrCreate(_fileName.c_str());
      char *map = writer.getMap(0, _fileWrite.QuadPart);
      char *out = &map[frameStart.QuadPart];

      for (size_t i = 0; i < _FRM_POINTS; ++i)
      {
        int offs[4] = {0, 4, 8, 16};
        for (size_t j = 0; j < 4; ++j)
        {
          int offset = offs[j];
          memcpy(out, reinterpret_cast<const char*>(&cloud.points[i]) + offset, 4);
          out += 4;
        }
      }
    }

    void copy(std::string fileName)
    {
      int count = 0;
      while(_hasData)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();

        readBinary(*_cloud);
        copyBinary(fileName, *_cloud);

        auto time = std::chrono::high_resolution_clock::now() - start;
        elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(time).count();
        _timeElapsed += elapsed;
        _cloud->timeElapsed = _timeElapsed / ++count;

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

    void copyBinary(std::string fileName, KinectCloud &cloud)
    {
      LARGE_INTEGER frameStart;
      frameStart.QuadPart = _fileWrite.QuadPart;
      _fileWrite.QuadPart = _fileWrite.QuadPart + _QTD_BYTES;

      MMF::Writer writer;
      writer.openOrCreate(fileName.c_str());
      char *map = writer.getMap(0, _fileWrite.QuadPart);
      char *out = &map[frameStart.QuadPart];

      for (size_t i = 0; i < _FRM_POINTS; ++i)
      {
        int offs[4] = {0, 4, 8, 16};
        for (size_t j = 0; j < 4; ++j)
        {
          int offset = offs[j];
          memcpy(out, reinterpret_cast<const char*>(&cloud.points[i]) + offset, 4);
          out += 4;
        }
      }
    }

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
    }

  signals:
    void send(KinectCloud::Ptr _cloud);
};

#endif // KINECTSENSOR_H
