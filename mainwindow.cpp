#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <vector>
#include <QMessageBox>

using namespace std;

int ErrorMessageBox(QString errorName, QString errorText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
    error->setText(errorName);
    error->setDetailedText(errorText);
    error->setModal(true);
    return error->exec();
}

class LoanedBook; //declarations of things
void ParseString(QString input, QString *output);
QDate QDateFromQString(QString input);

class Book //book class
{
private: //data members
    int isbn, pgCount, dewey;
    QString title, author, genre;
    bool isAvailable;
    QDate releaseDate; //note: ctime things are weird
    static int totalBooks;

public: //member functions
    void WriteToMemory () //writes the book into the database. please be careful not to duplicate books in the database
    {
        QFile bookFile("databases/books.csv");

        if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; } // !!! add a message box !!!

        QTextStream out(&bookFile);

        int y, m, d;
        releaseDate.getDate(&y, &m, &d);

        out << isbn << ',' << title << ',' << author << ',' << genre << ',' << pgCount << ',' << dewey << ',' << y << m << d << ',' << isAvailable << '\n';

        bookFile.flush();
        bookFile.close();
    }

    Book(int i, QString t, QString a, QString g, int p, int d, QDate r, bool iA = true) //constructor
    {
        isbn = i;
        title = t;
        author = a;
        genre = g;
        pgCount = p;
        dewey = d;
        releaseDate = r;
        isAvailable = iA;
        totalBooks++;
        WriteToMemory();
    }

    int GetISBN() { return isbn; } //getters (not many setters since most of that should be done in the edit book function)
    int GetDeweyDecimal() { return dewey; }
    QString GetTitle() { return title; }
    QString GetAuthor() { return author; }
    QString GetGenre() { return genre; }
    int GetPageCount() { return pgCount; }
    QDate GetReleaseDate() { return releaseDate; }
    static int Count() { return totalBooks; }
    bool IsAvailable() { return isAvailable; }

    QString EditBook ()
    {

    }

    void SetAvailable(bool b) { isAvailable = b; } //setter for this value since it will be frequently changed on its own
    //other values should only be edited within the edit book widget
};

class Account //account class
{
protected: //data members
    QString username, password;

public:
    Account () //constructor
    {
        username = "null";
        password = "null";
    }

    QString GetUsername() { return username; }//getters
    QString GetPassword() { return password; }
    bool CheckUsername(QString check) { return (check == username); } //use this when logging in
    bool CheckPassword(QString check) { return (check == password); } //use this when logging in
};

class Member : public Account //member class is a child of the account class
{
private: //data members
    int index, loanedBooks[5]; //loaned books array stores index of loanedbook class
    QString email, contactNo;
    static int memberCount;

public:
    void WriteToMemory () //write to memory
    {
        QFile memberFile("databases/members.csv");

        if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; } // !!! warning message box !!!

        QTextStream out(&memberFile);

        out << username << ',' << password << ',' << email << ',' << contactNo;

        for (int i : loanedBooks)
        {
            out << ',' << i;
        }

        out << '\n';

        memberFile.flush();
        memberFile.close();
    }

    Member(int i, QString u, QString p, QString e, QString c, int l[5]) //constructor
    {
        index = i;
        username = u;
        password = p;
        email = e;
        contactNo = c;

        for (int i = 0; i < 5; i++)
        {
            loanedBooks[i] = l[i];
        }

        memberCount++;
        WriteToMemory();
    }

    int GetIndex() { return index; } //getters
    QString GetEmail() { return email; }
    QString GetContactNumber() { return contactNo; }
    static int Count() { return memberCount; }

    /*LoanedBook GetLoanedBook (int index)
    {

    }
    */

    void DisplayLoanedBooks () //this will probably do some widget stuff
    {

    }

    void CheckoutBook (int bookIndex) //checks out a book. pass in the index of the book
    {
        //LoanedBook loaned = LoanedBook(LoanedBook()::Count(),
    }

    void ReturnBook (int loanIndex) //returns a book. pass in the index of the loanedbook
    {

    }

    void EditMember() //who knows
    {

    }
};

