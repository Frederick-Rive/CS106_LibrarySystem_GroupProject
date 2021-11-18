#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "addbook.h"
#include "bookdisplay.h"
#include "addmember.h"
#include "login.h"
#include <librarysystems.h>
#include <QLabel>
#include <QLayout>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include <qlineedit.h>
#include <memberinfo.h>

MainWindow::MainWindow(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, LibSystems::Account *a, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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

    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QPixmap icon;
    icon.load(":/resources/images/taskbarImg.PNG");
    this->setWindowIcon(QIcon(icon));

    this->setWindowTitle("Wellington Central Library");

    QPixmap logo (":/resources/images/wcl_logo_wide_white.png");
    ui->logolabel->setPixmap(logo.scaled(ui->logolabel->size()));

    QPixmap pixmap;
    pixmap.load(":/resources/images/background.png");
    ui->background->setPixmap(pixmap.scaled(1280, 730));
    activeElement = ui->background;
    auxWidget = ui->auxLabel;

    QPixmap facebookImg, twitterImg, instaImg;
    facebookImg.load(":/resources/images/facebooklogo.png"); twitterImg.load(":/resources/images/twitterlogo.png"); instaImg.load(":/resources/images/instalogo.png");
    QIcon facebookIcon(facebookImg), twitterIcon(twitterImg), instaIcon(instaImg);
    ui->facebookButton->setIcon(facebookIcon); ui->twitterButton->setIcon(twitterIcon); ui->instaButton->setIcon(instaIcon);
    ui->facebookButton->setIconSize(ui->facebookButton->size()); ui->twitterButton->setIconSize(ui->twitterButton->size()); ui->instaButton->setIconSize(ui->instaButton->size());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_logout_button_clicked()
{
    user = LibSystems::Account();
    login *log = new login(nullptr, books->Next(), members->Next(), loans->Next());
    log->show();
    hide();
}

void MainWindow::on_addbook_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->addbook_button);

    auxWidget = new QLabel(this);
    QLabel *lab = new QLabel(auxWidget);
    lab->setText("Add a new book");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #6895e8; padding-top: 10px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Book *last = books;

    while (last->Next() != nullptr)
    {
        last = last->Next();
    }
    activeElement = new AddBook(this, last);
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->activeLayout->addWidget(qScroll, 1, 1);
}

void MainWindow::EditBook (LibSystems::Book *book)
{
    ClearActiveArea();

    auxWidget = new QLabel(this);
    QLabel *lab = new QLabel(auxWidget);
    lab->setText("Edit an existing book");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #6895e8; padding-top: 10px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Book *last = books;

    while (last->Next() != nullptr)
    {
        last = last->Next();
    }
    activeElement = new AddBook(this, last, book);
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->activeLayout->addWidget(qScroll, 1, 1);
}

void MainWindow::on_viewbook_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->viewbook_button);

    auxWidget = new QWidget(this);
    QLineEdit *searchEdit = new QLineEdit(auxWidget);
    connect(searchEdit, &QLineEdit::returnPressed, this, &MainWindow::DisplayBooks);
    auxWidget->setStyleSheet("font: 12pt 'Roboto Regular'; padding-top: 10px;");
    searchEdit->setStyleSheet("padding: 5px; border-radius: 10px;");
    auxWidget->setMinimumSize(400, 30);
    searchEdit->setMinimumSize(400, 15);
    ui->activeLayout->addWidget(auxWidget, 0, 1, Qt::AlignHCenter | Qt::AlignBottom);

    DisplayBooks();
}

void MainWindow::DisplayBooks()
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

                connect(display, &BookDisplay::BookSignal, this, &MainWindow::EditBook);
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

void MainWindow::on_addmember_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->addmember_button);

    auxWidget = new QLabel(this);
    QLabel *lab = new QLabel(auxWidget);
    lab->setText("Add a new member");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #6895e8; margin-top: 10px; margin-left: 220px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Member *last = members;
    while(last->Next() != nullptr)
    {
        last = last->Next();
    }

    activeElement = new AddMember(this, last);
    ui->activeLayout->addWidget(activeElement, 1, 1, Qt::AlignHCenter);
}

void MainWindow::on_viewmember_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->viewmember_button);

    auxWidget = new QWidget(this);
    QLineEdit *searchEdit = new QLineEdit(auxWidget);
    connect(searchEdit, &QLineEdit::returnPressed, this, &MainWindow::DisplayMembers);
    auxWidget->setStyleSheet("font: 12pt 'Roboto Regular'; padding-top: 10px;");
    searchEdit->setStyleSheet("padding: 5px; border-radius: 10px;");
    auxWidget->setMinimumSize(400, 30);
    searchEdit->setMinimumSize(400, 15);
    ui->activeLayout->addWidget(auxWidget, 0, 1, Qt::AlignCenter | Qt::AlignBottom);

    DisplayMembers();
}

