#ifndef TRACKINGWIDGET_H
#define TRACKINGWIDGET_H

#include <QWidget>

namespace Ui {
  class TrackingWidget;
}

class TrackingWidget : public QWidget
{
    Q_OBJECT

  public:
    explicit TrackingWidget(QWidget *parent = 0);
    ~TrackingWidget();

  private:
    Ui::TrackingWidget *ui;
};

#endif // TRACKINGWIDGET_H
