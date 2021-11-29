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
    OverdueBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent = nullptr);
    OverdueBooks(LibSystems::Book *b, LibSystems::Account *a, LibSystems::LoanedBook *l, QWidget *parent = nullptr);

    OverdueBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, int time, QWidget *parent = nullptr);
    OverdueBooks(LibSystems::Book *b, LibSystems::Account *a, LibSystems::LoanedBook *l, int time, QWidget *parent = nullptr);
    ~OverdueBooks();

signals:
    void DisplayMember(LibSystems::Member *m);

private slots:
    void EmitMember();

private:
    Ui::OverdueBooks *ui;
    LibSystems::Member *member;
};

#endif // OVERDUEBOOKS_H