void MainWindow::DisplayMembers()
{
    if (LibSystems::Member::Count() > 0)
    {
        delete activeElement;
        delete qScroll;
        activeElement = new QWidget(this);

        QLineEdit *searchEdit = qobject_cast<QLineEdit*>(auxWidget->children()[0]);
        QString search = searchEdit->text().toLower();

        QGridLayout *qGrid = new QGridLayout(activeElement);
        qGrid->setSpacing(5);
        LibSystems::Member *thisMember = members->Next();

        //Labels up the top so the data isnt meaningless --------------------------------------------------------------
        QLabel *memberInfo = new QLabel(activeElement);
        QLabel *memberWidgets[6];
        QString memberData[6] = { "Id", "Full name", "Username", "Email", "Contact Number", "Date of birth" };

        QHBoxLayout *hLayout = new QHBoxLayout(memberInfo);

        for (int i = 0; i < 6; i++)
        {
            memberWidgets[i] = new QLabel;
            memberWidgets[i]->setText(memberData[i]);
            if (i > 0)
            {
                memberWidgets[i]->setMinimumSize(200, 25);
            }
            else
            {
                memberWidgets[i]->setMinimumSize(30, 25);

            }
            memberWidgets[i]->setStyleSheet("border-width: 0px;");
            memberWidgets[i]->setAlignment(Qt::AlignHCenter);
            hLayout->addWidget(memberWidgets[i]);
        }
        memberInfo->setMinimumSize(1100, 30);
        memberInfo->setStyleSheet("color: #6895e8; border: 0px;");
        qGrid->addWidget(memberInfo, 0, 0);
        //Labels up the top so the data isnt meaningless --------------------------------------------------------------

        activeElement->setStyleSheet("QPushButton { border-width: 1px; border-style: solid; border-color: black; border-radius: 5px; }"
                                     "QPushButton::hover { background-color: #DDDDDD; }"
                                     "QLabel { font: 12pt 'Roboto Regular'; }");

        for (int i = 0; i < LibSystems::Member::Count(); i++)
        {
            if (search == "" || (thisMember->GetUsername().toLower().contains(search) || thisMember->GetFullName().toLower().contains(search)))
            {
                MemberInfo *memberInfo = new MemberInfo(thisMember, activeElement);
                QLabel *memberWidgets[6];
                QString memberData[6] = {QString::number(thisMember->GetIndex()), thisMember->GetFullName(), thisMember->GetUsername(), thisMember->GetEmail(), thisMember->GetContactNumber(),
                                         (QString::number(thisMember->GetDOB().day()) + "/" + QString::number(thisMember->GetDOB().month()) + "/" + QString::number(thisMember->GetDOB().year()))};

                QHBoxLayout *hLayout = new QHBoxLayout(memberInfo);

                for (int i = 0; i < 6; i++)
                {
                    memberWidgets[i] = new QLabel;
                    memberWidgets[i]->setText(memberData[i]);
                    if (i > 0)
                    {
                        memberWidgets[i]->setMinimumSize(200, 25);
                    }
                    else
                    {
                        memberWidgets[i]->setMinimumSize(30, 25);

                    }
                    memberWidgets[i]->setStyleSheet("border-width: 0px;");
                    memberWidgets[i]->setAlignment(Qt::AlignHCenter);
                    hLayout->addWidget(memberWidgets[i]);
                }

                memberInfo->setMinimumSize(1100, 35);

                connect(memberInfo, &MemberInfo::SendMember, this, &MainWindow::EditMember);

                qGrid->addWidget(memberInfo, i + 1, 0);
            }
            thisMember = thisMember->Next();
        }

        qScroll = new QScrollArea(this);
        qScroll->setWidget(activeElement);
        qScroll->setMinimumSize(1120, 450);
        qScroll->setMaximumSize(1120, 450);

        ui->activeLayout->addWidget(qScroll, 1, 1);
    }
}

void MainWindow::EditMember(LibSystems::Member *member)
{
    ClearActiveArea();

    auxWidget = new QLabel(this);
    QLabel *lab = new QLabel(auxWidget);
    lab->setText("Edit an existing member");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #6895e8; margin-top: 10px; margin-left: 220px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Member *last = members;
    while(last->Next() != nullptr)
    {
        last = last->Next();
    }

    activeElement = new AddMember(this, last, member);
    ui->activeLayout->addWidget(activeElement, 1, 1, Qt::AlignHCenter);
}

void MainWindow::on_overduebooks_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->overduebooks_button);
}

void MainWindow::on_checkoutbooks_button_clicked()
{
    ClearActiveArea();
    SetActiveButton(ui->checkoutbooks_button);
}

void MainWindow::ClearActiveArea()
{
    delete activeElement;
    delete qScroll;
    delete auxWidget;
    activeElement = new QWidget;
    qScroll = new QScrollArea;
    auxWidget = new QWidget;

    ui->activeSpacer->changeSize(0, 50);
}

void MainWindow::SetActiveButton(QPushButton *pressed)
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

void MainWindow::on_facebookButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.facebook.com/wellingtoncitylibraries")));
}

void MainWindow::on_twitterButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://twitter.com/wcl_library")));
}

void MainWindow::on_instaButton_clicked()
{
    QDesktopServices::openUrl(QUrl(QString("https://www.instagram.com/wcl_library/")));
}
