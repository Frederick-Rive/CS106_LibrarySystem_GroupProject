/********************************************************************************
** Form generated from reading UI file 'addmember.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDMEMBER_H
#define UI_ADDMEMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddMember
{
public:
    QLabel *label_2;
    QLineEdit *usernameEntry;
    QLabel *label_3;
    QLineEdit *passwordEntry;
    QCheckBox *showPassword;
    QLabel *label_4;
    QLineEdit *emailEntry;
    QLineEdit *cntctEntry;
    QLabel *label_5;
    QPushButton *pushButton;
    QLabel *label_6;
    QLineEdit *firstnameEntry;
    QLineEdit *lastnameEntry;
    QLabel *label_7;
    QSpinBox *dayEntry;
    QSpinBox *monthEntry;
    QSpinBox *yearEntry;
    QLabel *label_9;
    QLabel *label_10;

    void setupUi(QWidget *AddMember)
    {
        if (AddMember->objectName().isEmpty())
            AddMember->setObjectName(QString::fromUtf8("AddMember"));
        AddMember->resize(780, 449);
        AddMember->setMinimumSize(QSize(780, 380));
        label_2 = new QLabel(AddMember);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 20, 170, 31));
        label_2->setMinimumSize(QSize(170, 0));
        label_2->setMaximumSize(QSize(170, 16777215));
        usernameEntry = new QLineEdit(AddMember);
        usernameEntry->setObjectName(QString::fromUtf8("usernameEntry"));
        usernameEntry->setGeometry(QRect(190, 20, 481, 31));
        label_3 = new QLabel(AddMember);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 170, 31));
        label_3->setMinimumSize(QSize(170, 0));
        label_3->setMaximumSize(QSize(170, 16777215));
        passwordEntry = new QLineEdit(AddMember);
        passwordEntry->setObjectName(QString::fromUtf8("passwordEntry"));
        passwordEntry->setGeometry(QRect(190, 80, 481, 31));
        passwordEntry->setEchoMode(QLineEdit::Password);
        showPassword = new QCheckBox(AddMember);
        showPassword->setObjectName(QString::fromUtf8("showPassword"));
        showPassword->setGeometry(QRect(700, 80, 71, 31));
        showPassword->setCursor(QCursor(Qt::PointingHandCursor));
        label_4 = new QLabel(AddMember);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 260, 170, 31));
        label_4->setMinimumSize(QSize(170, 0));
        label_4->setMaximumSize(QSize(170, 16777215));
        emailEntry = new QLineEdit(AddMember);
        emailEntry->setObjectName(QString::fromUtf8("emailEntry"));
        emailEntry->setGeometry(QRect(190, 260, 481, 31));
        cntctEntry = new QLineEdit(AddMember);
        cntctEntry->setObjectName(QString::fromUtf8("cntctEntry"));
        cntctEntry->setGeometry(QRect(190, 320, 481, 31));
        label_5 = new QLabel(AddMember);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 320, 170, 31));
        label_5->setMinimumSize(QSize(170, 0));
        label_5->setMaximumSize(QSize(170, 16777215));
        pushButton = new QPushButton(AddMember);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 390, 181, 41));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        label_6 = new QLabel(AddMember);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 140, 170, 31));
        label_6->setMinimumSize(QSize(170, 0));
        label_6->setMaximumSize(QSize(170, 16777215));
        firstnameEntry = new QLineEdit(AddMember);
        firstnameEntry->setObjectName(QString::fromUtf8("firstnameEntry"));
        firstnameEntry->setGeometry(QRect(190, 140, 231, 31));
        firstnameEntry->setEchoMode(QLineEdit::Normal);
        lastnameEntry = new QLineEdit(AddMember);
        lastnameEntry->setObjectName(QString::fromUtf8("lastnameEntry"));
        lastnameEntry->setGeometry(QRect(440, 140, 231, 31));
        lastnameEntry->setEchoMode(QLineEdit::Normal);
        label_7 = new QLabel(AddMember);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 200, 170, 21));
        label_7->setMinimumSize(QSize(170, 0));
        label_7->setMaximumSize(QSize(170, 16777215));
        dayEntry = new QSpinBox(AddMember);
        dayEntry->setObjectName(QString::fromUtf8("dayEntry"));
        dayEntry->setGeometry(QRect(190, 200, 51, 31));
        dayEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dayEntry->setMinimum(1);
        dayEntry->setMaximum(31);
        monthEntry = new QSpinBox(AddMember);
        monthEntry->setObjectName(QString::fromUtf8("monthEntry"));
        monthEntry->setGeometry(QRect(300, 200, 51, 31));
        monthEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        monthEntry->setMinimum(1);
        monthEntry->setMaximum(12);
        yearEntry = new QSpinBox(AddMember);
        yearEntry->setObjectName(QString::fromUtf8("yearEntry"));
        yearEntry->setGeometry(QRect(410, 200, 81, 31));
        yearEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        yearEntry->setMinimum(1);
        yearEntry->setMaximum(2021);
        yearEntry->setValue(2000);
        label_9 = new QLabel(AddMember);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(270, 200, 16, 31));
        label_9->setMinimumSize(QSize(0, 0));
        label_9->setMaximumSize(QSize(170, 16777215));
        label_10 = new QLabel(AddMember);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(380, 200, 16, 31));
        label_10->setMinimumSize(QSize(0, 0));
        label_10->setMaximumSize(QSize(170, 16777215));

        retranslateUi(AddMember);

        QMetaObject::connectSlotsByName(AddMember);
    } // setupUi

    void retranslateUi(QWidget *AddMember)
    {
        AddMember->setWindowTitle(QCoreApplication::translate("AddMember", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("AddMember", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("AddMember", "Password", nullptr));
        showPassword->setText(QCoreApplication::translate("AddMember", "Show", nullptr));
        label_4->setText(QCoreApplication::translate("AddMember", "Email Address", nullptr));
        label_5->setText(QCoreApplication::translate("AddMember", "Contact Number", nullptr));
        pushButton->setText(QCoreApplication::translate("AddMember", "Add Member", nullptr));
        label_6->setText(QCoreApplication::translate("AddMember", "First + Last name", nullptr));
        label_7->setText(QCoreApplication::translate("AddMember", "Date of birth", nullptr));
        label_9->setText(QCoreApplication::translate("AddMember", "/", nullptr));
        label_10->setText(QCoreApplication::translate("AddMember", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddMember: public Ui_AddMember {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDMEMBER_H
