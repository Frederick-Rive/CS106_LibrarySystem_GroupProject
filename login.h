#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr, LibSystems::Account *rtrn = nullptr);
    ~login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
