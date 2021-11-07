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
    return error->exec();
}

int QtHelpers::InformationMessageBox(QString infoName, QString infoText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Ok);
    error->setWindowTitle(infoName);
    error->setText(infoText);
    error->setModal(true);
    return error->exec();
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

Book::Book(int i, QString t, QString a, QString g, QString iP, int p, int d, QDate r, bool iA) //constructor
{
    isbn = i;
    title = t;
    author = a;
    genre = g;
    imgPath = iP;
    pgCount = p;
    dewey = d;
    releaseDate = r;
    isAvailable = iA;
    totalBooks++; //increment up the total number of books
}
void Book::WriteToMemory () //writes the book into the database. please be careful not to duplicate books in the database
{
    QFile bookFile("databases/books.csv");

    if (!bookFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; } // !!! add a warning message box !!!

    QTextStream out(&bookFile);

    int y, m, d;
    releaseDate.getDate(&y, &m, &d); //convert the date into 3 ints, that can be written into a file

    out << isbn << ',' << title << ',' << author << ',' << genre << ',' << imgPath << ',' << pgCount << ',' << dewey << ',' << y << m << d << ',' << isAvailable << '\n'; //write the bok data into the file

    bookFile.flush(); //flush the buffer into the file
    bookFile.close(); //close the file
}
int Book::GetISBN() { return isbn; } //getters
int Book::GetDeweyDecimal() { return dewey; }
QString Book::GetTitle() { return title; }
QString Book::GetAuthor() { return author; }
QString Book::GetGenre() { return genre; }
int Book::GetPageCount() { return pgCount; }
QDate Book::GetReleaseDate() { return releaseDate; }
int Book::Count() { return totalBooks; }
bool Book::IsAvailable() { return isAvailable; }
void Book::SetAvailable(bool b) { isAvailable = b; } //only a setter for this value. All others should only be changed from within the editbook function
QString Book::EditBook(int i, QString t, QString a, QString g, int p, int d, QDate r) //operates basically as a new constructor, except it returns a string ready to be inserted into a file
{
    isbn = i;
    title = t;
    author = a;
    genre = g;
    pgCount = p;
    dewey = d;
    releaseDate = r;

    int y, m, dy;
    releaseDate.getDate(&y, &m, &dy); //convert the date into 3 ints, that can be written into a file

    QTextStream rtrn;

    rtrn << isbn << ',' << title << ',' << author << ',' << genre << ',' << pgCount << ',' << dewey << ',' << y << m << dy << ',' << isAvailable << '\n';

    return rtrn.readLine();
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
LoanedBook Account::GetLoanedBook(int index) { return LoanedBook (-1, -1, -1, QDate::currentDate()); } //virtual functions, placeholder definitions
LoanedBook Account::GetLoanedBook(int index, LoanedBook *ptr) { return LoanedBook (-1, -1, -1, QDate::currentDate()); } //this is so we can store the users account as an account pointer
void Account::DisplayLoanedBooks() { return; }                                                                          //and still use these functions if they are a member
void Account::CheckoutBook(int bookIndex) { return; }
void Account::ReturnBook(int loanIndex) { return; }
int Account::GetIndex() { return -1; }
QString Account::GetEmail() { return "NULL"; }
QString Account::GetContactNumber() { return "NULL"; }

Member::Member(int i, QString u, QString p, QString e, QString c, int l[5]) //constructor
{
    index = i;
    username = u;
    password = p;
    email = e;
    contactNo = c;

    for (int i = 0; i < 5; i++)
    {
        loanedBooks[i] = l[i]; //indexes of loaned books. store as -1 if the user hasnt loaned a book in that slot
    }

    totalMembers++;
}
void Member::WriteToMemory () //write to memory
{
    QFile memberFile("databases/members.csv");

    if (!memberFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; } // !!! warning message box !!! also all of these should be opened in append mode but its gonna get replaced so i dont care !!!

    QTextStream out(&memberFile);

    out << username << ',' << password << ',' << email << ',' << contactNo; //send data to textstream

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
int Member::Count() { return totalMembers; }
LoanedBook Member::GetLoanedBook (int index, LoanedBook *ptr) { return *(ptr + loanedBooks[index]); }
LoanedBook Member::GetLoanedBook (int index) //getter that writes a new loanedbook object (please do not duplicate loanedbook objects)
{
    QFile loanFile ("databases/loans.csv"); //temp file location (no file actually stored there)

    if (loanFile.open(QIODevice::ReadOnly | QIODevice::Text)) //attempt to open the file in readonly mode
    {
        QTextStream in (&loanFile); //create textstream and string
        QString read;

        for (int i = 0; i <= loanedBooks[index]; i++)
        {
            read = in.readLine(); //overwrites prev line until you reach the one you want
        }

        QString parsed[4]; //create an array of QStrings with a length equal to the number of comma-seperated-strings within the read string
        int l[3]; //create an array of ints equal to the number of ints in the object we are creating

        QtHelpers::ParseString(read, &parsed[0]); //divide the line into strings based on comma placements
        l[0] = parsed[0].toInt(); //convert the strings that store int values to ints
        l[1] = parsed[1].toInt();
        l[2] = parsed[2].toInt();
        QDate date = QtHelpers::QDateFromQString(parsed[3]); //convert the string that stores a date variable to a qdate

        return LoanedBook(l[0], l[1], l[2], date); //create a loanedbook object based on variables gotten from the string, and return it
    }
}
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
}
void LoanedBook::WriteToMemory() //writes to memory
{
    QFile loanFile("databases/loans.csv");

    if (!loanFile.open(QIODevice::WriteOnly | QIODevice::Text)) { return; }

    QTextStream out(&loanFile);

    int y, m, d;
    dueDate.getDate(&y, &m, &d); //convert date to ints, so it can be written into the file

    out << index << ',' << book << ',' << member << ',' << y << m << d << '\n';

    loanFile.flush(); //flush buffer into file
    loanFile.close(); //close
}
int LoanedBook::GetIndex() { return index; } //getters
int LoanedBook::Count() { return totalLoans; }
QDate LoanedBook::GetDueDate () { return dueDate; }
Book LoanedBook::GetBook(std::vector<Book> books) { return books[book]; }
Member LoanedBook::GetMember(std::vector<Member> members) { return members[member]; }
Book LoanedBook::GetBook () //overloaded getter that creates the book from the file information (please do not create duplicate books)
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

        QString parsed[9];
        int isbn, pgCount, dewey;
        QDate releaseDate;
        bool isAvailable;

        QtHelpers::ParseString(read, &parsed[0]);

        isbn = parsed[0].toInt();
        pgCount = parsed[5].toInt();
        dewey = parsed[6].toInt();
        isAvailable = (parsed[8] == '1') ? true : false;
        releaseDate = QtHelpers::QDateFromQString(parsed[7]);

        return Book(isbn, parsed[1], parsed[2], parsed[3], parsed[4], pgCount, dewey, releaseDate, isAvailable);
    }
}
Member LoanedBook::GetMember () //overloaded getter that creates the member from the file information (please do not duplicate members)
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

        QtHelpers::ParseString(read, &parsed[0]);

        loaned[0] = parsed[4].toInt();
        loaned[1] = parsed[5].toInt();
        loaned[2] = parsed[6].toInt();
        loaned[3] = parsed[7].toInt();
        loaned[4] = parsed[8].toInt();

        return Member(member, parsed[0], parsed[1], parsed[2], parsed[3], loaned);
    }
}
bool LoanedBook::isOverDue () //checks if book is overdue
{
    QDate current = QDate::currentDate();
    return (current.dayOfYear() >= dueDate.dayOfYear()); // !!! DOES NOT ACCOUNT FOR BOOKS CHECKED OUT LATE IN YEAR WHICH ARE DUE EARLY NEXT YEAR !!!
}

