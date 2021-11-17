#include "memberwindow.h"
#include <login.h>
#include "ui_memberwindow.h"
#include "bookdisplay.h"
#include <QGraphicsDropShadowEffect>
#include <QDesktopServices>
#include <QLineEdit>

MemberWindow::MemberWindow(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, LibSystems::Account *a, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MemberWindow)
{
    ui->setupUi(this);

    books = b;
    members = m;
    loans = l;
    user = *a;

    this->setStyleSheet
            (
                "QWidget#header { background: qlineargradient(x1:0, y1:0, x2:1, y2:0.3, stop:0 #4d7fc9, stop: 0.4 #5687d1 stop:1 #88b5f8) }"
                "QPushButton { font: 12pt 'Roboto Regular'; }"
                "QPushButton#logout_button { border: 1px; border-color: #FFFFFF; border-style: solid; }"
                "QPushButton#facebookButton:hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#twitterButton:hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#instaButton:hover { background-color: rgba(0,0,0,0); }"
                "QLabel#followus { color: #6895e8; }"
            );

    this->setWindowTitle("Wellington Central Library");

    QPixmap logo (":/resources/images/wcl_logo_wide_white.png");
    ui->logolabel->setPixmap(logo.scaled(ui->logolabel->size()));

    QPixmap pixmap;
    pixmap.load(":/resources/images/background.png");
    ui->background->setPixmap(pixmap.scaled(1280, 730));
    activeElement = ui->background;
    auxWidget = new QWidget;

    QPixmap facebookImg, twitterImg, instaImg;
    facebookImg.load(":/resources/images/facebooklogo.png"); twitterImg.load(":/resources/images/twitterlogo.png"); instaImg.load(":/resources/images/instalogo.png");
    QIcon facebookIcon(facebookImg), twitterIcon(twitterImg), instaIcon(instaImg);
    ui->facebookButton->setIcon(facebookIcon); ui->twitterButton->setIcon(twitterIcon); ui->instaButton->setIcon(instaIcon);
    ui->facebookButton->setIconSize(ui->facebookButton->size()); ui->twitterButton->setIconSize(ui->twitterButton->size()); ui->instaButton->setIconSize(ui->instaButton->size());
}

MemberWindow::~MemberWindow()
{
    delete ui;
}

void MemberWindow::on_viewbooks_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->viewbooks_button);

    auxWidget = new QWidget(this);
    QLineEdit *searchEdit = new QLineEdit(auxWidget);
    connect(searchEdit, &QLineEdit::returnPressed, this, &MemberWindow::DisplayBooks);
    auxWidget->setStyleSheet("font: 12pt 'Roboto Regular'; padding-top: 10px;");
    searchEdit->setStyleSheet("padding: 5px; border-radius: 10px;");
    auxWidget->setMinimumSize(400, 30);
    searchEdit->setMinimumSize(400, 15);
    ui->activeLayout->addWidget(auxWidget, 0, 1, Qt::AlignHCenter | Qt::AlignBottom);

    DisplayBooks();
}

void MemberWindow::DisplayBooks()
{
    if (LibSystems::Book::Count() > 0)
    {
        delete activeElement;
        delete qScroll;

        activeElement = new QWidget;

        QLineEdit *searchEdit = qobject_cast<QLineEdit*>(auxWidget->children()[0]);
        QString search = searchEdit->text().toLower();

        QGridLayout *qGrid = new QGridLayout(activeElement);

        int row = 0;
        int column = 1;
        LibSystems::Book *displayBook = books->Next();

        QWidget *spacer = new QWidget(activeElement);
        spacer->setMinimumSize(75, 0);
        qGrid->addWidget(spacer, 0, 0);

        for (int index = 0; index < LibSystems::Book::Count(); index++)
        {
            if (search == "" || (displayBook->GetTitle().toLower().contains(search) || displayBook->GetAuthor().toLower().contains(search) || displayBook->GetGenre().toLower().contains(search) ||  displayBook->GetBlurb().toLower().contains(search)))
            {
                BookDisplay *display = new BookDisplay(activeElement, displayBook);

                qGrid->addWidget(display, row, column);
                column++;

                //connect(display, &BookDisplay::Edit, this, &MainWindow::EditBook);
                if (column == 6)
                {
                    row += 1;
                    column = 1;
                    QWidget *spacer = new QWidget(activeElement);
                    spacer->setMinimumSize(75, 0);
                    qGrid->addWidget(spacer, row, 0);
                }
            }

            displayBook = displayBook->Next();
        }

        if (column < 6 && column > 1)
        {
            for (column; column < 6; column++)
            {
                BookDisplay *display = new BookDisplay(activeElement);
                qGrid->addWidget(display, row, column);
            }
        }

        qScroll = new QScrollArea(this);
        qScroll->setWidget(activeElement);
        qScroll->setMinimumSize(970, 450);
        qScroll->setMaximumSize(1150, 450);
        ui->activeLayout->addWidget(qScroll, 1, 1);
    }
}

void MemberWindow::on_logout_button_clicked()
{
    user = LibSystems::Account();
    login *log = new login(nullptr);
    log->show();
    hide();
}

void MemberWindow::on_facebookButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.facebook.com/wellingtoncitylibraries")));
}

void MemberWindow::on_twitterButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://twitter.com/wcl_library")));
}

void MemberWindow::on_instaButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.instagram.com/wcl_library/")));
}

void MemberWindow::ClearActiveArea()
{
    delete activeElement;
    delete qScroll;
    delete auxWidget;
    activeElement = new QWidget;
    qScroll = new QScrollArea;
    auxWidget = new QWidget;

    ui->activeSpacer->changeSize(0, 50);
}

void MemberWindow::SetActiveButton(QPushButton *pressed)
{
    if (activeButton != nullptr)
    {
        activeButton->setStyleSheet("");
        activeButton->setGraphicsEffect(0);
    }
    pressed->setStyleSheet("background-color: #FFFFFF; color: #6895e8; ");
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this);
    dropShadow->setOffset(0, 2);
    dropShadow->setColor(QColor::fromRgb(68, 95, 158));
    pressed->setGraphicsEffect(dropShadow);
    activeButton = pressed;
}

