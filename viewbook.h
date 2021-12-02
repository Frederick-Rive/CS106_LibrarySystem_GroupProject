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
    ViewBook(LibSystems::Book *book, LibSystems::Account *u, QWidget *parent = nullptr);
    ViewBook(LibSystems::Book *book, QWidget *parent = nullptr);
    ~ViewBook();

signals:
    void Finish();
    void EmitBook(LibSystems::Book *book);

private slots:
    void ReserveBook();
    void EditBook();

private:
    Ui::ViewBook *ui;
    LibSystems::Book *book;
    LibSystems::Account *user;
};

#endif // VIEWBOOK_H
