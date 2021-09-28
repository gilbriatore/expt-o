#ifndef CAPTUREWIDGET_H
#define CAPTUREWIDGET_H

#include <QWidget>

namespace Ui {
  class CaptureWidget;
}

class CaptureWidget : public QWidget
{
    Q_OBJECT

  public:
    explicit CaptureWidget(QWidget *parent = 0);
    ~CaptureWidget();

  private:
    Ui::CaptureWidget *ui;
};

#endif // CAPTUREWIDGET_H
