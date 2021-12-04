/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddBook
{
public:
    QLabel *widgetTitle_2;
    QLineEdit *titleEdit;
    QLabel *widgetTitle_3;
    QLineEdit *authorEdit;
    QLabel *widgetTitle_4;
    QComboBox *genreBox;
    QLabel *widgetTitle_5;
    QLabel *widgetTitle_6;
    QSlider *ddSlider;
    QLabel *widgetTitle_8;
    QLabel *widgetTitle_9;
    QLabel *widgetTitle_10;
    QLabel *widgetTitle_11;
    QPushButton *coverpathSearch;
    QLineEdit *coverpathEntry;
    QPushButton *saveButton;
    QSpinBox *ddCounter;
    QLabel *coverlabel;
    QSpinBox *pgEntry;
    QSpinBox *dayEntry;
    QSpinBox *monthEntry;
    QSpinBox *yearEntry;
    QLabel *widgetTitle_12;
    QTextEdit *blurbEdit;
    QLabel *widgetTitle_7;
    QLineEdit *isbnEdit;

    void setupUi(QWidget *AddBook)
    {
        if (AddBook->objectName().isEmpty())
            AddBook->setObjectName(QString::fromUtf8("AddBook"));
        AddBook->resize(780, 945);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddBook->sizePolicy().hasHeightForWidth());
        AddBook->setSizePolicy(sizePolicy);
        AddBook->setMinimumSize(QSize(780, 870));
        widgetTitle_2 = new QLabel(AddBook);
        widgetTitle_2->setObjectName(QString::fromUtf8("widgetTitle_2"));
        widgetTitle_2->setGeometry(QRect(20, 20, 51, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font.setPointSize(16);
        widgetTitle_2->setFont(font);
        titleEdit = new QLineEdit(AddBook);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));
        titleEdit->setGeometry(QRect(190, 20, 341, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font1.setPointSize(12);
        titleEdit->setFont(font1);
        widgetTitle_3 = new QLabel(AddBook);
        widgetTitle_3->setObjectName(QString::fromUtf8("widgetTitle_3"));
        widgetTitle_3->setGeometry(QRect(20, 60, 71, 21));
        widgetTitle_3->setFont(font);
        authorEdit = new QLineEdit(AddBook);
        authorEdit->setObjectName(QString::fromUtf8("authorEdit"));
        authorEdit->setGeometry(QRect(190, 60, 341, 21));
        authorEdit->setFont(font1);
        widgetTitle_4 = new QLabel(AddBook);
        widgetTitle_4->setObjectName(QString::fromUtf8("widgetTitle_4"));
        widgetTitle_4->setGeometry(QRect(20, 100, 71, 21));
        widgetTitle_4->setFont(font);
        genreBox = new QComboBox(AddBook);
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->addItem(QString());
        genreBox->setObjectName(QString::fromUtf8("genreBox"));
        genreBox->setGeometry(QRect(190, 100, 171, 22));
        genreBox->setFont(font1);
        widgetTitle_5 = new QLabel(AddBook);
        widgetTitle_5->setObjectName(QString::fromUtf8("widgetTitle_5"));
        widgetTitle_5->setGeometry(QRect(20, 220, 111, 21));
        widgetTitle_5->setFont(font);
        widgetTitle_6 = new QLabel(AddBook);
        widgetTitle_6->setObjectName(QString::fromUtf8("widgetTitle_6"));
        widgetTitle_6->setGeometry(QRect(20, 180, 151, 21));
        widgetTitle_6->setFont(font);
        ddSlider = new QSlider(AddBook);
        ddSlider->setObjectName(QString::fromUtf8("ddSlider"));
        ddSlider->setGeometry(QRect(270, 180, 441, 21));
        ddSlider->setFont(font1);
        ddSlider->setMinimum(1);
        ddSlider->setMaximum(999);
        ddSlider->setOrientation(Qt::Horizontal);
        widgetTitle_8 = new QLabel(AddBook);
        widgetTitle_8->setObjectName(QString::fromUtf8("widgetTitle_8"));
        widgetTitle_8->setGeometry(QRect(20, 260, 131, 21));
        widgetTitle_8->setFont(font);
        widgetTitle_9 = new QLabel(AddBook);
        widgetTitle_9->setObjectName(QString::fromUtf8("widgetTitle_9"));
        widgetTitle_9->setGeometry(QRect(260, 260, 16, 21));
        widgetTitle_9->setFont(font1);
        widgetTitle_10 = new QLabel(AddBook);
        widgetTitle_10->setObjectName(QString::fromUtf8("widgetTitle_10"));
        widgetTitle_10->setGeometry(QRect(350, 260, 16, 21));
        widgetTitle_10->setFont(font1);
        widgetTitle_11 = new QLabel(AddBook);
        widgetTitle_11->setObjectName(QString::fromUtf8("widgetTitle_11"));
        widgetTitle_11->setGeometry(QRect(20, 300, 131, 21));
        widgetTitle_11->setFont(font);
        coverpathSearch = new QPushButton(AddBook);
        coverpathSearch->setObjectName(QString::fromUtf8("coverpathSearch"));
        coverpathSearch->setGeometry(QRect(420, 299, 81, 22));
        coverpathSearch->setFont(font1);
        coverpathEntry = new QLineEdit(AddBook);
        coverpathEntry->setObjectName(QString::fromUtf8("coverpathEntry"));
        coverpathEntry->setGeometry(QRect(190, 300, 231, 20));
        coverpathEntry->setFont(font1);
        saveButton = new QPushButton(AddBook);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(20, 840, 161, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Comic Sans MS")});
        font2.setPointSize(20);
        saveButton->setFont(font2);
        saveButton->setCursor(QCursor(Qt::PointingHandCursor));
        ddCounter = new QSpinBox(AddBook);
        ddCounter->setObjectName(QString::fromUtf8("ddCounter"));
        ddCounter->setGeometry(QRect(190, 180, 60, 22));
        ddCounter->setFont(font1);
        ddCounter->setFrame(true);
        ddCounter->setButtonSymbols(QAbstractSpinBox::NoButtons);
        ddCounter->setMinimum(1);
        ddCounter->setMaximum(999);
        ddCounter->setValue(1);
        coverlabel = new QLabel(AddBook);
        coverlabel->setObjectName(QString::fromUtf8("coverlabel"));
        coverlabel->setGeometry(QRect(190, 340, 161, 231));
        pgEntry = new QSpinBox(AddBook);
        pgEntry->setObjectName(QString::fromUtf8("pgEntry"));
        pgEntry->setGeometry(QRect(190, 220, 101, 22));
        pgEntry->setFont(font1);
        pgEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        pgEntry->setMinimum(1);
        pgEntry->setMaximum(9999);
        pgEntry->setValue(1);
        dayEntry = new QSpinBox(AddBook);
        dayEntry->setObjectName(QString::fromUtf8("dayEntry"));
        dayEntry->setGeometry(QRect(190, 260, 61, 22));
        dayEntry->setFont(font1);
        dayEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dayEntry->setMinimum(1);
        dayEntry->setMaximum(31);
        dayEntry->setValue(1);
        monthEntry = new QSpinBox(AddBook);
        monthEntry->setObjectName(QString::fromUtf8("monthEntry"));
        monthEntry->setGeometry(QRect(280, 260, 61, 22));
        monthEntry->setFont(font1);
        monthEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        monthEntry->setMinimum(1);
        monthEntry->setMaximum(12);
        monthEntry->setValue(1);
        yearEntry = new QSpinBox(AddBook);
        yearEntry->setObjectName(QString::fromUtf8("yearEntry"));
        yearEntry->setGeometry(QRect(370, 260, 81, 22));
        yearEntry->setFont(font1);
        yearEntry->setButtonSymbols(QAbstractSpinBox::NoButtons);
        yearEntry->setMinimum(1);
        yearEntry->setMaximum(2021);
        yearEntry->setValue(2000);
        widgetTitle_12 = new QLabel(AddBook);
        widgetTitle_12->setObjectName(QString::fromUtf8("widgetTitle_12"));
        widgetTitle_12->setGeometry(QRect(20, 590, 131, 21));
        widgetTitle_12->setFont(font);
        blurbEdit = new QTextEdit(AddBook);
        blurbEdit->setObjectName(QString::fromUtf8("blurbEdit"));
        blurbEdit->setGeometry(QRect(190, 590, 511, 231));
        widgetTitle_7 = new QLabel(AddBook);
        widgetTitle_7->setObjectName(QString::fromUtf8("widgetTitle_7"));
        widgetTitle_7->setGeometry(QRect(20, 140, 151, 21));
        widgetTitle_7->setFont(font);
        isbnEdit = new QLineEdit(AddBook);
        isbnEdit->setObjectName(QString::fromUtf8("isbnEdit"));
        isbnEdit->setGeometry(QRect(190, 140, 341, 21));
        isbnEdit->setFont(font1);

        retranslateUi(AddBook);

        QMetaObject::connectSlotsByName(AddBook);
    } // setupUi

    void retranslateUi(QWidget *AddBook)
    {
        AddBook->setWindowTitle(QCoreApplication::translate("AddBook", "Form", nullptr));
        widgetTitle_2->setText(QCoreApplication::translate("AddBook", "Title", nullptr));
        widgetTitle_3->setText(QCoreApplication::translate("AddBook", "Author", nullptr));
        authorEdit->setText(QString());
        widgetTitle_4->setText(QCoreApplication::translate("AddBook", "Genre", nullptr));
        genreBox->setItemText(0, QCoreApplication::translate("AddBook", "Biography", nullptr));
        genreBox->setItemText(1, QCoreApplication::translate("AddBook", "Academic", nullptr));
        genreBox->setItemText(2, QCoreApplication::translate("AddBook", "Historical", nullptr));
        genreBox->setItemText(3, QCoreApplication::translate("AddBook", "Journalism", nullptr));
        genreBox->setItemText(4, QCoreApplication::translate("AddBook", "Travel Guide", nullptr));
        genreBox->setItemText(5, QCoreApplication::translate("AddBook", "Guides", nullptr));
        genreBox->setItemText(6, QCoreApplication::translate("AddBook", "Action", nullptr));
        genreBox->setItemText(7, QCoreApplication::translate("AddBook", "Adventure", nullptr));
        genreBox->setItemText(8, QCoreApplication::translate("AddBook", "Romance", nullptr));
        genreBox->setItemText(9, QCoreApplication::translate("AddBook", "Science Fiction", nullptr));

        widgetTitle_5->setText(QCoreApplication::translate("AddBook", "Page Count", nullptr));
        widgetTitle_6->setText(QCoreApplication::translate("AddBook", "Dewey Decimal", nullptr));
        widgetTitle_8->setText(QCoreApplication::translate("AddBook", "Release Date", nullptr));
        widgetTitle_9->setText(QCoreApplication::translate("AddBook", "/", nullptr));
        widgetTitle_10->setText(QCoreApplication::translate("AddBook", "/", nullptr));
        widgetTitle_11->setText(QCoreApplication::translate("AddBook", "Cover Image", nullptr));
        coverpathSearch->setText(QCoreApplication::translate("AddBook", "Search:", nullptr));
        saveButton->setText(QCoreApplication::translate("AddBook", "Save Book", nullptr));
        coverlabel->setText(QString());
        widgetTitle_12->setText(QCoreApplication::translate("AddBook", "Description", nullptr));
        widgetTitle_7->setText(QCoreApplication::translate("AddBook", "ISBN", nullptr));
        isbnEdit->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddBook: public Ui_AddBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
