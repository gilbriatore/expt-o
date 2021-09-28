#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTimer>
#include <DirectXMath.h>

#pragma warning(push)
#pragma warning(disable:6255)
#pragma warning(disable:6263)
#pragma warning(disable:4995)
#include "ppl.h"
#pragma warning(pop)

using namespace DirectX;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitializeDefaultSensor();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(atualizarFrame()));
    timer->start(33);

    m_pInfraredRGBX = new RGBQUAD[cInfraredWidth * cInfraredHeight];
    m_pDepthRGBX = new RGBQUAD[cDepthWidth * cDepthHeight];
    m_pColorRGBX = new RGBQUAD[cColorWidth * cColorHeight];
    m_pOutputRGBX = new RGBQUAD[cColorWidth * cColorHeight];

    colorBuffer.resize(cColorWidth * cColorHeight * colorBytesPerPixel);
    depthBuffer.resize(cDepthWidth * cDepthHeight);

    //m_pDepthCoordinates = new DepthSpacePoint[cColorWidth * cColorHeight];
}

MainWindow::~MainWindow()
{
   delete ui;

    if (m_pOutputRGBX)
    {
        delete [] m_pOutputRGBX;
        m_pOutputRGBX = NULL;
    }

//    if (m_pDepthCoordinates)
//    {
//        delete[] m_pDepthCoordinates;
//        m_pDepthCoordinates = NULL;
//    }

   if (m_pInfraredRGBX)
   {
       delete [] m_pInfraredRGBX;
       m_pInfraredRGBX = NULL;
   }

   if (m_pColorRGBX)
   {
       delete [] m_pColorRGBX;
       m_pColorRGBX = NULL;
   }

   if (m_pDepthRGBX)
   {
       delete [] m_pDepthRGBX;
       m_pDepthRGBX = NULL;
   }

   // done with frame reader
   SafeRelease(m_pMultiSourceFrameReader);
   //SafeRelease(m_pInfraredFrameReader);
   //SafeRelease(m_pColorFrameReader);
   //SafeRelease(m_pDepthFrameReader);
   SafeRelease(m_pCoordinateMapper);

   if (m_pKinectSensor)
   {
       m_pKinectSensor->Close();
   }

   SafeRelease(m_pKinectSensor);
}

HRESULT MainWindow::InitializeDefaultSensor(){

    HRESULT hr;

    hr = GetDefaultKinectSensor(&m_pKinectSensor);
    if (FAILED(hr))
    {
        return hr;
    }

    if (m_pKinectSensor)
    {
        // Initialize the Kinect and get coordinate mapper and the frame reader

        if (SUCCEEDED(hr))
        {
            hr = m_pKinectSensor->get_CoordinateMapper(&m_pCoordinateMapper);
        }

        hr = m_pKinectSensor->Open();

        if (SUCCEEDED(hr))
        {
            hr = m_pKinectSensor->OpenMultiSourceFrameReader(
                FrameSourceTypes::FrameSourceTypes_Depth |
                FrameSourceTypes::FrameSourceTypes_Color |
                FrameSourceTypes::FrameSourceTypes_Infrared,
                &m_pMultiSourceFrameReader);
        }
    }

    if (!m_pKinectSensor || FAILED(hr))
    {
        //SetStatusMessage(L"No ready Kinect found!", 10000, true);
        return E_FAIL;
    }

    return hr;
}

