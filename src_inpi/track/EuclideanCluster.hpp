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

#include "kinect/KinectCloud.hpp"

#include "util/Defines.h"

class EuclideanCluster
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


//    //Euclidean Cluster Extraction
//    //http://www.pointclouds.org/documentation/tutorials/cluster_extraction.php#cluster-extraction
//    static std::vector<KinectCloud::Ptr> extract(KinectCloud::Ptr cloud, double tolerance = 0,
//                                    int minCluster = 0, int maxCluster = 0)
//    {
//      KinectCloud::Ptr cloud_f(new KinectCloud());
//      KinectCloud::Ptr cloud_filtered(new KinectCloud());
//      KinectCloud::Ptr cloud_plane(new KinectCloud());

////      // Create the filtering object: downsample the dataset using a leaf size of 1cm
////      pcl::VoxelGrid<KinectXYZRGB> vg;
////      vg.setInputCloud(cloud);
////      vg.setLeafSize(0.01f, 0.01f, 0.01f);
////      vg.filter(*cloud_filtered);
////      //std::cout << "PointCloud after filtering has: " << cloud_filtered->points.size()  << " data points." << std::endl; //*

////      // Create the segmentation object for the planar model and set all the parameters
////      pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
////      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);

////      pcl::SACSegmentation<KinectXYZRGB> seg;
////      seg.setOptimizeCoefficients(true);
////      seg.setModelType(pcl::SACMODEL_PLANE);
////      seg.setMethodType(pcl::SAC_RANSAC);
////      seg.setMaxIterations(100);
////      seg.setDistanceThreshold(0.02);

////      int i=0, nr_points = (int) cloud_filtered->points.size();
////      while (cloud_filtered->points.size() > 0.3 * nr_points)
////      {
////        // Segment the largest planar component from the remaining cloud
////        seg.setInputCloud(cloud_filtered);
////        seg.segment(*inliers, *coefficients);
////        if (inliers->indices.size() == 0)
////        {
////          std::cout << "Could not estimate a planar model for the given dataset." << std::endl;
////          break;
////        }

////        // Extract the planar inliers from the input cloud
////        pcl::ExtractIndices<KinectXYZRGB> extract;
////        extract.setInputCloud(cloud_filtered);
////        extract.setIndices(inliers);
////        extract.setNegative(false);

////        // Get the points associated with the planar surface
////        extract.filter(*cloud_plane);
////        //std::cout << "PointCloud representing the planar component: " << cloud_plane->points.size() << " data points." << std::endl;

////        // Remove the planar inliers, extract the rest
////        extract.setNegative(true);
////        extract.filter(*cloud_f);
////        *cloud_filtered = *cloud_f;
////      }

//      // Creating the KdTree object for the search method of the extraction
//      pcl::search::KdTree<KinectXYZRGB>::Ptr tree(new pcl::search::KdTree<KinectXYZRGB>);
//      tree->setInputCloud(cloud);

//      std::vector<pcl::PointIndices> cluster_indices;
//      pcl::EuclideanClusterExtraction<KinectXYZRGB> ec;
//      ec.setClusterTolerance(0.05); // 2cm
//      ec.setMinClusterSize(200);
//      ec.setMaxClusterSize(250);
//      ec.setSearchMethod(tree);
//      ec.setInputCloud(cloud);
//      ec.extract(cluster_indices);

//      std::vector<KinectCloud::Ptr> clusters;

//      int j = 0;
//      for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it)
//      {
//        KinectCloud::Ptr cloud_cluster(new KinectCloud());
//        for (std::vector<int>::const_iterator pit = it->indices.begin(); pit != it->indices.end(); ++pit)
//        {
//          cloud_cluster->points.push_back(cloud->points[*pit]); //*
//        }
//        cloud_cluster->width = cloud_cluster->points.size();
//        cloud_cluster->height = 1;
//        cloud_cluster->is_dense = true;

//        //std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size () << " data points." << std::endl;

//        clusters.push_back(cloud_cluster);

//        j++;
//      }

//      return clusters;

//      //      for (int i = 0; i < clusters.size(); ++i)
//      //      {
//      //        //int label = rand () % 8;
//      //        int red = (rand() % 255);
//      //        int gre = (rand() % 255);
//      //        int blu = (rand() % 255);

