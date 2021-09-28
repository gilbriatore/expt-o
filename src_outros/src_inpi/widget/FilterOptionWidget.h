#ifndef FILTEROPTIONWIDGET_H
#define FILTEROPTIONWIDGET_H

#include <QWidget>

namespace Ui {
    class FilterOptionWidget;
}

class FilterOptionWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FilterOptionWidget(QWidget *parent = 0);
    float getLeafSize();
    bool isFilteringEnabled();
    ~FilterOptionWidget();

private:
    Ui::FilterOptionWidget *ui;
};

#endif // FILTEROPTIONWIDGET_H
