#ifndef CLUSTERINGOPTIONWIDGET_H
#define CLUSTERINGOPTIONWIDGET_H

#include <QWidget>
#include "util/Defines.h"

namespace Ui {
  class ClusteringOptionWidget;
}

class ClusteringOptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClusteringOptionWidget(QWidget *parent = 0);

    bool isClusteringEnabled();

    float getClusterTolerance();
    int getMinClusterSize();
    int getMaxClusterSize();

    bool showUsedKeypoints();

    float getModelSample();
    float getDescriptorRadius();

    ~ClusteringOptionWidget();

private slots:
    void on_chkShowUsedKeypoints_toggled(bool checked);

private:
    Ui::ClusteringOptionWidget *ui;
};

#endif // CLUSTERINGOPTIONWIDGET_H
