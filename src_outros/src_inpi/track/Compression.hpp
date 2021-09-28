#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/compression/octree_pointcloud_compression.h>

using namespace pcl;
using namespace pcl::io;

class Compression
{
  public:
    static std::stringstream encode(PointCloud<PointXYZRGBA>::Ptr cloud)
    {
      OctreePointCloudCompression<PointXYZRGBA> enc(MED_RES_ONLINE_COMPRESSION_WITH_COLOR, true);
      std::stringstream compressedData;
      enc.encodePointCloud(cloud, compressedData);
      return compressedData;
    }

    static PointCloud<PointXYZRGBA>::Ptr decode(std::stringstream compressedData)
    {
      OctreePointCloudCompression<PointXYZRGBA> dec(MED_RES_ONLINE_COMPRESSION_WITH_COLOR, true);
      PointCloud<PointXYZRGBA>::Ptr decompressedCloud(new PointCloud<PointXYZRGBA>);
      dec.decodePointCloud(compressedData, decompressedCloud);
      return decompressedCloud;
    }
};


#endif // COMPRESSION_H