/*unclear if we will go this way yet, but the following 3 functions dynamically create all of their respective objects that are stored in files, place them in a vector (consecutive
 * memory locations), then return a pointer to the first object in the vector. with the number of objects we will be working with, this shouldn't use too much RAM and should be fine.
 * if we do go with this method then we will need to avoid calling any function that writes a new object from the files whenever possible.
 * also feel free to overwrite everything, as long as it produces the same result i don't care.
*/

Book *InitialiseBooks()
{
    QFile bookFile ("databases/books.csv");

    std::vector<Book*> bookVec;

    if (bookFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in (&bookFile);

        while (!in.atEnd())
        {
            QString read;

            read = in.readLine();

            QString parsed[9];
            int isbn, pgCount, dewey;
            QDate releaseDate;
            bool isAvailable;

            QtHelpers::ParseString(read, &parsed[0]);

            isbn = parsed[0].toInt();
            pgCount = parsed[5].toInt();
            dewey = parsed[6].toInt();
            isAvailable = (parsed[8] == '1') ? true : false;
            releaseDate = QtHelpers::QDateFromQString(parsed[7]);

            bookVec.push_back(new Book(isbn, parsed[1], parsed[2], parsed[3], parsed[4], pgCount, dewey, releaseDate, isAvailable));
        }
        return bookVec[0];
    }
    return nullptr;
}

Member *InitialseMembers()
{
    QFile memberFile ("databases/members.csv");

    std::vector<Member*> members;

    if (memberFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in (&memberFile);

        while (!in.atEnd())
        {
            QString read;

            read = in.readLine();

            QString parsed[9];
            int loaned[5];

            QtHelpers::ParseString(read, &parsed[0]);

            loaned[0] = parsed[4].toInt();
            loaned[1] = parsed[5].toInt();
            loaned[2] = parsed[6].toInt();
            loaned[3] = parsed[7].toInt();
            loaned[4] = parsed[8].toInt();

            members.push_back(new Member(Member::Count(), parsed[0], parsed[1], parsed[2], parsed[3], loaned));
        }
        return members[0];
    }
    return nullptr;
}

LoanedBook *InitialseLoans()
{
    QFile loanFile ("databases/loans.csv");

    std::vector<LoanedBook*> loans;

    if (loanFile.open(QIODevice::ReadOnly | QIODevice::Text))
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

            loans.push_back(new LoanedBook(l[0], l[1], l[2], date));
        }
        return loans[0];
    }
    return nullptr;
}
