#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <vector>
#include <QMessageBox>

int ErrorMessageBox(QString errorName, QString errorText)
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
    error->setText(errorName);
    error->setDetailedText(errorText);
    error->setModal(true);
    return error->exec();
}

class LoanedBook;
void ParseString(QString input, QString *output);
tm *TimeFromQString(QString input);

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

        out << isbn << ',' << title << ',' << author << ',' << genre << ',' << pgCount << ',' << dewey << ',' << releaseDate->tm_year << releaseDate->tm_mon << releaseDate->tm_mday << ',' << isAvailable << '\n';

        bookFile.flush();
        bookFile.close();
    }

public:
    Book(int i, QString t, QString a, QString g, int p, int d, tm *r, bool iA = true)
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
    int index, loanedBooks[5];
    QString email, contactNo;
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

        memberFile.flush();
        memberFile.close();
    }

public:
    Member(int i, QString u, QString p, QString e, QString c, int l[5] = { -1, -1, -1, -1, -1 })
    {
        index = i;
        username = u;
        password = p;
        email = e;
        contactNo = c;
        loanedBooks = l;
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

        loanFile.flush();
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

            QString parsed[8];
            int isbn, pgCount, dewey;
            tm *releaseDate;
            bool isAvailable;

            ParseString(read, &parsed[0]);

            isbn = parsed[0].toInt();
            pgCount = parsed[4].toInt();
            dewey = parsed[5].toInt();
            isAvailable = (parsed[7] == '1') ? true : false;
            releaseDate = TimeFromQString(parsed[6]);

            return Book(isbn, parsed[1], parsed[2], parsed[3], pgCount, dewey, releaseDate, isAvailable);
        }
    }

    Member GetMember ()
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

    bool isOverDue ()
    {
        time_t t = time(0);
        tm *current = localtime(&t);

        return (current->tm_yday > dueDate) ? (current->tm_yday > dueDate) : (current->tm_yday + 365 > dueDate);
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
        defualt:
            output->append(c);
            break;
        }
        i++;
    }
}

tm *TimeFromQString (QString input)
{
    tm *rtrn;
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

    rtrn->tm_year = y;
    rtrn->tm_mon = m;
    rtrn->tm_mday = d;

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

