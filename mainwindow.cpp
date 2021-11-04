#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include <librarysystems.h>

static LibSystems::Account *user;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    login *log = new login(nullptr, this, user);
    log->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

