#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include <librarysystems.h>
#include <qscrollarea.h>
#include <QGraphicsDropShadowEffect>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(LibSystems::Book *b, LibSystems::Member *m, LibSystems::LoanedBook *l, LibSystems::Account *a, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void EditBook(LibSystems::Book *book);

    void EditMember(LibSystems::Member *member);

    void HomeScreen();

private slots:
    void on_logout_button_clicked();

    void on_addbook_button_clicked();

    void on_viewbook_button_clicked();

    void DisplayBooks();

    void DisplaySingleBook(LibSystems::Book *book);

    void on_addmember_button_clicked();

    void on_viewmember_button_clicked();

    void DisplayMembers();

    void on_overduebooks_button_clicked();

    void on_checkoutbooks_button_clicked();

    void on_facebookButton_clicked();

    void on_twitterButton_clicked();

    void on_instaButton_clicked();

    void RemoveReservation(int index);

    void DisplaySingleMember(LibSystems::Member *member);

    void DisplayOverdueMember(LibSystems::Member *member);

    void on_returnbooks_button_clicked();

private:
    Ui::MainWindow *ui;
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
#endif // ADMINWINDOW_H
