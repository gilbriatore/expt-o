#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QThread>
#include <QMainWindow>

#include "kinect/KinectSensor.hpp"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  signals:
      void startKinect();

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private:
    Ui::MainWindow *_ui;
    KinectSensor *_kSensor;
    QThread *_ksThread;
};

#endif // MAINWINDOW_H
