#include "librarysystems.h"

using namespace LibSystems;

int Book::totalBooks = 0;
int Member::totalMembers = 0;
int LoanedBook::totalLoans = 0;

int ErrorMessageBox(QString errorName, QString errorText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
    error->setText(errorName);
    error->setDetailedText(errorText);
    error->setModal(true);
    return error->exec();
}

void ParseString (QString input, QString *output) //turns the information we get from the file into usable data
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

QDate QDateFromQString (QString input) //turns a QString into a QDate (only use if the qstring is in yyyymmdd format)
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

Book::Book(int i, QString t, QString a, QString g, int p, int d, QDate r, bool iA) //constructor
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
void Book::WriteToMemory () //writes the book into the database. please be careful not to duplicate books in the database
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
int Book::GetISBN() { return isbn; } //getters (not many setters since most of that should be done in the edit book function)
int Book::GetDeweyDecimal() { return dewey; }
QString Book::GetTitle() { return title; }
QString Book::GetAuthor() { return author; }
QString Book::GetGenre() { return genre; }
int Book::GetPageCount() { return pgCount; }
QDate Book::GetReleaseDate() { return releaseDate; }
int Book::Count() { return totalBooks; }
bool Book::IsAvailable() { return isAvailable; }
void Book::SetAvailable(bool b) { isAvailable = b; }

Account::Account (QString u, QString p) //constructor
{
    username = u;
    password = p;
}
QString Account::GetUsername() { return username; }//getters
QString Account::GetPassword() { return password; }
bool Account::CheckUsername(QString check) { return (check == username); }
bool Account::CheckPassword(QString check) { return (check == password); }

Member::Member(int i, QString u, QString p, QString e, QString c, int l[5]) //constructor
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

    totalMembers++;
    WriteToMemory();
}
void Member::WriteToMemory () //write to memory
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
int Member::GetIndex() { return index; } //getters
QString Member::GetEmail() { return email; }
QString Member::GetContactNumber() { return contactNo; }
int Member::Count() { return totalMembers; }
/*LoanedBook Member::GetLoanedBook (int index)
{

}
*/
void Member::DisplayLoanedBooks () //this will probably do some widget stuff
{

}
void Member::CheckoutBook (int bookIndex) //checks out a book. pass in the index of the book
{
    //LoanedBook loaned = LoanedBook(LoanedBook()::Count(),
}
void Member::ReturnBook (int loanIndex) //returns a book. pass in the index of the loanedbook
{

}
void Member::EditMember() //who knows
{

}

LoanedBook::LoanedBook (int i, int b, int m, QDate dd) //constructor
{
    index = i;
    book = b;
    member = m;
    dueDate = dd;
    totalLoans++;
    WriteToMemory();
}
void LoanedBook::WriteToMemory() //writes to memory
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
int LoanedBook::GetIndex() { return index; } //getters
int LoanedBook::Count() { return totalLoans; }
QDate LoanedBook::GetDueDate () { return dueDate; }
Book LoanedBook::GetBook(std::vector<Book> books) { return books[book]; }
Member LoanedBook::GetMember(std::vector<Member> members) { return members[member]; }
Book LoanedBook::GetBook () //overloaded getter that creates the book from the file information
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
Member LoanedBook::GetMember () //overloaded getter that creates the member from the file information
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
bool LoanedBook::isOverDue () //checks if book is overdue
{
    QDate current = QDate::currentDate();
    return (current.dayOfYear() >= dueDate.dayOfYear()); // !!! DOES NOT ACCOUNT FOR BOOKS CHECKED OUT LATE IN YEAR WHICH ARE DUE EARLY NEXT YEAR !!!
}
