#include "SegmentationOptionWidget.h"
#include "ui_SegmentationOptionWidget.h"

SegmentationOptionWidget::SegmentationOptionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SegmentationOptionWidget)
{
    ui->setupUi(this);

    ui->cmbMethodType->addItem("SAC_RANSAC");
    ui->cmbMethodType->addItem("SAC_LMEDS");
    ui->cmbMethodType->addItem("SAC_MSAC");
    ui->cmbMethodType->addItem("SAC_RRANSAC");
    ui->cmbMethodType->addItem("SAC_RMSAC");
    ui->cmbMethodType->addItem("SAC_MLESAC");
    ui->cmbMethodType->addItem("SAC_PROSAC");

    ui->cmbModelType->addItem("SACMODEL_PLANE");
    ui->cmbModelType->addItem("SACMODEL_LINE");
    ui->cmbModelType->addItem("SACMODEL_CIRCLE2D");
    ui->cmbModelType->addItem("SACMODEL_CIRCLE3D");
    ui->cmbModelType->addItem("SACMODEL_SPHERE");
    ui->cmbModelType->addItem("SACMODEL_CYLINDER");
    ui->cmbModelType->addItem("SACMODEL_CONE");
    ui->cmbModelType->addItem("SACMODEL_TORUS");
    ui->cmbModelType->addItem("SACMODEL_PARALLEL_LINE");
    ui->cmbModelType->addItem("SACMODEL_PERPENDICULAR");
    ui->cmbModelType->addItem("SACMODEL_PARALLEL_LINES");
    ui->cmbModelType->addItem("SACMODEL_NORMAL_PLANE");
    ui->cmbModelType->addItem("SACMODEL_NORMAL_SPHERE");
    ui->cmbModelType->addItem("SACMODEL_REGISTRATION");
    ui->cmbModelType->addItem("SACMODEL_REGISTRATION_2D");
    ui->cmbModelType->addItem("SACMODEL_PARALLEL_PLANE");
    ui->cmbModelType->addItem("SACMODEL_NORMAL_PARALLEL");
    ui->cmbModelType->addItem("SACMODEL_STICK");
}

bool SegmentationOptionWidget::isSegmentationEnabled()
{
    return ui->chkEnableSegmentation->isChecked();
}

bool SegmentationOptionWidget::getOptimizeCoeff()
{
    return ui->chkOptimazeCoef->isChecked();
}

int SegmentationOptionWidget::getMethodType()
{
    return ui->cmbMethodType->currentIndex();
}

int SegmentationOptionWidget::getModelType()
{
    return ui->cmbModelType->currentIndex();
}

int SegmentationOptionWidget::getMaxIterations()
{
    return ui->spnMaxIterations->value();
}

float SegmentationOptionWidget::getDistanceThreshold()
{
    return ui->spnDistanceThreshold->value();
}

SegmentationOptionWidget::~SegmentationOptionWidget()
{
    delete ui;
}
