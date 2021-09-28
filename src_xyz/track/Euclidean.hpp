#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/segmentation/conditional_euclidean_clustering.h>

#include "util/Defines.h"

using namespace pcl;

class Euclidean
{
  public:
    // Set cluster tolerance to 2cm (small values may cause objects to be divided
    // in several clusters, whereas big values may join objects in a same cluster).
    //    static std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> run(
    //        PointCloud<PointXYZRGBA>::Ptr cloud, double tolerance = 0.02,
    //        int minCluster = 100, int maxCluster = 2500)

    static bool
    customRegionGrowing (const pcl::PointXYZRGBNormal& point_a, const pcl::PointXYZRGBNormal& point_b, float squared_distance)
    {
      //      Eigen::Map<const Eigen::Vector3f> point_a_normal = point_a.normal, point_b_normal = point_b.normal;
      //      if (squared_distance < 10000)
      //      {
      //        if (fabs (point_a.intensity - point_b.intensity) < 8.0f)
      //          return (true);
      //        if (fabs (point_a_normal.dot (point_b_normal)) < 0.06)
      //          return (true);
      //      }
      //      else
      //      {
      //        if (fabs (point_a.intensity - point_b.intensity) < 3.0f)
      //          return (true);
      //      }
      return (false);
    }

    static pcl::PointCloud<pcl::PointXYZRGBA>::Ptr run(
        PointCloud<PointXYZRGBA>::Ptr cloud, double tolerance,
        int minCluster, int maxCluster)
    {
      // kd-tree object for searches.
      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGBA>);
      kdtree->setInputCloud(cloud);

      //Euclidean clustering object.
      pcl::EuclideanClusterExtraction<pcl::PointXYZRGBA> clustering;
      clustering.setClusterTolerance(tolerance);
      clustering.setMinClusterSize(minCluster);
      clustering.setMaxClusterSize(maxCluster);
      clustering.setSearchMethod(kdtree);
      clustering.setInputCloud(cloud);

      std::vector<pcl::PointIndices> clusters;
      //pcl::IndicesClustersPtr clusters(new pcl::IndicesClusters);
      clustering.extract(clusters);

      //pcl::PointCloud<PointXYZRGBA>::Ptr cloudOut(new pcl::PointCloud<PointXYZRGBA>);

      std::cout << "clusters.size() -----> " << clusters.size() << std::endl;



      int j = 0;
      for (std::vector<pcl::PointIndices>::const_iterator it = clusters.begin (); it != clusters.end (); ++it)
      {
        Colore rgb;
        if (j < 7)
        {
          rgb = colores[j];
        }
        else
        {
          rgb = colores[6];
        }
        //        int red = (rand() % 255);
        //        int gre = (rand() % 255);
        //        int blu = (rand() % 255);

        //pcl::PointCloud<pcl::PointXYZRGB>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGB>);
        for (std::vector<int>::const_iterator index = it->indices.begin (); index != it->indices.end (); index++)
        {
          //PointXYZRGBA point = cloud->points[index].r = red;
          //          cloud->points[*index].rgb = rgb;
          cloud->points[*index].r = rgb.red;
          cloud->points[*index].g = rgb.green;
          cloud->points[*index].b = rgb.blue;
          //cluster->points.push_back(cloud->points[*index]);
        }
        //        cluster->width = cluster->points.size();
        //        cluster->height = 1;
        //        cluster->is_dense = true;

        //cloudOut->push_back(cluster);

        j++;
      }

      //      for (int i = 0; i < clusters.size(); ++i)
      //      {
      //        //int label = rand () % 8;
      //        int red = (rand() % 255);
      //        int gre = (rand() % 255);
      //        int blu = (rand() % 255);

