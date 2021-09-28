#include "FilterOptionWidget.h"
#include "ui_FilterOptionWidget.h"

FilterOptionWidget::FilterOptionWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterOptionWidget)
{
    ui->setupUi(this);
}

float FilterOptionWidget::getLeafSize()
{
    return ui->spnLeafSize->value();
}

bool FilterOptionWidget::isFilteringEnabled()
{
    return ui->chkEnableFiltering->isChecked();
}

FilterOptionWidget::~FilterOptionWidget()
{
    delete ui;
}
