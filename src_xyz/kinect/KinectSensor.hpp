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
#include "Kinect/KinectCloud.hpp"

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
  private:
    IKinectSensor* _sensor;
    ICoordinateMapper* _mapper;
    IMultiSourceFrameReader* _msReader;
    KinectCloud::Ptr _cloud;
    ColorSpacePoint* _colors;
    CameraSpacePoint* _cameras;
    BYTE* _cBuffer;

    long _timeElapsed = 0;
    const long _miliseconds = 33;
    const int _dWidth  = 512;
    const int _dHeight = 424;
    const int _cWidth  = 1920;
    const int _cHeight = 1080;

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

  public slots:
    void run()
    {
      int count = 1;
      while(true)
      {
        auto elapsed = 0;
        auto start = std::chrono::high_resolution_clock::now();
        if (update())
        {
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
            cSize = _cWidth * _cHeight * 4;
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
              if (x < 0 || y < 0 || x > _cWidth || y > _cHeight)
              {
                _cloud->points[dIdx].b = 0;
                _cloud->points[dIdx].g = 0;
                _cloud->points[dIdx].r = 0;
              }
              else
              {
                UINT cIdx = (y * _cWidth + x) * 4;
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