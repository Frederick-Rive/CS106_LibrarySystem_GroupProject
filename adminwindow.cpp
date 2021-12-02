#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "addbook.h"
#include "bookdisplay.h"
#include "addmember.h"
#include "login.h"
#include "memberinfo.h"
#include "checkoutbooks.h"
#include "customcheckoutbooks.h"
#include "overduebooks.h"
#include "viewmember.h"
#include "viewbook.h"
#include "returnbooks.h"
#include "messageboxes.h"
#include <librarysystems.h>
#include <QLabel>
#include <QLayout>
#include <QIcon>
#include <QDesktopServices>
#include <QUrl>
#include <qlineedit.h>

MainWindow::MainWindow(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, LibSystems::Account *a, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) //constructor
{
    ui->setupUi(this);

    books = b; //initialize data members
    members = m;
    loans = l;
    user = *a;

    this->setStyleSheet //set style sheet for admin window
            (
                "QWidget#header { background: qlineargradient(x1:0, y1:0, x2:1, y2:0.3, stop:0 #4d7fc9, stop: 0.4 #5687d1 stop:1 #88b5f8) }"
                "QPushButton { font: 12pt 'Roboto Regular'; }"
                "QPushButton#logout_button { border: 1px; border-color: #FFFFFF; border-style: solid; }"
                "QPushButton#facebookButton:hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#twitterButton:hover { background-color: rgba(0,0,0,0); }"
                "QPushButton#instaButton:hover { background-color: rgba(0,0,0,0); }"
                "QLabel#followus { color: #5A98D1; }"
            );

    //this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QPixmap icon; //set taskbar image
    icon.load(":/resources/images/taskbarImg.PNG");
    this->setWindowIcon(QIcon(icon));

    this->setWindowTitle("Wellington Central Library"); //set window title

    QPixmap logo (":/resources/images/wcl_logo_wide_white.png");
    ui->logolabel->setPixmap(logo.scaled(ui->logolabel->size())); //set header image

    QPixmap pixmap;
    pixmap.load(":/resources/images/background.png");
    ui->background->setPixmap(pixmap.scaled(1280, 730));
    activeElement = ui->background;
    auxWidget = ui->auxLabel; //setup background

    QPixmap facebookImg, twitterImg, instaImg; //setup footer
    facebookImg.load(":/resources/images/facebooklogo.png"); twitterImg.load(":/resources/images/twitterlogo.png"); instaImg.load(":/resources/images/instalogo.png");
    QIcon facebookIcon(facebookImg), twitterIcon(twitterImg), instaIcon(instaImg);
    ui->facebookButton->setIcon(facebookIcon); ui->twitterButton->setIcon(twitterIcon); ui->instaButton->setIcon(instaIcon);
    ui->facebookButton->setIconSize(ui->facebookButton->size()); ui->twitterButton->setIconSize(ui->twitterButton->size()); ui->instaButton->setIconSize(ui->instaButton->size());
}

MainWindow::~MainWindow() //destructor
{
    delete ui;
}

void MainWindow::on_logout_button_clicked() //makes logout window, closes this one
{
    user = LibSystems::Account();
    login *log = new login(nullptr, books->Next(), members->Next(), loans->Next());
    log->show();
    close();
}

void MainWindow::on_addbook_button_clicked() //add book
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->addbook_button); //changes css on button that was just pressed

    QLabel *lab = new QLabel(auxWidget); //setup header
    lab->setText("Add a new book");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; padding-top: 10px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Book *last = (LibSystems::Book::Count() > 0) ? books->Next(LibSystems::Book::Count() - 1) : books; //declare pointer to last book object in linked list

    AddBook *add = new AddBook(this, last); //create addbook widget
    activeElement = add;
    qScroll = new QScrollArea(this); //setup scroll area to allow user to scroll down widget / fit widget in frame
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->activeLayout->addWidget(qScroll, 1, 1);

    connect(add, &AddBook::Finish, this, &MainWindow::HomeScreen); //when 'finish' signal is emited return to home page
}

void MainWindow::EditBook (LibSystems::Book *book)
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header

    QLabel *lab = new QLabel(auxWidget); //setup header
    lab->setText("Edit an existing book");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; padding-top: 10px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Book *last = books->Next(LibSystems::Book::Count() - 1); //declare pointer to last book object in linked list

    AddBook *editBook = new AddBook(this, last, book); //create addbook widget with edit value
    activeElement = editBook;
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(840, 470);
    qScroll->setMaximumSize(840, 470);
    ui->activeLayout->addWidget(qScroll, 1, 1);

    connect(editBook, &AddBook::Finish, this, &MainWindow::HomeScreen); //when 'finish' signal is emited return to home page
}

