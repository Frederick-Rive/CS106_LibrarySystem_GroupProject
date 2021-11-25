#ifndef OVERDUEBOOKS_H
#define OVERDUEBOOKS_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class OverdueBooks;
}

class OverdueBooks : public QWidget
{
    Q_OBJECT

public:
    explicit OverdueBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent = nullptr);
    ~OverdueBooks();

private:
    Ui::OverdueBooks *ui;
    LibSystems::Book *book;
    LibSystems::Member *member;
    LibSystems::LoanedBook *loan;
};

#endif // OVERDUEBOOKS_H
