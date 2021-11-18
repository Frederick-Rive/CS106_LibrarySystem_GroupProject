#ifndef MEMBERINFO_H
#define MEMBERINFO_H
#include <QPushButton>
#include "librarysystems.h"

class MemberInfo : public QPushButton
{
    Q_OBJECT

private:
    LibSystems::Member *member;

public:
    MemberInfo(LibSystems::Member *m, QWidget *parent = nullptr);

public slots:
    void memberClicked();

signals:
    void SendMember(LibSystems::Member *member);
};
#endif // MEMBERINFO_H
