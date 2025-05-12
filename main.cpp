#include <QApplication>
#include "mainwindow.h"
#include "library_system.h"
#include "library_system.h"

library_system* system = nullptr;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    system = new library_system();  // Global library context

    MainWindow w;
    w.show();

    int result = app.exec();

    delete system;  // Clean up
    return result;
}