void MainWindow::on_viewbook_button_clicked()
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->viewbook_button); //changes css on button that was just pressed

    auxWidget = new QWidget(this); //setup search bar
    QLineEdit *searchEdit = new QLineEdit(auxWidget);
    connect(searchEdit, &QLineEdit::returnPressed, this, &MainWindow::DisplayBooks);
    auxWidget->setStyleSheet("font: 12pt 'Roboto Regular'; padding-top: 10px;");
    searchEdit->setStyleSheet("padding: 5px; border-radius: 10px;");
    auxWidget->setMinimumSize(400, 30);
    searchEdit->setMinimumSize(400, 15);
    ui->activeLayout->addWidget(auxWidget, 0, 1, Qt::AlignHCenter | Qt::AlignBottom);

    DisplayBooks(); //actually display books
}

void MainWindow::DisplayBooks()
{
    if (LibSystems::Book::Count() > 0) //only perform function if there are books to be displayed
    {
        delete activeElement; //delete existing widget (doing this instead of calling the function so that the header remains)
        delete qScroll;

        activeElement = new QWidget;

        QLineEdit *searchEdit = qobject_cast<QLineEdit*>(auxWidget->children()[0]); //this feels messy but get the searchbar in this function
        QString search = searchEdit->text().toLower(); //get the text written inside the searchbar

        QGridLayout *qGrid = new QGridLayout(activeElement); //grid to layout the book widgets inside

        int row = 0;
        int column = 1;
        LibSystems::Book *displayBook = books->Next();

        QWidget *spacer = new QWidget(activeElement); //spacer to layout the books nicely
        spacer->setMinimumSize(75, 0);
        qGrid->addWidget(spacer, 0, 0);

        for (int index = 0; index < LibSystems::Book::Count(); index++) //run for each book
        {
            if (search == "" || (displayBook->GetTitle().toLower().contains(search) || displayBook->GetAuthor().toLower().contains(search) || displayBook->GetGenre().toLower().contains(search)))
            { //if the user isnt searching for a book, or if this book matches their search
                BookDisplay *display = new BookDisplay(activeElement, displayBook); //make a display widget for the current book

                qGrid->addWidget(display, row, column); //put the display into the grid layout
                column++;

                connect(display, &BookDisplay::BookSignal, this, &MainWindow::DisplaySingleBook); //call the edit book function when the display is clicked
                if (column == 6) //if there are 5 books on the current row, shift down 1 row
                {
                    row += 1;
                    column = 1;
                }
            }

            displayBook = displayBook->Next();
        }

        qScroll = new QScrollArea(this); //put the active element into a scroll area to fit them into a discrete area
        qScroll->setWidget(activeElement);
        qScroll->setMinimumSize(970, 450);
        qScroll->setMaximumSize(1150, 450);
        ui->activeLayout->addWidget(qScroll, 1, 1); //put the displays onto the admin window
    }
}

void MainWindow::DisplaySingleBook(LibSystems::Book *book)
{
    delete activeElement;
    delete qScroll;

    ViewBook *view = new ViewBook(book, this);
    activeElement = view;
    qScroll = new QScrollArea(this);
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(970, 450);
    qScroll->setMaximumSize(1150, 450);
    ui->activeLayout->addWidget(qScroll, 1, 1);

    connect(view, &ViewBook::EmitBook, this, &MainWindow::EditBook);
}

void MainWindow::on_addmember_button_clicked()
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->addmember_button); //changes css on button that was just pressed

    auxWidget = new QLabel(this); //setup header
    QLabel *lab = new QLabel(auxWidget);
    lab->setText("Add a new member");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; margin-top: 15px; margin-left: 220px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Member *last = (LibSystems::Member::Count() > 0) ? members->Next(LibSystems::Member::Count() - 1) : members; //select the last member in the member linked list

    AddMember *add = new AddMember(this, last); //declare a new addmember widget
    activeElement = add;
    ui->activeLayout->addWidget(activeElement, 1, 1, Qt::AlignHCenter); //add the addmember widget to the main window

    connect(add, &AddMember::Finish, this, &MainWindow::HomeScreen); //return to home page when user finishes adding a member
}

