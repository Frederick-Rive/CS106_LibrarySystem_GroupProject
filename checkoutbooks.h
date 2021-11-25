#ifndef CHECKOUTBOOKS_H
#define CHECKOUTBOOKS_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class CheckoutBooks;
}

class CheckoutBooks : public QWidget
{
    Q_OBJECT

public:
    explicit CheckoutBooks(int i, LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent);
    ~CheckoutBooks();

signals:
    void Remove(int i);

private slots:
    void on_confirmButton_clicked();

    void on_dismissButton_clicked();

private:
    Ui::CheckoutBooks *ui;
    int index;
    LibSystems::Book *book;
    LibSystems::Member *member;
    LibSystems::LoanedBook *loans;
};

#endif // CHECKOUTBOOKS_H
