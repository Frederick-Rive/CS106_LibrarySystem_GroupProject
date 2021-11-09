#include "mainwindow.h"
#include "login.h"
#include "librarysystems.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet
            (
                "QPushButton { border-radius: 15px; border-style: outset; color: #FFFFFF; background-color: #6895e8; font-size: 16px;}"
                "QPushButton:hover:!pressed { color: #6895e8; background-color: #EEEEEE; }"
                "QPushButton:pressed { background-color: #7777AA; }"
                "QPushButton#logout_button { border-color: #000000; }"
                "QLineEdit { border-radius: 15px; border-style: outset; }"
                "QLabel { font-size: 16px; font-family: 'Comic Sans'; }"
            );

    MainWindow w;
    return a.exec();
}
