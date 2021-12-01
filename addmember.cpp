#include "addmember.h"
#include "ui_addmember.h"
#include "messageboxes.h"

AddMember::AddMember(QWidget *parent, LibSystems::Member *lastMember, LibSystems::Member *editMember) :
    QWidget(parent),
    ui(new Ui::AddMember) //constructor
{
    ui->setupUi(this);

    member = lastMember; //initialize data member

    this->setStyleSheet //set css for this widget
            (
                "QLabel { color: #5A98D1; }"
                "QPushButton { background-color: #5A98D1; }"
                "QPushButton:hover { background-color: #5687d1; }"
                "QLineEdit { border-radius: 6px; border-style: outset; font: 16pt 'Roboto Regular'; }"
                "QSpinBox { border-radius: 6px; border-style: outset; font: 16pt 'Roboto Regular'; }"
                "QCheckBox { font: 12pt 'Roboto Regular'; } "
                "QCheckBox::indicator { border: 0px; border-radius: 2px; background-color: white; border-style: solid; }"
                "QCheckBox::indicator::checked { border: 2px; border-radius: 2px; border-color: white; background-color: #5A98D1; }"
            );
    edit = editMember; //initialize data member
    if (edit != nullptr) //if editing book (makes entry widgets have default arguments)
    {
        ui->usernameEntry->setText(edit->GetUsername()); ui->passwordEntry->setText(edit->GetPassword()); ui->firstnameEntry->setText(edit->GetFirstName());
        ui->lastnameEntry->setText(edit->GetLastName()); ui->emailEntry->setText(edit->GetEmail()); ui->cntctEntry->setText(edit->GetContactNumber());
        ui->dayEntry->setValue(edit->GetDOB().day()); ui->monthEntry->setValue(edit->GetDOB().month()); ui->yearEntry->setValue(edit->GetDOB().year()); ui->pushButton->setText("Save member");
    }
}

AddMember::~AddMember() //destructor
{
    delete ui;
}

void AddMember::on_showPassword_clicked(bool checked) //sets echo mode for password entry based on checkbox
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

void AddMember::on_pushButton_clicked() //saves member
{
    if (edit == nullptr) //if making new member
    {
        int i[5] = { -1, -1, -1, -1, -1 }; //initialses array of loan indices with -1 values (means empty, no loan)
        QDate dob;
        dob.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value()); //make QDate out of users input
        LibSystems::Member *newMember = new LibSystems::Member(LibSystems::Member::Count(), ui->usernameEntry->text(), ui->passwordEntry->text(), ui->emailEntry->text(),
                                                               ui->cntctEntry->text(), ui->firstnameEntry->text(), ui->lastnameEntry->text(), dob, i, member); //makes member with user input
        newMember->WriteToMemory(); //write new member to memory
        if (member != nullptr) { member->SetNext(newMember); } //links new member into the member linked list

        LibMessageBoxes::InformationMessageBox("Success", "The new member has been added to the database"); //send success message
    }
    else //if editing member
    {
        QDate dob;
        dob.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value());  //make QDate out of users input
        //edits book with user input
        edit->EditMember(ui->usernameEntry->text(), ui->passwordEntry->text(), ui->emailEntry->text(), ui->cntctEntry->text(), ui->firstnameEntry->text(), ui->lastnameEntry->text(), dob);

        while (member->Prev() != nullptr)
        {
            member = member->Prev();
        }

        LibSystems::RewriteMembers(member); //rewrite member file with new data

        LibMessageBoxes::InformationMessageBox("Success", "Your edits have been saved to the database"); //send success message
    }

    emit Finish(); //emit finish signal to adminwindow
}

void AddMember::on_monthEntry_valueChanged(int arg1) //restrict max value of date entry by current month entry, to ensure entry is valid
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

