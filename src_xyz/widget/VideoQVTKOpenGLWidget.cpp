#include "VideoQVTKOpenGLWidget.h"

#include <vtkPointPicker.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkCamera.h>
#include <vtkAxes.h>
#include <vtkAxesActor.h>

#include <pcl/common/common.h>
#include <pcl/common/transforms.h>

VideoQVTKOpenGLWidget::VideoQVTKOpenGLWidget(QWidget *parent)
  : QVTKOpenGLWidget(parent)
{
  // Create X,Y,Z axes at the origin
  vtkNew<vtkAxes> centerAxes;
  centerAxes->SetOrigin(0, 0, 0);
  centerAxes->SetSymmetric(1);
  centerAxes->SetComputeNormals(0);

  vtkSmartPointer<vtkPolyDataMapper> axesMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  axesMapper->SetInputConnection(centerAxes->GetOutputPort());
  vtkSmartPointer<vtkActor> axesActor = vtkSmartPointer<vtkActor>::New();
  axesActor->SetMapper(axesMapper);
  axesActor->GetProperty()->SetLighting(true);
  axesActor->GetProperty()->SetColor(255,255,255);
  axesActor->PickableOff();
  axesActor->SetScale(10);
  //axesActor->GetProperty()->SetLineWidth(3);

  //vtkSmartPointer<vtkAxesActor> axesActor = vtkSmartPointer<vtkAxesActor>::New();
  //axesActor->SetMapper(axesMapper);
  //axesActor->SetScale(10);
  //axesActor->SetShaftType(1);

  //  // The axes are positioned with a user transform
  //  axes->SetUserTransform(transform);

  //  vtkSmartPointer<vtkProperty> xAxis = vtkSmartPointer<vtkProperty>::New();
  //  xAxis->SetColor(255,255,255);
  //  axes->GetXAxisShaftProperty();
  //  xAxis->SetColor(1.0, 0.0, 0.0);
  // the actual text of the axis label can be changed:

  // properties of the axes labels can be set as follows
  // this sets the x axis label to red
  //axesActor->GetXAxisShaftProperty()->SetColor(0.1,0.1,0.1);
  //axesActor->GetXAxisShaftProperty()->SetColor (255, 255, 255);

  auto camera = vtkSmartPointer<vtkCamera>::New();
  //camera->Zoom(-1.5);
  camera->SetPosition(0,-0.1,-2);
  //camera->Yaw(180);
  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(axesActor);
  //renderer->AddActor(axesActor);
  renderer->SetActiveCamera(camera);
  //renderer->SetBackground(255,255,255);
  _renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
  _renderWindow->AddRenderer(renderer);
  _viewer.reset(new PCLVisualizer(renderer, _renderWindow, "viewer", false));
  //_viewer->addCoordinateSystem(0.1);
  //_viewer->setShowFPS(false);
  this->SetRenderWindow(_viewer->getRenderWindow());
  this->update();
}

void VideoQVTKOpenGLWidget::populateCloud(KinectCloud::Ptr cloud)
{
  if (!cloud)
  {
    std::cerr << "ERROR in input_data_processing.cpp: Input cloud is invalid.\n";
    return;
  }

  if (!cloud->empty())
  {
    if(!_viewer->updatePointCloud(cloud, "cloud"))
    {
      _viewer->addPointCloud(cloud, "cloud");
    }
    _renderWindow->Render();
  }
}