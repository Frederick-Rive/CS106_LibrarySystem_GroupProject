#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "addbook.h"
#include <librarysystems.h>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (QDir("databases").exists())
    {
        //bookVector = LibSystems::InitialiseBooks();
        memberVector = LibSystems::InitialiseMembers();
        loanVector = LibSystems::InitialseLoans();
    }
    else
    {
        QDir().mkdir("databases");
        QDir().mkdir("databases/covers");
    }

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

void MainWindow::on_addbook_button_clicked()
{
    activeElement->~QWidget();
    qScroll->~QScrollArea();
    activeElement = new AddBook(this, bookVector);
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->gridLayout->addWidget(qScroll, 5, 1);
}


void MainWindow::on_viewbook_button_clicked()
{
    activeElement->~QWidget();
    qScroll->~QScrollArea();
    activeElement = new QWidget;
    qScroll = new QScrollArea;
}

