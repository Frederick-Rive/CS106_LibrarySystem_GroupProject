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

    this->setWindowTitle("Wellington Central Library");

    QPixmap logo (":/resources/images/wcl_logo.png");
    ui->logolabel->setPixmap(logo.scaled(ui->logolabel->size()));

    login *log = new login(nullptr, this, user);
    log->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_logout_button_clicked()
{
    user = nullptr;
    login *log = new login(nullptr, this, user);
    log->show();
    hide();
}

