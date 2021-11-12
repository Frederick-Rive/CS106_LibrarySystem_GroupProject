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
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>

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
        books->SetNext(LibSystems::InitialiseBooks());
        members->SetNext(LibSystems::InitialiseMembers());
        loans->SetNext(LibSystems::InitialseLoans());
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

    QPixmap facebookImg, twitterImg, instaImg;
    facebookImg.load(":/resources/images/facebookLogo.png"); twitterImg.load(":/resources/images/twitterLogo.png"); instaImg.load(":/resources/images/instaLogo.jfif");
    QIcon facebookIcon(facebookImg), twitterIcon(twitterImg), instaIcon(instaImg);
    ui->facebookButton->setIcon(facebookIcon); ui->twitterButton->setIcon(twitterIcon); ui->instaButton->setIcon(instaIcon);
    ui->facebookButton->setIconSize(ui->facebookButton->size()); ui->twitterButton->setIconSize(ui->twitterButton->size()); ui->instaButton->setIconSize(ui->instaButton->size());

    login *log = new login(nullptr, this, &user, members->Next());
    log->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_logout_button_clicked()
{
    user = LibSystems::Account();
    login *log = new login(nullptr, this, &user, members->Next());
    log->show();
    hide();
}

void MainWindow::on_addbook_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->addbook_button);

    LibSystems::Book *last = books;

    while (last->Next() != nullptr)
    {
        last = last->Next();
    }
    activeElement = new AddBook(this, last);
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->activeLayout->addWidget(qScroll, 1);
}

void MainWindow::EditBook (LibSystems::Book *book)
{
    ClearActiveArea();

    LibSystems::Book *last = books;

    while (last->Next() != nullptr)
    {
        last = last->Next();
    }
    activeElement = new AddBook(this, last, book);
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
    if (LibSystems::Book::Count() > 0)
    {
        QGridLayout *qGrid = new QGridLayout(activeElement);

        int row = 0;
        int column = 0;
        LibSystems::Book *displayBook = books->Next();
        for (int index = 0; index < LibSystems::Book::Count(); index++)
        {
            BookDisplay *display = new BookDisplay(activeElement, displayBook);

            qGrid->addWidget(display, row, column);

            displayBook = displayBook->Next();

            connect(display, &BookDisplay::Edit, this, &MainWindow::EditBook);

            column++;
            if (column == 5)
            {
                row += 1;
                column = 0;
            }
        }

        if (column < 5 && column > 0)
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
}

void MainWindow::on_addmember_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->addmember_button);

    LibSystems::Member *last = members;
    while(last->Next() != nullptr)
    {
        last = last->Next();
    }

    activeElement = new AddMember(this, last);
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
    delete activeElement;
    delete qScroll;
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

void MainWindow::on_facebookButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.facebook.com/wellingtoncitylibraries")));
}

void MainWindow::on_twitterButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://twitter.com/wcl_library")));
}

void MainWindow::on_instaButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.instagram.com/wcl_library/")));
}

