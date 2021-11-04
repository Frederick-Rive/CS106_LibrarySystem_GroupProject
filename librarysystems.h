#ifndef LIBRARYSYSTEMS_H
#define LIBRARYSYSTEMS_H
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <vector>
#include <QMessageBox>
#include <QDate>

namespace LibSystems
{
    int ErrorMessageBox(QString errorName, QString errorText);
    class LoanedBook; //declarations of things

    class Book //book class
    {
    private: //data members
        int isbn, pgCount, dewey;
        QString title, author, genre;
        bool isAvailable;
        QDate releaseDate;
        static int totalBooks;

    public: //member functions
        void WriteToMemory ();
        Book(int i, QString t, QString a, QString g, int p, int d, QDate r, bool iA = true);
        int GetISBN();
        int GetDeweyDecimal();
        QString GetTitle();
        QString GetAuthor();
        QString GetGenre();
        int GetPageCount();
        QDate GetReleaseDate();
        static int Count();
        bool IsAvailable();
        QString EditBook ();
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
        //virtual *LoanedBook GetLoanedBook();
        /*
        virtual void DisplayLoanedBooks();
        virtual void CheckoutBook();
        virtual void ReturnBook();
        virtual int GetIndex();
        virtual QString GetEmail();
        virtual QString GetContactNumber();
        */
    };

    class Member : public Account //member class is a child of the account class
    {
    private: //data members
        int index, loanedBooks[5]; //loaned books array stores index of loanedbook class
        QString email, contactNo;
        static int totalMembers;

    public:
        Member(int i, QString u, QString p, QString e, QString c, int l[5]);
        void WriteToMemory ();
        int GetIndex();
        QString GetEmail();
        QString GetContactNumber();
        static int Count();
        //LoanedBook GetLoanedBook (int index);
        void DisplayLoanedBooks ();
        void CheckoutBook (int bookIndex);
        void ReturnBook (int loanIndex);
        void EditMember();
    };

    class LoanedBook //loanedbook class contains the index of a book and the member it was lent too, and the date that the book is due.
    {
    private: //data members
        int index, book, member;
        QDate dueDate;
        static int totalLoans;

    public:
        LoanedBook (int i, int b, int m, QDate dd);
        void WriteToMemory();
        int GetIndex();
        static int Count();
        QDate GetDueDate ();
        Book GetBook(std::vector<Book> books);
        Member GetMember(std::vector<Member> members);
        Book GetBook ();
        Member GetMember ();
        bool isOverDue ();
    };

    //QDate QDateFromQString (QString input);
    //void ParseString (QString input, QString *output);

    class LibrarySystems
    {
    public:
        LibrarySystems();
    };
}
#endif // LIBRARYSYSTEMS_H
