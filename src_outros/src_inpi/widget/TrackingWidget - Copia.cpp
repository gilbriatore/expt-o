#include "TrackingWidget.h"
#include "ui_TrackingWidget.h"

TrackingWidget::TrackingWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TrackingWidget)
{
  ui->setupUi(this);
}

TrackingWidget::~TrackingWidget()
{
  delete ui;
}
