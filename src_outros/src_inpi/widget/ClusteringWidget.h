#ifndef CLUSTERINGWIDGET_H
#define CLUSTERINGWIDGET_H

#include <QWidget>
#include "VideoQVTKOpenGLWidget.h"
#include "kinect/KinectCloud.hpp"

namespace Ui {
  class ClusteringWidget;
}

class ClusteringWidget : public QWidget
{
    Q_OBJECT

  public slots:
    void populateCloud(KinectCloud::Ptr cloud);

  public:
    explicit ClusteringWidget(QWidget *parent = 0);
    ~ClusteringWidget();

  private:
    Ui::ClusteringWidget *ui;
};

#endif // CLUSTERINGWIDGET_H
