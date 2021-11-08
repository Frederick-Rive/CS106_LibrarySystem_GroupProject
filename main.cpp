#include "mainwindow.h"
#include "login.h"
#include "librarysystems.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    return a.exec();
}
