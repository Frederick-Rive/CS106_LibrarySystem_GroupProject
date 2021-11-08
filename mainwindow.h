#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <librarysystems.h>
#include <qscrollarea.h>

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

private:
    Ui::MainWindow *ui;
    LibSystems::Account *user;
    std::vector<LibSystems::Book*> bookVector;
    std::vector<LibSystems::Member*> memberVector;
    std::vector<LibSystems::LoanedBook*> loanVector;
    QWidget *activeElement = new QWidget;
    QScrollArea *qScroll = new QScrollArea;
};
#endif // MAINWINDOW_H
