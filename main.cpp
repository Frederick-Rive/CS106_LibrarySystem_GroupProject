#include "adminwindow.h"
#include "memberwindow.h"
#include "login.h"
#include "librarysystems.h"
#include <QApplication>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFontDatabase::addApplicationFont(":/resources/Roboto/Roboto-Regular.ttf");

    a.setStyleSheet
            (
                "QPushButton { border-radius: 15px; border-style: outset; color: #FFFFFF; background-color: rgba(0,0,0,0); font: 16pt 'Roboto Regular'; }"
                "QPushButton:hover:!pressed { background-color: #38588c; }"
                "QPushButton:pressed { background-color: #FFFFFF; color: #6895e8; }"
                "QPushButton#logout_button { border-color: #000000; }"
                "QLineEdit { border-radius: 15px; border-style: outset; }"
                "QLabel { font: 16pt 'Roboto Regular'; }"
                "QScrollBar { background-color: #FFFFFF;  width: 5px; }"
                "QScrollBar::handle { background: #6895e8; border: 0px; }"
                "QScrollArea { border: 1px; border-style: outset; border-radius: 5px; }"
            );

    login l;
    l.show();
    return a.exec();
}
