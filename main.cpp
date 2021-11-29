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
                "QPushButton:pressed { background-color: #FFFFFF; color: #5A98D1; }"
                "QPushButton#logout_button { border-color: #000000; }"
                "QLineEdit { border-radius: 15px; border-style: outset; padding-left: 5px;}"
                "QLabel { font: 16pt 'Roboto Regular'; }"
                "QScrollBar { background-color: #FFFFFF;  width: 5px; }"
                "QScrollBar::handle { background: #5A98D1; border: 0px; }"
                "QScrollArea { border: 1px; border-style: outset; }"
                "QMessageBox QPushButton { background-color: #5A98D1; padding: 10px 30px; }"
            );

    login l;
    l.show();
    return a.exec();
}
