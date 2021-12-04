/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *header;
    QVBoxLayout *header_layout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *logolabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *logout_button;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *navmenu;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *addbook_button;
    QPushButton *viewbook_button;
    QPushButton *addmember_button;
    QPushButton *viewmember_button;
    QPushButton *overduebooks_button;
    QPushButton *checkoutbooks_button;
    QPushButton *returnbooks_button;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer;
    QGridLayout *activeLayout;
    QLabel *auxLabel;
    QLabel *background;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *activeSpacer;
    QLabel *followus;
    QHBoxLayout *socialmedia;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *facebookButton;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *twitterButton;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *instaButton;
    QSpacerItem *horizontalSpacer_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1280, 850);
        MainWindow->setMinimumSize(QSize(1280, 850));
        MainWindow->setMaximumSize(QSize(1920, 1080));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        header = new QWidget(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setMinimumSize(QSize(1280, 200));
        header_layout = new QVBoxLayout(header);
        header_layout->setObjectName(QString::fromUtf8("header_layout"));
        header_layout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        logolabel = new QLabel(header);
        logolabel->setObjectName(QString::fromUtf8("logolabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logolabel->sizePolicy().hasHeightForWidth());
        logolabel->setSizePolicy(sizePolicy);
        logolabel->setMinimumSize(QSize(400, 120));
        logolabel->setMaximumSize(QSize(400, 120));

        horizontalLayout_2->addWidget(logolabel);

        horizontalSpacer = new QSpacerItem(660, 50, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        logout_button = new QPushButton(header);
        logout_button->setObjectName(QString::fromUtf8("logout_button"));
        sizePolicy.setHeightForWidth(logout_button->sizePolicy().hasHeightForWidth());
        logout_button->setSizePolicy(sizePolicy);
        logout_button->setMinimumSize(QSize(160, 30));
        logout_button->setMaximumSize(QSize(160, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(16);
        logout_button->setFont(font);
        logout_button->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(logout_button);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        header_layout->addLayout(horizontalLayout_2);

        navmenu = new QHBoxLayout();
        navmenu->setObjectName(QString::fromUtf8("navmenu"));
        horizontalSpacer_9 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        navmenu->addItem(horizontalSpacer_9);

        addbook_button = new QPushButton(header);
        addbook_button->setObjectName(QString::fromUtf8("addbook_button"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(addbook_button->sizePolicy().hasHeightForWidth());
        addbook_button->setSizePolicy(sizePolicy1);
        addbook_button->setMinimumSize(QSize(150, 30));
        addbook_button->setMaximumSize(QSize(150, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(14);
        addbook_button->setFont(font1);
        addbook_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(addbook_button);

        viewbook_button = new QPushButton(header);
        viewbook_button->setObjectName(QString::fromUtf8("viewbook_button"));
        sizePolicy1.setHeightForWidth(viewbook_button->sizePolicy().hasHeightForWidth());
        viewbook_button->setSizePolicy(sizePolicy1);
        viewbook_button->setMinimumSize(QSize(150, 30));
        viewbook_button->setMaximumSize(QSize(150, 30));
        viewbook_button->setFont(font1);
        viewbook_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(viewbook_button);

        addmember_button = new QPushButton(header);
        addmember_button->setObjectName(QString::fromUtf8("addmember_button"));
        sizePolicy1.setHeightForWidth(addmember_button->sizePolicy().hasHeightForWidth());
        addmember_button->setSizePolicy(sizePolicy1);
        addmember_button->setMinimumSize(QSize(150, 30));
        addmember_button->setMaximumSize(QSize(150, 30));
        addmember_button->setFont(font1);
        addmember_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(addmember_button);

        viewmember_button = new QPushButton(header);
        viewmember_button->setObjectName(QString::fromUtf8("viewmember_button"));
        sizePolicy1.setHeightForWidth(viewmember_button->sizePolicy().hasHeightForWidth());
        viewmember_button->setSizePolicy(sizePolicy1);
        viewmember_button->setMinimumSize(QSize(150, 30));
        viewmember_button->setMaximumSize(QSize(150, 30));
        viewmember_button->setFont(font1);
        viewmember_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(viewmember_button);

        overduebooks_button = new QPushButton(header);
        overduebooks_button->setObjectName(QString::fromUtf8("overduebooks_button"));
        sizePolicy1.setHeightForWidth(overduebooks_button->sizePolicy().hasHeightForWidth());
        overduebooks_button->setSizePolicy(sizePolicy1);
        overduebooks_button->setMinimumSize(QSize(150, 30));
        overduebooks_button->setMaximumSize(QSize(150, 30));
        overduebooks_button->setFont(font1);
        overduebooks_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(overduebooks_button);

        checkoutbooks_button = new QPushButton(header);
        checkoutbooks_button->setObjectName(QString::fromUtf8("checkoutbooks_button"));
        sizePolicy1.setHeightForWidth(checkoutbooks_button->sizePolicy().hasHeightForWidth());
        checkoutbooks_button->setSizePolicy(sizePolicy1);
        checkoutbooks_button->setMinimumSize(QSize(150, 30));
        checkoutbooks_button->setMaximumSize(QSize(150, 30));
        checkoutbooks_button->setFont(font1);
        checkoutbooks_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(checkoutbooks_button);

        returnbooks_button = new QPushButton(header);
        returnbooks_button->setObjectName(QString::fromUtf8("returnbooks_button"));
        returnbooks_button->setMinimumSize(QSize(150, 30));
        returnbooks_button->setMaximumSize(QSize(150, 16777215));
        returnbooks_button->setCursor(QCursor(Qt::PointingHandCursor));

        navmenu->addWidget(returnbooks_button);

        horizontalSpacer_10 = new QSpacerItem(60, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        navmenu->addItem(horizontalSpacer_10);


        header_layout->addLayout(navmenu);

        verticalSpacer = new QSpacerItem(13, 0, QSizePolicy::Minimum, QSizePolicy::Maximum);

        header_layout->addItem(verticalSpacer);


        verticalLayout->addWidget(header);

        activeLayout = new QGridLayout();
        activeLayout->setObjectName(QString::fromUtf8("activeLayout"));
        auxLabel = new QLabel(centralwidget);
        auxLabel->setObjectName(QString::fromUtf8("auxLabel"));
        sizePolicy1.setHeightForWidth(auxLabel->sizePolicy().hasHeightForWidth());
        auxLabel->setSizePolicy(sizePolicy1);
        auxLabel->setMaximumSize(QSize(0, 0));

        activeLayout->addWidget(auxLabel, 0, 1, 1, 1);

        background = new QLabel(centralwidget);
        background->setObjectName(QString::fromUtf8("background"));
        background->setMinimumSize(QSize(1280, 500));

        activeLayout->addWidget(background, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 500, QSizePolicy::Minimum, QSizePolicy::Fixed);

        activeLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        activeSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Minimum);

        activeLayout->addItem(activeSpacer, 0, 0, 1, 1);


        verticalLayout->addLayout(activeLayout);

        followus = new QLabel(centralwidget);
        followus->setObjectName(QString::fromUtf8("followus"));
        followus->setMinimumSize(QSize(1280, 50));
        followus->setMaximumSize(QSize(16777215, 50));
        followus->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(followus);

        socialmedia = new QHBoxLayout();
        socialmedia->setObjectName(QString::fromUtf8("socialmedia"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        socialmedia->addItem(horizontalSpacer_5);

        facebookButton = new QPushButton(centralwidget);
        facebookButton->setObjectName(QString::fromUtf8("facebookButton"));
        facebookButton->setMinimumSize(QSize(30, 30));
        facebookButton->setMaximumSize(QSize(30, 30));
        facebookButton->setCursor(QCursor(Qt::PointingHandCursor));

        socialmedia->addWidget(facebookButton);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        socialmedia->addItem(horizontalSpacer_7);

        twitterButton = new QPushButton(centralwidget);
        twitterButton->setObjectName(QString::fromUtf8("twitterButton"));
        twitterButton->setMinimumSize(QSize(30, 30));
        twitterButton->setMaximumSize(QSize(30, 30));
        twitterButton->setCursor(QCursor(Qt::PointingHandCursor));

        socialmedia->addWidget(twitterButton);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        socialmedia->addItem(horizontalSpacer_8);

        instaButton = new QPushButton(centralwidget);
        instaButton->setObjectName(QString::fromUtf8("instaButton"));
        instaButton->setMinimumSize(QSize(30, 30));
        instaButton->setMaximumSize(QSize(30, 30));
        instaButton->setCursor(QCursor(Qt::PointingHandCursor));

        socialmedia->addWidget(instaButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        socialmedia->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(socialmedia);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1280, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logolabel->setText(QString());
        logout_button->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        addbook_button->setText(QCoreApplication::translate("MainWindow", "Add Book", nullptr));
        viewbook_button->setText(QCoreApplication::translate("MainWindow", "View / Edit Books", nullptr));
        addmember_button->setText(QCoreApplication::translate("MainWindow", "Add Member", nullptr));
        viewmember_button->setText(QCoreApplication::translate("MainWindow", "View / Edit Member", nullptr));
        overduebooks_button->setText(QCoreApplication::translate("MainWindow", "Overdue Books", nullptr));
        checkoutbooks_button->setText(QCoreApplication::translate("MainWindow", "Checkout Books", nullptr));
        returnbooks_button->setText(QCoreApplication::translate("MainWindow", "Return Books", nullptr));
        auxLabel->setText(QCoreApplication::translate("MainWindow", "FUCK", nullptr));
        background->setText(QString());
        followus->setText(QCoreApplication::translate("MainWindow", "Follow us on", nullptr));
        facebookButton->setText(QString());
        twitterButton->setText(QString());
        instaButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
