#include "adminwindow.h"
#include "login.h"
#include "librarysystems.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet
            (
                "QPushButton { border-radius: 15px; border-style: outset; color: #FFFFFF; background-color: rgba(0,0,0,0); font-size: 16px;}"
                "QPushButton:hover:!pressed { background-color: #38588c; }"
                "QPushButton:pressed { background-color: #FFFFFF; color: #6895e8; }"
                "QPushButton#logout_button { border-color: #000000; }"
                "QLineEdit { border-radius: 15px; border-style: outset; }"
                "QLabel { font-size: 16px; font: \"Courier New\"; }"
                "QMessageBox { font-size: 200px; margin: 20px; }"
                "QScrollBar { background-color: #FFFFFF;  width: 5px; }"
                "QScrollBar::handle { background: #6895e8; border: 0px; }"
                "QScrollArea { border: 1px; border-style: outset; border-radius: 5px; }"
            );

    MainWindow w;
    return a.exec();
}
