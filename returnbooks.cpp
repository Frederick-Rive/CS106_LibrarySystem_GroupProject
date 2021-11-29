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
}

ReturnBooks::~ReturnBooks()
{
    delete ui;
}

void ReturnBook ()
{
    LibSystems::Book *thisBook = loan->GetBook(books);
    LibSystems::Member *thisMember = loan->GetMember(members);

    thisBook->SetAvailable(true);

    QFile bookFile("databases/books.csv");
    if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        LibMessageBoxes::ErrorMessageBox("Error", "There was an error writing these changes");
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
        if (thisMember->GetLoanedBook(i) == loan->GetIndex())
        {
            thisMember->ReturnBook(i);
            break;
        }
    }

    QFile memberFile("databases/members.csv");
    if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        LibMessageBoxes::ErrorMessageBox("Error", "There was an error saving this data");
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

    QFile loanFile("databases/loans.csv");
    if (!loanFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        LibMessageBoxes::ErrorMessageBox("Error", "There was an error saving this data");
        return;
    }

    QTextStream in(&loanFile);
    std::vector<QString> loanVec;
    int index = 0;

    while (!in.atEnd())
    {
        if (index == loan->GetIndex())
        {
            in.readLine();
            index++;
            continue;
        }
        loanVec.push_back(in.readLine());
        index++;
    }

    loanFile.close();
    if (!loanFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        LibMessageBoxes::ErrorMessageBox("Error", "There was an error saving this data");
        return;
    }

    QTextStream out(&loanFile);

    for (QString l : loanVec)
    {
        out << l << "\n";
    }

    loanFile.flush();
    loanFile.close();

    LibMessageBoxes::InformationMessageBox("Success", "Your book has been returned");

    emit Finish();
}

void FlagReturned ()
{

}

