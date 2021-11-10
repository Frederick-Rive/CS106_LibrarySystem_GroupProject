#include "bookdisplay.h"
#include "ui_bookdisplay.h"

BookDisplay::BookDisplay(QWidget *parent, LibSystems::Book *book) :
    QWidget(parent),
    ui(new Ui::BookDisplay)
{
    ui->setupUi(this);

    if (book != nullptr)
    {
        ui->cover->setPixmap(book->GetCover().scaled(ui->cover->size()));
        ui->title->setText(book->GetTitle());
        ui->author->setText(book->GetAuthor());
        ui->genre->setText(book->GetGenre());
    }
    else
    {
        QPixmap defaultCover;
        defaultCover.load(":/resources/images/defaultbookcover.jpg");
        ui->cover->setPixmap(defaultCover.scaled(ui->cover->size()));
        ui->title->setText("---");
        ui->author->setText("---");
        ui->genre->setText("---");
    }
}

BookDisplay::~BookDisplay()
{
    delete ui;
}
