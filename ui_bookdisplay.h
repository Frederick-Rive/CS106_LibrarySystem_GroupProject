/********************************************************************************
** Form generated from reading UI file 'bookdisplay.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDISPLAY_H
#define UI_BOOKDISPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookDisplay
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *cover;
    QLabel *title;
    QLabel *author;
    QLabel *genre;

    void setupUi(QWidget *BookDisplay)
    {
        if (BookDisplay->objectName().isEmpty())
            BookDisplay->setObjectName(QString::fromUtf8("BookDisplay"));
        BookDisplay->resize(180, 400);
        BookDisplay->setMinimumSize(QSize(180, 350));
        BookDisplay->setMaximumSize(QSize(220, 400));
        verticalLayout = new QVBoxLayout(BookDisplay);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 5);
        cover = new QPushButton(BookDisplay);
        cover->setObjectName(QString::fromUtf8("cover"));
        cover->setMinimumSize(QSize(180, 288));
        cover->setCursor(QCursor(Qt::PointingHandCursor));

        verticalLayout->addWidget(cover);

        title = new QLabel(BookDisplay);
        title->setObjectName(QString::fromUtf8("title"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);
        title->setMinimumSize(QSize(20, 30));
        title->setMaximumSize(QSize(220, 60));
        title->setAlignment(Qt::AlignCenter);
        title->setWordWrap(true);

        verticalLayout->addWidget(title);

        author = new QLabel(BookDisplay);
        author->setObjectName(QString::fromUtf8("author"));
        author->setMaximumSize(QSize(220, 16777215));
        author->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(author);

        genre = new QLabel(BookDisplay);
        genre->setObjectName(QString::fromUtf8("genre"));
        genre->setMaximumSize(QSize(220, 16777215));
        genre->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(genre);


        retranslateUi(BookDisplay);

        QMetaObject::connectSlotsByName(BookDisplay);
    } // setupUi

    void retranslateUi(QWidget *BookDisplay)
    {
        BookDisplay->setWindowTitle(QCoreApplication::translate("BookDisplay", "Form", nullptr));
        cover->setText(QString());
        title->setText(QString());
        author->setText(QCoreApplication::translate("BookDisplay", "title", nullptr));
        genre->setText(QCoreApplication::translate("BookDisplay", "title", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookDisplay: public Ui_BookDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDISPLAY_H