void MainWindow::on_viewmember_button_clicked()
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->viewmember_button); //changes css on button that was just pressed

    auxWidget = new QWidget(this); //setup search bar
    QLineEdit *searchEdit = new QLineEdit(auxWidget);
    connect(searchEdit, &QLineEdit::returnPressed, this, &MainWindow::DisplayMembers);
    auxWidget->setStyleSheet("font: 12pt 'Roboto Regular'; padding-top: 10px;");
    searchEdit->setStyleSheet("padding: 5px; border-radius: 10px;");
    auxWidget->setMinimumSize(400, 30);
    searchEdit->setMinimumSize(400, 15);
    ui->activeLayout->addWidget(auxWidget, 0, 1, Qt::AlignCenter | Qt::AlignBottom);

    DisplayMembers(); //actually display members
}

void MainWindow::DisplayMembers()
{
    if (LibSystems::Member::Count() > 0) // only perform function if there are members to display
    {
        delete activeElement; //delete existing widget (doing this instead of calling the function so that the header remains)
        delete qScroll;
        activeElement = new QWidget(this);

        QLineEdit *searchEdit = qobject_cast<QLineEdit*>(auxWidget->children()[0]); //this feels messy but get the searchbar in this function
        QString search = searchEdit->text().toLower(); //get the text written inside the searchbar

        QGridLayout *qGrid = new QGridLayout(activeElement); //grid to layout the book widgets inside
        qGrid->setSpacing(5);
        LibSystems::Member *thisMember = members->Next();

        //Labels up the top so the data isnt meaningless --------------------------------------------------------------
        QLabel *memberInfo = new QLabel(activeElement);  //toplabel
        QLabel *memberWidgets[6]; //sublabels to go inside the top label
        QString memberData[6] = { "Id", "Full name", "Username", "Email", "Contact Number", "Date of birth" }; //the strings that are inside of the sublabel

        QHBoxLayout *hLayout = new QHBoxLayout(memberInfo);

        for (int i = 0; i < 6; i++) //generate each sublabel of the top label
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
        memberInfo->setStyleSheet("color: #5A98D1; border: 0px;"); //set style
        qGrid->addWidget(memberInfo, 0, 0); //add top label to the main window
        //Labels up the top so the data isnt meaningless --------------------------------------------------------------

        activeElement->setStyleSheet("QPushButton { border-width: 1px; border-style: solid; border-color: black; border-radius: 5px; }"
                                     "QPushButton::hover { background-color: #DDDDDD; }"
                                     "QLabel { font: 12pt 'Roboto Regular'; }"); //set style sheet for the member displays

        for (int i = 0; i < LibSystems::Member::Count(); i++) //for each member in the member linked list
        {
            if (search == "" || (thisMember->GetUsername().toLower().contains(search) || thisMember->GetFullName().toLower().contains(search)))
            { //if the user isnt searching for a member, or if the current member matches the search
                MemberInfo *memberInfo = new MemberInfo(thisMember, activeElement); //make a new label to act as the member display
                QLabel *memberWidgets[6]; //sublabels
                QString memberData[6] = {QString::number(thisMember->GetIndex()), thisMember->GetFullName(), thisMember->GetUsername(), thisMember->GetEmail(), thisMember->GetContactNumber(),
                                         (QString::number(thisMember->GetDOB().day()) + "/" + QString::number(thisMember->GetDOB().month()) + "/" + QString::number(thisMember->GetDOB().year()))};

                QHBoxLayout *hLayout = new QHBoxLayout(memberInfo); //internal layout in member display

                for (int i = 0; i < 6; i++) //generate sublabels
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

                connect(memberInfo, &MemberInfo::SendMember, this, &MainWindow::DisplaySingleMember); //allow user to edit member by clicking on their display

                qGrid->addWidget(memberInfo, i + 1, 0); //add display to active widget
            }
            thisMember = thisMember->Next();
        }

        qScroll = new QScrollArea(this); //put a scroll area on the active widget to make it fit into the window
        qScroll->setWidget(activeElement);
        qScroll->setMinimumSize(1120, 450);
        qScroll->setMaximumSize(1120, 450);

        ui->activeLayout->addWidget(qScroll, 1, 1); //add the active wiget to the main screen
    }
}

