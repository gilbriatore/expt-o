#include "CaptureWidget.h"
#include "ui_CaptureWidget.h"

CaptureWidget::CaptureWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::CaptureWidget)
{
  ui->setupUi(this);
}

CaptureWidget::~CaptureWidget()
{
  delete ui;
}
