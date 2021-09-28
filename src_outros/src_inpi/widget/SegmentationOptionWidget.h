#ifndef SEGMENTATIONOPTIONWIDGET_H
#define SEGMENTATIONOPTIONWIDGET_H

#include <QWidget>

namespace Ui {
   class SegmentationOptionWidget;
}

class SegmentationOptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SegmentationOptionWidget(QWidget *parent = 0);

    bool isSegmentationEnabled();

    bool getOptimizeCoeff();
    int getModelType();
    int getMethodType();
    int getMaxIterations();
    float getDistanceThreshold();

    ~SegmentationOptionWidget();

private:
    Ui::SegmentationOptionWidget *ui;
};

#endif // SEGMENTATIONOPTIONWIDGET_H
