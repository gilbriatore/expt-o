#ifndef RECONSTRUCTION_H
#define RECONSTRUCTION_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/surface/mls.h>

using namespace pcl;

class Reconstruction
{
  public:
    // Use all neighbors in a radius of 3cm.
    static PointCloud<PointNormal>::Ptr smooth(PointCloud<PointXYZRGBA>::Ptr cloud, double radius = 0.03)
    {
        PointCloud<PointNormal>::Ptr smooth(new PointCloud<PointNormal>);
        MovingLeastSquares<PointXYZRGBA, PointNormal> filter;
        filter.setInputCloud(cloud);
        // Use all neighbors in a radius of 3cm.
        filter.setSearchRadius(radius);
        // If true, the surface and normal are approximated using a polynomial estimation
        // (if false, only a tangent one).
        filter.setPolynomialFit(true);
        // We can tell the algorithm to also compute smoothed normals (optional).
        filter.setComputeNormals(true);
        // kd-tree object for performing searches.
        search::KdTree<PointXYZRGBA>::Ptr kdtree;
        filter.setSearchMethod(kdtree);
        filter.process(*smooth);
        return smooth;
    }
};

#endif // RECONSTRUCTION_H
