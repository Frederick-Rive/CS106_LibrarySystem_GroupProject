#include "login.h"
#include "ui_login.h"
#include <QMainWindow>
#include <librarysystems.h>

static LibSystems::Account *rtrn;
static QMainWindow *main;

login::login(QWidget *parent, QMainWindow *m, LibSystems::Account *acc) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap logo (":/resources/images/wcl_logo.png");
    ui->logoLabel->setPixmap(logo.scaled(ui->logoLabel->size()));
    this->setWindowTitle("Log In");

    rtrn = acc;
    main = m;
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
            QMessageBox *qMessage = new QMessageBox;
            qMessage->setText("You Have Logged In As Admin");
            qMessage->exec();
            rtrn = &LibSystems::Admin;
            main->show();
            this->hide();
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

