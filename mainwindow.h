#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private slots:
    void on_logout_button_clicked();

    void on_addbook_button_clicked();

    void on_viewbook_button_clicked();

    void on_addmember_button_clicked();

    void on_viewmember_button_clicked();

    void on_overduebooks_button_clicked();

    void on_checkoutbooks_button_clicked();

private:
    Ui::MainWindow *ui;
    LibSystems::Account *user;
    LibSystems::Book *books = nullptr;
    LibSystems::Member *members = nullptr;
    LibSystems::LoanedBook *loans = nullptr;
    QWidget *activeElement = new QWidget;
    QScrollArea *qScroll = new QScrollArea;
    QPushButton *activeButton = nullptr;

    void ClearActiveArea();
    void SetActiveButton (QPushButton *pressed);
};
#endif // MAINWINDOW_H
