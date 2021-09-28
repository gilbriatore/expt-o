#include "TrackingWidget.h"
#include "ui_TrackingWidget.h"

TrackingWidget::TrackingWidget(QWidget *parent) :
  QWidget(parent), ui(new Ui::TrackingWidget)
{
  ui->setupUi(this);
}

void TrackingWidget::populateCloud(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud)
{
  //ui->qvtkGLWidget->populateCloud(cloud, );
}

TrackingWidget::~TrackingWidget()
{
  delete ui;
}
