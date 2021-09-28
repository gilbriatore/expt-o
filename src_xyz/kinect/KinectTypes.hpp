#ifndef KINECTTYPES_H
#define KINECTTYPES_H

#define PCL_NO_PRECOMPILE
#include <Kinect.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

const int _colorBytes = 4;
const int _depthWidth  = 512;
const int _depthHeight = 424;
const int _colorWidth  = 1920;
const int _colorHeight = 1080;
const int _depthSize = _depthWidth * _depthHeight;
const int _colorSize = _colorWidth * _colorHeight;

typedef pcl::PointXYZRGB KinectXYZRGB;

#endif // KINECTTYPES_H