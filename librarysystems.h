#ifndef LIBRARYSYSTEMS_H
#define LIBRARYSYSTEMS_H
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <vector>
#include <QMessageBox>
#include <QDate>

/*Declarations of classes, data members, and member functions. Definitions of functions are found within the librarysystems.cpp file.
 * Including this header file in a cpp file will allow you to use any object / function definied inside.
 * By putting all of the classes in here, we can use them in all of our cpp files, and therefore all of our windows/widgets. */

namespace LibSystems
{
class LoanedBook; //declaring this once early because of cascading compiler, or whatever its called.

class Book //book class
{
private: //data members
    int isbn, pgCount, dewey;
    QString title, author, genre, coverPath, blurb;
    bool isAvailable;
    QDate releaseDate;
    static int totalBooks;
    Book* links[2];

public: //member functions
    void WriteToMemory ();
    Book(int i, QString t, QString a, QString g, QString cP, QString b, int p, int d, QDate r, Book* prev, bool iA = true);
    int GetISBN();
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
    void SetPrev(Book* p);
    void SetNext(Book* n);
    static int Count();
    bool IsAvailable();
    QString EditBook(int i, QString t, QString a, QString g, int p, int d, QDate r);
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
    virtual LoanedBook GetLoanedBook(int index, LoanedBook *ptr);
    virtual void DisplayLoanedBooks();
    virtual void CheckoutBook(int bookIndex);
    virtual void ReturnBook(int loanIndex);
    virtual int GetIndex();
    virtual QString GetEmail();
    virtual QString GetContactNumber();
    virtual QString GetFirstName();
    virtual QString GetLastName();
    virtual QString GetFullName();
};

static Account Admin("username", "password"); //declaration of Admin account

class Member : public Account //member class is a child of the account class
{
private: //data members
    int index, loanedBooks[5]; //loaned books array stores index of loanedbook class
    QString email, contactNo, firstName, lastName;
    Member* links[2];
    static int totalMembers;

public:
    Member(int i, QString u, QString p, QString e, QString c, QString fN, QString lN, int l[5], Member *prev);
    void WriteToMemory ();
    int GetIndex();
    QString GetEmail();
    QString GetContactNumber();
    QString GetFirstName();
    QString GetLastName();
    QString GetFullName();
    static int Count();
    LoanedBook GetLoanedBook (int index, LoanedBook *ptr);
    void DisplayLoanedBooks ();
    void CheckoutBook (int bookIndex);
    void ReturnBook (int loanIndex);
    Member *Prev();
    Member *Next();
    void SetPrev(Member* p);
    void SetNext(Member* n);
    void EditMember();
};

class LoanedBook //loanedbook class contains the index of a book and the member it was lent too, and the date that the book is due.
{
private: //data members
    int index, book, member;
    QDate dueDate;
    LoanedBook *links[2];
    static int totalLoans;

public:
    LoanedBook (int i, int b, int m, QDate dd, LoanedBook *prev);
    void WriteToMemory();
    int GetIndex();
    static int Count();
    QDate GetDueDate ();
    Book GetBook(std::vector<Book> books);
    Member GetMember(std::vector<Member> members);
    bool isOverDue ();
    LoanedBook *Prev();
    LoanedBook *Next();
    void SetPrev(LoanedBook* p);
    void SetNext(LoanedBook* n);
};

Book* InitialiseBooks ();
Member* InitialiseMembers();
LoanedBook* InitialseLoans();
}

namespace QtHelpers
{
void ParseString(QString input, QString *output);
int ErrorMessageBox(QString errorName, QString errorText);
int InformationMessageBox(QString infoName, QString infoText);
QDate QDateFromQString (QString input);
}
#endif // LIBRARYSYSTEMS_H
