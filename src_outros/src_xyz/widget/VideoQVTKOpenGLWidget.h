#ifndef VIDEOQVKTOPENGLWIDGET_H
#define VIDEOQVKTOPENGLWIDGET_H

#include <QWidget>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <QVTKOpenGLWidget.h>
#include <pcl/visualization/pcl_visualizer.h>
#include "kinect/KinectCloud.hpp"

using namespace pcl::visualization;

class VideoQVTKOpenGLWidget : public QVTKOpenGLWidget
{
  public:
    explicit VideoQVTKOpenGLWidget(QWidget *parent = 0);
    void populateCloud(KinectCloud::Ptr cloud);

  private:
    boost::shared_ptr<PCLVisualizer> _viewer;
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> _renderWindow;
};

#endif // VIDEOQVKTOPENGLWIDGET_H