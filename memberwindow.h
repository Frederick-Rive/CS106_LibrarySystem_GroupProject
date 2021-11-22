#ifndef MEMBERWINDOW_H
#define MEMBERWINDOW_H

#include <QMainWindow>
#include "librarysystems.h"
#include <QScrollArea>

namespace Ui {
class MemberWindow;
}

class MemberWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MemberWindow(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, LibSystems::Account *a, QWidget *parent = nullptr);
    ~MemberWindow();

private slots:
    void on_facebookButton_clicked();

    void on_twitterButton_clicked();

    void on_instaButton_clicked();

    void on_logout_button_clicked();

    void on_viewbooks_button_clicked();

    void DisplayBooks();

    void DisplaySingleBook(LibSystems::Book *book);

private:
    Ui::MemberWindow *ui;
    LibSystems::Account user;
    LibSystems::Book *books = new LibSystems::Book();
    LibSystems::Member *members = new LibSystems::Member();
    LibSystems::LoanedBook *loans = new LibSystems::LoanedBook();
    QWidget *activeElement = new QWidget;
    QWidget *auxWidget = new QWidget;
    QScrollArea *qScroll = new QScrollArea;
    QPushButton *activeButton = nullptr;

    void ClearActiveArea();
    void SetActiveButton (QPushButton *pressed);
};

#endif // MEMBERWINDOW_H
