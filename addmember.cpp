#include "addmember.h"
#include "ui_addmember.h"


AddMember::AddMember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);

    this->setStyleSheet
            (
                "QPushButton { background-color: #6895e8; }"
                "QPushButton:hover { background-color: #5687d1; }"
                "QLineEdit { border-radius: 6px; border-style: outset; }"
                "QSpinBox { border-radius: 6px; border-style: outset; }"
                "QSlider::groove {  }"
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
    LibSystems::memberVector.push_back(new LibSystems::Member(LibSystems::Member::Count(), ui->usernameEntry->text(), ui->passwordEntry->text(), ui->emailEntry->text(), ui->cntctEntry->text(), i));
    LibSystems::memberVector[LibSystems::Member::Count() - 1]->WriteToMemory();
}

