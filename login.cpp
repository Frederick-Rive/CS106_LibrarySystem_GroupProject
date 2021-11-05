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
    QPixmap logo (":/resources/images/wcl_logo_wide.png");
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
            rtrn = &LibSystems::Admin;
            QtHelpers::InformationMessageBox("Success", "You have logged on as the Admin");
            main->show();
            this->hide();
        }
        else
        {
            switch(QtHelpers::ErrorMessageBox("Error", "Incorrect username/password"))
            {
            case QMessageBox::Retry:
                break;
            case QMessageBox::Cancel:
                hide();
            }
        }
    }
    else
    {
        switch(QtHelpers::ErrorMessageBox("Error", "Incorrect username/password"))
        {
        case QMessageBox::Retry:
            break;
        case QMessageBox::Cancel:
            hide();
        }
    }
}

