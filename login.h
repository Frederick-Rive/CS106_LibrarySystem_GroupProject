#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMainWindow>
#include <librarysystems.h>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::login *ui;
    LibSystems::Account *acc;
    LibSystems::Book *books = new LibSystems::Book();
    LibSystems::Member *members = new LibSystems::Member();
    LibSystems::LoanedBook *loans = new LibSystems::LoanedBook();
};

#endif // LOGIN_H
