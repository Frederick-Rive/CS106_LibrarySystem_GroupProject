#include "addmember.h"
#include "ui_addmember.h"

AddMember::AddMember(QWidget *parent, LibSystems::Member *lastMember, LibSystems::Member *editMember) :
    QWidget(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);

    member = lastMember;

    this->setStyleSheet
            (
                "QPushButton { background-color: #5A98D1; }"
                "QPushButton:hover { background-color: #5687d1; }"
                "QLineEdit { border-radius: 6px; border-style: outset; font: 16pt 'Roboto Regular'; }"
                "QSpinBox { border-radius: 6px; border-style: outset; font: 16pt 'Roboto Regular'; }"
                "QCheckBox { font: 12pt 'Roboto Regular'; } "
                "QCheckBox::indicator { border: 0px; border-radius: 2px; background-color: white; border-style: solid; }"
                "QCheckBox::indicator::checked { border: 2px; border-radius: 2px; border-color: white; background-color: #5A98D1; }"
            );
    edit = editMember;
    if (edit != nullptr)
    {
        ui->usernameEntry->setText(edit->GetUsername()); ui->passwordEntry->setText(edit->GetPassword()); ui->firstnameEntry->setText(edit->GetFirstName());
        ui->lastnameEntry->setText(edit->GetLastName()); ui->emailEntry->setText(edit->GetEmail()); ui->cntctEntry->setText(edit->GetContactNumber());
        ui->dayEntry->setValue(edit->GetDOB().day()); ui->monthEntry->setValue(edit->GetDOB().month()); ui->yearEntry->setValue(edit->GetDOB().year()); ui->pushButton->setText("Save member");
    }
}

AddMember::~AddMember()
{
    delete ui;
}

void AddMember::on_showPassword_clicked(bool checked)
{
    if (checked)
    {
        ui->passwordEntry->setEchoMode(QLineEdit::EchoMode::Normal);
    }
   else
    {
        ui->passwordEntry->setEchoMode(QLineEdit::EchoMode::Password);
    }
}

void AddMember::on_pushButton_clicked()
{
    if (edit == nullptr)
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
    else
    {
        QFile memberFile("databases/members.csv");

        std::vector<QString> memberVec;

        if (memberFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&memberFile);

            for (int i = 0; i < edit->GetIndex(); i++)
            {
                memberVec.push_back(in.readLine());
            }

            QDate dob;
            dob.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value());

            memberVec.push_back(edit->EditMember(ui->usernameEntry->text(), ui->passwordEntry->text(), ui->emailEntry->text(), ui->cntctEntry->text(), ui->firstnameEntry->text(), ui->lastnameEntry->text(), dob));

            in.readLine();

            while (!in.atEnd())
            {
                memberVec.push_back(in.readLine());
            }
        }
        else
        {
            QtHelpers::ErrorMessageBox("Error", "File Didn't Open");
            return;
        }

        memberFile.close();

        if (memberFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QTextStream out(&memberFile);

            for (QString s : memberVec)
            {
                if (s.size() > 0)
                {
                    out << s << '\n';
                }
            }

            QtHelpers::InformationMessageBox("Success", "Your edits have been saved to the database");
        }
        else
        {
            QtHelpers::ErrorMessageBox("Error", "File Didn't Open");
            return;
        }

        memberFile.flush();
        memberFile.close();
    }

    emit Finish();
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

