#include "memberinfo.h"

MemberInfo::MemberInfo(LibSystems::Member *m, QWidget *parent)
{
    member = m;
    setParent(parent);

    connect(this, &QPushButton::clicked, this, &MemberInfo::memberClicked);
}

void MemberInfo::memberClicked()
{
    emit SendMember(member);
}
