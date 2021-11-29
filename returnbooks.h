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
    explicit ReturnBooks(LibSystems::LoanedBook *l, LibSystems::Book *b, LibSystems::Member *m, QWidget *parent = nullptr);
    ~ReturnBooks();

signals:
    void Finish();

private slots:
    void ReturnBook();
    void FlagReturned();

private:
    Ui::ReturnBooks *ui;
    LibSystems::Book *books;
    LibSystems::Member *members;
    LibSystems::LoanedBook *loan;
};

#endif // RETURNBOOKS_H
