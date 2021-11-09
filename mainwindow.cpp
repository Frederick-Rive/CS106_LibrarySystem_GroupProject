#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "addbook.h"
#include <librarysystems.h>
#include <QDir>
#include <QLabel>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (QDir("databases").exists())
    {
        bookVector = LibSystems::InitialiseBooks();
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
    ClearActiveArea();
    activeElement = new AddBook(this, bookVector);
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    qScroll->setStyleSheet("border: 0px;");
    ui->activeLayout->addWidget(qScroll, 1);
}


void MainWindow::on_viewbook_button_clicked()
{
    ClearActiveArea();
    QGridLayout *qGrid = new QGridLayout(activeElement);

    int row = 0;
    int column = 0;
    for (int index = 0; index < LibSystems::Book::Count(); index++)
    {
        LibSystems::Book *book = bookVector[index];

        QWidget *item = new QWidget(activeElement);
        QVBoxLayout *itemLayout = new QVBoxLayout(item);

        QLabel *coverLab = new QLabel(item);
        QLabel *titleLab = new QLabel(item);
        QLabel *authorLab = new QLabel(item);
        QLabel *genreLab = new QLabel(item);

        coverLab->setPixmap(book->GetCover().scaled(135, 180));
        titleLab->setText(book->GetTitle());
        titleLab->setMaximumSize(140, 20);
        authorLab->setText(QString("Author: ") + book->GetAuthor());
        authorLab->setMaximumSize(140, 20);
        genreLab->setText(QString("Genre: ")+ book->GetGenre());
        genreLab->setMaximumSize(140, 20);

        itemLayout->addWidget(coverLab, 0);
        itemLayout->addWidget(titleLab, 1);
        itemLayout->addWidget(authorLab, 2);
        itemLayout->addWidget(genreLab, 3);

        qGrid->addWidget(item, row, column);

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
            QWidget *item = new QWidget(activeElement);
            QVBoxLayout *itemLayout = new QVBoxLayout(item);

            QLabel *coverLab = new QLabel(item);
            QLabel *titleLab = new QLabel(item);
            QLabel *authorLab = new QLabel(item);
            QLabel *genreLab = new QLabel(item);

            QPixmap defaultCover;
            defaultCover.load(":/resources/images/defaultbookcover.jpg");
            coverLab->setPixmap(defaultCover.scaled(135, 180));
            titleLab->setText("---");
            titleLab->setMaximumSize(140, 20);
            authorLab->setText("---");
            authorLab->setMaximumSize(140, 20);
            genreLab->setText("---");
            genreLab->setMaximumSize(140, 20);

            itemLayout->addWidget(coverLab, 0);
            itemLayout->addWidget(titleLab, 0);
            itemLayout->addWidget(authorLab, 0);
            itemLayout->addWidget(genreLab, 0);

            qGrid->addWidget(item, row, column);
        }
    }

    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 450);
    qScroll->setMaximumSize(840, 450);
    qScroll->setStyleSheet("border: 0px;");
    ui->activeLayout->addWidget(qScroll, 1);
}

void MainWindow::on_addmember_button_clicked()
{
    ClearActiveArea();
}

void MainWindow::on_viewmember_button_clicked()
{
    ClearActiveArea();
}

void MainWindow::on_overduebooks_button_clicked()
{
    ClearActiveArea();
}

void MainWindow::on_checkoutbooks_button_clicked()
{
    ClearActiveArea();
}

void MainWindow::ClearActiveArea()
{
    activeElement->~QWidget();
    qScroll->~QScrollArea();
    activeElement = new QWidget;
    qScroll = new QScrollArea;
}
