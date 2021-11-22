#include "librarysystems.h"

using namespace LibSystems; //if you arent using this namespace by default, remember to prefix anything you use from this file with LibSystems::

int Book::totalBooks = 0; //define static variables, used to determine the number of objects of each type
int Member::totalMembers = 0;
int LoanedBook::totalLoans = 0;

int QtHelpers::ErrorMessageBox(QString errorName, QString errorText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
    error->setWindowTitle(errorName);
    error->setText(errorText);
    error->setModal(true);
    error->setMinimumSize(100, 80);
    return error->exec();
}

int QtHelpers::InformationMessageBox(QString infoName, QString infoText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *info = new QMessageBox;
    info->setStandardButtons(QMessageBox::Ok);
    info->setWindowTitle(infoName);
    info->setText(infoText);
    info->setModal(true);
    info->setMinimumSize(100, 80);
    return info->exec();
}

void QtHelpers::ParseString (QString input, QString *output) //turns the string we get from the file into usable data, stored in a QString array.
{ //make sure that the array is the correct size for the number of comma seperated strings within the input string, or else there will be errors
    int i = 0;

    while (input.data()[i] != '\n')
    {
        char c = input.data()[i].toLatin1(); //Qt even has its own chars. i cannot begin to fathom why

        switch(c)
        {
        case ',':
            output++;
            break;
        case '\u0000':
            return;
        default:
            output->append(c);
            break;
        }
        i++;
    }
}

QDate QtHelpers::QDateFromQString (QString input) //turns a QString into a QDate (only use if the qstring is in yyyymmdd format). used to remake dates stored in files
{
    QDate rtrn;
    QString dates[3];
    int i = 0;
    for (char c : input.toStdString())
    {
        switch(c)
        {
        case '/':
            i++;
            break;
        default:
            dates[i].append(c);
            break;
        }
    }

    int y = dates[0].toInt();
    int m = dates[1].toInt();
    int d = dates[2].toInt();

    rtrn.setDate(y, m, d);

    return rtrn;
}

Book::Book(QString i, QString t, QString a, QString g, QString cP, QString b, int p, int d, QDate r, Book* prev, bool iA) //constructor
{
    index = totalBooks;
    isbn = i;
    title = t;
    author = a;
    genre = g;
    coverPath = cP;
    blurb = b;
    pgCount = p;
    dewey = d;
    releaseDate = r;
    isAvailable = iA;

    links[0] = prev;
    links[1] = nullptr;

    totalBooks++; //increment up the total number of books
}
Book::~Book()
{
    totalBooks--;
}
Book::Book() //default constructor. Use only for the head of the linked list
{
    index = -1;
    isbn = "";
    title = "";
    author = "";
    genre = "";
    coverPath = "";
    blurb = "";
    pgCount = -1;
    dewey = -1;
    releaseDate = QDate::currentDate();
    isAvailable = false;

    links[0] = nullptr;
    links[1] = nullptr;
}
void Book::WriteToMemory () //writes the book into the database. please be careful not to duplicate books in the database
{
    QFile bookFile("databases/books.csv");

    if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Append)) { return; } // !!! add a warning message box !!!

    QTextStream out(&bookFile);

    int y, m, d;
    releaseDate.getDate(&y, &m, &d); //convert the date into 3 ints, that can be written into a file

    out << isbn << ',' << title << ',' << author << ',' << genre << ',' << coverPath << ',' << pgCount << ',' << dewey << ',' << y << "/" << m << "/" << d << ',' << isAvailable << ',' << blurb <<'\n'; //write the bok data into the file

    bookFile.flush(); //flush the buffer into the file
    bookFile.close(); //close the file
}
int Book::GetIndex() { return index; }
QString Book::GetISBN() { return isbn; } //getters
int Book::GetDeweyDecimal() { return dewey; }
QString Book::GetTitle() { return title; }
QString Book::GetAuthor() { return author; }
QString Book::GetGenre() { return genre; }
QString Book::GetCoverPath() { return coverPath; }
QPixmap Book::GetCover() { QPixmap rtrn; rtrn.load(coverPath); return rtrn; }
QString Book::GetBlurb() { return blurb; }
int Book::GetPageCount() { return pgCount; }
QDate Book::GetReleaseDate() { return releaseDate; }
Book* Book::Prev() { return links[0]; }
Book* Book::Next() { return links[1]; }
Book* Book::Next(int index) { Book* rtrn = links[1]; for (int i = 0; i < index; i++) { rtrn = rtrn->links[1]; } return rtrn; }
void Book::SetPrev(Book *p) { links[0] = p; }
void Book::SetNext(Book *n) { links[1] = n; }
int Book::Count() { return totalBooks; }
bool Book::IsAvailable() { return isAvailable; }
void Book::SetAvailable(bool b) { isAvailable = b; } //only a setter for this value. All others should only be changed from within the editbook function
QString Book::EditBook(QString i, QString t, QString a, QString g, QString cP, QString b, int p, int d, QDate r) //operates basically as a new constructor, except it returns a string ready to be inserted into a file
{
    isbn = i;
    title = t;
    author = a;
    genre = g;
    blurb = b;
    pgCount = p;
    dewey = d;
    releaseDate = r;

    int y, m, dy;
    releaseDate.getDate(&y, &m, &dy); //convert the date into 3 ints, that can be written into a file

    QString rtrn;
    QTextStream ts(&rtrn);

    ts << isbn << ',' << title << ',' << author << ',' << genre << ',' << coverPath << ',' << pgCount << ',' << dewey << ',' << y << "/" << m << "/" << dy << ',' << isAvailable << ',' << blurb;

    return rtrn;
}

