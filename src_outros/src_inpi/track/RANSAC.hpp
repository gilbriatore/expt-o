#ifndef RANSAC_H
#define RANSAC_H

#include <iostream>
#include <csignal>

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <pcl/search/kdtree.h>
#include <pcl/search/pcl_search.h>

#include <pcl/features/normal_3d.h>

#include <pcl/segmentation/region_growing.h>
#include <pcl/segmentation/min_cut_segmentation.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/segmentation/extract_polygonal_prism_data.h>

#include <pcl/common/time.h>
#include <pcl/common/distances.h>

#include <pcl/sample_consensus/ransac.h>
#include <pcl/sample_consensus/sac_model_sphere.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>

#include <pcl/filters/extract_indices.h>
#include <pcl/filters/project_inliers.h>

#include <pcl/surface/concave_hull.h>
#include <pcl/surface/convex_hull.h>

#include <QDebug>

//void signalHandler( int signum ) {
//   std::cout << "Interrupt signal (" << signum << ") received.\n";

//   // cleanup and close up stuff here
//   // terminate program

//   exit(signum);
//}

using namespace pcl;

class RANSAC
{
  public:

    // Set cluster tolerance to 2cm (small values may cause objects to be divided
    // in several clusters, whereas big values may join objects in a same cluster).
//    static std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> run(
//        PointCloud<PointXYZRGBA>::Ptr cloud, double tolerance = 0.02,
//        int minCluster = 100, int maxCluster = 2500)
    static std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> clustering(
        PointCloud<PointXYZRGBA>::Ptr cloud, double tolerance,
        int minCluster, int maxCluster)
    {

      // kd-tree object for searches.
      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGBA>);
      kdtree->setInputCloud(cloud);

      // Euclidean clustering object.
      pcl::EuclideanClusterExtraction<pcl::PointXYZRGBA> clustering;
      clustering.setClusterTolerance(tolerance);
      clustering.setMinClusterSize(minCluster);
      clustering.setMaxClusterSize(maxCluster);
      clustering.setSearchMethod(kdtree);
      clustering.setInputCloud(cloud);
      std::vector<pcl::PointIndices> clusters;
      clustering.extract(clusters);

      std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> cloudClustered;
      int j = 0;
      for (std::vector<pcl::PointIndices>::const_iterator it = clusters.begin (); it != clusters.end (); ++it)
      {
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGBA>);
        for (std::vector<int>::const_iterator point = it->indices.begin (); point != it->indices.end (); point++)
        {
          cluster->points.push_back (cloud->points[*point]);
        }
        cluster->width = cluster->points.size();
        cluster->height = 1;
        cluster->is_dense = true;

        cloudClustered.push_back(cluster);

