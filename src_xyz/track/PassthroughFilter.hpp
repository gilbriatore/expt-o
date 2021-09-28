#ifndef PASSTHROUGHFILTER_H
#define PASSTHROUGHFILTER_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>

using namespace pcl;
using namespace pcl::io;

class PassthroughFilter
{
  public:
    // Filter out all points with X values not in the range using min/max.
    static PointCloud<PointXYZRGBA>::Ptr x(PointCloud<PointXYZRGBA>::Ptr cloud, float min, float max)
    {
      PointCloud<PointXYZRGBA>::Ptr filteredCloud(new PointCloud<pcl::PointXYZRGBA>);
      PassThrough<PointXYZRGBA> filter;
      filter.setInputCloud(cloud);
      filter.setFilterFieldName("x");
      filter.setFilterLimits(min, max);
      filter.filter(*filteredCloud);
      return filteredCloud;
    }

    // Filter out all points with Y values not in the range using min/max.
    static PointCloud<PointXYZRGBA>::Ptr y(PointCloud<PointXYZRGBA>::Ptr cloud, float min, float max)
    {
      PointCloud<PointXYZRGBA>::Ptr filteredCloud(new PointCloud<pcl::PointXYZRGBA>);
      PassThrough<PointXYZRGBA> filter;
      filter.setInputCloud(cloud);
      filter.setFilterFieldName("y");
      filter.setFilterLimits(min, max);
      filter.filter(*filteredCloud);
      return filteredCloud;
    }

    // Filter out all points with Z values not in the range using min/max.
    static PointCloud<PointXYZRGBA>::Ptr z(PointCloud<PointXYZRGBA>::Ptr cloud, float min, float max)
    {
      PointCloud<PointXYZRGBA>::Ptr filteredCloud(new PointCloud<pcl::PointXYZRGBA>);
      PassThrough<PointXYZRGBA> filter;
      filter.setInputCloud(cloud);
      filter.setFilterFieldName("z");
      filter.setFilterLimits(min, max);
      filter.filter(*filteredCloud);
      return filteredCloud;
    }

    // Filter out all points with XYZ values not in the range using min/max.
    static PointCloud<PointXYZRGBA>::Ptr xyz(PointCloud<PointXYZRGBA>::Ptr cloud,
                                             float xMin, float xMax,
                                             float yMin, float yMax,
                                             float zMin, float zMax)
    {
      PassThrough<PointXYZRGBA> fx;
      fx.setFilterFieldName("x");
      fx.setFilterLimits(xMin, xMax);
      fx.setInputCloud(cloud);
      PointCloud<PointXYZRGBA>::Ptr x(new PointCloud<PointXYZRGBA>);
      fx.filter(*x);

      PassThrough<PointXYZRGBA> fy;
      fy.setFilterFieldName("y");
      fy.setFilterLimits(yMin, yMax);
      fy.setInputCloud(x);
      PointCloud<PointXYZRGBA>::Ptr y(new PointCloud<PointXYZRGBA>);
      fy.filter(*y);

      PassThrough<PointXYZRGBA> fz;
      fz.setFilterFieldName("z");
      fz.setFilterLimits(zMin, zMax);
      fz.setInputCloud(y);
      PointCloud<PointXYZRGBA>::Ptr z(new PointCloud<PointXYZRGBA>);
      fz.filter(*z);

      return z;
    }
};

#endif // PASSTHROUGHFILTER_H
