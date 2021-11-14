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
    explicit login(QWidget *parent = nullptr, QMainWindow *m = nullptr, LibSystems::Account *acc = nullptr, LibSystems::Member *memb = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::login *ui;
    LibSystems::Account *rtrn;
    LibSystems::Member *members;
    QMainWindow *mn;
};

#endif // LOGIN_H