        j++;
      }

      return cloudClustered;
    }

    // Set the maximum allowed distance to the model.
    static PointCloud<PointXYZRGBA>::Ptr sphere(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      PointCloud<PointXYZRGBA>::Ptr points(new PointCloud<PointXYZRGBA>);
      SampleConsensusModelSphere<PointXYZRGBA>::Ptr model(new SampleConsensusModelSphere<PointXYZRGBA>(cloud));
      RandomSampleConsensus<PointXYZRGBA> ransac(model);
      ransac.setDistanceThreshold(thres);
      ransac.computeModel();
      std::vector<int> inlierIndices;
      ransac.getInliers(inlierIndices);
      copyPointCloud<PointXYZRGBA>(*cloud, inlierIndices, *points);
      return points;
    }

    static PointCloud<PointXYZRGBA>::Ptr euclideanCluster(PointCloud<PointXYZRGBA>::Ptr cloud)
    {


      std::cout << "cloud.size() " << cloud->points.size() << " points." << std::endl;
      //      if (!cloudIn)
      //      {
      //        std::cerr << "ERROR in input_data_processing.cpp: Input cloud is invalid.\n";
      //        return cloudIn;
      //      }

      //      PointCloud<PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
      //      copyPointCloud(*cloudIn, *cloud);

      // kd-tree object for searches.
      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGBA>);
      kdtree->setInputCloud(cloud);

      // Euclidean clustering object.
      pcl::EuclideanClusterExtraction<pcl::PointXYZRGBA> clustering;
      // Set cluster tolerance to 2cm (small values may cause objects to be divided
      // in several clusters, whereas big values may join objects in a same cluster).
      clustering.setClusterTolerance(0.02); //2cm
      // Set the minimum and maximum number of points that a cluster can have.
      clustering.setMinClusterSize(300);
      clustering.setMaxClusterSize(1000);
      clustering.setSearchMethod(kdtree);
      clustering.setInputCloud(cloud);
      std::vector<pcl::PointIndices> clusters;
      clustering.extract(clusters);

      //Vector of objects, one point cloud per object;
      std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> cloudObjects;

      // For every cluster...
      int currentClusterNum = 1;
      for (std::vector<pcl::PointIndices>::const_iterator i = clusters.begin(); i != clusters.end(); ++i)
      {
        // ...add all its points to a new cloud...
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGBA>);
        for (std::vector<int>::const_iterator point = i->indices.begin(); point != i->indices.end(); point++)
        {
          cluster->points.push_back(cloud->points[*point]);
        }
        cluster->width = cluster->points.size();
        cluster->height = 1;
        cluster->is_dense = true;

        cloudObjects.push_back(cluster);
        //          // ...and save it to disk.
        //          if (cluster->points.size() <= 0)
        //            break;
        //          std::cout << "Cluster " << currentClusterNum << " has " << cluster->points.size() << " points." << std::endl;
        //          std::string fileName = "cluster" + boost::to_string(currentClusterNum) + ".pcd";
        //          pcl::io::savePCDFileASCII(fileName, *cluster);

        currentClusterNum++;
      }


      //Vector of objects, one point cloud per object;
      std::vector<pcl::PointCloud<pcl::PointXYZRGBA>::Ptr> objects;

      pcl::EuclideanClusterExtraction<pcl::PointXYZRGBA> euclideanClusters;
      euclideanClusters.setInputCloud(cloud);

      std::vector<pcl::PointIndices> clusterIndices;
      euclideanClusters.extract(clusterIndices);

      pcl::ExtractIndices<pcl::PointXYZRGBA> extractObjects;
      for(int i = 0; i < clusterIndices.size(); ++i)
      {
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr object(new pcl::PointCloud<pcl::PointXYZRGBA>);
        extractObjects.setInputCloud(cloud);
        extractObjects.setIndices(boost::make_shared<const pcl::PointIndices>(clusterIndices[i]));
        extractObjects.filter(*object);
        objects.push_back(object);
      }

      if (objects.size() > 0)
      {
        return objects[0];
      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr concaveHull(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr plane(new pcl::PointCloud<pcl::PointXYZRGBA>);
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr concaveHull(new pcl::PointCloud<pcl::PointXYZRGBA>);

      // Get the plane model, if present.
      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
      pcl::SACSegmentation<pcl::PointXYZRGBA> segmentation;
      segmentation.setInputCloud(cloud);
      segmentation.setModelType(pcl::SACMODEL_PLANE);
      segmentation.setMethodType(pcl::SAC_RANSAC);
      segmentation.setDistanceThreshold(thres);
      segmentation.setOptimizeCoefficients(true);
      pcl::PointIndices::Ptr inlierIndices(new pcl::PointIndices);
      segmentation.segment(*inlierIndices, *coefficients);

      if (inlierIndices->indices.size() != 0)
      {
        // Copy the points of the plane to a new cloud.
        pcl::ExtractIndices<pcl::PointXYZRGBA> extract;
        extract.setInputCloud(cloud);
        extract.setIndices(inlierIndices);
        extract.filter(*plane);

        // Object for retrieving the concave hull.
        pcl::ConcaveHull<pcl::PointXYZRGBA> hull;
        hull.setInputCloud(plane);
        // Set alpha, which is the maximum length from a vertex to the center of the voronoi cell
        // (the smaller, the greater the resolution of the hull).
        hull.setAlpha(0.1);
        hull.reconstruct(*concaveHull);

        return concaveHull;
      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr convexHull(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr plane(new pcl::PointCloud<pcl::PointXYZRGBA>);
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr convexHull(new pcl::PointCloud<pcl::PointXYZRGBA>);

      // Get the plane model, if present.
      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
      pcl::SACSegmentation<pcl::PointXYZRGBA> segmentation;
      segmentation.setInputCloud(cloud);
      segmentation.setModelType(pcl::SACMODEL_PLANE);
      segmentation.setMethodType(pcl::SAC_RANSAC);
      segmentation.setDistanceThreshold(thres);
      segmentation.setOptimizeCoefficients(true);
      pcl::PointIndices::Ptr inlierIndices(new pcl::PointIndices);
      segmentation.segment(*inlierIndices, *coefficients);

      if (inlierIndices->indices.size() != 0)
      {
        // Copy the points of the plane to a new cloud.
        pcl::ExtractIndices<pcl::PointXYZRGBA> extract;
        extract.setInputCloud(cloud);
        extract.setIndices(inlierIndices);
        extract.filter(*plane);

        // Object for retrieving the convex hull.
        pcl::ConvexHull<pcl::PointXYZRGBA> hull;
        hull.setInputCloud(plane);
        hull.reconstruct(*convexHull);

        return convexHull;
      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr cylinder(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr inlierPoints(new pcl::PointCloud<pcl::PointXYZRGBA>);

      // Object for storing the plane model coefficients.
      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
      // Create the segmentation object.
      pcl::SACSegmentation<pcl::PointXYZRGBA> segmentation;
      segmentation.setInputCloud(cloud);
      // Configure the object to look for a plane.
      segmentation.setModelType(pcl::SACMODEL_CYLINDER);
      // Use RANSAC method.
      segmentation.setMethodType(pcl::SAC_RANSAC);
      // Set the maximum allowed distance to the model.
      segmentation.setDistanceThreshold(thres);
      // Enable model coefficient refinement (optional).
      segmentation.setOptimizeCoefficients(true);
      // Set minimum and maximum radii of the cylinder.
      segmentation.setRadiusLimits(0, 0.1);

      pcl::PointIndices inlierIndices;
      segmentation.segment(inlierIndices, *coefficients);

      if (inlierIndices.indices.size() != 0)
      {
        pcl::copyPointCloud<pcl::PointXYZRGBA>(*cloud, inlierIndices, *inlierPoints);
        return inlierPoints;
      }
      return cloud;
    }


    // Points at less than 0.01 = 1cm over the plane.
    static PointCloud<PointXYZRGBA>::Ptr planeObjects(
        PointCloud<PointXYZRGBA>::Ptr cloud, double thresh = 0.01)
    {
      // Coefficients (a,b,c,d) of ax + by + cz +d = 0;
      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);

      // Create the segmentation object.
      pcl::SACSegmentation<pcl::PointXYZRGBA> segmentation;
      segmentation.setInputCloud(cloud);
      // Configure the object to look for a plane.
      segmentation.setModelType(pcl::SACMODEL_PLANE);
      // Use RANSAC method.
      segmentation.setMethodType(pcl::SAC_RANSAC);
      // Set the maximum allowed distance to the model.
      segmentation.setDistanceThreshold(thresh);
      // Enable model coefficient refinement (optional).
      segmentation.setOptimizeCoefficients(true);
      segmentation.setMaxIterations(100);

      // Point indices belonging to the plane;
      pcl::PointIndices inliersIndices;
      segmentation.segment(inliersIndices, *coefficients);

      // Points belonging to objects;
      pcl::PointCloud<pcl::PointXYZRGBA> objects;

      // Project the inliers to the estimated plane;
      pcl::PointCloud<pcl::PointXYZRGBA> projectedPoints;
      pcl::ProjectInliers<pcl::PointXYZRGBA> projectedInliers;
      projectedInliers.setInputCloud(cloud);
      projectedInliers.setIndices(boost::make_shared<const pcl::PointIndices>(inliersIndices));
      projectedInliers.setModelCoefficients(coefficients);
      projectedInliers.filter(projectedPoints);

      // Estimate the convex hull of the projected points;
      pcl::PointCloud<pcl::PointXYZRGBA> hullPoints;
      pcl::ConvexHull<pcl::PointXYZRGBA> convelHull;
      convelHull.setInputCloud(projectedPoints.makeShared());
      convelHull.reconstruct(hullPoints);

      // Determine the points over the plane;
      pcl::PointIndices objectsIndices;
      pcl::ExtractPolygonalPrismData<pcl::PointXYZRGBA> prism;

      // Objects must lie between 1cm and 50cm;
      //prism.setHeightLimits(0.05,0.5);
      prism.setHeightLimits(0.01,0.05);


      // Over the plane;
      prism.setInputCloud(cloud);
      prism.setInputPlanarHull(hullPoints.makeShared());
      prism.segment(objectsIndices);

      // Extract the point cloud corresponding to the extracted indices.
      pcl::ExtractIndices<PointXYZRGBA> extractIndices;
      extractIndices.setInputCloud(cloud);
      extractIndices.setIndices(boost::make_shared<const pcl::PointIndices>(objectsIndices));
      extractIndices.filter(objects);

      return boost::make_shared<pcl::PointCloud<pcl::PointXYZRGBA>>(objects);
    }

    // Points at less than 0.01 = 1cm over the plane.
    static PointCloud<PointXYZRGBA>::Ptr run(PointCloud<PointXYZRGBA>::Ptr cloud,
          bool opt, int  model, int  method, int  max, float distance)
    {
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr inlierPoints(new pcl::PointCloud<pcl::PointXYZRGBA>);

      // Object for storing the plane model coefficients.
      pcl::ModelCoefficients::Ptr coefficients(new pcl::ModelCoefficients);
      // Create the segmentation object.
      pcl::SACSegmentation<pcl::PointXYZRGBA> segmentation;
      segmentation.setInputCloud(cloud);
      // Enable model coefficient refinement (optional).
      segmentation.setOptimizeCoefficients(opt);
      // Configure the object to look for a plane.
      segmentation.setModelType(model);
      // Use RANSAC method.
      segmentation.setMethodType(method);
      segmentation.setMaxIterations(max);
      // Set the maximum allowed distance to the model.
      segmentation.setDistanceThreshold(distance);

      pcl::PointIndices inliersIndices;
      segmentation.segment(inliersIndices, *coefficients);

      if (inliersIndices.indices.size() != 0)
      {
        // Copy all inliers of the model to another cloud.
        pcl::copyPointCloud<pcl::PointXYZRGBA>(*cloud, inliersIndices, *inlierPoints);
        return inlierPoints;
      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr mincut(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      // Min-cut clustering object.
      pcl::MinCutSegmentation<pcl::PointXYZRGBA> clustering;
      clustering.setInputCloud(cloud);
      // Create a cloud that lists all the points that we know belong to the object
      // (foreground points). We should set here the object's center.
      pcl::PointCloud<pcl::PointXYZRGBA>::Ptr foregroundPoints(new pcl::PointCloud<pcl::PointXYZRGBA>());
      pcl::PointXYZRGBA point;
      point.x = 100.0;
      point.y = 100.0;
      point.z = 100.0;
      foregroundPoints->points.push_back(point);
      clustering.setForegroundPoints(foregroundPoints);
      // Set sigma, which affects the smooth cost calculation. It should be
      // set depending on the spacing between points in the cloud (resolution).
      clustering.setSigma(0.05);
      // Set the radius of the object we are looking for.
      clustering.setRadius(0.20);
      // Set the number of neighbors to look for. Increasing this also increases
      // the number of edges the graph will have.
      clustering.setNumberOfNeighbours(20);
      // Set the foreground penalty. It is the weight of the edges
      // that connect clouds points with the source vertex.
      clustering.setSourceWeight(0.6);

      std::vector <pcl::PointIndices> clusters;
      clustering.extract(clusters);

      std::cout << "Maximum flow is " << clustering.getMaxFlow() << "." << std::endl;

      // For every cluster...
      int currentClusterNum = 1;
      for (std::vector<pcl::PointIndices>::const_iterator i = clusters.begin(); i != clusters.end(); ++i)
      {
        // ...add all its points to a new cloud...
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGBA>);
        for (std::vector<int>::const_iterator point = i->indices.begin(); point != i->indices.end(); point++)
          cluster->points.push_back(cloud->points[*point]);
        cluster->width = cluster->points.size();
        cluster->height = 1;
        cluster->is_dense = true;

        currentClusterNum++;
      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr color(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      //      // kd-tree object for searches.
      //      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGBA>);
      //      kdtree->setInputCloud(cloud);

      //      // Color-based region growing clustering object.
      //      pcl::RegionGrowingRGB<pcl::PointXYZRGBA> clustering;
      //      clustering.setInputCloud(cloud);
      //      clustering.setSearchMethod(kdtree);
      //      // Here, the minimum cluster size affects also the postprocessing step:
      //      // clusters smaller than this will be merged with their neighbors.
      //      clustering.setMinClusterSize(100);
      //      // Set the distance threshold, to know which points will be considered neighbors.
      //      clustering.setDistanceThreshold(10);
      //      // Color threshold for comparing the RGB color of two points.
      //      clustering.setPointColorThreshold(6);
      //      // Region color threshold for the postprocessing step: clusters with colors
      //      // within the threshold will be merged in one.
      //      clustering.setRegionColorThreshold(5);

      //      std::vector <pcl::PointIndices> clusters;
      //      clustering.extract(clusters);

      //      // For every cluster...
      //      int currentClusterNum = 1;
      //      for (std::vector<pcl::PointIndices>::const_iterator i = clusters.begin(); i != clusters.end(); ++i)
      //      {
      //        // ...add all its points to a new cloud...
      //        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGBA>);
      //        for (std::vector<int>::const_iterator point = i->indices.begin(); point != i->indices.end(); point++)
      //          cluster->points.push_back(cloud->points[*point]);
      //        cluster->width = cluster->points.size();
      //        cluster->height = 1;
      //        cluster->is_dense = true;
      //        currentClusterNum++;
      //      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr region(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      pcl::PointCloud<pcl::Normal>::Ptr normals(new pcl::PointCloud<pcl::Normal>);
      // kd-tree object for searches.
      pcl::search::KdTree<pcl::PointXYZRGBA>::Ptr kdtree(new pcl::search::KdTree<pcl::PointXYZRGBA>);
      kdtree->setInputCloud(cloud);

      // Estimate the normals.
      pcl::NormalEstimation<pcl::PointXYZRGBA, pcl::Normal> normalEstimation;
      normalEstimation.setInputCloud(cloud);
      normalEstimation.setRadiusSearch(0.03);
      normalEstimation.setSearchMethod(kdtree);
      normalEstimation.compute(*normals);

      // Region growing clustering object.
      pcl::RegionGrowing<pcl::PointXYZRGBA, pcl::Normal> clustering;
      clustering.setMinClusterSize(100);
      clustering.setMaxClusterSize(10000);
      clustering.setSearchMethod(kdtree);
      clustering.setNumberOfNeighbours(30);
      clustering.setInputCloud(cloud);
      clustering.setInputNormals(normals);
      // Set the angle in radians that will be the smoothness threshold
      // (the maximum allowable deviation of the normals).
      clustering.setSmoothnessThreshold(7.0 / 180.0 * M_PI); // 7 degrees.
      // Set the curvature threshold. The disparity between curvatures will be
      // tested after the normal deviation check has passed.
      clustering.setCurvatureThreshold(1.0);

      std::vector <pcl::PointIndices> clusters;
      clustering.extract(clusters);

      // For every cluster...
      int currentClusterNum = 1;
      for (std::vector<pcl::PointIndices>::const_iterator i = clusters.begin(); i != clusters.end(); ++i)
      {
        // ...add all its points to a new cloud...
        pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cluster(new pcl::PointCloud<pcl::PointXYZRGBA>);
        for (std::vector<int>::const_iterator point = i->indices.begin(); point != i->indices.end(); point++)
        {
          cluster->points.push_back(cloud->points[*point]);
        }
        cluster->width = cluster->points.size();
        cluster->height = 1;
        cluster->is_dense = true;

        currentClusterNum++;
      }
      return cloud;
    }

    static PointCloud<PointXYZRGBA>::Ptr project(PointCloud<PointXYZRGBA>::Ptr cloud, double thres = 0.01)
    {
      PointCloud<PointXYZRGBA>::Ptr cloudNoPlane(new PointCloud<PointXYZRGBA>);
      PointCloud<PointXYZRGBA>::Ptr planePoints(new PointCloud<PointXYZRGBA>);
      PointCloud<PointXYZRGBA>::Ptr projectedPoints(new PointCloud<PointXYZRGBA>);

      // Get the plane model, if present.
      ModelCoefficients::Ptr coefficients(new ModelCoefficients);
      SACSegmentation<PointXYZRGBA> segmentation;
      segmentation.setInputCloud(cloud);
      segmentation.setModelType(SACMODEL_PLANE);
      segmentation.setMethodType(SAC_RANSAC);
      segmentation.setDistanceThreshold(thres);
      segmentation.setOptimizeCoefficients(true);
      PointIndices::Ptr inlierIndices(new PointIndices);
      segmentation.segment(*inlierIndices, *coefficients);

      if (inlierIndices->indices.size() != 0)
      {
        // Create a second point cloud that does not have the plane points.
        // Also, extract the plane points to visualize them later.
        ExtractIndices<PointXYZRGBA> extract;
        extract.setInputCloud(cloud);
        extract.setIndices(inlierIndices);
        extract.filter(*planePoints);
        extract.setNegative(true);
        extract.filter(*cloudNoPlane);

        // Object for projecting points onto a model.
        ProjectInliers<PointXYZRGBA> projection;
        // We have to specify what model we used.
        projection.setModelType(SACMODEL_PLANE);
        projection.setInputCloud(cloudNoPlane);
        // And we have to give the coefficients we got.
        projection.setModelCoefficients(coefficients);
        projection.filter(*projectedPoints);

        //return planePoints;
        return projectedPoints;
      }
      return cloud;
    }



};

#endif // RANSAC_H