//      //        for (int j = 0; j < clusters[i].indices.size(); ++j)
//      //        {
//      //          PointXYZRGBA point = cloud->points[i * j];
//      //          point.r = red;
//      //          point.g = gre;
//      //          point.b = blu;
//      //          cloudOut->push_back(point);
//      //        }
//      //      }
//      //return cloud;
//    }

    //Euclidean Cluster Extraction
    //http://www.pointclouds.org/documentation/tutorials/cluster_extraction.php#cluster-extraction
    static std::vector<KinectCloud::Ptr> extract(
        KinectCloud::Ptr cloud, double tolerance = 0,
        int minCluster = 0, int maxCluster = 0)
    {
      KinectCloud::Ptr cloud_f(new KinectCloud());
      KinectCloud::Ptr cloud_filtered(new KinectCloud());
      KinectCloud::Ptr cloud_plane(new KinectCloud());

      //JUNTAR TODOS OS CLUSTERS EM CORES DIFERENTES EM UM SÓ.

      // Create the filtering object: downsample the dataset using a leaf size of 1cm
      pcl::VoxelGrid<KinectXYZRGB> vg;
      vg.setInputCloud(cloud);
      vg.setLeafSize(0.01f, 0.01f, 0.01f);
      vg.filter(*cloud_filtered);
      //std::cout << "PointCloud after filtering has: " << cloud_filtered->points.size()  << " data points." << std::endl; //*

      // Create the segmentation object for the planar model and set all the parameters
      pcl::PointIndices::Ptr inliers(new pcl::PointIndices);
      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);

      pcl::SACSegmentation<KinectXYZRGB> seg;
      seg.setOptimizeCoefficients(true);
      seg.setModelType(pcl::SACMODEL_PLANE);
      seg.setMethodType(pcl::SAC_RANSAC);
      seg.setMaxIterations(100);
      seg.setDistanceThreshold(0.02);

      int i=0, nr_points = (int) cloud_filtered->points.size();
      while (cloud_filtered->points.size() > 0.3 * nr_points)
      {
        // Segment the largest planar component from the remaining cloud
        seg.setInputCloud(cloud_filtered);
        seg.segment(*inliers, *coefficients);
        if (inliers->indices.size() == 0)
        {
          std::cout << "Could not estimate a planar model for the given dataset." << std::endl;
          break;
        }

        // Extract the planar inliers from the input cloud
        pcl::ExtractIndices<KinectXYZRGB> extract;
        extract.setInputCloud(cloud_filtered);
        extract.setIndices(inliers);
        extract.setNegative(false);

        // Get the points associated with the planar surface
        extract.filter(*cloud_plane);
        //std::cout << "PointCloud representing the planar component: " << cloud_plane->points.size() << " data points." << std::endl;

        // Remove the planar inliers, extract the rest
        extract.setNegative(true);
        extract.filter(*cloud_f);
        *cloud_filtered = *cloud_f;
      }

      // Creating the KdTree object for the search method of the extraction
      pcl::search::KdTree<KinectXYZRGB>::Ptr tree(new pcl::search::KdTree<KinectXYZRGB>);
      tree->setInputCloud(cloud_filtered);

      std::vector<pcl::PointIndices> cluster_indices;
      pcl::EuclideanClusterExtraction<KinectXYZRGB> ec;
      ec.setClusterTolerance(0.1); // 2cm
      ec.setMinClusterSize(200);
      ec.setMaxClusterSize(250);
      ec.setSearchMethod(tree);
      ec.setInputCloud(cloud_filtered);
      ec.extract(cluster_indices);

      std::vector<KinectCloud::Ptr> clusters;

      int j = 0;
      for (std::vector<pcl::PointIndices>::const_iterator it = cluster_indices.begin (); it != cluster_indices.end (); ++it)
      {
        KinectCloud::Ptr cloud_cluster(new KinectCloud());
        for (std::vector<int>::const_iterator pit = it->indices.begin (); pit != it->indices.end (); ++pit)
        {
          cloud_cluster->points.push_back(cloud_filtered->points[*pit]); //*
        }
        cloud_cluster->width = cloud_cluster->points.size ();
        cloud_cluster->height = 1;
        cloud_cluster->is_dense = true;

        //std::cout << "PointCloud representing the Cluster: " << cloud_cluster->points.size () << " data points." << std::endl;

        clusters.push_back(cloud_cluster);

        j++;
      }

      return clusters;

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
      //return cloud;
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