void MainWindow::DisplaySingleMember(LibSystems::Member *member)
{
    delete activeElement; //delete existing widget (doing this instead of calling the function so that the header remains)
    delete qScroll;

    ViewMember *viewM = new ViewMember(member, loans, &user, this);
    activeElement = viewM; //make new viewmember widget
    qScroll = new QScrollArea; //put a scroll area on the active widget to make it fit into the window
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(1120, 450);
    qScroll->setMaximumSize(1120, 450);

    connect(viewM, &ViewMember::EmitMember, this, &MainWindow::EditMember);

    ui->activeLayout->addWidget(qScroll, 1, 1); //add the active wiget to the main screen
}

void MainWindow::EditMember(LibSystems::Member *member)
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header

    auxWidget = new QLabel(this); //setup header
    QLabel *lab = new QLabel(auxWidget);
    lab->setText("Edit an existing member");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; margin-top: 15px; margin-left: 220px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    LibSystems::Member *last = members->Next(LibSystems::Member::Count() - 1); //declare member pointer as last node in member linked list

    AddMember *editMember = new AddMember(this, last, member); //declare new edit member widget
    activeElement = editMember;
    ui->activeLayout->addWidget(activeElement, 1, 1, Qt::AlignHCenter); //add edit member to main window

    connect(editMember, &AddMember::Finish, this, &MainWindow::HomeScreen); //return to home screen once the user has finished editing the member
}

void MainWindow::on_overduebooks_button_clicked()
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->overduebooks_button); //changes css on button that was just pressed

    QLabel *lab = new QLabel(auxWidget); //setup header
    lab->setText("Overdue Log");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; margin-top: 15px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    QVBoxLayout *vertLayout = new QVBoxLayout(activeElement); //setup vertical layout to hold overdue book widgets

    LibSystems::LoanedBook *thisLoan = loans->Next(); //declare loan pointer as the first non-head loan in the linked list
    QDate current = QDate::currentDate(); //get current date to compare with due dates
    int overdueCount = 0;

    for (int i = 0; i < LibSystems::LoanedBook::Count(); i++) //for each loan in the loan linked list
    {
        if (thisLoan->isOverDue()) //if the loan is overdue
        {
            OverdueBooks *overdue = new OverdueBooks(thisLoan->GetBook(books), thisLoan->GetMember(members), thisLoan, activeElement); //make overdue book widget
            connect(overdue, &OverdueBooks::DisplayMember, this, &MainWindow::DisplayOverdueMember); //allow user to view member who has book
            vertLayout->addWidget(overdue, 0, Qt::AlignHCenter); //add widget to the active widget
            overdueCount++;
        }
        else if (thisLoan->GetDueDate().dayOfYear() <= current.dayOfYear() + 3 || thisLoan->GetDueDate().dayOfYear() < (365 - current.dayOfYear() + 3)) //if there is less than 3 days till the book is due
        {
            OverdueBooks *overdue = new OverdueBooks(thisLoan->GetBook(books), thisLoan->GetMember(members), thisLoan, thisLoan->GetDueDate().dayOfYear() - current.dayOfYear(), activeElement);
            connect(overdue, &OverdueBooks::DisplayMember, this, &MainWindow::DisplayOverdueMember); //same as above, but with a differernt constructor for the overdue books widget
            vertLayout->addWidget(overdue, 0, Qt::AlignHCenter);
            overdueCount++;
        }
        thisLoan = thisLoan->Next();
    }

    if (overdueCount == 0)
    {
        QLabel *emptyLabel = new QLabel(activeElement); //declare label that says there are no overdue books if there are no overdue books
        emptyLabel->setText("There are no overdue books at this time");
        emptyLabel->setStyleSheet("color: #000000; font: 12pt 'Roboto Regular';");
        emptyLabel->setMinimumWidth(1120);
        emptyLabel->setAlignment(Qt::AlignCenter);
        vertLayout->addWidget(emptyLabel, 0, Qt::AlignHCenter); //put that label in the vertical layout
    }

    qScroll->setWidget(activeElement); //put a scroll area on the active widget to make it fit into the window (there is no leak it is deleted)
    qScroll->setMinimumSize(1120, 450);
    qScroll->setMaximumSize(1120, 450);

    ui->activeLayout->addWidget(qScroll, 1, 1); //add the active wiget to the main screen
}