Account::Account (QString u, QString p) //constructor
{
    username = u;
    password = p;
}
QString Account::GetUsername() { return username; }//getters
QString Account::GetPassword() { return password; }
bool Account::CheckUsername(QString check) { return (check == username); } //use these to validate login data
bool Account::CheckPassword(QString check) { return (check == password); }
int Account::GetLoanedBook(int index) { return -1; }//this is so we can store the users account as an account pointer                                                                  //and still use these functions if they are a member
void Account::ReturnBook(int loanIndex) { return; }
int Account::GetIndex() { return -1; }
QString Account::GetEmail() { return "NULL"; }
QString Account::GetContactNumber() { return "NULL"; }
QString Account::GetFirstName() { return "NULL"; }
QString Account::GetLastName() { return "NULL"; }
QString Account::GetFullName() { return "NULL"; }
QDate Account::GetDOB() { return QDate::currentDate(); }

Member::Member(int i, QString u, QString p, QString e, QString c, QString fN, QString lN, QDate d, int l[5], Member *prev) //constructor
{
    index = i;
    username = u;
    password = p;
    email = e;
    contactNo = c;
    firstName = fN;
    lastName = lN;
    dob = d;

    links[0] = prev;
    links[1] = nullptr;

    for (int i = 0; i < 5; i++)
    {
        loanedBooks[i] = l[i]; //indexes of loaned books. store as -1 if the user hasnt loaned a book in that slot
    }

    totalMembers++;
}
Member::Member() //constructor
{
    index = -1;
    username = "";
    password = "";
    email = "";
    contactNo = "";
    firstName = "";
    lastName = "";
    dob = QDate::currentDate();

    links[0] = nullptr;
    links[1] = nullptr;

    for (int i = 0; i < 5; i++)
    {
        loanedBooks[i] = -1; //indexes of loaned books. store as -1 if the user hasnt loaned a book in that slot
    }
}
Member::~Member()
{
    totalMembers--;
}
void Member::WriteToMemory () //write to memory
{
    QFile memberFile("databases/members.csv");

    if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Append)) { return; } // !!! warning message box !!!

    QTextStream out(&memberFile);

    int d, m, y;
    dob.getDate(&y, &m, &d);

    out << username << ',' << password << ',' << email << ',' << contactNo << ',' << firstName << ',' << lastName << ',' << y << '/' << m << '/' << d; //send data to textstream

    for (int i : loanedBooks) //add the books the member has loaned to the file
    {
        out << ',' << i;
    }

    out << '\n';

    memberFile.flush(); //flush buffer into file
    memberFile.close(); //close file
}
int Member::GetIndex() { return index; } //getters
QString Member::GetEmail() { return email; }
QString Member::GetContactNumber() { return contactNo; }
QString Member::GetFirstName() { return firstName; }
QString Member::GetLastName() { return lastName; }
QString Member::GetFullName() { return firstName + " " + lastName; }
QDate Member::GetDOB() { return dob; }
Member* Member::Prev() { return links[0]; }
Member* Member::Next() { return links[1]; }
Member* Member::Next(int index) { Member* rtrn = links[1]; for (int i = 0; i < index; i++) { rtrn = rtrn->links[1]; } return rtrn; }
void Member::SetPrev(Member *p) { links[0] = p; }
void Member::SetNext(Member *n) { links[1] = n; }
int Member::Count() { return totalMembers; }
int Member::GetLoanedBook (int index) { return loanedBooks[index]; }
void Member::SetLoanedBook (int index, int loan) { loanedBooks[index] = loan; }
void Member::ReturnBook (int loanIndex) //returns a book. pass in the index of the loanedbook
{

}
QString Member::EditMember(QString u, QString p, QString e, QString c, QString fN, QString lN, QDate date)
{
    username = u;
    password = p;
    email = e;
    contactNo = c;
    firstName = fN;
    lastName = lN;
    dob = date;

    int d, m, y;
    dob.getDate(&y, &m, &d);

    QString rtrn;
    QTextStream ts(&rtrn);

    ts << username << ',' << password << ',' << email << ',' << contactNo << ',' << firstName << ',' << lastName << ',' << y << '/' << m << '/' << d; //send data to textstream

    for (int i : loanedBooks)
    {
        ts << ',' << i;
    }

    return rtrn;
}

