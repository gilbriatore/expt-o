#ifndef DOWNSAMPLING_H
#define DOWNSAMPLING_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

using namespace pcl;

class Resampling
{
  public:


    static PointCloud<PointXYZRGBA>::Ptr up(PointCloud<PointXYZRGBA>::Ptr cloud, double radius = 0.03)
    {
      PointCloud<PointXYZRGBA>::Ptr filtered(new PointCloud<PointXYZRGBA>);
      //      pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
      //      sor.setInputCloud (cloud);
      //      sor.setLeafSize (0.01f, 0.01f, 0.01f);
      //      sor.filter (*filtered);
      return filtered;
    }


    static PointCloud<PointXYZRGBA>::Ptr down(PointCloud<PointXYZRGBA>::Ptr cloud, float size = 0.01)
    {
      PointCloud<PointXYZRGBA>::Ptr cloud_filtered(new PointCloud<PointXYZRGBA>);
      pcl::VoxelGrid<pcl::PointXYZRGBA> sor;
      sor.setInputCloud(cloud);
      sor.setLeafSize (size, size, size);
      sor.filter (*cloud_filtered);

      return cloud_filtered;
    }
};


#endif // DOWNSAMPLING_H