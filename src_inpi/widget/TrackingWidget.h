#ifndef TRACKINGWIDGET_H
#define TRACKINGWIDGET_H

#include <QWidget>
#include "VideoQVTKOpenGLWidget.h"

namespace Ui {
  class TrackingWidget;
}

class TrackingWidget : public QWidget
{
    Q_OBJECT

  public slots:
    void populateCloud(pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud);

  public:
    explicit TrackingWidget(QWidget *parent = 0);
    ~TrackingWidget();

  private:
    Ui::TrackingWidget *ui;
};

#endif // TRACKINGWIDGET_H
