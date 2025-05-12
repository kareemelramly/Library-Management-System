#include <QApplication>
#include "login.h"
#include "library_system.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    library_system* system = new library_system();
    MainWindow w(system);
    w.show();

    int result = app.exec();

     // Clean up
    return result;
}
