#ifndef LIBRARYSYSTEMS_H
#define LIBRARYSYSTEMS_H
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <vector>
#include <QDate>
#include <QPushButton>

/*Declarations of classes, data members, and member functions. Definitions of functions are found within the librarysystems.cpp file.
 * Including this header file in a cpp file will allow you to use any object / function definied inside.
 * By putting all of the classes in here, we can use them in all of our cpp files, and therefore all of our windows/widgets. */

namespace LibSystems
{
class LoanedBook; //declaring this once early because of cascading compiler, or whatever its called.

class Book //book class
{
private: //data members
    int index, pgCount, dewey;
    QString isbn, title, author, genre, coverPath, blurb;
    bool isAvailable;
    QDate releaseDate;
    static int totalBooks;
    Book* links[2];

public: //member functions
    void WriteToMemory ();
    Book(QString i, QString t, QString a, QString g, QString cP, QString b, int p, int d, QDate r, Book* prev, bool iA = true);
    Book();
    ~Book();
    int GetIndex();
    QString GetISBN();
    int GetDeweyDecimal();
    QString GetTitle();
    QString GetAuthor();
    QString GetGenre();
    QString GetCoverPath();
    QPixmap GetCover();
    QString GetBlurb();
    int GetPageCount();
    QDate GetReleaseDate();
    Book *Prev();
    Book *Next();
    Book *Next(int index);
    void SetPrev(Book* p);
    void SetNext(Book* n);
    static int Count();
    bool IsAvailable();
    void EditBook(QString i, QString t, QString a, QString g, QString cP, QString b, int p, int d, QDate r);
    void SetAvailable(bool b);
};

class Account //account class
{
protected: //data members
    QString username, password;

public:
    Account (QString u = "NULL", QString p = "NULL");
    QString GetUsername();
    QString GetPassword();
    bool CheckUsername(QString check);
    bool CheckPassword(QString check);
    virtual int GetLoanedBook(int index);
    virtual int GetIndex();
    virtual int GetLoanedCount();
    virtual int GetOverdueCount(LoanedBook *loans);
    virtual QString GetEmail();
    virtual QString GetContactNumber();
    virtual QString GetFirstName();
    virtual QString GetLastName();
    virtual QString GetFullName();
    virtual QDate GetDOB();
};

static Account Admin("username", "password"); //declaration of Admin account

class Member : public Account //member class is a child of the account class
{
private: //data members
    int index, loanedBooks[5]; //loaned books array stores index of loanedbook class
    QString email, contactNo, firstName, lastName;
    QDate dob;
    Member* links[2];
    static int totalMembers;

public:
    Member(int i, QString u, QString p, QString e, QString c, QString fN, QString lN, QDate d, int l[5], Member *prev);
    Member();
    ~Member();
    void WriteToMemory ();
    int GetIndex();
    QString GetEmail();
    QString GetContactNumber();
    QString GetFirstName();
    QString GetLastName();
    QString GetFullName();
    QDate GetDOB();
    static int Count();
    int GetLoanedBook (int index);
    void SetLoanedBook (int index, int loan);
    void ReturnBook (int loanIndex);
    int GetOverdueCount(LoanedBook *loans);
    int GetLoanedCount();
    Member *Prev();
    Member *Next();
    Member *Next(int index);
    void SetPrev(Member* p);
    void SetNext(Member* n);
    void EditMember(QString u, QString p, QString e, QString c, QString fN, QString lN, QDate date);
};

class LoanedBook //loanedbook class contains the index of a book and the member it was lent too, and the date that the book is due.
{
private: //data members
    int index, book, member;
    bool returned;
    QDate dueDate;
    LoanedBook *links[2];
    static int totalLoans;

public:
    LoanedBook (int b, int m, QDate dd, LoanedBook *prev, bool r = false);
    LoanedBook();
    ~LoanedBook();
    void WriteToMemory();
    int GetIndex();
    bool IsReturned();
    void SetReturned(bool r);
    static int Count();
    QDate GetDueDate ();
    Book* GetBook(Book *books);
    Member* GetMember(Member *members);
    bool isOverDue ();
    LoanedBook *Prev();
    LoanedBook *Next();
    LoanedBook *Next(int index);
    void SetPrev(LoanedBook* p);
    void SetNext(LoanedBook* n);
};

Book* InitialiseBooks ();
Member* InitialiseMembers();
LoanedBook* InitialseLoans();
void RewriteBooks(Book *books);
void RewriteMembers(Member *members);
void RewriteLoans(LoanedBook *loans);
void RemoveLoan(int index);
void RemoveReservation(int index);
}

namespace QtHelpers
{
void ParseString(QString input, QString *output);
QDate QDateFromQString (QString input);
}
#endif // LIBRARYSYSTEMS_H
