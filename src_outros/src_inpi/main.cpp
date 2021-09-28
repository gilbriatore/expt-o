#include "MainWindow.h"
#include <QApplication>
#include <QVTKOpenGLWidget.h>
#include <qsurfaceformat.h>
#include <QDebug>

//extern "C" {
//__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//}

class MyApplication : public QApplication {
public:
  MyApplication(int& argc, char ** argv) :
    QApplication(argc, argv) { }
  virtual ~MyApplication() { }

  // reimplemented from QApplication so we can throw exceptions in slots
  virtual bool notify(QObject * receiver, QEvent * event) {
    try {
      return QApplication::notify(receiver, event);
    } catch(std::exception& e) {
      qCritical() << "Exception thrown:" << e.what();
    }
    return false;
  }
};

int main(int argc, char *argv[])
{
  try
  {
    QSurfaceFormat qFormat = QVTKOpenGLWidget::defaultFormat();
    qFormat.setSamples(0);
    QSurfaceFormat::setDefaultFormat(qFormat);

    //QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    MyApplication app(argc, argv);
    app.setApplicationName("Expt-o");

    MainWindow window;
    window.showMaximized();
    //window.show();
    return app.exec();
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << std::endl;
  }
  catch (...)
  {
    std::cout << "Unknown exception!" << std::endl;
  }
  return 0;
}
