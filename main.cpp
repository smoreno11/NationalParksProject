#include "mainwindow.h"
#include "customer.h"
#include "databasesetup.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    setupDB();
    MainWindow w;
    w.show();

    return a.exec();
}
