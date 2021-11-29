#ifndef CUSTOMCHECKOUTBOOKS_H
#define CUSTOMCHECKOUTBOOKS_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class CustomCheckoutBooks;
}

class CustomCheckoutBooks : public QWidget
{
    Q_OBJECT

public:
    explicit CustomCheckoutBooks(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, QWidget *parent = nullptr);
    ~CustomCheckoutBooks();

signals:
    void Finish();

private slots:
    void on_pushButton_clicked();

    void on_memberEdit_editingFinished();

    void on_bookEdit_editingFinished();

private:
    Ui::CustomCheckoutBooks *ui;
    LibSystems::Book *books, *selectedBook;
    LibSystems::Member *members, *selectedMember;
    LibSystems::LoanedBook *loans;
};

#endif // CUSTOMCHECKOUTBOOKS_H