void MainWindow::atualizarFrame()
{
    if (!m_pMultiSourceFrameReader)
    {
        return;
    }

    IMultiSourceFrame* pMultiSourceFrame = NULL;
    IDepthFrame* pDepthFrame = NULL;
    IColorFrame* pColorFrame = NULL;
    IInfraredFrame* pInfraredFrame = NULL;

    HRESULT hr = m_pMultiSourceFrameReader->AcquireLatestFrame(&pMultiSourceFrame);

    if (SUCCEEDED(hr))
    {
        IColorFrameReference* pColorFrameReference = NULL;

        hr = pMultiSourceFrame->get_ColorFrameReference(&pColorFrameReference);
        if (SUCCEEDED(hr))
        {
            hr = pColorFrameReference->AcquireFrame(&pColorFrame);
        }

        SafeRelease(pColorFrameReference);
    }

    if (SUCCEEDED(hr))
    {
        IInfraredFrameReference* pInfraredFrameReference = NULL;

        hr = pMultiSourceFrame->get_InfraredFrameReference(&pInfraredFrameReference);
        if (SUCCEEDED(hr))
        {
            hr = pInfraredFrameReference->AcquireFrame(&pInfraredFrame);
        }

        SafeRelease(pInfraredFrameReference);
    }

    if (SUCCEEDED(hr))
    {
        IDepthFrameReference* pDepthFrameReference = NULL;

        hr = pMultiSourceFrame->get_DepthFrameReference(&pDepthFrameReference);
        if (SUCCEEDED(hr))
        {
            hr = pDepthFrameReference->AcquireFrame(&pDepthFrame);
        }

        SafeRelease(pDepthFrameReference);
    }

    if (SUCCEEDED(hr))
    {

        // get infrared frame data
        INT64 nInfraredTime = 0;
        IFrameDescription* pInfraredFrameDescription = NULL;
        int nInfraredWidth = 0;
        int nInfraredHeight = 0;
        UINT nInfraredBufferSize = 0;
        UINT16 *pInfraredBuffer = NULL;

        hr = pInfraredFrame->get_RelativeTime(&nInfraredTime);

        if (SUCCEEDED(hr))
        {
            hr = pInfraredFrame->get_FrameDescription(&pInfraredFrameDescription);
        }

        if (SUCCEEDED(hr))
        {
            hr = pInfraredFrameDescription->get_Width(&nInfraredWidth);
        }

        if (SUCCEEDED(hr))
        {
            hr = pInfraredFrameDescription->get_Height(&nInfraredHeight);
        }

        if (SUCCEEDED(hr))
        {
            hr = pInfraredFrame->AccessUnderlyingBuffer(&nInfraredBufferSize, &pInfraredBuffer);
        }

        // get depth frame data
        INT64 nDepthTime = 0;
        IFrameDescription* pDepthFrameDescription = NULL;
        int nDepthWidth = 0;
        int nDepthHeight = 0;
        UINT nDepthBufferSize = 0;
        UINT16 *pDepthBuffer = NULL;
        USHORT nDepthMinReliableDistance = 0;
        USHORT nDepthMaxDistance = 0;

        hr = pDepthFrame->get_RelativeTime(&nDepthTime);

        if (SUCCEEDED(hr))
        {
            hr = pDepthFrame->get_FrameDescription(&pDepthFrameDescription);
        }

        if (SUCCEEDED(hr))
        {
            hr = pDepthFrameDescription->get_Width(&nDepthWidth);
        }

        if (SUCCEEDED(hr))
        {
            hr = pDepthFrameDescription->get_Height(&nDepthHeight);
        }

        if (SUCCEEDED(hr))
        {
            hr = pDepthFrame->get_DepthMinReliableDistance(&nDepthMinReliableDistance);
        }

        if (SUCCEEDED(hr))
        {
            //hr = pDepthFrameDescription->get_BytesPerPixel(&depthBytesPerPixel); // 2
        }

        if (SUCCEEDED(hr))
        {
            // In order to see the full range of depth (including the less reliable far field depth)
            // we are setting nDepthMaxDistance to the extreme potential depth threshold
            nDepthMaxDistance = USHRT_MAX;

            // Note:  If you wish to filter by reliable depth distance, uncomment the following line.
            //// hr = pDepthFrame->get_DepthMaxReliableDistance(&nDepthMaxDistance);
        }

        if (SUCCEEDED(hr))
        {
            //hr = pDepthFrame->AccessUnderlyingBuffer(&nDepthBufferSize, &pDepthBuffer);
            hr = pDepthFrame->CopyFrameDataToArray(static_cast<UINT>(depthBuffer.size()), &depthBuffer[0]);
        }


        // get color frame data
        INT64 nColorTime = 0;
        IFrameDescription* pColorFrameDescription = NULL;
        int nColorWidth = 0;
        int nColorHeight = 0;
        ColorImageFormat imageFormat = ColorImageFormat_None;
        UINT nColorBufferSize = 0;
        RGBQUAD *pColorBuffer = NULL;

         hr = pColorFrame->get_RelativeTime(&nColorTime);

        if (SUCCEEDED(hr))
        {
            hr = pColorFrame->get_FrameDescription(&pColorFrameDescription);
        }

        if (SUCCEEDED(hr))
        {
            hr = pColorFrameDescription->get_Width(&nColorWidth);
        }

        if (SUCCEEDED(hr))
        {
            hr = pColorFrameDescription->get_Height(&nColorHeight);
        }

        if (SUCCEEDED(hr))
        {
            hr = pColorFrame->get_RawColorImageFormat(&imageFormat);
        }

        if (SUCCEEDED(hr))
        {
           // hr = pColorFrameDescription->get_BytesPerPixel(&colorBytesPerPixel); // 4
        }

        if (SUCCEEDED(hr))
        {
            if (imageFormat == ColorImageFormat_Bgra)
            {
                hr = pColorFrame->AccessRawUnderlyingBuffer(&nColorBufferSize, reinterpret_cast<BYTE**>(&pColorBuffer));
            }
            else if (m_pColorRGBX)
            //else if (colorBuffer)
            {

                //pColorBuffer = m_pColorRGBX;
                //nColorBufferSize = cColorWidth * cColorHeight * sizeof(RGBQUAD);
                //hr = pColorFrame->CopyConvertedFrameDataToArray(nColorBufferSize, reinterpret_cast<BYTE*>(pColorBuffer), ColorImageFormat_Bgra);
                hr = pColorFrame->CopyConvertedFrameDataToArray(static_cast<UINT>(colorBuffer.size()), &colorBuffer[0], ColorImageFormat::ColorImageFormat_Bgra);
            }
            else
            {
                hr = E_FAIL;
            }
        }

        ui->lblCor->setPixmap(QPixmap::fromImage(QImage((uchar*)&colorBuffer, cDepthWidth,
                                cDepthHeight, QImage::Format_RGB32)).scaledToWidth(400));

//        ui->lblCor->setPixmap(QPixmap::fromImage(QImage((uchar*)colorBuffer, cDepthWidth,
//                                cDepthHeight, QImage::Format_RGB32)).scaledToWidth(400));

        //std::vector<RGBQUAD> depthBuffer(nDepthWidth * nDepthHeight);
        //std::vector<ColorSpacePoint> colorSpacePoints(nDepthWidth * nDepthHeight);
        //m_pCoordinateMapper->MapDepthFrameToColorSpace(nDepthBufferSize, pDepthBuffer,
        //        colorSpacePoints.size(), &colorSpacePoints[0]);

        //cColorWidth * cColorHeight * sizeof(RGBQUAD)

        // Mapped Color Buffer
        //m_pOutputRGBX[nDepthWidth * nDepthHeight * colorBytesPerPixel];
        //m_pOutputRGBX = new RGBQUAD[cColorWidth * cColorHeight * colorBytesPerPixel];


        //RGBQUAD *pDephColorBuffer = m_pColorRGBX;
//        RGBQUAD *pDephColorBuffer = m_pOutputRGBX;

//        cColorWidth = cColorWidth /2;
//        cColorHeight = cColorHeight /2;

//        unsigned int width = cColorWidth;
//        unsigned int height = cColorHeight;
//        RGBQUAD* rawPixels = pColorBuffer;

//        Concurrency::parallel_for(0u, height, [&](unsigned int y)
//        {
//            unsigned int index = y * width;
//            unsigned int mirrorIndex = index + width - 1;

//            for (unsigned int x = 0; x < (width / 2); ++x, ++index, --mirrorIndex)
//            {
//                // In-place swap to mirror
//                RGBQUAD temp = rawPixels[index];
//                rawPixels[index] = rawPixels[mirrorIndex];
//                rawPixels[mirrorIndex] = temp;
//            }
//        });

//        ProcessColor(nColorTime, pColorBuffer, cColorWidth, cColorHeight);

//        for(int y = 0; y < cColorHeight; y++)
//        {
//            for(int x = 0; x < cColorWidth; x++)
//            {
//                int index = y + x;
//                pDephColorBuffer[index] = m_pColorRGBX[index];
////                RGBQUAD color = m_pColorRGBX[index];

////                //pDephColorBuffer[index] =  pColorBuffer[index];
////                pDephColorBuffer[index].rgbBlue     =  color.rgbBlue;
////                pDephColorBuffer[index].rgbGreen    =  color.rgbGreen;
////                pDephColorBuffer[index].rgbRed      =  color.rgbRed;
////                pDephColorBuffer[index].rgbReserved =  color.rgbReserved;
//            }
//        }

//        ProcessColor(nColorTime, pDephColorBuffer, cColorWidth, cColorHeight);



//        int cx1 = 0;
//        int cx2 = 512;

//        int cy1 = 0;
//        int cy2 = 424;

        //for(int x = cx1; x < cx2; x++)
//        for(int depthY = 0; depthY < nDepthHeight; depthY++)
//        {
//            const unsigned int depthOffset = depthY * nDepthWidth;

//            //for(int y = cy1; y < cy2; y++)
//            for(int depthX = 0; depthX < nDepthWidth; depthX++)
//            {
//                //int depthIndex = (x + y) * colorBytesPerPixel;
//                //int colorIndex = (y * 1920) + x;
//                // Modify data

//                unsigned int depthIndex = depthOffset + depthX;

//                //const int colorX = static_cast<int>(colorSpacePoints[depthIndex].X + 0.5f);
//                //const int colorY = static_cast<int>(colorSpacePoints[depthIndex].Y + 0.5f);

//                //if((0 <= colorX) && (colorX < cColorWidth) && (0 <= colorY) && (colorY < cColorHeight)){

//                //    unsigned int colorIndex = ((colorY * cColorWidth) + colorX) * colorBytesPerPixel;
//                    unsigned int colorIndex = (depthIndex * colorBytesPerPixel) * -1;

//                    m_pOutputRGBX[depthIndex + 0].rgbBlue     =  pColorBuffer[colorIndex + 0].rgbBlue;
//                    m_pOutputRGBX[depthIndex + 1].rgbGreen    =  pColorBuffer[colorIndex + 1].rgbGreen;
//                    m_pOutputRGBX[depthIndex + 2].rgbRed      =  pColorBuffer[colorIndex + 2].rgbRed;
//                    m_pOutputRGBX[depthIndex + 3].rgbReserved =  pColorBuffer[colorIndex + 3].rgbReserved;
//                //}
//            }
//        }

        //cColorWidth * cColorHeight

        // Mapping Color Data to Depth Resolution
//        Concurrency::parallel_for(0, nDepthHeight, [&](const int depthY){

//            const unsigned int depthOffset = depthY * nDepthWidth;
//            for(int depthX = 0; depthX < nDepthWidth; depthX++){

//                unsigned int depthIndex = depthOffset + depthX;

//                const int colorX = static_cast<int>(colorSpacePoints[depthIndex].X + 0.5f);
//                const int colorY = static_cast<int>(colorSpacePoints[depthIndex].Y + 0.5f);

//                if((0 <= colorX) && (colorX < cColorWidth) && (0 <= colorY) && (colorY < cColorHeight)){

//                    const unsigned int colorIndex = (colorY * cColorWidth + colorX) * colorBytesPerPixel;

////                    RGBQUAD color = colorBuffer[colorY * colorWidth + colorX];
////                    point.b = color.rgbBlue;
////                    point.g = color.rgbGreen;
////                    point.r = color.rgbRed;

//                    depthIndex = depthIndex * colorBytesPerPixel;

//                    m_pOutputRGBX[depthIndex + 0].rgbBlue     = pColorBuffer[colorIndex + 0].rgbBlue;
//                    m_pOutputRGBX[depthIndex + 1].rgbGreen    = pColorBuffer[colorIndex + 1].rgbGreen;
//                    m_pOutputRGBX[depthIndex + 2].rgbRed      = pColorBuffer[colorIndex + 2].rgbRed;
//                    m_pOutputRGBX[depthIndex + 3].rgbReserved = pColorBuffer[colorIndex + 3].rgbReserved;


//                    //m_pOutputRGBX[depthIndex] = pColorBuffer[colorIndex];

////                    m_pOutputRGBX[depthIndex + 0] = pColorBuffer[colorIndex + 0];
////                    m_pOutputRGBX[depthIndex + 1] = pColorBuffer[colorIndex + 1];
////                    m_pOutputRGBX[depthIndex + 2] = pColorBuffer[colorIndex + 2];
////                    m_pOutputRGBX[depthIndex + 3] = pColorBuffer[colorIndex + 3];
//                }
//            }
//        });

        // process frames
        //ProcessColor(nColorTime, pColorBuffer, nColorWidth, nColorHeight);
        //ProcessColorCropped(nColorTime, m_pOutputRGBX, nDepthWidth, nDepthHeight);
        //ProcessColor(nColorTime, pDephColorBuffer, nColorWidth, nColorHeight);
        ProcessInfrared(nInfraredTime, pInfraredBuffer, nInfraredWidth, nInfraredHeight);
        //ProcessDepth(nDepthTime, pDepthBuffer, nDepthWidth, nDepthHeight, nDepthMinReliableDistance, nDepthMaxDistance);
//        ProcessFrame(nDepthTime, pDepthBuffer, nDepthWidth, nDepthHeight,
//            pColorBuffer, nColorWidth, nColorHeight,
//            pInfraredBuffer, nInfraredWidth, nInfraredHeight);

        SafeRelease(pDepthFrameDescription);
        SafeRelease(pColorFrameDescription);
        SafeRelease(pInfraredFrameDescription);
    }

    SafeRelease(pDepthFrame);
    SafeRelease(pColorFrame);
    SafeRelease(pInfraredFrame);
    SafeRelease(pMultiSourceFrame);
}

