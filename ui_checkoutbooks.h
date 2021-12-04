/********************************************************************************
** Form generated from reading UI file 'checkoutbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTBOOKS_H
#define UI_CHECKOUTBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckoutBooks
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *genreLabel;
    QLabel *authorLabel;
    QLabel *titleLabel;
    QLabel *isbnLabel;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *oCountLabel;
    QLabel *indexLabel;
    QLabel *bcountLabel;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *nameLabel;
    QLabel *label_17;
    QLabel *label_18;
    QPushButton *confirmButton;
    QPushButton *dismissButton;
    QPushButton *cover;

    void setupUi(QWidget *CheckoutBooks)
    {
        if (CheckoutBooks->objectName().isEmpty())
            CheckoutBooks->setObjectName(QString::fromUtf8("CheckoutBooks"));
        CheckoutBooks->resize(1020, 230);
        CheckoutBooks->setMinimumSize(QSize(1020, 230));
        CheckoutBooks->setMaximumSize(QSize(1020, 230));
        label = new QLabel(CheckoutBooks);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 70, 91, 21));
        label_2 = new QLabel(CheckoutBooks);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 100, 101, 21));
        label_3 = new QLabel(CheckoutBooks);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 130, 91, 21));
        label_4 = new QLabel(CheckoutBooks);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(180, 160, 91, 21));
        genreLabel = new QLabel(CheckoutBooks);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setGeometry(QRect(260, 160, 171, 21));
        genreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        authorLabel = new QLabel(CheckoutBooks);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setGeometry(QRect(260, 100, 171, 21));
        authorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        titleLabel = new QLabel(CheckoutBooks);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(260, 70, 171, 21));
        titleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        isbnLabel = new QLabel(CheckoutBooks);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setGeometry(QRect(260, 130, 171, 21));
        isbnLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(CheckoutBooks);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(470, 160, 131, 21));
        label_10 = new QLabel(CheckoutBooks);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(470, 100, 101, 21));
        oCountLabel = new QLabel(CheckoutBooks);
        oCountLabel->setObjectName(QString::fromUtf8("oCountLabel"));
        oCountLabel->setGeometry(QRect(620, 160, 101, 21));
        oCountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        indexLabel = new QLabel(CheckoutBooks);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        indexLabel->setGeometry(QRect(570, 70, 151, 21));
        indexLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        bcountLabel = new QLabel(CheckoutBooks);
        bcountLabel->setObjectName(QString::fromUtf8("bcountLabel"));
        bcountLabel->setGeometry(QRect(610, 130, 111, 21));
        bcountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(CheckoutBooks);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(470, 70, 101, 21));
        label_15 = new QLabel(CheckoutBooks);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(470, 130, 101, 21));
        nameLabel = new QLabel(CheckoutBooks);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(570, 100, 151, 21));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(CheckoutBooks);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(260, 30, 91, 31));
        label_18 = new QLabel(CheckoutBooks);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(520, 30, 141, 31));
        confirmButton = new QPushButton(CheckoutBooks);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        confirmButton->setGeometry(QRect(790, 80, 200, 30));
        confirmButton->setCursor(QCursor(Qt::PointingHandCursor));
        dismissButton = new QPushButton(CheckoutBooks);
        dismissButton->setObjectName(QString::fromUtf8("dismissButton"));
        dismissButton->setGeometry(QRect(790, 130, 200, 30));
        dismissButton->setCursor(QCursor(Qt::PointingHandCursor));
        cover = new QPushButton(CheckoutBooks);
        cover->setObjectName(QString::fromUtf8("cover"));
        cover->setGeometry(QRect(40, 30, 100, 160));

        retranslateUi(CheckoutBooks);

        QMetaObject::connectSlotsByName(CheckoutBooks);
    } // setupUi

    void retranslateUi(QWidget *CheckoutBooks)
    {
        CheckoutBooks->setWindowTitle(QCoreApplication::translate("CheckoutBooks", "Form", nullptr));
        label->setText(QCoreApplication::translate("CheckoutBooks", "Book Title", nullptr));
        label_2->setText(QCoreApplication::translate("CheckoutBooks", "Author Name", nullptr));
        label_3->setText(QCoreApplication::translate("CheckoutBooks", "ISBN", nullptr));
        label_4->setText(QCoreApplication::translate("CheckoutBooks", "Genre", nullptr));
        genreLabel->setText(QCoreApplication::translate("CheckoutBooks", "Genre", nullptr));
        authorLabel->setText(QCoreApplication::translate("CheckoutBooks", "Author Name", nullptr));
        titleLabel->setText(QCoreApplication::translate("CheckoutBooks", "Book Title", nullptr));
        isbnLabel->setText(QCoreApplication::translate("CheckoutBooks", "ISBN", nullptr));
        label_9->setText(QCoreApplication::translate("CheckoutBooks", "Overdue Count", nullptr));
        label_10->setText(QCoreApplication::translate("CheckoutBooks", "Full Name", nullptr));
        oCountLabel->setText(QCoreApplication::translate("CheckoutBooks", "Member", nullptr));
        indexLabel->setText(QCoreApplication::translate("CheckoutBooks", "Member", nullptr));
        bcountLabel->setText(QCoreApplication::translate("CheckoutBooks", "Member", nullptr));
        label_14->setText(QCoreApplication::translate("CheckoutBooks", "Card Number", nullptr));
        label_15->setText(QCoreApplication::translate("CheckoutBooks", "Book Count", nullptr));
        nameLabel->setText(QCoreApplication::translate("CheckoutBooks", "Member", nullptr));
        label_17->setText(QCoreApplication::translate("CheckoutBooks", "Book Details", nullptr));
        label_18->setText(QCoreApplication::translate("CheckoutBooks", "Member Details", nullptr));
        confirmButton->setText(QCoreApplication::translate("CheckoutBooks", "Confirm", nullptr));
        dismissButton->setText(QCoreApplication::translate("CheckoutBooks", "Dismiss", nullptr));
        cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CheckoutBooks: public Ui_CheckoutBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTBOOKS_H