void MainWindow::DisplayOverdueMember(LibSystems::Member *member)
{
    delete activeElement; //delete existing widget (doing this instead of calling the function so that the header remains)
    delete qScroll;

    activeElement = new ViewMember(member, loans, this); //make new viewmember widget
    qScroll = new QScrollArea; //put a scroll area on the active widget to make it fit into the window
    qScroll->setWidget(activeElement);
    qScroll->setMinimumSize(1120, 450);
    qScroll->setMaximumSize(1120, 450);

    ui->activeLayout->addWidget(qScroll, 1, 1); //add the active wiget to the main screen
}

void MainWindow::on_checkoutbooks_button_clicked()
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->checkoutbooks_button); //changes css on button that was just pressed

    QLabel *lab = new QLabel(auxWidget); //setup header
    lab->setMinimumHeight(30);
    lab->setText("Checkout Books");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; margin-top: 15px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    QFile reservationsFile("databases/reservations.csv"); //declare file
    if (!reservationsFile.open(QIODevice::ReadOnly | QIODevice::Text)) //if the program fails to open the file in read mode
    {
        int e = LibMessageBoxes::ErrorMessageBox("Error", "Couldn't open file"); //send error message
        switch(e)
        {
        case (QMessageBox::Cancel): //if the user decides to cancel
            MainWindow::HomeScreen(); //go to homescreen
            break;
        case (QMessageBox::Retry): //if user decides to retry
            MainWindow::on_checkoutbooks_button_clicked(); //call this function again (it will probably fail to open again.
            break;
        }
    }
    QVBoxLayout *vertLayout = new QVBoxLayout(activeElement); //create vertical layout

    CustomCheckoutBooks *ccb = new CustomCheckoutBooks(books, members, loans, activeElement); //declare new custom checkout book widget
    vertLayout->addWidget(ccb, 0, Qt::AlignHCenter); //add custom checkout book to the vertical layout

    QLabel *reservationLabel = new QLabel(activeElement); //declare label that says 'reservations:'
    reservationLabel->setText("Reservations:");
    reservationLabel->setStyleSheet("color: #5A98D1; font: 24pt 'Roboto Regular';");
    vertLayout->addWidget(reservationLabel, 0, Qt::AlignHCenter); //put that label in the vertical layout

    QTextStream in(&reservationsFile); //create text stream to read file
    int index = 0;
    while (!in.atEnd()) //for each line in the reservation file
    {
        QString s[2];
        int i[2];

        QtHelpers::ParseString(in.readLine(), s); //read a line from file and divide it by the comma
        i[0] = s[0].toInt(); i[1] = s[1].toInt(); //convert the strings from the file into ints

        LibSystems::Member *m = members->Next(i[0]); //get the member based on the index that was saved in the file
        LibSystems::Book *b = books->Next(i[1]); //get the book based on the index that was saved in the file
        CheckoutBooks *cb = new CheckoutBooks(index, b, m, loans, activeElement); //create a new checkoutbooks widget based on the book + memeber
        vertLayout->addWidget(cb, 0, Qt::AlignHCenter); //add the checkoutbooks widget to the vertical layout
        connect(cb, &CheckoutBooks::Remove, this, &MainWindow::RemoveReservation); //connect remove signal to the remove function in this class
        index++;
    }

    if (index == 0)
    {
        QLabel *emptyLabel = new QLabel(activeElement); //declare label that says there are no reservations if there are no reservations
        emptyLabel->setText("There are no reservations at this time");
        emptyLabel->setStyleSheet("color: #000000; font: 12pt 'Roboto Regular';");\
        vertLayout->addWidget(emptyLabel, 0, Qt::AlignHCenter); //put that label in the vertical layout
    }

    qScroll->setWidget(activeElement); //put a scroll area on the active widget to make it fit into the window
    qScroll->setMinimumSize(1120, 450);
    qScroll->setMaximumSize(1120, 450);

    ui->activeLayout->addWidget(qScroll, 1, 1); //add the active wiget to the main screen
}

void MainWindow::RemoveReservation(int index)
{
    LibSystems::RemoveReservation(index); //remove reservation at the index given
    MainWindow::on_checkoutbooks_button_clicked(); //recreate the checkoutbooks widget without the removed reservation
}

