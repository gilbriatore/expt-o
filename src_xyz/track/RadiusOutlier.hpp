#ifndef RADIUSOUTLIER_H
#define RADIUSOUTLIER_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/radius_outlier_removal.h>

using namespace pcl;
using namespace pcl::io;

class RadiusOutlier
{
  public:
    static PointCloud<PointXYZRGBA>::Ptr filter(PointCloud<PointXYZRGBA>::Ptr cloud, float size = 0.01f)
    {
      PointCloud<PointXYZRGBA>::Ptr filtered(new PointCloud<PointXYZRGBA>);
      pcl::RadiusOutlierRemoval<pcl::PointXYZRGBA> outrem;
      outrem.setInputCloud(cloud);
      outrem.setRadiusSearch(3);
      outrem.setMinNeighborsInRadius(5);
      outrem.filter(*filtered);
      return filtered;
    }
};

#endif // RADIUSOUTLIER_H
