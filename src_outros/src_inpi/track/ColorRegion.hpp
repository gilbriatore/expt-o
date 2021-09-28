#ifndef COLORREGION_H
#define COLORREGION_H

#include <vector>
#include <iostream>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/search/search.h>
#include <pcl/search/kdtree.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/filters/passthrough.h>
#include <pcl/features/normal_3d.h>
#include <pcl/segmentation/region_growing_rgb.h>
using namespace pcl;

class ColorRegion
{
  public:
    static PointCloud<PointXYZRGBA>::Ptr run(PointCloud<PointXYZRGBA>::Ptr cloud)
    {
//      pcl::search::Search <pcl::PointXYZRGBA>::Ptr tree =
//          boost::shared_ptr<pcl::search::Search<pcl::PointXYZRGBA>>(new pcl::search::KdTree<pcl::PointXYZRGBA>);

//      pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);
//      pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;
//      normal_estimator.setSearchMethod (tree);
//      normal_estimator.setInputCloud (cloud);
//      normal_estimator.setKSearch(50);
//      normal_estimator.compute (*normals);

//      //      pcl::IndicesPtr indices (new std::vector <int>);
//      //      pcl::PassThrough<pcl::PointXYZRGBA> pass;
//      //      pass.setInputCloud (cloud);
//      //      pass.setFilterFieldName ("z");
//      //      pass.setFilterLimits (0.0, 1.0);
//      //      pass.filter (*indices);

//      pcl::RegionGrowing<pcl::PointXYZRGBA, pcl::Normal> reg;
//      reg.setInputCloud (cloud);
//      //reg.setIndices (indices);
//      reg.setInputNormals (normals);
//      reg.setSearchMethod (tree);
//      reg.setDistanceThreshold (10);
//      reg.setPointColorThreshold (6);
//      reg.setRegionColorThreshold (5);
//      reg.setMinClusterSize (600);

//      std::vector<pcl::PointIndices>clusters;
//      reg.extract(clusters);

//      return reg.getColoredCloud();
      return cloud;
    }
};


#endif // COLORREGION_H
