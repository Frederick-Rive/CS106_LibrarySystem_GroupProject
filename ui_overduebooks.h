/********************************************************************************
** Form generated from reading UI file 'overduebooks.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERDUEBOOKS_H
#define UI_OVERDUEBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OverdueBooks
{
public:
    QPushButton *cover;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *authorLabel_2;
    QLabel *titleLabel_2;
    QLabel *isbnLabel_2;
    QLabel *genreLabel_2;
    QLabel *dueLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *isbnLabel;
    QLabel *genreLabel;
    QPushButton *overdueButton;

    void setupUi(QWidget *OverdueBooks)
    {
        if (OverdueBooks->objectName().isEmpty())
            OverdueBooks->setObjectName(QString::fromUtf8("OverdueBooks"));
        OverdueBooks->resize(1020, 200);
        OverdueBooks->setMinimumSize(QSize(1020, 200));
        cover = new QPushButton(OverdueBooks);
        cover->setObjectName(QString::fromUtf8("cover"));
        cover->setGeometry(QRect(60, 20, 100, 160));
        layoutWidget = new QWidget(OverdueBooks);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(210, 30, 131, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        authorLabel_2 = new QLabel(layoutWidget);
        authorLabel_2->setObjectName(QString::fromUtf8("authorLabel_2"));
        authorLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(authorLabel_2);

        titleLabel_2 = new QLabel(layoutWidget);
        titleLabel_2->setObjectName(QString::fromUtf8("titleLabel_2"));
        titleLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(titleLabel_2);

        isbnLabel_2 = new QLabel(layoutWidget);
        isbnLabel_2->setObjectName(QString::fromUtf8("isbnLabel_2"));
        isbnLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(isbnLabel_2);

        genreLabel_2 = new QLabel(layoutWidget);
        genreLabel_2->setObjectName(QString::fromUtf8("genreLabel_2"));
        genreLabel_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(genreLabel_2);

        dueLabel = new QLabel(OverdueBooks);
        dueLabel->setObjectName(QString::fromUtf8("dueLabel"));
        dueLabel->setGeometry(QRect(580, 90, 241, 31));
        dueLabel->setAlignment(Qt::AlignCenter);
        layoutWidget1 = new QWidget(OverdueBooks);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(340, 30, 201, 141));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(layoutWidget1);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(titleLabel);

        authorLabel = new QLabel(layoutWidget1);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(authorLabel);

        isbnLabel = new QLabel(layoutWidget1);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(isbnLabel);

        genreLabel = new QLabel(layoutWidget1);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(genreLabel);

        overdueButton = new QPushButton(OverdueBooks);
        overdueButton->setObjectName(QString::fromUtf8("overdueButton"));
        overdueButton->setGeometry(QRect(840, 90, 150, 30));
        overdueButton->setCursor(QCursor(Qt::PointingHandCursor));

        retranslateUi(OverdueBooks);

        QMetaObject::connectSlotsByName(OverdueBooks);
    } // setupUi

    void retranslateUi(QWidget *OverdueBooks)
    {
        OverdueBooks->setWindowTitle(QCoreApplication::translate("OverdueBooks", "Form", nullptr));
        cover->setText(QString());
        authorLabel_2->setText(QCoreApplication::translate("OverdueBooks", "Title", nullptr));
        titleLabel_2->setText(QCoreApplication::translate("OverdueBooks", "Author", nullptr));
        isbnLabel_2->setText(QCoreApplication::translate("OverdueBooks", "ISBN", nullptr));
        genreLabel_2->setText(QCoreApplication::translate("OverdueBooks", "Genre", nullptr));
        dueLabel->setText(QCoreApplication::translate("OverdueBooks", "DueDate", nullptr));
        titleLabel->setText(QCoreApplication::translate("OverdueBooks", "TextLabel", nullptr));
        authorLabel->setText(QCoreApplication::translate("OverdueBooks", "TextLabel", nullptr));
        isbnLabel->setText(QCoreApplication::translate("OverdueBooks", "TextLabel", nullptr));
        genreLabel->setText(QCoreApplication::translate("OverdueBooks", "TextLabel", nullptr));
        overdueButton->setText(QCoreApplication::translate("OverdueBooks", "View Member", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OverdueBooks: public Ui_OverdueBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERDUEBOOKS_H
