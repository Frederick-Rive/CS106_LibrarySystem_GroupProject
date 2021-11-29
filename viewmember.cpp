#include "viewmember.h"
#include "ui_viewmember.h"
#include "messageboxes.h"

ViewMember::ViewMember(LibSystems::Member *member, LibSystems::LoanedBook *loans, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMember)
{
    ui->setupUi(this);

    ui->indexLabel->setText(QString::number(member->GetIndex())); ui->firstnameLabel->setText(member->GetFirstName()); ui->lastnameLabel->setText(member->GetLastName());
    ui->dobLabel->setText(member->GetDOB().toString(Qt::DateFormat::ISODate)); ui->contactLabel->setText(member->GetContactNumber()); ui->emailLabel->setText(member->GetEmail());
    ui->bcountLabel->setText(QString::number(member->GetLoanedCount())); ui->ocountLabel->setText(QString::number(member->GetOverdueCount(loans)));

    this->setStyleSheet
            (
                "QLabel { border-width: 1px; border-style: solid; border-radius: 20px; border-color: #636363; padding-left: 5px; font: 14pt 'Roboto Regular'; }"
                "QPushButton#pushButton { background-color: #5A98D1; }"
                "QPushButton#pushButton::hover { background-color: #38588c; }"
            );
    ui->labels->setStyleSheet("QLabel { border-width: 0px; color: #5A98D1; font: 12pt 'Roboto Regular'; }");
}

ViewMember::ViewMember(LibSystems::Account *member, LibSystems::LoanedBook *loans, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMember)
{
    ui->setupUi(this);

    ui->indexLabel->setText(QString::number(member->GetIndex())); ui->firstnameLabel->setText(member->GetFirstName()); ui->lastnameLabel->setText(member->GetLastName());
    ui->dobLabel->setText(member->GetDOB().toString(Qt::DateFormat::ISODate)); ui->contactLabel->setText(member->GetContactNumber()); ui->emailLabel->setText(member->GetEmail());
    ui->bcountLabel->setText(QString::number(member->GetLoanedCount())); ui->ocountLabel->setText(QString::number(member->GetOverdueCount(loans))); ui->usernameLabel->setText(member->GetUsername());

    this->setStyleSheet
            (
                "QLabel { border-width: 1px; border-style: solid; border-radius: 20px; border-color: #636363; padding-left: 5px; font: 14pt 'Roboto Regular'; }"
            );
    ui->labels->setStyleSheet("QLabel { border-width: 0px; color: #5A98D1; font: 12pt 'Roboto Regular'; }");

    ui->pushButton->hide();
}

ViewMember::~ViewMember()
{
    delete ui;
}

void ViewMember::on_pushButton_clicked()
{
    LibMessageBoxes::InformationMessageBox("Success", "An email has been sent to the member");
}

