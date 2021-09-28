#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  _ui(new Ui::MainWindow)
{
  _ui->setupUi(this);

  _ksThread = new QThread();
  _kSensor = new KinectSensor();
  _kSensor->moveToThread(_ksThread);

  qRegisterMetaType<KinectCloud::Ptr>("KinectCloud::Ptr");

  this->connect(this, SIGNAL(startKinect()), _kSensor, SLOT(run()));
  this->connect(_kSensor, SIGNAL(send(KinectCloud::Ptr)), _ui->clustering, SLOT(populateCloud(KinectCloud::Ptr)));

  _ksThread->start();
  emit startKinect();
}

MainWindow::~MainWindow()
{
  delete _ui;
}