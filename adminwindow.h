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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void Edit(LibSystems::Book *book);

public slots:
    void EditBook(LibSystems::Book *book);

private slots:
    void on_logout_button_clicked();

    void on_addbook_button_clicked();

    void on_viewbook_button_clicked();

    void DisplayBooks();

    void on_addmember_button_clicked();

    void on_viewmember_button_clicked();

    void DisplayMembers();

    void on_overduebooks_button_clicked();

    void on_checkoutbooks_button_clicked();

    void on_facebookButton_clicked();

    void on_twitterButton_clicked();

    void on_instaButton_clicked();

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
    void SetActiveButton (QPushButton *pressed);;
};
#endif // ADMINWINDOW_H
