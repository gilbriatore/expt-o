#ifndef KINECTCLOUD_H
#define KINECTCLOUD_H

#include "Kinect/KinectTypes.hpp"

class KinectCloud : public pcl::PointCloud<KinectXYZRGB>
{
  public:
    KinectCloud(){}
    typedef boost::shared_ptr<KinectCloud> Ptr;
    long timeElapsed;
};

#endif // KINECTCLOUD_H