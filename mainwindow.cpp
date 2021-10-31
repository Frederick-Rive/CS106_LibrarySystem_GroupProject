#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <vector>

class LoanedBook;
QString *ParseString(int length);

class Book
{
private:
    int isbn, pgCount, dewey;
    QString title, author, genre;
    bool isAvailable;
    tm *releaseDate;
    static int totalBooks;

    void WriteToMemory ()
    {
        QFile bookFile("databases/books.csv");

        if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }

        QTextStream out(&bookFile);

        out << isbn << ',' << title << ',' << author << ',' << genre << ',' << pgCount << ',' << dewey << ',' << releaseDate << ',' << isAvailable << '\n';

        bookFile.close();
    }

public:
    Book(int i, QString t, QString a, QString g, int p, int d, tm *r)
    {
        isbn = i;
        title = t;
        author = a;
        genre = g;
        pgCount = p;
        dewey = d;
        releaseDate = r;
        isAvailable = true;
        totalBooks++;
        WriteToMemory();
    }

    int GetISBN() { return isbn; }
    int GetDeweyDecimal() { return dewey; }
    QString GetTitle() { return title; }
    QString GetAuthor() { return author; }
    QString GetGenre() { return genre; }
    int GetPageCount() { return pgCount; }
    tm* GetReleaseDate() { return releaseDate; }
    static int Count() { return totalBooks; }
    bool IsAvailable() { return isAvailable; }

    QString EditBook ()
    {

    }

    void SetAvailable(bool b) { isAvailable = b; }

};

class Account
{
protected:
    QString username, password;

public:
    Account ()
    {
        username = "null";
        password = "null";
    }

    QString GetUsername() { return username; }
    bool CheckPassword(QString check) { return (check == password); }
};

class Member : public Account
{
private:
    int index;
    QString email, contactNo;
    std::vector<int> loanedBooks;
    static int memberCount;

    void WriteToMemory ()
    {
        QFile memberFile("databases/members.csv");

        if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }

        QTextStream out(&memberFile);

        out << username << ',' << password << ',' << email << ',' << contactNo;

        for (int i : loanedBooks)
        {
            out << ',' << i;
        }

        out << '\n';

        memberFile.close();
    }

public:
    Member(int i, QString u, QString p, QString e, QString c)
    {
        index = i;
        username = u;
        password = p;
        email = e;
        contactNo = c;
        memberCount++;
        WriteToMemory();
    }

    int GetIndex() { return index; }
    QString GetEmail() { return email; }
    QString GetContactNumber() { return contactNo; }
    static int Count() { return memberCount; }

    void DisplayLentBooks ()
    {

    }

    void CheckoutBook (int bookIndex)
    {
        //LoanedBook loaned = LoanedBook(LoanedBook()::Count(),
    }

    void ReturnBook (int loanIndex)
    {

    }

    void EditMember()
    {

    }
};

class LoanedBook
{
private:
    int index, book, member, dueDate;
    static int loanedBookCount;

    void WriteToMemory()
    {
        QFile loanFile("databases/loan.csv");

        if (!loanFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }

        QTextStream out(&loanFile);

        out << index << ',' << member << ',' << dueDate << '\n';

        loanFile.close();
    }

public:
    LoanedBook (int i, int b, int m, int dd)
    {
        index = i;
        book = b;
        member = m;
        dueDate = dd;
        WriteToMemory();
        loanedBookCount++;
    }

    int GetIndex() { return index; }
    static int Count() { return loanedBookCount; }
    int GetDueDate () { return dueDate; }

    Book GetBook ()
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

            QString
        }

    }

    Member GetMember ()
    {

    }

    bool isOverDue ()
    {
        time_t t = time(0);
        tm *current = localtime(&t);

        return (current->tm_yday > dueDate) ? (current->tm_yday > dueDate) : (current->tm_yday + 365 > dueDate);
    }
};

QString ParseString (int length)
{

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

