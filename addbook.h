#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>

namespace Ui {
class AddBook;
}

class AddBook : public QWidget
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();

private slots:
    void on_ddSlider_valueChanged(int value);

    void on_ddCounter_valueChanged(int arg1);
private:
    Ui::AddBook *ui;
};

#endif // ADDBOOK_H
