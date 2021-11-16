#include "addmember.h"
#include "ui_addmember.h"


AddMember::AddMember(QWidget *parent, LibSystems::Member *lastMember) :
    QWidget(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);

    member = lastMember;

    this->setStyleSheet
            (
                "QPushButton { background-color: #6895e8; }"
                "QPushButton:hover { background-color: #5687d1; }"
                "QLineEdit { border-radius: 6px; border-style: outset; }"
                "QSpinBox { border-radius: 6px; border-style: outset; }"
                "QCheckBox::indicator { border: 0px; border-radius: 2px; background-color: white; border-style: solid; }"
                "QCheckBox::indicator::checked { border: 2px; border-radius: 2px; border-color: white; background-color: #6895e8; }"
                "QTextEdit { border-radius: 2px; border-style: outset; border: 1px; }"
                "QSlider::handle { background-color: #6895e8; border-radius: 2px; border-style: outset; }"
                "QLineEdit#coverpathEntry { border-radius: 0px; }"
            );
}

AddMember::~AddMember()
{
    delete ui;
}

void AddMember::on_showPassword_clicked(bool checked)
{
    switch (checked)
    {
    case true:
        ui->passwordEntry->setEchoMode(QLineEdit::EchoMode::Normal);
        break;
    case false:
        ui->passwordEntry->setEchoMode(QLineEdit::EchoMode::Password);
        break;
    }
}


void AddMember::on_pushButton_clicked()
{
    int i[5] = { -1, -1, -1, -1, -1 };
    QDate dob;
    dob.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value());
    LibSystems::Member *newMember = new LibSystems::Member(LibSystems::Member::Count(), ui->usernameEntry->text(), ui->passwordEntry->text(), ui->emailEntry->text(),
                                                           ui->cntctEntry->text(), ui->firstnameEntry->text(), ui->lastnameEntry->text(), dob, i, member);
    newMember->WriteToMemory();
    if (member != nullptr) { member->SetNext(newMember); }
    member = newMember;

    QtHelpers::InformationMessageBox("Success", "The new member has been added to the database");
}


void AddMember::on_monthEntry_valueChanged(int arg1)
{
    switch (arg1)
    {
    case 2:
        if (ui->yearEntry->value() % 4 != 0)
        {
            ui->dayEntry->setMaximum(28);
        }
        else
        {
            ui->dayEntry->setMaximum(29);
        }
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        ui->dayEntry->setMaximum(31);
        break;
    default:
        ui->dayEntry->setMaximum(30);
    }
}