      //        for (int j = 0; j < clusters[i].indices.size(); ++j)
      //        {
      //          PointXYZRGBA point = cloud->points[i * j];
      //          point.r = red;
      //          point.g = gre;
      //          point.b = blu;
      //          cloudOut->push_back(point);
      //        }
      //      }
      return cloud;
    }




    //    static std::vector<pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr> run(
    //        PointCloud<PointXYZRGBA>::Ptr cloud, double tolerance,
    //        int minCluster, int maxCluster)

    //    static pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr run(
    //        PointCloud<PointXYZRGBA>::Ptr cloud, double tolerance,
    //        int minCluster, int maxCluster)
    //    {

    //      pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cloudNormals(new pcl::PointCloud<pcl::PointXYZRGBNormal>);

    //      // kd-tree object for searches.
    //      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGBA>);
    //      kdtree->setInputCloud(cloud);

    //      // Euclidean clustering object.
    //      //      pcl::EuclideanClusterExtraction<pcl::PointXYZRGBA> clustering;
    //      //      clustering.setClusterTolerance(tolerance);
    //      //      clustering.setMinClusterSize(minCluster);
    //      //      clustering.setMaxClusterSize(maxCluster);
    //      //      clustering.setSearchMethod(kdtree);
    //      //      clustering.setInputCloud(cloud);
    //      //      std::vector<pcl::PointIndices> clusters;
    //      //      clustering.extract(clusters);

    //      pcl::copyPointCloud(*cloud, *cloudNormals);

    //      // Set up a Normal Estimation class and merge data in cloud_with_normals
    //      pcl::NormalEstimation<pcl::PointXYZRGBA, pcl::PointXYZRGBNormal> ne;
    //      ne.setInputCloud(cloud);
    //      ne.setSearchMethod(kdtree);
    //      ne.setRadiusSearch(300.0);
    //      ne.compute(*cloudNormals);

    //      pcl::ConditionalEuclideanClustering<pcl::PointXYZRGBNormal> clustering(true);
    //      clustering.setClusterTolerance(tolerance);
    //      clustering.setMinClusterSize(minCluster);
    //      clustering.setMaxClusterSize(maxCluster);
    //      //clustering.setSearchMethod(kdtree);
    //      // Set the function that will be called for every pair of points to check.
    //      clustering.setConditionFunction(&customRegionGrowing);
    //      clustering.setInputCloud(cloud);
    //      std::vector<pcl::PointIndices> clusters;
    //      clustering.extract(clusters);

    //      pcl::PointCloud<PointXYZRGBNormal>::Ptr cloudOut(new pcl::PointCloud<PointXYZRGBNormal>);

    //      for (int i = 0; i < clusters->size(); ++i)
    //      {
    //        int label = rand () % 8;
    //        for (int j = 0; j < (*clusters)[i].indices.size(); ++j)
    //        {
    //          cloudOut->points[(*clusters)[i].indices[j]].intensity = label;
    //        }
    //      }

    //      return cloudOut;

    //      //      std::vector<pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr> cloudClustered;
    //      //      int j = 0;
    //      //      for (std::vector<pcl::PointIndices>::const_iterator it = clusters.begin (); it != clusters.end (); ++it)
    //      //      {
    //      //        int label = rand() % 8;
    //      //        pcl::PointCloud<pcl::PointXYZRGBNormal>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGBNormal>);
    //      //        for (std::vector<int>::const_iterator point = it->indices.begin (); point != it->indices.end (); point++)
    //      //        {
    //      //cloud->points[*point];

    //      //          cluster->points.push_back();
    //      //        }
    //      //        cluster->width = cluster->points.size();
    //      //        cluster->height = 1;
    //      //        cluster->is_dense = true;

    //      //        cloudClustered.push_back(cluster);

    //      //        j++;
    //      //      }

    //      //      std::vector<pcl::PointCloud<pcl::PointXYZRGB>::Ptr> cloudClustered;
    //      //      int j = 0;
    //      //      for (std::vector<pcl::PointIndices>::const_iterator it = clusters.begin (); it != clusters.end (); ++it)
    //      //      {
    //      //        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGB>);
    //      //        for (std::vector<int>::const_iterator point = it->indices.begin (); point != it->indices.end (); point++)
    //      //        {
    //      //          cluster->points.push_back (cloud->points[*point]);
    //      //        }
    //      //        cluster->width = cluster->points.size();
    //      //        cluster->height = 1;
    //      //        cluster->is_dense = true;

    //      //        cloudClustered.push_back(cluster);

    //      //        j++;
    //      //      }

    //      //      return cloudClustered;
    //    }
};

#endif // EUCLIDEAN_H
