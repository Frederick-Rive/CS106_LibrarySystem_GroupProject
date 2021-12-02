#include "viewmember.h"
#include "ui_viewmember.h"
#include "messageboxes.h"

ViewMember::ViewMember(LibSystems::Member *m, LibSystems::LoanedBook *loans, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMember)
{
    ui->setupUi(this);

    member = m;

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

    connect(ui->pushButton, &QPushButton::clicked, this, &ViewMember::SendReminder);
}

ViewMember::ViewMember(LibSystems::Member *m, LibSystems::LoanedBook *loans, LibSystems::Account *u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMember)
{
    ui->setupUi(this);

    member = m;

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

    ui->pushButton->setText("Edit Member");
    connect(ui->pushButton, &QPushButton::clicked, this, &ViewMember::EditMember);
}

ViewMember::ViewMember(LibSystems::Account *m, LibSystems::LoanedBook *loans, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMember)
{
    ui->setupUi(this);

    ui->indexLabel->setText(QString::number(m->GetIndex())); ui->firstnameLabel->setText(m->GetFirstName()); ui->lastnameLabel->setText(m->GetLastName());
    ui->dobLabel->setText(m->GetDOB().toString(Qt::DateFormat::ISODate)); ui->contactLabel->setText(m->GetContactNumber()); ui->emailLabel->setText(m->GetEmail());
    ui->bcountLabel->setText(QString::number(m->GetLoanedCount())); ui->ocountLabel->setText(QString::number(m->GetOverdueCount(loans))); ui->usernameLabel->setText(m->GetUsername());

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

void ViewMember::EditMember()
{
    emit EmitMember(member);
}

void ViewMember::SendReminder()
{
    LibMessageBoxes::InformationMessageBox("Success", "An email has been sent to the member");
}

