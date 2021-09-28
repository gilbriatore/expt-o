#ifndef CENTROID_H
#define CENTROID_H

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/centroid.h>

using namespace pcl;

class Centroid
{
  public:
    static Eigen::Vector4f get(PointCloud<PointXYZRGBA>::Ptr cloud)
    {
      Eigen::Vector4f centroid;
      compute3DCentroid(*cloud, centroid);
      return centroid;
    }
};

#endif // CENTROID_H
