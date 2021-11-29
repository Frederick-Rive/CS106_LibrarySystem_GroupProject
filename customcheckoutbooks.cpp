#include "customcheckoutbooks.h"
#include "ui_customcheckoutbooks.h"

CustomCheckoutBooks::CustomCheckoutBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomCheckoutBooks)
{
    ui->setupUi(this);

    books = b;
    members = m;
    loans = l;

    selectedBook = books;
    selectedMember = members;

    this->setStyleSheet
            (
                "font: 12pt 'Roboto Regular';"
            );

    ui->pushButton->setStyleSheet("QPushButton {background-color: #5A98D1; } QPushButton::hover { background-color: #38588c; }");
}

CustomCheckoutBooks::~CustomCheckoutBooks()
{
    delete ui;
}

void CustomCheckoutBooks::on_pushButton_clicked()
{
    if (selectedBook->GetIndex() >= 0 && selectedMember->GetIndex() >= 0)
    {
        if (selectedBook->IsAvailable())
        {
            if (selectedMember->GetLoanedCount() < 5)
            {
                loans = (LibSystems::LoanedBook::Count() > 0) ? loans->Next(LibSystems::LoanedBook::Count() - 1) : loans;

                LibSystems::LoanedBook *newloan = new LibSystems::LoanedBook(LibSystems::LoanedBook::Count(), selectedBook->GetIndex(), selectedMember->GetIndex(), QDate::currentDate().addDays(14), loans);
                loans->SetNext(newloan);
                newloan->WriteToMemory();

                selectedBook->SetAvailable(false);

                QFile bookFile("databases/books.csv");
                if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    QtHelpers::ErrorMessageBox("Error", "There was an error writing these changes");
                    return;
                }
                bookFile.flush();
                bookFile.close();
                books = books->Next();

                while (books != nullptr)
                {
                    books->WriteToMemory();
                    books = books->Next();
                }

                for (int i = 0; i  < 5; i++)
                {
                    if (selectedMember->GetLoanedBook(i) == -1)
                    {
                        selectedMember->SetLoanedBook(i, newloan->GetIndex());
                        break;
                    }
                }

                QFile memberFile("databases/members.csv");
                if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
                {
                    QtHelpers::ErrorMessageBox("Error", "There was an error saving this data");
                    return;
                }
                memberFile.flush();
                memberFile.close();

                members = members->Next();

                while (members != nullptr)
                {
                    members->WriteToMemory();
                    members = members->Next();
                }

                ui->bcountLabel->setText(QString::number(selectedMember->GetLoanedCount()));

                QtHelpers::InformationMessageBox("Success", "The book will be due on " + newloan->GetDueDate().toString());
            }
            else
            {
                QtHelpers::ErrorMessageBox("Error", "The member has the maximum number of books currently checked out");
            }
        }
        else
        {
            QtHelpers::ErrorMessageBox("Error", "This book is currently unavailable");
        }
    }
    else
    {
        QtHelpers::ErrorMessageBox("Error", "Book / Member not set");
    }
}

void CustomCheckoutBooks::on_memberEdit_editingFinished()
{
    if (ui->memberEdit->text().size() > 0)
    {
        LibSystems::Member *current = members->Next();
        QString search = ui->memberEdit->text().toLower();
        for (int i = 0; i < LibSystems::Member::Count(); i++)
        {
            if (current->GetFullName().toLower().contains(search))
            {
                selectedMember = current;

                ui->nameLabel->setText(selectedMember->GetFullName());
                ui->indexLabel->setText(QString::number(selectedMember->GetIndex()));
                ui->bcountLabel->setText(QString::number(selectedMember->GetLoanedCount()));
                ui->oCountLabel->setText(QString::number(selectedMember->GetOverdueCount(loans)));
                break;
            }
            current = current->Next();
        }
    }
    else
    {
        selectedMember = members;

        ui->nameLabel->setText("---");
        ui->indexLabel->setText("---");
        ui->bcountLabel->setText("---");
        ui->oCountLabel->setText("---");
    }
}

void CustomCheckoutBooks::on_bookEdit_editingFinished()
{
    if (ui->bookEdit->text().size() > 0)
    {
        LibSystems::Book *current = books->Next();
        QString search = ui->bookEdit->text().toLower();
        for (int i = 0; i < LibSystems::Book::Count(); i++)
        {
            if (current->GetTitle().toLower().contains(search) || search == current->GetISBN())
            {
                selectedBook = current;

                ui->titleLabel->setText(selectedBook->GetTitle());
                ui->genreLabel->setText(selectedBook->GetGenre());
                ui->isbnLabel->setText(selectedBook->GetISBN());
                ui->authorLabel->setText(selectedBook->GetAuthor());

                if (!selectedBook->IsAvailable())
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

