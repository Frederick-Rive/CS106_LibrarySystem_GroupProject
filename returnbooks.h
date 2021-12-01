#ifndef RETURNBOOKS_H
#define RETURNBOOKS_H

#include <QWidget>
#include "librarysystems.h"

namespace Ui {
class ReturnBooks;
}

class ReturnBooks : public QWidget
{
    Q_OBJECT

public:
    ReturnBooks(LibSystems::LoanedBook *l, LibSystems::Book *b, LibSystems::Member *m, QWidget *parent = nullptr);
    ReturnBooks(LibSystems::LoanedBook *l, LibSystems::Book *b, QWidget *parent = nullptr);
    ~ReturnBooks();

signals:
    void Finish();

private slots:
    void ReturnBook();
    void FlagReturned();
    void FlagNotReturned();

private:
    Ui::ReturnBooks *ui;
    LibSystems::Book *books;
    LibSystems::Member *members;
    LibSystems::LoanedBook *loan;
};

#endif // RETURNBOOKS_H
