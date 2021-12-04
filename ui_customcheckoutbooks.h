/********************************************************************************
** Form generated from reading UI file 'customcheckoutbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMCHECKOUTBOOKS_H
#define UI_CUSTOMCHECKOUTBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomCheckoutBooks
{
public:
    QLineEdit *memberEdit;
    QLineEdit *bookEdit;
    QPushButton *pushButton;
    QLabel *memberTitle;
    QLabel *bookTitle;
    QLabel *bcountLabel;
    QLabel *isbnLabel;
    QLabel *label_15;
    QLabel *nameLabel;
    QLabel *label_3;
    QLabel *genreLabel;
    QLabel *label_10;
    QLabel *oCountLabel;
    QLabel *indexLabel;
    QLabel *label_4;
    QLabel *titleLabel;
    QLabel *label_14;
    QLabel *authorLabel;
    QLabel *label_9;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *CustomCheckoutBooks)
    {
        if (CustomCheckoutBooks->objectName().isEmpty())
            CustomCheckoutBooks->setObjectName(QString::fromUtf8("CustomCheckoutBooks"));
        CustomCheckoutBooks->resize(1020, 240);
        CustomCheckoutBooks->setMinimumSize(QSize(1020, 240));
        memberEdit = new QLineEdit(CustomCheckoutBooks);
        memberEdit->setObjectName(QString::fromUtf8("memberEdit"));
        memberEdit->setGeometry(QRect(460, 70, 300, 30));
        bookEdit = new QLineEdit(CustomCheckoutBooks);
        bookEdit->setObjectName(QString::fromUtf8("bookEdit"));
        bookEdit->setGeometry(QRect(80, 70, 300, 30));
        pushButton = new QPushButton(CustomCheckoutBooks);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(819, 70, 190, 30));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        memberTitle = new QLabel(CustomCheckoutBooks);
        memberTitle->setObjectName(QString::fromUtf8("memberTitle"));
        memberTitle->setGeometry(QRect(460, 30, 300, 30));
        memberTitle->setAlignment(Qt::AlignCenter);
        bookTitle = new QLabel(CustomCheckoutBooks);
        bookTitle->setObjectName(QString::fromUtf8("bookTitle"));
        bookTitle->setGeometry(QRect(80, 30, 300, 30));
        bookTitle->setAlignment(Qt::AlignCenter);
        bcountLabel = new QLabel(CustomCheckoutBooks);
        bcountLabel->setObjectName(QString::fromUtf8("bcountLabel"));
        bcountLabel->setGeometry(QRect(620, 170, 111, 21));
        bcountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        isbnLabel = new QLabel(CustomCheckoutBooks);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setGeometry(QRect(180, 170, 171, 21));
        isbnLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_15 = new QLabel(CustomCheckoutBooks);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(480, 170, 101, 21));
        nameLabel = new QLabel(CustomCheckoutBooks);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(580, 140, 151, 21));
        nameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(CustomCheckoutBooks);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 110, 91, 21));
        genreLabel = new QLabel(CustomCheckoutBooks);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setGeometry(QRect(180, 200, 171, 21));
        genreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_10 = new QLabel(CustomCheckoutBooks);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(480, 140, 101, 21));
        oCountLabel = new QLabel(CustomCheckoutBooks);
        oCountLabel->setObjectName(QString::fromUtf8("oCountLabel"));
        oCountLabel->setGeometry(QRect(630, 200, 101, 21));
        oCountLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        indexLabel = new QLabel(CustomCheckoutBooks);
        indexLabel->setObjectName(QString::fromUtf8("indexLabel"));
        indexLabel->setGeometry(QRect(580, 110, 151, 21));
        indexLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(CustomCheckoutBooks);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 140, 101, 21));
        titleLabel = new QLabel(CustomCheckoutBooks);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setGeometry(QRect(180, 110, 171, 21));
        titleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_14 = new QLabel(CustomCheckoutBooks);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(480, 110, 101, 21));
        authorLabel = new QLabel(CustomCheckoutBooks);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setGeometry(QRect(180, 140, 171, 21));
        authorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_9 = new QLabel(CustomCheckoutBooks);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(480, 200, 131, 21));
        label_5 = new QLabel(CustomCheckoutBooks);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 170, 91, 21));
        label_6 = new QLabel(CustomCheckoutBooks);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 200, 91, 21));

        retranslateUi(CustomCheckoutBooks);

        QMetaObject::connectSlotsByName(CustomCheckoutBooks);
    } // setupUi

    void retranslateUi(QWidget *CustomCheckoutBooks)
    {
        CustomCheckoutBooks->setWindowTitle(QCoreApplication::translate("CustomCheckoutBooks", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CustomCheckoutBooks", "Confirm", nullptr));
        memberTitle->setText(QCoreApplication::translate("CustomCheckoutBooks", "Member Name", nullptr));
        bookTitle->setText(QCoreApplication::translate("CustomCheckoutBooks", "Book Title / ISBN", nullptr));
        bcountLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        isbnLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        label_15->setText(QCoreApplication::translate("CustomCheckoutBooks", "Book Count", nullptr));
        nameLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        label_3->setText(QCoreApplication::translate("CustomCheckoutBooks", "Book Title", nullptr));
        genreLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        label_10->setText(QCoreApplication::translate("CustomCheckoutBooks", "Full Name", nullptr));
        oCountLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        indexLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        label_4->setText(QCoreApplication::translate("CustomCheckoutBooks", "Author Name", nullptr));
        titleLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        label_14->setText(QCoreApplication::translate("CustomCheckoutBooks", "Card Number", nullptr));
        authorLabel->setText(QCoreApplication::translate("CustomCheckoutBooks", "---", nullptr));
        label_9->setText(QCoreApplication::translate("CustomCheckoutBooks", "Overdue Count", nullptr));
        label_5->setText(QCoreApplication::translate("CustomCheckoutBooks", "ISBN", nullptr));
        label_6->setText(QCoreApplication::translate("CustomCheckoutBooks", "Genre", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomCheckoutBooks: public Ui_CustomCheckoutBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMCHECKOUTBOOKS_H
