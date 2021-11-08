#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "addbook.h"
#include <librarysystems.h>
#include <QScrollArea>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bookVector = LibSystems::InitialiseBooks();
    memberVector = LibSystems::InitialiseMembers();
    loanVector = LibSystems::InitialseLoans();

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
    AddBook *add = new AddBook(this);
    QScrollArea *vScroll = new QScrollArea(this);
    vScroll->setWidget(add);
    vScroll->setMinimumSize(840, 470);
    vScroll->setMaximumSize(840, 470);
    ui->gridLayout->addWidget(vScroll, 5, 1);
}

