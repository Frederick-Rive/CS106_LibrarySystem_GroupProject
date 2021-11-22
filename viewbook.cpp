#include "viewbook.h"
#include "ui_viewbook.h"

ViewBook::ViewBook(LibSystems::Book *b, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewBook)
{
    ui->setupUi(this);

    book = b;

    QPixmap cover;
    cover.load(book->GetCoverPath());
    ui->coverLabel->setPixmap(cover.scaled(ui->coverLabel->size()));
    ui->titleLabel->setText("Title: " + book->GetTitle()); ui->authorLabel->setText("Author: " + book->GetAuthor()); ui->pgLabel->setText(QString::number(book->GetPageCount()) + " pages");
    ui->genreLabel->setText("Genre: " + book->GetGenre()); ui->ddLabel->setText("Dewey Decimal Number: " + QString::number(book->GetDeweyDecimal())); ui->isbnLabel->setText("ISBN: " + book->GetISBN()); ui->blurbLabel->setText("Description: " + book->GetBlurb());
    ui->publishdateLabel->setText("Publishing Date: " + QString::number(book->GetReleaseDate().day()) + "/" + QString::number(book->GetReleaseDate().month()) + "/" + QString::number(book->GetReleaseDate().year()));

    this->setStyleSheet
            (
                "QLabel { border-width: 1px; border-style: solid; border-radius: 20px; border-color: #636363; padding-left: 5px; font: 11pt 'Roboto Regular'; }"
                "QLabel#coverLabel { border-width: 0px; }"
                "QLabel#availableLabel { background-color: " + (book->IsAvailable() ? QString("#84e89f") : QString("#e88484")) + "  }"
                "QPushButton { background-color: #6895e8; border-radius: 20px; }"
                "QPushButton::hover { background-color: #38588c; }"
             );
}

ViewBook::~ViewBook()
{
    delete ui;
}
