#include "login.h"
#include "adminwindow.h"
#include "memberwindow.h"
#include "ui_login.h"
#include <QMainWindow>
#include <librarysystems.h>
#include <QDir>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    acc = new LibSystems::Account;

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

    this->setStyleSheet
            (
                "QPushButton#pushButton { background-color: #6895e8; }"
                "QPushButton#closeButton { font-size: 60px; color: #6895e8; }"
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
            QtHelpers::InformationMessageBox("Success", "You have logged on as the Admin");

            MainWindow *m = new MainWindow(books, members, loans, acc);
            m->show();

            this->hide();
            return;
        }
    }
    else
    {
        while (members != nullptr)
        {
            if (members->CheckUsername(uEntry))
            {
                if (members->CheckPassword(pEntry))
                {
                    *acc = *members;
                    QtHelpers::InformationMessageBox("Success", "You have logged on as " + members->GetUsername());

                    MemberWindow *m = new MemberWindow(books, members, loans, acc);
                    m->show();

                    this->hide();
                    return;
                }
            }
            members = members->Next();
        }
    }

    switch(QtHelpers::ErrorMessageBox("Error", "Incorrect username/password"))
    {
    case QMessageBox::Retry:
        ui->username_LineEdit->setText("");
        ui->password_LineEdit->setText("");
        break;
    case QMessageBox::Cancel:
        hide();
    }
}

void login::on_closeButton_clicked()
{
    this->hide();
}

