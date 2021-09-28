#ifndef MINCUTOPTIONWIDGET_H
#define MINCUTOPTIONWIDGET_H

#include <QWidget>
#include "util/Defines.h"

namespace Ui {
class MinCutOptionWidget;
}

class MinCutOptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MinCutOptionWidget(QWidget *parent = 0);
    ~MinCutOptionWidget();

    float getx();
    float gety();
    float getz();

    float getSigma();
    float getRadius();
    int getNrNeighbours();
    float getSourceWeight();

    bool isMinCutEnabled();

private:
    Ui::MinCutOptionWidget *ui;
};

#endif // MINCUTOPTIONWIDGET_H
