/********************************************************************************
** Form generated from reading UI file 'memberwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERWINDOW_H
#define UI_MEMBERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemberWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QWidget *header;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *logolabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *logout_button;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *viewbooks_button;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *overdue_button;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *account_Button;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *returnButton;
    QSpacerItem *horizontalSpacer_12;
    QGridLayout *activeLayout;
    QSpacerItem *activeSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *background;
    QLabel *followus;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *facebookButton;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *twitterButton;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *instaButton;
    QSpacerItem *horizontalSpacer_11;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MemberWindow)
    {
        if (MemberWindow->objectName().isEmpty())
            MemberWindow->setObjectName(QString::fromUtf8("MemberWindow"));
        MemberWindow->resize(1280, 850);
        MemberWindow->setMinimumSize(QSize(1280, 850));
        MemberWindow->setMaximumSize(QSize(1280, 850));
        centralwidget = new QWidget(MemberWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setMaximumSize(QSize(1280, 850));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        header = new QWidget(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setMinimumSize(QSize(1280, 200));
        verticalLayout = new QVBoxLayout(header);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        logolabel = new QLabel(header);
        logolabel->setObjectName(QString::fromUtf8("logolabel"));
        logolabel->setMinimumSize(QSize(400, 120));
        logolabel->setMaximumSize(QSize(400, 120));

        horizontalLayout->addWidget(logolabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        logout_button = new QPushButton(header);
        logout_button->setObjectName(QString::fromUtf8("logout_button"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logout_button->sizePolicy().hasHeightForWidth());
        logout_button->setSizePolicy(sizePolicy);
        logout_button->setMinimumSize(QSize(160, 30));
        logout_button->setMaximumSize(QSize(160, 30));
        logout_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(logout_button);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(140, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        viewbooks_button = new QPushButton(header);
        viewbooks_button->setObjectName(QString::fromUtf8("viewbooks_button"));
        viewbooks_button->setMinimumSize(QSize(200, 30));
        viewbooks_button->setMaximumSize(QSize(200, 30));
        viewbooks_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(viewbooks_button);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        overdue_button = new QPushButton(header);
        overdue_button->setObjectName(QString::fromUtf8("overdue_button"));
        overdue_button->setMinimumSize(QSize(200, 30));
        overdue_button->setMaximumSize(QSize(200, 30));
        overdue_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(overdue_button);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        account_Button = new QPushButton(header);
        account_Button->setObjectName(QString::fromUtf8("account_Button"));
        account_Button->setMinimumSize(QSize(200, 30));
        account_Button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(account_Button);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        returnButton = new QPushButton(header);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setMinimumSize(QSize(200, 30));
        returnButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(returnButton);

        horizontalSpacer_12 = new QSpacerItem(140, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(header);

        activeLayout = new QGridLayout();
        activeLayout->setSpacing(6);
        activeLayout->setObjectName(QString::fromUtf8("activeLayout"));
        activeSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        activeLayout->addItem(activeSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 500, QSizePolicy::Minimum, QSizePolicy::Fixed);

        activeLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);

        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setMinimumSize(QSize(1280, 500));

        activeLayout->addWidget(background, 2, 1, 1, 1);


        verticalLayout_2->addLayout(activeLayout);

        followus = new QLabel(centralwidget);
        followus->setObjectName(QString::fromUtf8("followus"));
        followus->setMinimumSize(QSize(1280, 50));
        followus->setMaximumSize(QSize(1280, 50));
        followus->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(followus);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);

        facebookButton = new QPushButton(centralwidget);
        facebookButton->setObjectName(QString::fromUtf8("facebookButton"));
        facebookButton->setMinimumSize(QSize(30, 30));
        facebookButton->setMaximumSize(QSize(30, 30));
        facebookButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(facebookButton);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        twitterButton = new QPushButton(centralwidget);
        twitterButton->setObjectName(QString::fromUtf8("twitterButton"));
        twitterButton->setMinimumSize(QSize(30, 30));
        twitterButton->setMaximumSize(QSize(30, 30));
        twitterButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(twitterButton);

        horizontalSpacer_9 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        instaButton = new QPushButton(centralwidget);
        instaButton->setObjectName(QString::fromUtf8("instaButton"));
        instaButton->setMinimumSize(QSize(30, 30));
        instaButton->setMaximumSize(QSize(30, 30));
        instaButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_3->addWidget(instaButton);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_11);


        verticalLayout_2->addLayout(horizontalLayout_3);

        MemberWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MemberWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        MemberWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MemberWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MemberWindow->setStatusBar(statusbar);

        retranslateUi(MemberWindow);

        QMetaObject::connectSlotsByName(MemberWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MemberWindow)
    {
        MemberWindow->setWindowTitle(QCoreApplication::translate("MemberWindow", "MainWindow", nullptr));
        logolabel->setText(QString());
        logout_button->setText(QCoreApplication::translate("MemberWindow", "Log out", nullptr));
        viewbooks_button->setText(QCoreApplication::translate("MemberWindow", "View All Books", nullptr));
        overdue_button->setText(QCoreApplication::translate("MemberWindow", "My Overdue Books", nullptr));
        account_Button->setText(QCoreApplication::translate("MemberWindow", "My Account", nullptr));
        returnButton->setText(QCoreApplication::translate("MemberWindow", "Return Book", nullptr));
        background->setText(QString());
        followus->setText(QCoreApplication::translate("MemberWindow", "Follow us on", nullptr));
        facebookButton->setText(QString());
        twitterButton->setText(QString());
        instaButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MemberWindow: public Ui_MemberWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERWINDOW_H