/*
   Kinect Coordinate System

   The Kinect uses a cartesian coordinate system centered at the Kinect's IR sensor.
   The positive Y axis points up, the positive Z axis points where the Kinect is pointing,
   and the positive X axis is to the left. One unit in this coordinate system is equal to one meter.

   Using the Coordinate Mapper Interface

   We are dealing with three different coordinate spaces in this program.
   The 3D (XYZ) space, where the point cloud coordinates are in, is used for display.
   The 2D (column, row) space of pixel coordinates in the 1920*1080 color image.
   The 2D (column, row) space of pixel coordinates in the 512*424 depth image.
*/

void MainWindow::ProcessInfrared(INT64 nTime, const UINT16* pBuffer, int nWidth, int nHeight)
{
    if (m_pInfraredRGBX && pBuffer && (nWidth == cInfraredWidth) && (nHeight == cInfraredHeight))
    {
        RGBQUAD* pDest = m_pInfraredRGBX;

        // end pixel is start + width*height - 1
        const UINT16* pBufferEnd = pBuffer + (nWidth * nHeight);

        while (pBuffer < pBufferEnd)
        {
            // normalize the incoming infrared data (ushort) to a float ranging from
            // [InfraredOutputValueMinimum, InfraredOutputValueMaximum] by
            // 1. dividing the incoming value by the source maximum value
            float intensityRatio = static_cast<float>(*pBuffer) / InfraredSourceValueMaximum;

            // 2. dividing by the (average scene value * standard deviations)
            intensityRatio /= InfraredSceneValueAverage * InfraredSceneStandardDeviations;

            // 3. limiting the value to InfraredOutputValueMaximum
            intensityRatio = min(InfraredOutputValueMaximum, intensityRatio);

            // 4. limiting the lower value InfraredOutputValueMinimym
            intensityRatio = max(InfraredOutputValueMinimum, intensityRatio);

            // 5. converting the normalized value to a byte and using the result
            // as the RGB components required by the image
            byte intensity = static_cast<byte>(intensityRatio * 255.0f);
            pDest->rgbRed = intensity;
            pDest->rgbGreen = intensity;
            pDest->rgbBlue = intensity;

            ++pDest;
            ++pBuffer;
        }

        unsigned int width = nWidth;
        unsigned int height = nHeight;
        RGBQUAD* rawPixels = m_pInfraredRGBX;

        Concurrency::parallel_for(0u, height, [&](unsigned int y)
        {
            unsigned int index = y * width;
            unsigned int mirrorIndex = index + width - 1;

            for (unsigned int x = 0; x < (width / 2); ++x, ++index, --mirrorIndex)
            {
                // In-place swap to mirror
                RGBQUAD pixel = rawPixels[index];
                rawPixels[index] = rawPixels[mirrorIndex];
                rawPixels[mirrorIndex] = pixel;
            }
        });

        ui->lblIR->setPixmap(QPixmap::fromImage(QImage((uchar*)m_pInfraredRGBX, cInfraredWidth,
                                cInfraredHeight, QImage::Format_RGB32)).scaledToWidth(250));
    }
}

