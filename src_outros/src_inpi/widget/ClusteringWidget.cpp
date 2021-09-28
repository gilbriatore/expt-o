#include "ClusteringWidget.h"
#include "ui_ClusteringWidget.h"

ClusteringWidget::ClusteringWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ClusteringWidget)
{
  ui->setupUi(this);
}

void ClusteringWidget::populateCloud(KinectCloud::Ptr cloud)
{
    ui->_displayElapsed->display(QString::number(cloud->timeElapsed));
    ui->qvtkGLWidget->populateCloud(cloud);
}

ClusteringWidget::~ClusteringWidget()
{
  delete ui;
}
