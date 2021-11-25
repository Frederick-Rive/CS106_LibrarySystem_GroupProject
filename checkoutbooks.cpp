#include "checkoutbooks.h"
#include "ui_checkoutbooks.h"
#include <QGraphicsDropShadowEffect>

CheckoutBooks::CheckoutBooks(int i, LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CheckoutBooks)
{
    ui->setupUi(this);

    index = i;
    book = b;
    member = m;
    loans = l;

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton#confirmButton { background-color: #5A98D1; }"
                "QPushButton#confirmButton::hover { background-color: #38588c; }"
                "QPushButton#dismissButton { background-color: #e88484; }"
                "QPushButton#dismissButton::hover { background-color: #a86060; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
            );

    ui->titleLabel->setText(book->GetTitle()); ui->authorLabel->setText(book->GetAuthor()); ui->isbnLabel->setText(book->GetISBN()); ui->genreLabel->setText(book->GetGenre());
    ui->indexLabel->setText(QString::number(member->GetIndex())); ui->nameLabel->setText(member->GetFullName()); ui->bcountLabel->setText(QString::number(member->GetLoanedCount())); ui->oCountLabel->setText(QString::number(member->GetOverdueCount(loans)));

    QPixmap c;
    c.load(book->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);
}

CheckoutBooks::~CheckoutBooks()
{
    delete ui;
}

void CheckoutBooks::on_confirmButton_clicked()
{
    if (member->GetLoanedCount() < 5)
    {
        LibSystems::LoanedBook *last = (loans->Count() > 0) ? loans->Next(LibSystems::LoanedBook::Count() - 1) : loans;
        LibSystems::LoanedBook *newloan = new LibSystems::LoanedBook(LibSystems::LoanedBook::Count(), book->GetIndex(), member->GetIndex(), QDate::currentDate().addDays(14), last);
        last->SetNext(newloan);
        newloan->WriteToMemory();

        for (int i = 0; i  < 5; i++)
        {
            if (member->GetLoanedBook(i) == -1)
            {
                member->SetLoanedBook(i, newloan->GetIndex());
                qDebug().nospace() << "aaa";
                break;
            }
        }

        while (member->Prev() != nullptr)
        {
            member = member->Prev();
        }

        QFile memberFile("databases/members.csv");
        if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
        {
            QtHelpers::ErrorMessageBox("Error", "There was an error saving this data");
            return;
        }
        memberFile.flush();
        memberFile.close();

        while (member != nullptr)
        {
            member->WriteToMemory();
            member = member->Next();
        }

        QtHelpers::InformationMessageBox("Checkout confirmed", "The book will be due on " + newloan->GetDueDate().toString());
        emit Remove(index);
    }
    else
    {
        QtHelpers::ErrorMessageBox("Error", "The member's current inventory is too large to give them a new book. They will need to return at least one book first.");
        return;
    }
}

void CheckoutBooks::on_dismissButton_clicked()
{
    QtHelpers::InformationMessageBox("Checkout rejected", "hehe");

    book->SetAvailable(true);

    while (book->Prev() != nullptr)
    {
        book = book->Prev();
    }

    QFile bookFile("databases/books.csv");
    if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QtHelpers::ErrorMessageBox("Error", "There was an error writing these changes");
        return;
    }
    bookFile.flush();
    bookFile.close();

    while (book != nullptr)
    {
        book->WriteToMemory();
        book = book->Next();
    }

    emit Remove(index);
}

