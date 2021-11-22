#ifndef VIEWBOOK_H
#define VIEWBOOK_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class ViewBook;
}

class ViewBook : public QWidget
{
    Q_OBJECT

public:
    explicit ViewBook(LibSystems::Book *book, QWidget *parent = nullptr);
    ~ViewBook();

private:
    Ui::ViewBook *ui;
    LibSystems::Book *book;
};

#endif // VIEWBOOK_H
