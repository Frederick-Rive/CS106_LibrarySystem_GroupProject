#include "login.h"
#include "ui_login.h"
#include <librarysystems.h>

login::login(QWidget *parent, LibSystems::Account *rtrn) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap logo (":/resources/images/wcl_logo.png");
    ui->logoLabel->setPixmap(logo.scaled(ui->logoLabel->size()));
    this->setWindowTitle("Log In");
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString uEntry = ui->username_LineEdit->text();
    QString pEntry = ui->password_LineEdit->text();

    LibSystems::Account admin = LibSystems::Account("username", "password");

    if (admin.CheckUsername(uEntry))
    {
        if (admin.CheckPassword(pEntry))
        {
            QMessageBox *qMessage = new QMessageBox;
            qMessage->setText("You Have Logged In As Admin");
            qMessage->exec();
        }
        else
        {
            QMessageBox *qMessage = new QMessageBox;
            qMessage->setText("Incorrect Password");
            qMessage->exec();
        }
    }
    else
    {
        QMessageBox *qMessage = new QMessageBox;
        qMessage->setText("Incorrect Username");
        qMessage->exec();
    }
}

