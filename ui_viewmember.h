/********************************************************************************
** Form generated from reading UI file 'viewmember.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWMEMBER_H
#define UI_VIEWMEMBER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewMember
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *indexLabel;
    QLabel *firstnameLabel;
    QLabel *lastnameLabel;
    QLabel *usernameLabel;
    QLabel *contactLabel;
    QLabel *emailLabel;
    QLabel *dobLabel;
    QLabel *bcountLabel;
    QLabel *ocountLabel;
    QPushButton *pushButton;
    QWidget *labels;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *ViewMember)
    {
        if (ViewMember->objectName().isEmpty())
            ViewMember->setObjectName(QString::fromUtf8("ViewMember"));
        ViewMember->resize(940, 450);
        ViewMember->setMinimumSize(QSize(940, 450));
        layoutWidget = new QWidget(ViewMember);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 10, 391, 421));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        indexLabel = new QLabel(layoutWidget);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        indexLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(indexLabel);

        firstnameLabel = new QLabel(layoutWidget);
        firstnameLabel->setObjectName(QString::fromUtf8("firstnameLabel"));
        firstnameLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(firstnameLabel);

        lastnameLabel = new QLabel(layoutWidget);
        lastnameLabel->setObjectName(QString::fromUtf8("lastnameLabel"));
        lastnameLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(lastnameLabel);

        usernameLabel = new QLabel(layoutWidget);
        usernameLabel->setObjectName(QString::fromUtf8("usernameLabel"));
        usernameLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(usernameLabel);

        contactLabel = new QLabel(layoutWidget);
        contactLabel->setObjectName(QString::fromUtf8("contactLabel"));
        contactLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(contactLabel);

        emailLabel = new QLabel(layoutWidget);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(emailLabel);

        dobLabel = new QLabel(layoutWidget);
        dobLabel->setObjectName(QString::fromUtf8("dobLabel"));
        dobLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(dobLabel);

        bcountLabel = new QLabel(layoutWidget);
        bcountLabel->setObjectName(QString::fromUtf8("bcountLabel"));
        bcountLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(bcountLabel);

        ocountLabel = new QLabel(layoutWidget);
        ocountLabel->setObjectName(QString::fromUtf8("ocountLabel"));
        ocountLabel->setMaximumSize(QSize(16777215, 40));

        verticalLayout_2->addWidget(ocountLabel);

        pushButton = new QPushButton(ViewMember);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(580, 210, 250, 30));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        labels = new QWidget(ViewMember);
        labels->setObjectName(QString::fromUtf8("labels"));
        labels->setGeometry(QRect(30, 10, 141, 421));
        verticalLayout = new QVBoxLayout(labels);
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(labels);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 40));
        label_3->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_3);

        label = new QLabel(labels);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 40));
        label->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(labels);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 40));
        label_2->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_2);

        label_4 = new QLabel(labels);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 40));
        label_4->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_4);

        label_6 = new QLabel(labels);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 40));
        label_6->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_6);

        label_5 = new QLabel(labels);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 40));
        label_5->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_5);

        label_7 = new QLabel(labels);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 40));
        label_7->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_7);

        label_8 = new QLabel(labels);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(0, 40));
        label_8->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_8);

        label_9 = new QLabel(labels);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 40));
        label_9->setMaximumSize(QSize(16777215, 40));

        verticalLayout->addWidget(label_9);


        retranslateUi(ViewMember);

        QMetaObject::connectSlotsByName(ViewMember);
    } // setupUi

    void retranslateUi(QWidget *ViewMember)
    {
        ViewMember->setWindowTitle(QCoreApplication::translate("ViewMember", "Form", nullptr));
        indexLabel->setText(QCoreApplication::translate("ViewMember", "Index", nullptr));
        firstnameLabel->setText(QCoreApplication::translate("ViewMember", "First Name", nullptr));
        lastnameLabel->setText(QCoreApplication::translate("ViewMember", "Last Name", nullptr));
        usernameLabel->setText(QCoreApplication::translate("ViewMember", "Username", nullptr));
        contactLabel->setText(QCoreApplication::translate("ViewMember", "Contact Number", nullptr));
        emailLabel->setText(QCoreApplication::translate("ViewMember", "Email", nullptr));
        dobLabel->setText(QCoreApplication::translate("ViewMember", "Date of birth", nullptr));
        bcountLabel->setText(QCoreApplication::translate("ViewMember", "Book Count", nullptr));
        ocountLabel->setText(QCoreApplication::translate("ViewMember", "Overdue Count", nullptr));
        pushButton->setText(QCoreApplication::translate("ViewMember", "Send Email Reminder", nullptr));
        label_3->setText(QCoreApplication::translate("ViewMember", "Card Number", nullptr));
        label->setText(QCoreApplication::translate("ViewMember", "First Name", nullptr));
        label_2->setText(QCoreApplication::translate("ViewMember", "Last Name", nullptr));
        label_4->setText(QCoreApplication::translate("ViewMember", "Username", nullptr));
        label_6->setText(QCoreApplication::translate("ViewMember", "Contact Number", nullptr));
        label_5->setText(QCoreApplication::translate("ViewMember", "Email", nullptr));
        label_7->setText(QCoreApplication::translate("ViewMember", "Date of birth", nullptr));
        label_8->setText(QCoreApplication::translate("ViewMember", "Book Count", nullptr));
        label_9->setText(QCoreApplication::translate("ViewMember", "Overdue Count", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewMember: public Ui_ViewMember {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWMEMBER_H
