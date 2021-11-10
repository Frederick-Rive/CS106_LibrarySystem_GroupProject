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
    explicit AddBook(QWidget *parent, std::vector<LibSystems::Book*> b);
    ~AddBook();

private slots:
    void on_ddSlider_valueChanged(int value);

    void on_ddCounter_valueChanged(int arg1);

    void on_coverpathSearch_clicked();

    void on_saveButton_clicked();

private:
    Ui::AddBook *ui;
    std::vector<LibSystems::Book*> bookVec;
};

#endif // ADDBOOK_H