void MainWindow::ProcessColor(INT64 nTime, RGBQUAD* pBuffer, int nWidth, int nHeight)
{
    if (pBuffer && (nWidth == cColorWidth) && (nHeight == cColorHeight))
    {
        unsigned int width = nWidth;
        unsigned int height = nHeight;
        RGBQUAD* rawPixels = pBuffer;

        Concurrency::parallel_for(0u, height, [&](unsigned int y)
        {
            unsigned int index = y * width;
            unsigned int mirrorIndex = index + width - 1;

            for (unsigned int x = 0; x < (width / 2); ++x, ++index, --mirrorIndex)
            {
                // In-place swap to mirror
                RGBQUAD pixel = rawPixels[index];
                rawPixels[index] = rawPixels[mirrorIndex];
                rawPixels[mirrorIndex] = pixel;
            }
        });

        ui->lblCor->setPixmap(QPixmap::fromImage(QImage((uchar*)pBuffer, cColorWidth,
                                cColorHeight, QImage::Format_RGB32)).scaledToWidth(400));
    }
}

void MainWindow::ProcessColorCropped(INT64 nTime, RGBQUAD* pBuffer, int nWidth, int nHeight)
{
    //cDepthWidth * cDepthHeight
    if (pBuffer && (nWidth == cDepthWidth) && (nHeight == cDepthHeight))
    {
        unsigned int width = nWidth;
        unsigned int height = nHeight;
        RGBQUAD* rawPixels = pBuffer;

        Concurrency::parallel_for(0u, height, [&](unsigned int y)
        {
            unsigned int index = y * width;
            unsigned int mirrorIndex = index + width - 1;

            for (unsigned int x = 0; x < (width / 2); ++x, ++index, --mirrorIndex)
            {
                // In-place swap to mirror
                RGBQUAD pixel = rawPixels[index];
                rawPixels[index] = rawPixels[mirrorIndex];
                rawPixels[mirrorIndex] = pixel;
            }
        });

        ui->lblCor->setPixmap(QPixmap::fromImage(QImage((uchar*)pBuffer, cDepthWidth,
                                cDepthHeight, QImage::Format_RGB32)).scaledToWidth(400));
    }
}

