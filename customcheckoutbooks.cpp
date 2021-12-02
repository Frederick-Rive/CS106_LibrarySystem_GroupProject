#include "customcheckoutbooks.h"
#include "ui_customcheckoutbooks.h"
#include "messageboxes.h"

CustomCheckoutBooks::CustomCheckoutBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomCheckoutBooks) //constructor
{
    ui->setupUi(this);

    books = b; //initialize data members
    members = m;
    loans = l;

    selectedBook = books;
    selectedMember = members;

    this->setStyleSheet //style sheets
            (
                "font: 12pt 'Roboto Regular';"
            );

    ui->pushButton->setStyleSheet("QPushButton {background-color: #5A98D1; } QPushButton::hover { background-color: #38588c; }");
}

CustomCheckoutBooks::~CustomCheckoutBooks() //destructors
{
    delete ui;
}

void CustomCheckoutBooks::on_pushButton_clicked() //checkout
{
    if (selectedBook->GetIndex() >= 0 && selectedMember->GetIndex() >= 0) //make sure that the user has selected a book and a member
    {
        if (selectedBook->IsAvailable()) //make sure the book is available to be checked out
        {
            if (selectedMember->GetLoanedCount() < 5) //make sure the member isn't at the max number of books
            {
                loans = (LibSystems::LoanedBook::Count() > 0) ? loans->Next(LibSystems::LoanedBook::Count() - 1) : loans; //declare loan pointer as last loan in linked list

                LibSystems::LoanedBook *newloan = new LibSystems::LoanedBook(selectedBook->GetIndex(), selectedMember->GetIndex(), QDate::currentDate().addDays(14), loans); //generate new loan
                loans->SetNext(newloan); //link new loan into list
                newloan->WriteToMemory(); //write new loan into memory

                selectedBook->SetAvailable(false); //set book to unavailable

                LibSystems::RewriteBooks(books); //write changes into files

                for (int i = 0; i  < 5; i++) //write the index of the new loan into the members inventory
                {
                    if (selectedMember->GetLoanedBook(i) == -1)
                    {
                        selectedMember->SetLoanedBook(i, newloan->GetIndex());
                        break;
                    }
                }

                LibSystems::RewriteMembers(members); //write changes of member into file

                ui->bcountLabel->setText(QString::number(selectedMember->GetLoanedCount())); //update some data displays to reflect changes
                ui->pushButton->setStyleSheet("QPushButton { background-color: #e88484; } QPushButton::hover { background-color: #a86060; }");
                ui->pushButton->setText("Unavailable");

                LibMessageBoxes::InformationMessageBox("Success", "The book will be due on " + newloan->GetDueDate().toString()); //send success message
            }
            else
            {
                LibMessageBoxes::ErrorMessageBox("Error", "The member has the maximum number of books currently checked out"); //send failure mesage
            }
        }
        else
        {
            LibMessageBoxes::ErrorMessageBox("Error", "This book is currently unavailable"); //send failure message
        }
    }
    else
    {
        LibMessageBoxes::ErrorMessageBox("Error", "Book / Member not set"); //send failure message
    }
}

void CustomCheckoutBooks::on_memberEdit_editingFinished()
{
    if (ui->memberEdit->text().size() > 0) //if the user has entered text
    {
        LibSystems::Member *current = members->Next(); // search through members to find one that fits with the search
        QString search = ui->memberEdit->text().toLower();
        for (int i = 0; i < LibSystems::Member::Count(); i++)
        {
            if (current->GetFullName().toLower().contains(search)) //once member that fits has been found
            {
                selectedMember = current; //set selected member variable

                ui->nameLabel->setText(selectedMember->GetFullName()); //display varaibles of selected member, so the user knows what they selected
                ui->indexLabel->setText(QString::number(selectedMember->GetIndex()));
                ui->bcountLabel->setText(QString::number(selectedMember->GetLoanedCount()));
                ui->oCountLabel->setText(QString::number(selectedMember->GetOverdueCount(loans)));
                break;
            }
            current = current->Next();
        }
    }
    else //if user hasnt entered text
    {
        selectedMember = members; //deselect any member, and update widget text to reflect this

        ui->nameLabel->setText("---");
        ui->indexLabel->setText("---");
        ui->bcountLabel->setText("---");
        ui->oCountLabel->setText("---");
    }
}

void CustomCheckoutBooks::on_bookEdit_editingFinished()
{
    if (ui->bookEdit->text().size() > 0) //same as above but for books. i wont comment all this
    {
        LibSystems::Book *current = books->Next();
        QString search = ui->bookEdit->text().toLower();
        for (int i = 0; i < LibSystems::Book::Count(); i++)
        {
            if (current->GetTitle().toLower().contains(search) || search == current->GetISBN())
            {
                selectedBook = current;

                for (int o = i; o < LibSystems::Book::Count(); o++) //ensures that there are no exact matches that are being ignored because of a casual match earlier in the list
                {
                    if (current->GetTitle().toLower() == search)
                    {
                        selectedBook = current;
                        break;
                    }
                    current = current->Next();
                }

                ui->titleLabel->setText(selectedBook->GetTitle());
                ui->genreLabel->setText(selectedBook->GetGenre());
                ui->isbnLabel->setText(selectedBook->GetISBN());
                ui->authorLabel->setText(selectedBook->GetAuthor());

                if (!selectedBook->IsAvailable()) //update the button to allow admin to see if book is available before attempting to check it out
                {
                    ui->pushButton->setStyleSheet("QPushButton { background-color: #e88484; } QPushButton::hover { background-color: #a86060; }");
                    ui->pushButton->setText("Unavailable");
                }
                else
                {
                    ui->pushButton->setStyleSheet("QPushButton {background-color: #5A98D1; } QPushButton::hover { background-color: #38588c; }");
                    ui->pushButton->setText("Confirm");
                }

                break;
            }
            current = current->Next();
        }
    }
    else
    {
        selectedBook = books;

        ui->titleLabel->setText("---");
        ui->genreLabel->setText("---");
        ui->isbnLabel->setText("---");
        ui->authorLabel->setText("---");
    }
}

