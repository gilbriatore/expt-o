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

  //Quadrado
  //  pcl::ModelCoefficients coeffs;
  //  coeffs.values.push_back(0.0);
  //  coeffs.values.push_back(0.0);
  //  coeffs.values.push_back(1.0);
  //  coeffs.values.push_back(0.0);
  //  _viewer->addPlane (coeffs, "plane");

  //Circle
  //  int x = 0;
  //  int y = 0;
  //  int radius = 2;
  //  pcl::ModelCoefficients circle_coeff;
  //  circle_coeff.values.resize (3);    // We need 3 values
  //  circle_coeff.values[0] = x;
  //  circle_coeff.values[1] = y;
  //  circle_coeff.values[2] = radius;

  //  _viewer->addCircle(circle_coeff, "circle");

  //  int p1 = 10;
  //  int p2 = -10;
  //  pcl::ModelCoefficients line_coeff;
  //  line_coeff.values.resize(2);    // We need 7 values
  //  line_coeff.values[0] = p1;
  //  line_coeff.values[1] = p2;
  //  _viewer->addLine(line_coeff);


  //  pcl::ModelCoefficients cylinder_coeff;
  //  cylinder_coeff.values.resize (7);    // We need 7 values
  //  cylinder_coeff.values[0] = pt_on_axis.x ();
  //  cylinder_coeff.values[1] = pt_on_axis.y ();
  //  cylinder_coeff.values[2] = pt_on_axis.z ();
  //  cylinder_coeff.values[3] = axis_direction.x ();
  //  cylinder_coeff.values[4] = axis_direction.y ();
  //  cylinder_coeff.values[5] = axis_direction.z ();
  //  cylinder_coeff.values[6] = radius;
  //  addCylinder (cylinder_coeff);


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