void MainWindow::on_returnbooks_button_clicked()
{
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    SetActiveButton(ui->returnbooks_button); //changes css on button that was just pressed

    QLabel *lab = new QLabel(auxWidget); //setup header
    lab->setMinimumHeight(30);
    lab->setText("Return Books");
    auxWidget->setStyleSheet("font: 24pt 'Roboto Regular'; color: #5A98D1; margin-top: 15px;");
    ui->activeLayout->addWidget(auxWidget, 0, 1);

    QVBoxLayout *vertLayout = new QVBoxLayout(activeElement); //create vertical layout
    int returnCount = 0;

    if (LibSystems::LoanedBook::Count() > 0) //only perform function if there are loans to display
    {
        LibSystems::LoanedBook *current = loans->Next(); //declare loan object as first non-head loan in the loan linked list

        while (current != nullptr) //for each loan in the loan linked list
        {
            if (current->IsReturned()) //if the member has flagged this loan as 'returned'
            {
                ReturnBooks *rtrn = new ReturnBooks(current, books, members, activeElement); //create a returnbooks object with the 'admin' constructor

                vertLayout->addWidget(rtrn, 0, Qt::AlignHCenter); //add to vertical layout
                connect(rtrn, &ReturnBooks::Finish, this, &MainWindow::on_returnbooks_button_clicked); //remake this widget when the admin removes / unflags a loan

                returnCount++;
            }
            current = current->Next();
        }
    }

    if (returnCount == 0)
    {
        QLabel *emptyLabel = new QLabel(activeElement); //declare label that says there are no returns if there are no returns
        emptyLabel->setText("There are no book returns to validate at this time");
        emptyLabel->setStyleSheet("color: #000000; font: 12pt 'Roboto Regular';");
        emptyLabel->setMinimumWidth(1120);
        emptyLabel->setAlignment(Qt::AlignCenter);
        vertLayout->addWidget(emptyLabel, 0, Qt::AlignHCenter); //put that label in the vertical layout
    }

    qScroll->setWidget(activeElement); //put a scroll area on the active widget to make it fit into the window
    qScroll->setMinimumSize(1120, 450);
    qScroll->setMaximumSize(1120, 450);

    ui->activeLayout->addWidget(qScroll, 1, 1);  //add the active wiget to the main screen
}

void MainWindow::HomeScreen()
{
    if (activeButton != nullptr) //remove the special styling from the most recently pressed button
    {
        activeButton->setStyleSheet("");
        activeButton->setGraphicsEffect(0);
    }
    ClearActiveArea(); //destroys whatever the current centre widget is, along with the header
    ui->activeSpacer->changeSize(0, 0);
    QLabel *background = new QLabel(this); //create background label
    background->setMinimumSize(1280, 550);
    QPixmap img;
    img.load(":/resources/images/background.png"); //get the background image and put it on the background label
    background->setPixmap(img.scaled(1280, 730));
    activeElement = background;
    ui->activeLayout->addWidget(activeElement, 1, 1);
    qScroll = new QScrollArea;
    auxWidget = new QWidget;
}

void MainWindow::ClearActiveArea()
{
    delete activeElement; //delete the active widgets and components
    delete qScroll;
    delete auxWidget;
    activeElement = new QWidget(this);
    qScroll = new QScrollArea(this);
    auxWidget = new QWidget(this);

    ui->activeSpacer->changeSize(0, 50);
}

void MainWindow::SetActiveButton(QPushButton *pressed)
{
    if (activeButton != nullptr) //set the previously pressed button to default
    {
        activeButton->setStyleSheet("");
        activeButton->setGraphicsEffect(0);
    }
    pressed->setStyleSheet("background-color: #FFFFFF; color: #5A98D1; "); //change css on newly pressed button
    QGraphicsDropShadowEffect *dropShadow = new QGraphicsDropShadowEffect(this); //create drop shadow
    dropShadow->setOffset(0, 2);
    dropShadow->setColor(QColor::fromRgb(68, 95, 158));
    pressed->setGraphicsEffect(dropShadow); //add drop shadow to button
    activeButton = pressed; //set active button to the recently pressed button
}

void MainWindow::on_facebookButton_clicked() //open facebook
{
    QDesktopServices::openUrl(QUrl(QString("https://www.facebook.com/wellingtoncitylibraries")));
}

void MainWindow::on_twitterButton_clicked() //open twitter
{
    QDesktopServices::openUrl(QUrl(QString("https://twitter.com/wcl_library")));
}

void MainWindow::on_instaButton_clicked() //open instagram
{
    QDesktopServices::openUrl(QUrl(QString("https://www.instagram.com/wcl_library/")));
}
