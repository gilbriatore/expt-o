#ifndef REMOVENANS_H
#define REMOVENANS_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/filter.h>

using namespace pcl;

class RemoveNaNs
{
  public:
    static PointCloud<PointXYZRGBA>::Ptr run(PointCloud<PointXYZRGBA>::Ptr cloud)
    {
        std::vector<int> mapping;
        removeNaNFromPointCloud(*cloud, *cloud, mapping);
        return cloud;
    }
};

#endif // REMOVENANS_H