LoanedBook::LoanedBook (int i, int b, int m, QDate dd, LoanedBook *prev) //constructor
{
    index = i;
    book = b;
    member = m;
    dueDate = dd;

    links[0] = prev;
    links[1] = nullptr;

    totalLoans++;
}
LoanedBook::LoanedBook () //constructor
{
    index = -1;
    book = -1;
    member = -1;
    dueDate = QDate::currentDate();

    links[0] = nullptr;
    links[1] = nullptr;

}
LoanedBook::~LoanedBook()
{
    totalLoans--;
}
void LoanedBook::WriteToMemory() //writes to memory
{
    QFile loanFile("databases/loans.csv");

    if (!loanFile.open(QIODevice::WriteOnly | QIODevice::Append)) { return; }

    QTextStream out(&loanFile);

    int y, m, d;
    dueDate.getDate(&y, &m, &d); //convert date to ints, so it can be written into the file

    out << index << ',' << book << ',' << member << ',' << y << '/' << m<< '/' << d << '\n';

    loanFile.flush(); //flush buffer into file
    loanFile.close(); //close
}
int LoanedBook::GetIndex() { return index; } //getters
int LoanedBook::Count() { return totalLoans; }
QDate LoanedBook::GetDueDate () { return dueDate; }
Book* LoanedBook::GetBook(Book *books) { return books->Next(book); }
Member* LoanedBook::GetMember(Member *members) { return members->Next(member); }
LoanedBook* LoanedBook::Prev() { return links[0]; }
LoanedBook* LoanedBook::Next() { return links[1]; }
LoanedBook* LoanedBook::Next(int index) { LoanedBook* rtrn = links[1]; for (int i = 0; i < index; i++) { rtrn = rtrn->links[1]; } return rtrn; }
void LoanedBook::SetPrev(LoanedBook *p) { links[0] = p; }
void LoanedBook::SetNext(LoanedBook *n) { links[1] = n; }
bool LoanedBook::isOverDue () //checks if book is overdue
{
    QDate current = QDate::currentDate();
    return (current.dayOfYear() >= dueDate.dayOfYear()); // !!! DOES NOT ACCOUNT FOR BOOKS CHECKED OUT LATE IN YEAR WHICH ARE DUE EARLY NEXT YEAR !!!
}