/**

Coordinate System

The each sensors that mounted on Kinect v2 is located on a different physical position.
Therefore, The data that is able to retrieved from them sensors have different coordinate systems.

The basic stream data that retrieve from Kinect v2 has been each following coordinate-systems.
Coordinate System           Stream Data
Color Coordinate System     Color
Depth Coordinate System	    Depth / Infrared / BodyIndex
Camera Coordinate System    Body


A color space point describes a 2D point on the color image.
So a position in color space is a row/column location of a pixel
on the image, where x=0, y=0 is the pixel at the top left of
the color image, and x=1919, y=1079 (width-1, height-1)
corresponds to the bottom right.


*/

byte* _colorData;
byte* _displayPixels;

void MainWindow::alignColor2Depth(const UINT16* pDepthBuffer, const RGBQUAD* pColorBuffer)
{
    HRESULT hr;
//    int numDepthPoints = cDepthWidth * cDepthHeight;

//    // Map from depth to color
//    ColorSpacePoint* _colorPoints[numDepthPoints];
//    hr = m_pCoordinateMapper->MapDepthFrameToColorSpace(numDepthPoints,
//        (UINT16*) pDepthBuffer, numDepthPoints, _colorPoints);

//    for (int i = 0; i < 424 * 512; i++)
//    {
//        ColorSpacePoint p = _colorPoints[i];
//        if (p.X != -std::numeric_limits<float>::infinity() && p.Y != -std::numeric_limits<float>::infinity())
//        {
//            int colorX = static_cast<int>(p.X + 0.5f);
//            int colorY = static_cast<int>(p.Y + 0.5f);

//            if ((colorX >= 0 && colorX < 1920) && (colorY >= 0 && colorY < 1080))
//            {
//                m_pOutputRGBX[i*4]     = pColorBuffer[(colorY * 1920 + colorX)*4];
//                m_pOutputRGBX[i*4 + 1] = pColorBuffer[(colorY * 1920 + colorX) * 4+1];
//                m_pOutputRGBX[i*4 + 2] = pColorBuffer[(colorY * 1920 + colorX) * 4+2];
//                m_pOutputRGBX[i*4 + 3] = pColorBuffer[(colorY * 1920 + colorX) * 4+3];
//            }
//        }
//    }

    // fill up the output matrix with R,G,B values from the current color image
//    if (SUCCEEDED(hr))
//    {
//        for (int y = 0; y < depthHeight; ++y)
//        {
//            for (int x = 0; x < depthWidth; ++x)
//            {
//                int depthIndex = (y * depthWidth) + x;

//                //byte player = _bodyData[depthIndex];

//                // Check whether this pixel belong to a human!!!
//                //if (player != 0xff)
//                //{
//                    ColorSpacePoint colorPoint = _colorPoints[depthIndex];

//                    int colorX = (int)Math.Floor(colorPoint.X + 0.5);
//                    int colorY = (int)Math.Floor(colorPoint.Y + 0.5);

//                    if ((colorX >= 0) && (colorX < colorWidth)
//                    && (colorY >= 0) && (colorY < colorHeight))
//                    {
//                        int colorIndex = ((colorY * colorWidth) + colorX) * BYTES_PER_PIXEL;
//                        int displayIndex = depthIndex * BYTES_PER_PIXEL;

//                        _displayPixels[displayIndex + 0] = _colorData[colorIndex];
//                        _displayPixels[displayIndex + 1] = _colorData[colorIndex + 1];
//                        _displayPixels[displayIndex + 2] = _colorData[colorIndex + 2];
//                        _displayPixels[displayIndex + 3] = 0xff;
//                    }
//                //}
//            }
//        }


//        int colorCoordX, colorCoordY;
//        for (int x=0, k=0; x < cDepthWidth; x++)
//        {
//            for (int y=0; y < cDepthHeight; y++,k++)
//            {
//                int idx = y * cDepthWidth + x;
//                colorCoordX = (UINT16) _colorPoints[idx].X;
//                colorCoordY = (UINT16) _colorPoints[idx].Y;

//                // Sample the RGB components from the color image
//                unsigned char R=0, G=0, B=0;

//                // first make sure the coordinates maps to a valid point in color space
//                int colorX = (int)(floor(colorCoordX + 0.5));
//                int colorY = (int)(floor(colorCoordY + 0.5));

//                if ((colorX >= 0) && (colorX < cColorWidth) && (colorY >= 0) && (colorY < cColorHeight))
//                {
//                    // calculate index into color array
//                    int colorIndex = (colorX + (colorY * cColorWidth)) * 4;

//                   R = m_pColor[colorIndex];
//                   G = m_pColor[colorIndex + 1];
//                   B = m_pColor[colorIndex + 2];
//                }

//                m_pOutputRGBX[k] = R;
//                m_pOutputRGBX[k + numDepthPoints] = G;
//                m_pOutputRGBX[k + numDepthPoints + numDepthPoints] = B;
//            }
//        }
//    }
//    else
//    {

//       // mexPrintf("Depth to Color Mapping error.\n");
//    }
} // end alignColor2Depth

