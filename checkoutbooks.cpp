#include "checkoutbooks.h"
#include "ui_checkoutbooks.h"
#include "messageboxes.h"
#include <QGraphicsDropShadowEffect>

CheckoutBooks::CheckoutBooks(int i, LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckoutBooks) //constructor
{
    ui->setupUi(this);

    index = i; //initialize data members
    book = b;
    member = m;
    loans = l;

    this->setStyleSheet //set the style sheets for this widget
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton#confirmButton { background-color: #5A98D1; }"
                "QPushButton#confirmButton::hover { background-color: #38588c; }"
                "QPushButton#dismissButton { background-color: #e88484; }"
                "QPushButton#dismissButton::hover { background-color: #a86060; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
            );

    //set widget text
    ui->titleLabel->setText(book->GetTitle()); ui->authorLabel->setText(book->GetAuthor()); ui->isbnLabel->setText(book->GetISBN()); ui->genreLabel->setText(book->GetGenre());
    ui->indexLabel->setText(QString::number(member->GetIndex())); ui->nameLabel->setText(member->GetFullName()); ui->bcountLabel->setText(QString::number(member->GetLoanedCount())); ui->oCountLabel->setText(QString::number(member->GetOverdueCount(loans)));

    QPixmap c; //get cover image from cover path
    c.load(book->GetCoverPath());
    ui->cover->setIcon(QIcon(c)); //display image
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this); //give cover a drop shadow
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);
}

CheckoutBooks::~CheckoutBooks() //destructor
{
    delete ui;
}

void CheckoutBooks::on_confirmButton_clicked()
{
    if (member->GetLoanedCount() < 5) //ensure that the member hasn't hit the max number of books they are allowed
    {
        LibSystems::LoanedBook *last = (loans->Count() > 0) ? loans->Next(LibSystems::LoanedBook::Count() - 1) : loans; //declare loan pointer to last node in loan linked list
        LibSystems::LoanedBook *newloan = new LibSystems::LoanedBook(book->GetIndex(), member->GetIndex(), QDate::currentDate().addDays(14), last); //create a new loan with the member/book, give
        last->SetNext(newloan); //link new loan into the linked list
        newloan->WriteToMemory(); //write new loan to memory

        for (int i = 0; i  < 5; i++) //save index of loan to the member
        {
            if (member->GetLoanedBook(i) == -1)
            {
                member->SetLoanedBook(i, newloan->GetIndex());
                break;
            }
        }

        //book is already considered unavailable because it is reserved. dont need to do anything to it

        while (member->Prev() != nullptr) //get head node of member linked list
        {
            member = member->Prev();
        }

        LibSystems::RewriteMembers(member); //rewrite members

        LibMessageBoxes::InformationMessageBox("Checkout confirmed", "The book will be due on " + newloan->GetDueDate().toString()); //send success message
        emit Remove(index); //remove this reservation
    }
    else
    {
        LibMessageBoxes::ErrorMessageBox("Error", "The member's current inventory is too large to give them a new book. They will need to return at least one book first."); //send error message
        return;
    }
}

void CheckoutBooks::on_dismissButton_clicked()
{
    book->SetAvailable(true); //set book as available

    while (book->Prev() != nullptr) //get head node of book linked list
    {
        book = book->Prev();
    }

    LibSystems::RewriteBooks(book); //rewrite the books

    LibMessageBoxes::InformationMessageBox("Checkout rejected", "The book is available to anyone again"); //send success message

    emit Remove(index); //remove this reservation
}

