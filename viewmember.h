#ifndef VIEWMEMBER_H
#define VIEWMEMBER_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class ViewMember;
}

class ViewMember : public QWidget
{
    Q_OBJECT

public:
    ViewMember(LibSystems::Member *member, LibSystems::LoanedBook *loans, QWidget *parent = nullptr);
    ViewMember(LibSystems::Account *member, LibSystems::LoanedBook *loans, QWidget *parent = nullptr);
    ~ViewMember();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewMember *ui;
};

#endif // VIEWMEMBER_H
