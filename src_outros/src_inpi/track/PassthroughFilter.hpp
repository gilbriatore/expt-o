#ifndef PASSTHROUGHFILTER_H
#define PASSTHROUGHFILTER_H

#include "kinect/KinectCloud.hpp"
#include <pcl/filters/passthrough.h>


class PassthroughFilter
{
  public:
    // Filter out all points with X values not in the range using min/max.
    static KinectCloud::Ptr x(KinectCloud::Ptr cloud, float xLeftCm, float xRightCm)
    {
      KinectCloud::Ptr filteredCloud(new KinectCloud);
      pcl::PassThrough<KinectXYZRGB> filter;
      filter.setInputCloud(cloud);
      filter.setFilterFieldName("x");
      filter.setFilterLimits((xLeftCm * -1) / 100, xRightCm / 100);
      filter.filter(*filteredCloud);
      return filteredCloud;
    }

    // Filter out all points with Y values not in the range using min/max.
    static KinectCloud::Ptr y(KinectCloud::Ptr cloud, float yLeftCm, float yRightCm)
    {
      KinectCloud::Ptr filteredCloud(new KinectCloud);
      pcl::PassThrough<KinectXYZRGB> filter;
      filter.setInputCloud(cloud);
      filter.setFilterFieldName("y");
      filter.setFilterLimits((yLeftCm * -1) / 100, yRightCm / 100);
      filter.filter(*filteredCloud);
      return filteredCloud;
    }

    // Filter out all points with Z values not in the range using min/max.
    static KinectCloud::Ptr z(KinectCloud::Ptr cloud, float zLeftCm, float zRightCm)
    {
      KinectCloud::Ptr filteredCloud(new KinectCloud);
      pcl::PassThrough<KinectXYZRGB> filter;
      filter.setInputCloud(cloud);
      filter.setFilterFieldName("z");
      filter.setFilterLimits((zLeftCm * -1) / 100, zRightCm / 100);
      filter.filter(*filteredCloud);
      return filteredCloud;
    }

    // Filter out all points with XYZ values not in the range using min/max.
    static KinectCloud::Ptr xyz(KinectCloud::Ptr cloud,
                               float xLeftCm, float xRightCm,
                               float yLeftCm, float yRightCm,
                               float zLeftCm, float zRightCm)
    {
      pcl::PassThrough<KinectXYZRGB> fx;
      fx.setFilterFieldName("x");
      fx.setFilterLimits((xLeftCm * -1) / 100, xRightCm / 100);
      fx.setInputCloud(cloud);
      KinectCloud::Ptr x(new KinectCloud);
      fx.filter(*x);

      pcl::PassThrough<KinectXYZRGB> fy;
      fy.setFilterFieldName("y");
      fy.setFilterLimits((yLeftCm * -1) / 100, yRightCm / 100);
      fy.setInputCloud(x);
      KinectCloud::Ptr y(new KinectCloud);
      fy.filter(*y);

      pcl::PassThrough<KinectXYZRGB> fz;
      fz.setFilterFieldName("z");
      fz.setFilterLimits((zLeftCm * -1) / 100, zRightCm / 100);
      fz.setInputCloud(y);
      KinectCloud::Ptr z(new KinectCloud);
      fz.filter(*z);

      return z;
    }
};

#endif // PASSTHROUGHFILTER_H
