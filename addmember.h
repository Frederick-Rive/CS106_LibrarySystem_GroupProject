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
    explicit AddMember(QWidget *parent, LibSystems::Member *lastMember, LibSystems::Member *editMember = nullptr);
    ~AddMember();

private slots:
    void on_showPassword_clicked(bool checked);

    void on_pushButton_clicked();

    void on_monthEntry_valueChanged(int arg1);

private:
    Ui::AddMember *ui;
    LibSystems::Member *member;
    LibSystems::Member *edit;
};

#endif // ADDMEMBER_H
