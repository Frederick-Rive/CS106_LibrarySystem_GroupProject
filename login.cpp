#include "login.h"
#include "ui_login.h"
#include <QMainWindow>
#include <librarysystems.h>

login::login(QWidget *parent, QMainWindow *m, LibSystems::Account *acc, LibSystems::Member *memb) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    this->setStyleSheet
            (
                "QPushButton { background-color: #6895e8; }"
                "QPushButton:hover { background-color: #5784d7; }"
                "QLabel { font-size: 24px; }"
                "QLineEdit { border-radius: 20px; border-style: outset; padding-left: 20px; }"
            );

    QPixmap logo (":/resources/images/wcl_logo.png");
    ui->logoLabel->setPixmap(logo.scaled(ui->logoLabel->size()));
    this->setWindowTitle("Log In");

    rtrn = acc;
    mn = m;
    members = memb;
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
            *rtrn = LibSystems::Admin;
            QtHelpers::InformationMessageBox("Success", "You have logged on as the Admin");
            mn->show();
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
                    *rtrn = *members;
                    QtHelpers::InformationMessageBox("Success", "You have logged on as " + members->GetUsername());
                    mn->show();
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

