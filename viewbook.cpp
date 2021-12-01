#include "viewbook.h"
#include "ui_viewbook.h"
#include "messageboxes.h"
#include <QGraphicsDropShadowEffect>

ViewBook::ViewBook(LibSystems::Book *b, LibSystems::Account *u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewBook)
{
    ui->setupUi(this);

    book = b;
    user = u;

    QPixmap cover;
    cover.load(book->GetCoverPath());
    ui->coverLabel->setIcon(cover);
    ui->coverLabel->setIconSize(ui->coverLabel->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->coverLabel->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(book->GetTitle()); ui->authorLabel->setText(book->GetAuthor()); ui->pgLabel->setText(QString::number(book->GetPageCount()) + " pages");
    ui->genreLabel->setText(book->GetGenre()); ui->ddLabel->setText(QString::number(book->GetDeweyDecimal())); ui->isbnLabel->setText(book->GetISBN()); ui->blurbLabel->setText(book->GetBlurb());
    ui->publishdateLabel->setText(QString::number(book->GetReleaseDate().day()) + "/" + QString::number(book->GetReleaseDate().month()) + "/" + QString::number(book->GetReleaseDate().year()));

    this->setStyleSheet
            (
                "QLabel { border-width: 1px; border-style: solid; border-radius: 20px; border-color: #636363; padding-left: 5px; font: 11pt 'Roboto Regular'; }"
                "QLabel#coverLabel { border-width: 0px; }"
                "QLabel#blurbLabel { border-radius: 10px; }"
                "QLabel#availableLabel { background-color: " + (book->IsAvailable() ? QString("#84e89f") : QString("#e88484")) + "  }"
                "QPushButton { background-color: #5A98D1; border-radius: 20px; } QPushButton#coverLabel { background-color: rgba(0,0,0,0); }"
                "QPushButton::hover { background-color: #38588c; } QPushButton#coverLabel::hover { background-color: rgba(0,0,0,0); }"
             );
    ui->labels->setStyleSheet("QLabel { border-width: 0px; color: #5A98D1; }");

    if (book->IsAvailable())
    {
        connect (ui->prebookButton, &QPushButton::clicked, this, &ViewBook::ReserveBook);
    }
    else
    {
        ui->prebookButton->setText("Request");
        ui->availableLabel->setText("Not Available");
    }
}

void ViewBook::ReserveBook()
{
    QFile reservations("databases/reservations.csv");

    if (!reservations.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
    {
        LibMessageBoxes::ErrorMessageBox("Error", "The program failed to reserve this book for you");
        return;
    }

    QTextStream out(&reservations);

    out << user->GetIndex() << "," << book->GetIndex() << "\n";

    reservations.flush();
    reservations.close();

    book->SetAvailable(false);

    while (book->Prev() != nullptr)
    {
        book = book->Prev();
    }

    LibSystems::RewriteBooks(book);

    LibMessageBoxes::InformationMessageBox("Success", "Your reservation has been made. Please come to the library in person to collect your book, and bring your card.");

    emit Finish();
}

ViewBook::~ViewBook()
{
    delete ui;
}
