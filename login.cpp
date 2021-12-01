#include "login.h"
#include "adminwindow.h"
#include "memberwindow.h"
#include "ui_login.h"
#include "messageboxes.h"
#include <QMainWindow>
#include <librarysystems.h>
#include <QDir>

login::login(QWidget *parent, LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    acc = new LibSystems::Account;

    if (QDir("databases").exists())
    {
        books->SetNext((b != nullptr) ? b : LibSystems::InitialiseBooks()); if (LibSystems::Book::Count() > 0) { books->Next()->SetPrev(books); }
        members->SetNext((m != nullptr) ? m : LibSystems::InitialiseMembers()); if (LibSystems::Member::Count() > 0) { members->Next()->SetPrev(members); }
        loans->SetNext((l != nullptr) ? l : LibSystems::InitialseLoans()); if (LibSystems::LoanedBook::Count() > 0) { loans->Next()->SetPrev(loans); }
    }
    else
    {
        QDir().mkdir("databases");
        QDir().mkdir("databases/covers");

        QFile books("databases/books.csv"); QFile members("databases/members.csv"); QFile loans("databases/loans.csv"); QFile reserves("databases/reservations.csv");
        books.open(QIODevice::WriteOnly);members.open(QIODevice::WriteOnly);loans.open(QIODevice::WriteOnly);reserves.open(QIODevice::WriteOnly);
        books.close();members.close();loans.close();reserves.close();
    }

    this->setStyleSheet
            (
                "QPushButton#pushButton { background-color: #5A98D1; }"
                "QPushButton#closeButton { font-size: 60px; color: #5A98D1; }"
                "QPushButton#closeButton:hover { font-size: 65px; background-color: rgba(0,0,0,0); color: #38588c; }"
                "QLabel { font: 24pt 'Roboto Regular'; }"
                "QLineEdit { border-radius: 20px; border-style: outset; padding-left: 20px; font: 24pt 'Roboto Regular'; }"
            );

    QPixmap logo (":/resources/images/wcl_logo.png");
    ui->logoLabel->setPixmap(logo.scaled(ui->logoLabel->size()));
    this->setWindowTitle("Log In");
    QPixmap icon;
    icon.load(":/resources/images/taskbarImg.PNG");
    this->setWindowIcon(QIcon(icon));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString uEntry = ui->username_LineEdit->text();
    QString pEntry = ui->password_LineEdit->text();

    if (LibSystems::Admin.CheckUsername(uEntry))
    {
        if (LibSystems::Admin.CheckPassword(pEntry))
        {
            *acc = LibSystems::Admin;
            LibMessageBoxes::InformationMessageBox("Success", "You have logged on as the Admin");

            MainWindow *m = new MainWindow(books, members, loans, acc);
            m->show();

            this->hide();
            return;
        }
    }
    else
    {
        LibSystems::Member *thisMember = members->Next();
        while (thisMember != nullptr)
        {
            if (thisMember->CheckUsername(uEntry))
            {
                if (thisMember->CheckPassword(pEntry))
                {
                    acc = thisMember;
                    LibMessageBoxes::InformationMessageBox("Success", "You have logged on as " + thisMember->GetUsername());

                    MemberWindow *m = new MemberWindow(books, members, loans, acc);
                    m->show();

                    this->hide();
                    return;
                }
            }
            thisMember = thisMember->Next();
        }
    }

    switch(LibMessageBoxes::ErrorMessageBox("Error", "Incorrect username/password"))
    {
    case QMessageBox::Retry:
        //ui->username_LineEdit->setText("");
        //ui->password_LineEdit->setText("");
        break;
    case QMessageBox::Cancel:
        close();
    }
}

void login::on_closeButton_clicked()
{
    this->close();
}

