#include "bookdisplay.h"
#include "ui_bookdisplay.h"
#include <QGraphicsDropShadowEffect>
#include <adminwindow.h>

BookDisplay::BookDisplay(QWidget *parent, LibSystems::Book *b) :
    QWidget(parent),
    ui(new Ui::BookDisplay) //constructor
{
    ui->setupUi(this);

    book = b; //initialize data member

    if (book != nullptr) //display variables from books on widgets
    {
        QPixmap cover;
        cover.load(book->GetCoverPath());
        ui->cover->setIcon(QIcon(cover));
        ui->cover->setIconSize(ui->cover->size());
        ui->title->setText("Title: " + book->GetTitle());
        ui->author->setText("Author: " + book->GetAuthor());
        ui->genre->setText("Genre: " + book->GetGenre());
    }
    else //default book
    {
        QPixmap defaultCover;
        defaultCover.load(":/resources/images/defaultbookcover.jpg");
        ui->cover->setIcon(QIcon(defaultCover));
        ui->cover->setIconSize(ui->cover->size());
        ui->title->setText("---");
        ui->author->setText("---");
        ui->genre->setText("---");
    }

    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this); //make drop shadow, attatch to cover
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->title->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';"); //stylesheets are a bit messy, i have to set each labels' individually
    ui->author->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
    ui->genre->setStyleSheet("color: rgba(0,0,0,0); font: 10pt 'Roboto Regular';");
    ui->cover->setStyleSheet("background-color: rgba(0,0,0,0);");

    this->setMouseTracking(true); //some funky stuff to allow me to call a function when the mouse hovers over a button
    ui->cover->setAttribute(Qt::WA_Hover); //https://doc.qt.io/qt-5/eventsandfilters.html
    ui->cover->installEventFilter(this);

    connect(ui->cover, SIGNAL(clicked()), this, SLOT(SendBook())); //sendbook function sends a signal with the book being displayed inside. it is sent when the cover is clicked
}

BookDisplay::~BookDisplay() //destructor
{
    delete ui;
}

bool BookDisplay::eventFilter(QObject *obj, QEvent *event) //called whenever an event takes place on a widget (probably a bit wasteful? not sure)
{
    if (obj == (QObject*)ui->cover) //if event is happening to the book cover
    {
        if (event->type() == QEvent::Enter) //if the event is the mouse entering the cover, update the css of the labels to display the text
        {
            ui->title->setStyleSheet("color: black; font: 10pt 'Roboto Regular';");
            ui->author->setStyleSheet("color: black; font: 10pt 'Roboto Regular';");
            ui->genre->setStyleSheet("color: black; font: 10pt 'Roboto Regular';");
            ui->cover->setStyleSheet("background-color: rgba(100,100,100,20);");
        }
        else if (event->type() == QEvent::Leave) //if the event is the mouse leaving the cover, update the css of the labels to hide the text
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

void BookDisplay::SendBook() //emit the booksignal to be recieved by the admin window / member window
{
    emit BookSignal(book);
}


