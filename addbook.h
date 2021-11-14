#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class AddBook;
}

class AddBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent, LibSystems::Book *lastBook, LibSystems::Book *editBook = nullptr);
    ~AddBook();

private slots:
    void on_ddSlider_valueChanged(int value);

    void on_ddCounter_valueChanged(int arg1);

    void on_coverpathSearch_clicked();

    void on_saveButton_clicked();

    void on_monthEntry_valueChanged(int arg1);

private:
    Ui::AddBook *ui;
    LibSystems::Book *book;
    LibSystems::Book *edit;
};

#endif // ADDBOOK_H
