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
    ViewMember(LibSystems::Member *m, LibSystems::LoanedBook *loans, QWidget *parent);
    ViewMember(LibSystems::Member *m, LibSystems::LoanedBook *loans, LibSystems::Account *u, QWidget *parent = nullptr);
    ViewMember(LibSystems::Account *m, LibSystems::LoanedBook *loans, QWidget *parent = nullptr);
    ~ViewMember();

signals:
    void EmitMember(LibSystems::Member *member);

private slots:
    void SendReminder();
    void EditMember();

private:
    Ui::ViewMember *ui;
    LibSystems::Member *member;
};

#endif // VIEWMEMBER_H