Book* LibSystems::InitialiseBooks()
{
    QFile bookFile ("databases/books.csv");

    std::vector<Book*> bookVec;

    if (bookFile.open(QIODevice::ReadOnly | QIODevice::Text) && !bookFile.atEnd())
    {
        QTextStream in (&bookFile);

        while (!in.atEnd())
        {
            QString read;

            read = in.readLine();

            QString parsed[10];
            int pgCount, dewey;
            QDate releaseDate;
            bool isAvailable;

            QtHelpers::ParseString(read, &parsed[0]);

            pgCount = parsed[5].toInt();
            dewey = parsed[6].toInt();
            isAvailable = (parsed[8][0] == '1') ? true : false;
            releaseDate = QtHelpers::QDateFromQString(parsed[7]);
            if (bookVec.size() == 0)
            {
                bookVec.push_back(new Book(parsed[0], parsed[1], parsed[2], parsed[3], parsed[4], parsed[9], pgCount, dewey, releaseDate, nullptr, isAvailable));
            }
            else
            {
                bookVec.push_back(new Book(parsed[0], parsed[1], parsed[2], parsed[3], parsed[4], parsed[9], pgCount, dewey, releaseDate, bookVec[bookVec.size() - 1], isAvailable));
                bookVec[bookVec.size() - 2]->SetNext(bookVec[bookVec.size() - 1]);
            }
        }
        return bookVec[0];
    }
    return nullptr;
}

Member* LibSystems::InitialiseMembers()
{
    QFile memberFile ("databases/members.csv");

    std::vector<Member*> members;

    if (memberFile.open(QIODevice::ReadOnly | QIODevice::Text) && !memberFile.atEnd())
    {
        QTextStream in (&memberFile);

        while (!in.atEnd())
        {
            QString read;

            read = in.readLine();

            QString parsed[12];
            int loaned[5];

            QtHelpers::ParseString(read, &parsed[0]);

            QDate dob = QtHelpers::QDateFromQString(parsed[6]);

            loaned[0] = parsed[7].toInt();
            loaned[1] = parsed[8].toInt();
            loaned[2] = parsed[9].toInt();
            loaned[3] = parsed[10].toInt();
            loaned[4] = parsed[11].toInt();

            if (members.size() == 0)
            {
                members.push_back(new Member(Member::Count(), parsed[0], parsed[1], parsed[2], parsed[3], parsed[4], parsed[5], dob, loaned, nullptr));
            }
            else
            {
                members.push_back(new Member(Member::Count(), parsed[0], parsed[1], parsed[2], parsed[3], parsed[4], parsed[5], dob, loaned, members[members.size() - 1]));
                members[members.size() - 2]->SetNext(members[members.size() - 1]);
            }
        }
        return members[0];
    }
    return nullptr;
}

LoanedBook* LibSystems::InitialseLoans()
{
    QFile loanFile ("databases/loans.csv");

    std::vector<LoanedBook*> loans;

    if (loanFile.open(QIODevice::ReadOnly | QIODevice::Text) && !loanFile.atEnd())
    {
        QTextStream in (&loanFile);

        while (!in.atEnd())
        {
            QString read;

            read = in.readLine();

            QString parsed[4];
            int l[3];

            QtHelpers::ParseString(read, &parsed[0]);
            l[0] = parsed[0].toInt();
            l[1] = parsed[1].toInt();
            l[2] = parsed[2].toInt();
            QDate date = QtHelpers::QDateFromQString(parsed[3]);

            if (loans.size() == 0)
            {
                loans.push_back(new LoanedBook(l[0], l[1], l[2], date, nullptr));
            }
            else
            {
                loans.push_back(new LoanedBook(l[0], l[1], l[2], date, loans[loans.size() - 1]));
                loans[loans.size() - 2]->SetNext(loans[loans.size() - 1]);
            }
        }
        return loans[0];
    }
    return nullptr;
}

