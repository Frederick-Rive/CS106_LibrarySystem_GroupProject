/********************************************************************************
** Form generated from reading UI file 'viewbook.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWBOOK_H
#define UI_VIEWBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewBook
{
public:
    QPushButton *prebookButton;
    QLabel *availableLabel;
    QLabel *blurbLabel;
    QPushButton *coverLabel;
    QWidget *labels;
    QVBoxLayout *labelLayout;
    QLabel *titleLabel_2;
    QLabel *authorLabel_2;
    QLabel *isbnLabel_2;
    QLabel *pgLabel_2;
    QLabel *genreLabel_2;
    QLabel *ddLabel_2;
    QLabel *publishdateLabel_2;
    QWidget *layoutWidget;
    QVBoxLayout *dataLayout;
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *isbnLabel;
    QLabel *pgLabel;
    QLabel *genreLabel;
    QLabel *ddLabel;
    QLabel *publishdateLabel;

    void setupUi(QWidget *ViewBook)
    {
        if (ViewBook->objectName().isEmpty())
            ViewBook->setObjectName(QString::fromUtf8("ViewBook"));
        ViewBook->resize(1120, 620);
        ViewBook->setMinimumSize(QSize(780, 620));
        prebookButton = new QPushButton(ViewBook);
        prebookButton->setObjectName(QString::fromUtf8("prebookButton"));
        prebookButton->setGeometry(QRect(420, 400, 150, 40));
        prebookButton->setCursor(QCursor(Qt::PointingHandCursor));
        availableLabel = new QLabel(ViewBook);
        availableLabel->setObjectName(QString::fromUtf8("availableLabel"));
        availableLabel->setGeometry(QRect(190, 400, 140, 40));
        availableLabel->setMinimumSize(QSize(140, 40));
        availableLabel->setMaximumSize(QSize(140, 40));
        availableLabel->setAlignment(Qt::AlignCenter);
        blurbLabel = new QLabel(ViewBook);
        blurbLabel->setObjectName(QString::fromUtf8("blurbLabel"));
        blurbLabel->setGeometry(QRect(210, 460, 691, 131));
        blurbLabel->setMinimumSize(QSize(100, 100));
        blurbLabel->setMaximumSize(QSize(750, 150));
        blurbLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        blurbLabel->setWordWrap(true);
        coverLabel = new QPushButton(ViewBook);
        coverLabel->setObjectName(QString::fromUtf8("coverLabel"));
        coverLabel->setGeometry(QRect(160, 40, 200, 320));
        labels = new QWidget(ViewBook);
        labels->setObjectName(QString::fromUtf8("labels"));
        labels->setGeometry(QRect(400, 30, 131, 351));
        labelLayout = new QVBoxLayout(labels);
        labelLayout->setObjectName(QString::fromUtf8("labelLayout"));
        labelLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel_2 = new QLabel(labels);
        titleLabel_2->setObjectName(QString::fromUtf8("titleLabel_2"));
        titleLabel_2->setMinimumSize(QSize(100, 40));
        titleLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(titleLabel_2);

        authorLabel_2 = new QLabel(labels);
        authorLabel_2->setObjectName(QString::fromUtf8("authorLabel_2"));
        authorLabel_2->setMinimumSize(QSize(100, 40));
        authorLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(authorLabel_2);

        isbnLabel_2 = new QLabel(labels);
        isbnLabel_2->setObjectName(QString::fromUtf8("isbnLabel_2"));
        isbnLabel_2->setMinimumSize(QSize(100, 40));
        isbnLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(isbnLabel_2);

        pgLabel_2 = new QLabel(labels);
        pgLabel_2->setObjectName(QString::fromUtf8("pgLabel_2"));
        pgLabel_2->setMinimumSize(QSize(100, 40));
        pgLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(pgLabel_2);

        genreLabel_2 = new QLabel(labels);
        genreLabel_2->setObjectName(QString::fromUtf8("genreLabel_2"));
        genreLabel_2->setMinimumSize(QSize(100, 40));
        genreLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(genreLabel_2);

        ddLabel_2 = new QLabel(labels);
        ddLabel_2->setObjectName(QString::fromUtf8("ddLabel_2"));
        ddLabel_2->setMinimumSize(QSize(100, 40));
        ddLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(ddLabel_2);

        publishdateLabel_2 = new QLabel(labels);
        publishdateLabel_2->setObjectName(QString::fromUtf8("publishdateLabel_2"));
        publishdateLabel_2->setMinimumSize(QSize(100, 40));
        publishdateLabel_2->setMaximumSize(QSize(500, 40));

        labelLayout->addWidget(publishdateLabel_2);

        layoutWidget = new QWidget(ViewBook);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(529, 30, 431, 351));
        dataLayout = new QVBoxLayout(layoutWidget);
        dataLayout->setObjectName(QString::fromUtf8("dataLayout"));
        dataLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(layoutWidget);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        titleLabel->setMinimumSize(QSize(100, 40));
        titleLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(titleLabel);

        authorLabel = new QLabel(layoutWidget);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setMinimumSize(QSize(100, 40));
        authorLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(authorLabel);

        isbnLabel = new QLabel(layoutWidget);
        isbnLabel->setObjectName(QString::fromUtf8("isbnLabel"));
        isbnLabel->setMinimumSize(QSize(100, 40));
        isbnLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(isbnLabel);

        pgLabel = new QLabel(layoutWidget);
        pgLabel->setObjectName(QString::fromUtf8("pgLabel"));
        pgLabel->setMinimumSize(QSize(100, 40));
        pgLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(pgLabel);

        genreLabel = new QLabel(layoutWidget);
        genreLabel->setObjectName(QString::fromUtf8("genreLabel"));
        genreLabel->setMinimumSize(QSize(100, 40));
        genreLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(genreLabel);

        ddLabel = new QLabel(layoutWidget);
        ddLabel->setObjectName(QString::fromUtf8("ddLabel"));
        ddLabel->setMinimumSize(QSize(100, 40));
        ddLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(ddLabel);

        publishdateLabel = new QLabel(layoutWidget);
        publishdateLabel->setObjectName(QString::fromUtf8("publishdateLabel"));
        publishdateLabel->setMinimumSize(QSize(100, 40));
        publishdateLabel->setMaximumSize(QSize(500, 40));

        dataLayout->addWidget(publishdateLabel);


        retranslateUi(ViewBook);

        QMetaObject::connectSlotsByName(ViewBook);
    } // setupUi

    void retranslateUi(QWidget *ViewBook)
    {
        ViewBook->setWindowTitle(QCoreApplication::translate("ViewBook", "Form", nullptr));
        prebookButton->setText(QCoreApplication::translate("ViewBook", "Reserve", nullptr));
        availableLabel->setText(QCoreApplication::translate("ViewBook", "Available", nullptr));
        blurbLabel->setText(QCoreApplication::translate("ViewBook", "BLURB", nullptr));
        coverLabel->setText(QString());
        titleLabel_2->setText(QCoreApplication::translate("ViewBook", "Title", nullptr));
        authorLabel_2->setText(QCoreApplication::translate("ViewBook", "Author", nullptr));
        isbnLabel_2->setText(QCoreApplication::translate("ViewBook", "ISBN", nullptr));
        pgLabel_2->setText(QCoreApplication::translate("ViewBook", "Page Count", nullptr));
        genreLabel_2->setText(QCoreApplication::translate("ViewBook", "Genre", nullptr));
        ddLabel_2->setText(QCoreApplication::translate("ViewBook", "Dewey Decimal", nullptr));
        publishdateLabel_2->setText(QCoreApplication::translate("ViewBook", "Publishing Date", nullptr));
        titleLabel->setText(QCoreApplication::translate("ViewBook", "TITLE", nullptr));
        authorLabel->setText(QCoreApplication::translate("ViewBook", "AUTHOR", nullptr));
        isbnLabel->setText(QCoreApplication::translate("ViewBook", "ISBN", nullptr));
        pgLabel->setText(QCoreApplication::translate("ViewBook", "PAGE COUNT", nullptr));
        genreLabel->setText(QCoreApplication::translate("ViewBook", "GENRE", nullptr));
        ddLabel->setText(QCoreApplication::translate("ViewBook", "DD", nullptr));
        publishdateLabel->setText(QCoreApplication::translate("ViewBook", "PUBLISH", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ViewBook: public Ui_ViewBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWBOOK_H
