#include "MainWindow.h"
#include <QApplication>
#include <QVTKOpenGLWidget.h>
#include <qsurfaceformat.h>

//extern "C" {
//__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
//}

int main(int argc, char *argv[])
{
  try
  {
    QSurfaceFormat qFormat = QVTKOpenGLWidget::defaultFormat();
    qFormat.setSamples(0);
    QSurfaceFormat::setDefaultFormat(qFormat);

    //QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication app(argc, argv);
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