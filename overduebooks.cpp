#include "overduebooks.h"
#include "ui_overduebooks.h"
#include <QGraphicsDropShadowEffect>

OverdueBooks::OverdueBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverdueBooks)
{
    ui->setupUi(this);

    member = m;

    QPixmap c;
    c.load(b->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(b->GetTitle());
    ui->authorLabel->setText(b->GetAuthor());
    ui->genreLabel->setText(b->GetGenre());
    ui->isbnLabel->setText(b->GetISBN());
    ui->dueLabel->setText("Due date: " + l->GetDueDate().toString(Qt::DateFormat::ISODate));

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton::hover { background-color: rgba(0,0,0,0); }"
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#cover { background-color: rgba(0,0,0,0); }"
            );

    ui->overdueButton->setStyleSheet("QPushButton { background-color: #5A98D1; } QPushButton::hover { background-color: #38588c; }");
    connect(ui->overdueButton, &QPushButton::clicked, this, &OverdueBooks::EmitMember);
}

OverdueBooks::OverdueBooks(LibSystems::Book *b, LibSystems::Account *a, LibSystems::LoanedBook *l, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverdueBooks)
{
    ui->setupUi(this);

    QPixmap c;
    c.load(b->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(b->GetTitle());
    ui->authorLabel->setText(b->GetAuthor());
    ui->genreLabel->setText(b->GetGenre());
    ui->isbnLabel->setText(b->GetISBN());
    ui->dueLabel->setText("Due date: " + l->GetDueDate().toString(Qt::DateFormat::ISODate));

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton::hover { background-color: rgba(0,0,0,0); }"
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#cover { background-color: rgba(0,0,0,0); }"
            );

    ui->overdueButton->setStyleSheet("QPushButton { background-color: #ff8f87; border-width: 1px; border-color: #e88484; }");
    ui->overdueButton->setText("Overdue");
}
OverdueBooks::OverdueBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, int time, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverdueBooks)
{
    ui->setupUi(this);

    member = m;

    QPixmap c;
    c.load(b->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(b->GetTitle());
    ui->authorLabel->setText(b->GetAuthor());
    ui->genreLabel->setText(b->GetGenre());
    ui->isbnLabel->setText(b->GetISBN());
    ui->dueLabel->setText("Due date: " + l->GetDueDate().toString(Qt::DateFormat::ISODate));

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton::hover { background-color: rgba(0,0,0,0); }"
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#cover { background-color: rgba(0,0,0,0); }"
            );

    ui->overdueButton->setStyleSheet("QPushButton { background-color: #ff8f87; border-width: 1px; border-color: #a86060; }"
                                        "QPushButton::hover { background-color: #a86060; border-width: 1px; border-color: #e88484; }");
    ui->overdueButton->setText("Days left: " + QString::number(time));
    connect(ui->overdueButton, &QPushButton::clicked, this, &OverdueBooks::EmitMember);
}

OverdueBooks::OverdueBooks(LibSystems::Book *b, LibSystems::Account *a, LibSystems::LoanedBook *l, int time, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OverdueBooks)
{
    ui->setupUi(this);

    QPixmap c;
    c.load(b->GetCoverPath());
    ui->cover->setIcon(QIcon(c));
    ui->cover->setIconSize(ui->cover->size());
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 4);
    dropShadow->setColor(QColor::fromRgb(200, 200, 200));
    dropShadow->setBlurRadius(20);
    ui->cover->setGraphicsEffect(dropShadow);

    ui->titleLabel->setText(b->GetTitle());
    ui->authorLabel->setText(b->GetAuthor());
    ui->genreLabel->setText(b->GetGenre());
    ui->isbnLabel->setText(b->GetISBN());
    ui->dueLabel->setText("Due date: " + l->GetDueDate().toString(Qt::DateFormat::ISODate));

    this->setStyleSheet
            (
                "QLabel { font: 12pt 'Roboto Regular'; }"
                "QPushButton::hover { background-color: rgba(0,0,0,0); }"
                "QHBoxLayout { border-width: 1px; border-style: solid; border-radius: 5px; }"
                "QPushButton#cover::hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#cover { background-color: rgba(0,0,0,0); }"
            );

    ui->overdueButton->setStyleSheet("QPushButton { background-color: #ff8f87; border-width: 1px; border-color: #a86060; }");
    ui->overdueButton->setText("Days left: " + QString::number(time));
}

void OverdueBooks::EmitMember()
{
    emit DisplayMember(member);
}

OverdueBooks::~OverdueBooks()
{
    delete ui;
}
