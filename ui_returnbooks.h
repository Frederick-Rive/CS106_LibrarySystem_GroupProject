/********************************************************************************
** Form generated from reading UI file 'returnbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETURNBOOKS_H
#define UI_RETURNBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReturnBooks
{
public:
    QLabel *dueLabel;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *isbnLabel;
    QLabel *genreLabel;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *authorLabel_2;
    QLabel *titleLabel_2;
    QLabel *isbnLabel_2;
    QLabel *genreLabel_2;
    QPushButton *cover;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *outputLayout;
    QPushButton *returnButton;

    void setupUi(QWidget *ReturnBooks)
    {
        if (ReturnBooks->objectName().isEmpty())
            ReturnBooks->setObjectName(QString::fromUtf8("ReturnBooks"));
        ReturnBooks->resize(1020, 200);
        ReturnBooks->setMinimumSize(QSize(1020, 200));
        dueLabel = new QLabel(ReturnBooks);
        dueLabel->setObjectName(QString::fromUtf8("dueLabel"));
        dueLabel->setGeometry(QRect(560, 90, 251, 31));
        dueLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(ReturnBooks);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(340, 30, 201, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(titleLabel);

        authorLabel = new QLabel(layoutWidget);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(authorLabel);

        isbnLabel = new QLabel(layoutWidget);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(isbnLabel);

        genreLabel = new QLabel(layoutWidget);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(genreLabel);

        layoutWidget_2 = new QWidget(ReturnBooks);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(210, 30, 131, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        authorLabel_2 = new QLabel(layoutWidget_2);
        authorLabel_2->setObjectName(QString::fromUtf8("authorLabel_2"));
        authorLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(authorLabel_2);

        titleLabel_2 = new QLabel(layoutWidget_2);
        titleLabel_2->setObjectName(QString::fromUtf8("titleLabel_2"));
        titleLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(titleLabel_2);

        isbnLabel_2 = new QLabel(layoutWidget_2);
        isbnLabel_2->setObjectName(QString::fromUtf8("isbnLabel_2"));
        isbnLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(isbnLabel_2);

        genreLabel_2 = new QLabel(layoutWidget_2);
        genreLabel_2->setObjectName(QString::fromUtf8("genreLabel_2"));
        genreLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(genreLabel_2);

        cover = new QPushButton(ReturnBooks);
        cover->setObjectName(QString::fromUtf8("cover"));
        cover->setGeometry(QRect(60, 20, 100, 160));
        verticalLayoutWidget = new QWidget(ReturnBooks);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(830, 60, 160, 91));
        outputLayout = new QVBoxLayout(verticalLayoutWidget);
        outputLayout->setObjectName(QString::fromUtf8("outputLayout"));
        outputLayout->setContentsMargins(0, 0, 0, 0);
        returnButton = new QPushButton(verticalLayoutWidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));
        returnButton->setMinimumSize(QSize(150, 30));
        returnButton->setCursor(QCursor(Qt::PointingHandCursor));

        outputLayout->addWidget(returnButton);


        retranslateUi(ReturnBooks);

        QMetaObject::connectSlotsByName(ReturnBooks);
    } // setupUi

    void retranslateUi(QWidget *ReturnBooks)
    {
        ReturnBooks->setWindowTitle(QCoreApplication::translate("ReturnBooks", "Form", nullptr));
        dueLabel->setText(QCoreApplication::translate("ReturnBooks", "DueDate", nullptr));
        titleLabel->setText(QCoreApplication::translate("ReturnBooks", "TextLabel", nullptr));
        authorLabel->setText(QCoreApplication::translate("ReturnBooks", "TextLabel", nullptr));
        isbnLabel->setText(QCoreApplication::translate("ReturnBooks", "TextLabel", nullptr));
        genreLabel->setText(QCoreApplication::translate("ReturnBooks", "TextLabel", nullptr));
        authorLabel_2->setText(QCoreApplication::translate("ReturnBooks", "Title", nullptr));
        titleLabel_2->setText(QCoreApplication::translate("ReturnBooks", "Author", nullptr));
        isbnLabel_2->setText(QCoreApplication::translate("ReturnBooks", "ISBN", nullptr));
        genreLabel_2->setText(QCoreApplication::translate("ReturnBooks", "Genre", nullptr));
        cover->setText(QString());
        returnButton->setText(QCoreApplication::translate("ReturnBooks", "Return", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReturnBooks: public Ui_ReturnBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETURNBOOKS_H
