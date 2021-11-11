#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class AddMember;
}

class AddMember : public QWidget
{
    Q_OBJECT

public:
    explicit AddMember(QWidget *parent);
    ~AddMember();

private slots:
    void on_showPassword_clicked(bool checked);

    void on_pushButton_clicked();

private:
    Ui::AddMember *ui;
};

#endif // ADDMEMBER_H
