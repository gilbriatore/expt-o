#include "ClusteringOptionWidget.h"
#include "ui_ClusteringOptionWidget.h"

ClusteringOptionWidget::ClusteringOptionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClusteringOptionWidget)
{
    ui->setupUi(this);
}

bool ClusteringOptionWidget::isClusteringEnabled()
{
    return ui->chkEnableClustering->isChecked();
}

float ClusteringOptionWidget::getClusterTolerance()
{
    return ui->spnClusterTolerance->value();
}

int ClusteringOptionWidget::getMinClusterSize()
{
    return ui->spnMinClusterSize->value();
}

int ClusteringOptionWidget::getMaxClusterSize()
{
    return ui->spnMaxClusterSize->value();
}

bool ClusteringOptionWidget::showUsedKeypoints()
{
    return ui->chkShowUsedKeypoints->isChecked();
}

float ClusteringOptionWidget::getModelSample()
{
    return ui->spnModelSample->value();
}

float ClusteringOptionWidget::getDescriptorRadius()
{
    return ui->spnDescriptorRadius->value();
}

ClusteringOptionWidget::~ClusteringOptionWidget()
{
    delete ui;
}

void ClusteringOptionWidget::on_chkShowUsedKeypoints_toggled(bool checked)
{
    if(checked) {
        ui->spnModelSample->setEnabled(true);
        ui->spnDescriptorRadius->setEnabled(true);
    } else {
        ui->spnModelSample->setEnabled(false);
        ui->spnDescriptorRadius->setEnabled(false);
    }
}
