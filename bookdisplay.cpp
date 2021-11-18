#include "bookdisplay.h"
#include "ui_bookdisplay.h"
#include <QGraphicsDropShadowEffect>
#include <adminwindow.h>

BookDisplay::BookDisplay(QWidget *parent, LibSystems::Book *b) :
    QWidget(parent),
    ui(new Ui::BookDisplay)
{
    ui->setupUi(this);

    book = b;

    if (book != nullptr)
    {
        QPixmap cover;
        cover.load(book->GetCoverPath());
        ui->cover->setIcon(QIcon(cover));
        ui->cover->setIconSize(ui->cover->size());
        ui->title->setText("Title: " + book->GetTitle());
        ui->author->setText("Author: " + book->GetAuthor());
        ui->genre->setText("Genre: " + book->GetGenre());

        QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
        dropShadow->setOffset(0, 4);
        dropShadow->setColor(QColor::fromRgb(200, 200, 200));
        dropShadow->setBlurRadius(20);
        ui->cover->setGraphicsEffect(dropShadow);
    }
    else
    {
        QPixmap defaultCover;
        defaultCover.load(":/resources/images/defaultbookcover.jpg");
        ui->cover->setIcon(QIcon(defaultCover));
        ui->cover->setIconSize(ui->cover->size());
        ui->title->setText("---");
        ui->author->setText("---");
        ui->genre->setText("---");

        QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
        dropShadow->setOffset(0, 4);
        dropShadow->setColor(QColor::fromRgb(200, 200, 200));
        dropShadow->setBlurRadius(20);
        ui->cover->setGraphicsEffect(dropShadow);
    }

    ui->title->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
    ui->author->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
    ui->genre->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
    ui->cover->setStyleSheet("background-color: rgba(0,0,0,0);");

    this->setMouseTracking(true);
    ui->cover->setAttribute(Qt::WA_Hover);
    ui->cover->installEventFilter(this);

    connect(ui->cover, SIGNAL(clicked()), this, SLOT(SendBook()));
}

BookDisplay::~BookDisplay()
{
    delete ui;
}

bool BookDisplay::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == (QObject*)ui->cover)
    {
        if (event->type() == QEvent::Enter)
        {
            ui->title->setStyleSheet("color: black; font: 10pt 'Roboto Regular';");
            ui->author->setStyleSheet("color: black; font: 10pt 'Roboto Regular';");
            ui->genre->setStyleSheet("color: black; font: 10pt 'Roboto Regular';");
            ui->cover->setStyleSheet("background-color: rgba(100,100,100,20);");
        }
        else if (event->type() == QEvent::Leave)
        {
            ui->title->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
            ui->author->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
            ui->genre->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
            ui->cover->setStyleSheet("background-color: rgba(0,0,0,0);");
        }
        return QWidget::eventFilter(obj, event);
    }
    else
    {
        return QWidget::eventFilter(obj, event);
    }
}

void BookDisplay::SendBook()
{
    emit BookSignal(book);
}