void MainWindow::ProcessDepth(INT64 nTime, const UINT16* pBuffer, int nWidth, int nHeight, USHORT nMinDepth, USHORT nMaxDepth)
{
    if (m_pDepthRGBX && pBuffer && (nWidth == cDepthWidth) && (nHeight == cDepthHeight))
    {

        RGBQUAD* pRGBX = m_pDepthRGBX;
        const UINT16* pBufferEnd = pBuffer + (nWidth * nHeight);

        while (pBuffer < pBufferEnd)
        {
            USHORT depth = *pBuffer;

            // To convert to a byte, we're discarding the most-significant
            // rather than least-significant bits.
            // We're preserving detail, although the intensity will "wrap."
            // Values outside the reliable depth range are mapped to 0 (black).

            // Note: Using conditionals in this loop could degrade performance.
            // Consider using a lookup table instead when writing production code.
            BYTE intensity = static_cast<BYTE>((depth >= nMinDepth) && (depth <= nMaxDepth) ? (depth % 256) : 0);

            pRGBX->rgbRed   = intensity;
            pRGBX->rgbGreen = intensity;
            pRGBX->rgbBlue  = intensity;

            ++pRGBX;
            ++pBuffer;
        }

        unsigned int width = nWidth;
        unsigned int height = nHeight;
        RGBQUAD* rawPixels = m_pDepthRGBX;

        Concurrency::parallel_for(0u, height, [&](unsigned int y)
        {
            unsigned int index = y * width;
            unsigned int mirrorIndex = index + width - 1;

            for (unsigned int x = 0; x < (width / 2); ++x, ++index, --mirrorIndex)
            {
                // In-place swap to mirror
                RGBQUAD pixel = rawPixels[index];
                rawPixels[index] = rawPixels[mirrorIndex];
                rawPixels[mirrorIndex] = pixel;
            }
        });


        ui->lbl3D->setPixmap(QPixmap::fromImage(QImage((uchar*)m_pDepthRGBX, cDepthWidth,
                                cDepthHeight, QImage::Format_RGB32)).scaledToWidth(250));
    }
}
