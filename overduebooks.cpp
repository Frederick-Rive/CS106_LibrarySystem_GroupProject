#include "overduebooks.h"
#include "ui_overduebooks.h"
#include <QGraphicsDropShadowEffect>

OverdueBooks::OverdueBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverdueBooks)
{
    ui->setupUi(this);

    book = b;
    member = m;
    loan = l;

    QPixmap c;
    c.load(book->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(book->GetTitle());
    ui->authorLabel->setText(book->GetAuthor());
    ui->genreLabel->setText(book->GetGenre());

    this->setStyleSheet
            (
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
            );
}

OverdueBooks::~OverdueBooks()
{
    delete ui;
}
