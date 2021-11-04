#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <login.h>
#include <librarysystems.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    login *l = new login;
    l->show();
    l->setFocus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

