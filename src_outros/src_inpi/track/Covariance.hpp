#ifndef COVARIANCE_HPP
#define COVARIANCE_HPP

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/common/centroid.h>

using namespace pcl;

class Covariance
{
  public:
    static Eigen::Matrix3f get(PointCloud<PointXYZRGBA>::Ptr cloud,
                               Eigen::Vector4f centroid)
    {
      Eigen::Matrix3f covariance;
      computeCovarianceMatrixNormalized(*cloud, centroid, covariance);
      return covariance;
    }
};

#endif // COVARIANCE_HPP
