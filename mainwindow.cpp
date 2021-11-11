#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "addbook.h"
#include "bookdisplay.h"
#include "addmember.h"
#include <librarysystems.h>
#include <QDir>
#include <QLabel>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setStyleSheet
            (
                "QWidget#header { background: qlineargradient(x1:0, y1:0, x2:1, y2:0.3, stop:0 #4d7fc9, stop: 0.4 #5687d1 stop:1 #88b5f8) }"
                "QPushButton#logout_button { border: 1px; border-color: #FFFFFF; border-style: solid; }"
            );

    if (QDir("databases").exists())
    {
        LibSystems::bookVector = LibSystems::InitialiseBooks();
        LibSystems::memberVector = LibSystems::InitialiseMembers();
        LibSystems::loanVector = LibSystems::InitialseLoans();
    }
    else
    {
        QDir().mkdir("databases");
        QDir().mkdir("databases/covers");
    }

    this->setWindowTitle("Wellington Central Library");

    QPixmap logo (":/resources/images/wcl_logo_wide_white.png");
    ui->logolabel->setPixmap(logo.scaled(ui->logolabel->size()));

    QPixmap pixmap;
    pixmap.load(":/resources/images/background.png");
    ui->background->setPixmap(pixmap.scaled(1280, 730));
    activeElement = ui->background;

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
    ClearActiveArea();
    SetActiveButton(ui->addbook_button);
    activeElement = new AddBook(this);
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->activeLayout->addWidget(qScroll, 1);
}


void MainWindow::on_viewbook_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->viewbook_button);
    QGridLayout *qGrid = new QGridLayout(activeElement);

    int row = 0;
    int column = 0;
    for (int index = 0; index < LibSystems::Book::Count(); index++)
    {
        LibSystems::Book *book = LibSystems::bookVector[index];

        BookDisplay *display = new BookDisplay(activeElement, book);

        display->setAttribute(Qt::WA_Hover);

        qGrid->addWidget(display, row, column);

        column++;
        if (column == 5)
        {
            row += 1;
            column = 0;
        }
    }

    if (column < 5)
    {
        for (column; column < 5; column++)
        {
            BookDisplay *display = new BookDisplay(activeElement);

            qGrid->addWidget(display, row, column);
        }
    }

    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 450);
    qScroll->setMaximumSize(1150, 450);
    ui->activeLayout->addWidget(qScroll, 1);
}

void MainWindow::on_addmember_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->addmember_button);
    activeElement = new AddMember(this);
    ui->activeLayout->addWidget(activeElement, 1, Qt::AlignCenter);
}

void MainWindow::on_viewmember_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->viewmember_button);
}

void MainWindow::on_overduebooks_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->overduebooks_button);
}

void MainWindow::on_checkoutbooks_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->checkoutbooks_button);
}

void MainWindow::ClearActiveArea()
{
    activeElement->~QWidget();
    qScroll->~QScrollArea();
    activeElement = new QWidget;
    qScroll = new QScrollArea;
}

void MainWindow::SetActiveButton(QPushButton *pressed)
{
    if (activeButton != nullptr)
    {
        activeButton->setStyleSheet("");
        activeButton->setGraphicsEffect(0);
    }
    pressed->setStyleSheet("background-color: #FFFFFF; color: #6895e8; ");
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 2);
    dropShadow->setColor(QColor::fromRgb(68, 95, 158));
    pressed->setGraphicsEffect(dropShadow);
    activeButton = pressed;
}
