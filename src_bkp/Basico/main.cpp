#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    app.setApplicationName("Expt-o");

    MainWindow window;
    window.show();

    return app.exec();
}