class LoanedBook //loanedbook class contains the index of a book and the member it was lent too, and the date that the book is due.
{
private: //data members
    int index, book, member;
    QDate dueDate;
    static int loanedBookCount;

public:
    void WriteToMemory() //writes to memory
    {
        QFile loanFile("databases/loan.csv");

        if (!loanFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }

        QTextStream out(&loanFile);

        int y, m, d;
        dueDate.getDate(&y, &m, &d);

        out << index << ',' << member << ',' << y << m << d << '\n';

        loanFile.flush();
        loanFile.close();
    }

    LoanedBook (int i, int b, int m, QDate dd) //constructor
    {
        index = i;
        book = b;
        member = m;
        dueDate = dd;
        loanedBookCount++;
        WriteToMemory();
    }

    int GetIndex() { return index; } //getters
    static int Count() { return loanedBookCount; }
    QDate GetDueDate () { return dueDate; }
    Book GetBook(vector<Book> books) { return books[book]; }
    Member GetMember(vector<Member> members) { return members[member]; }

    Book GetBook () //overloaded getter that creates the book from the file information
    {
        QFile bookFile ("databases/books.csv");

        if (bookFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in (&bookFile);

            QString read;
            for (int i = 0; i <= book; i++)
            {
                read = in.readLine();
            }

            QString parsed[8];
            int isbn, pgCount, dewey;
            QDate releaseDate;
            bool isAvailable;

            ParseString(read, &parsed[0]);

            isbn = parsed[0].toInt();
            pgCount = parsed[4].toInt();
            dewey = parsed[5].toInt();
            isAvailable = (parsed[7] == '1') ? true : false;
            releaseDate = QDateFromQString(parsed[6]);

            return Book(isbn, parsed[1], parsed[2], parsed[3], pgCount, dewey, releaseDate, isAvailable);
        }
    }

    Member GetMember () //overloaded getter that creates the member from the file information
    {
        QFile memberFile ("databases/members.csv");

        if (memberFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in (&memberFile);

            QString read;
            for (int i = 0; i <= book; i++)
            {
                read = in.readLine();
            }

            QString parsed[9];
            int loaned[5];

            ParseString(read, &parsed[0]);

            loaned[0] = parsed[4].toInt();
            loaned[1] = parsed[5].toInt();
            loaned[2] = parsed[6].toInt();
            loaned[3] = parsed[7].toInt();
            loaned[4] = parsed[8].toInt();

            return Member(book, parsed[0], parsed[1], parsed[2], parsed[3], loaned);
        }
    }

    bool isOverDue () //checks if book is overdue
    {
        QDate current = QDate::currentDate();
        return (current.dayOfYear() >= dueDate.dayOfYear()); // !!! DOES NOT ACCOUNT FOR BOOKS CHECKED OUT LATE IN YEAR WHICH ARE DUE EARLY NEXT YEAR !!!
    }
};

void ParseString (QString input, QString *output)
{
    int i = 0;

    while (input.data()[i] != '\n')
    {
        char c = input.data()[i].toLatin1();

        switch(c)
        {
        case ',':
            output++;
            break;
        default:
            output->append(c);
            break;
        }
        i++;
    }
}

QDate QDateFromQString (QString input)
{
    QDate rtrn;
    QString dates[3];

    for (int i = 0; i < 4; i++)
    {
        dates[0].append(input.data()[i]);
    }
    for (int i = 4; i < 6; i++)
    {
        dates[1].append(input.data()[i]);
    }
    for (int i = 6; i < 8; i++)
    {
        dates[2].append(input.data()[i]);
    }

    int y = dates[0].toInt();
    int m = dates[1].toInt();
    int d = dates[2].toInt();

    rtrn.setDate(y, m, d);

    return rtrn;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

