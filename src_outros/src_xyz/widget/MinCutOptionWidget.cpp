#include "MinCutOptionWidget.h".h"
#include "ui_MinCutOptionWidget.h"

MinCutOptionWidget::MinCutOptionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MinCutOptionWidget)
{
    ui->setupUi(this);
}

MinCutOptionWidget::~MinCutOptionWidget()
{
    delete ui;
}

float MinCutOptionWidget::getx()
{
    return ui->spnxCenterPoint->value();
}

float MinCutOptionWidget::gety()
{
    return ui->spnyCenterPoint->value();
}

float MinCutOptionWidget::getz()
{
    return ui->spnzCenterPoint->value();
}

float MinCutOptionWidget::getSigma()
{
    return ui->spnSigma->value();
}

float MinCutOptionWidget::getRadius()
{
    return ui->spnRadius->value();
}

int MinCutOptionWidget::getNrNeighbours()
{
    return ui->spnNrNeighbours->value();
}

float MinCutOptionWidget::getSourceWeight()
{
    return ui->spnSourceWeight->value();
}

bool MinCutOptionWidget::isMinCutEnabled()
{
    return ui->chkEnableMinCut->isChecked();
}