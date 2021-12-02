#include "returnbooks.h"
#include "ui_returnbooks.h"
#include "messageboxes.h"
#include <QGraphicsDropShadowEffect>

ReturnBooks::ReturnBooks(LibSystems::LoanedBook *l, LibSystems::Book *b, LibSystems::Member *m, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReturnBooks)
{
    ui->setupUi(this);

    books = b;
    members = m;
    loan = l;

    LibSystems::Book *thisBook = loan->GetBook(books);

    QPixmap c;
    c.load(thisBook->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(thisBook->GetTitle());
    ui->authorLabel->setText(thisBook->GetAuthor());
    ui->genreLabel->setText(thisBook->GetGenre());
    ui->isbnLabel->setText(thisBook->GetISBN());
    ui->dueLabel->setText("Due date: " + loan->GetDueDate().toString(Qt::DateFormat::ISODate));

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton::hover { background-color: rgba(0,0,0,0); }"
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#cover { background-color: rgba(0,0,0,0); }"
                "QPushButton { background-color: #5A98D1; }"
                "QPushButton::hover { background-color: #38588c; }"
            );

    QPushButton *notReturned = new QPushButton(this);
    notReturned->setText("Not Returned");
    notReturned->setStyleSheet("QPushButton { background-color: #a86060; border-width: 1px; border-color: #e88484; }");
    notReturned->setMinimumSize(150, 30);
    ui->outputLayout->addWidget(notReturned);

    connect(ui->returnButton, &QPushButton::clicked, this, &ReturnBooks::ReturnBook);
    connect(notReturned, &QPushButton::clicked, this, &ReturnBooks::FlagNotReturned);
}

ReturnBooks::ReturnBooks(LibSystems::LoanedBook *l, LibSystems::Book *b, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReturnBooks)
{
    ui->setupUi(this);

    books = b;
    loan = l;

    LibSystems::Book *thisBook = loan->GetBook(books);

    QPixmap c;
    c.load(thisBook->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(thisBook->GetTitle());
    ui->authorLabel->setText(thisBook->GetAuthor());
    ui->genreLabel->setText(thisBook->GetGenre());
    ui->isbnLabel->setText(thisBook->GetISBN());
    ui->dueLabel->setText("Due date: " + loan->GetDueDate().toString(Qt::DateFormat::ISODate));

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton::hover { background-color: rgba(0,0,0,0); }"
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#cover { background-color: rgba(0,0,0,0); }"
                "QPushButton { background-color: #5A98D1; }"
                "QPushButton::hover { background-color: #38588c; }"
            );

    connect(ui->returnButton, &QPushButton::clicked, this, &ReturnBooks::FlagReturned);
}

ReturnBooks::~ReturnBooks()
{
    delete ui;
}

void ReturnBooks::ReturnBook ()
{
    LibSystems::Book *thisBook = loan->GetBook(books);
    LibSystems::Member *thisMember = loan->GetMember(members);

    thisBook->SetAvailable(true);

    LibSystems::RewriteBooks(books);

    for (int i = 0; i  < 5; i++)
    {
        if (thisMember->GetLoanedBook(i) == loan->GetIndex())
        {
            thisMember->ReturnBook(i);
            break;
        }
    }

    LibSystems::RewriteMembers(members);

    LibSystems::RemoveLoan(loan->GetIndex());

    loan->Prev()->SetNext(loan->Next());
    if (loan->Next() != nullptr) { loan->Next()->SetPrev(loan->Prev()); }
    delete loan;

    LibMessageBoxes::InformationMessageBox("Success", "Your book has been returned");

    emit Finish();
}

void ReturnBooks::FlagNotReturned ()
{
    loan->SetReturned(false);

    while (loan->Prev() != nullptr)
    {
        loan = loan->Prev();
    }

    LibSystems::RewriteLoans(loan);

    LibMessageBoxes::InformationMessageBox("Success", "A message has been sent to the book holder");

    emit Finish();
}

void ReturnBooks::FlagReturned ()
{
    loan->SetReturned(true);

    while (loan->Prev() != nullptr)
    {
        loan = loan->Prev();
    }

    LibSystems::RewriteLoans(loan);

    LibMessageBoxes::InformationMessageBox("Success", "An administrator will process your book, and remove the loan from your account");

    emit Finish();
}

