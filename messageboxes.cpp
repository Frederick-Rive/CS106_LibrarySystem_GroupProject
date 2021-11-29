#include "messageboxes.h"
#include <QLayout>
#include <QLabel>
#include <QMessageBox>

int LibMessageBoxes::ErrorMessageBox(QString errorName, QString errorText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Retry | QMessageBox::Cancel);
    error->setWindowTitle("Error");
    error->setText(errorName);
    error->setInformativeText(errorText);
    error->setModal(true);
    error->setMinimumSize(100, 80);
    error->setWindowFlag(Qt::FramelessWindowHint);
    return error->exec();
}

int LibMessageBoxes::InformationMessageBox(QString infoName, QString infoText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *info = new QMessageBox;
    info->setStandardButtons(QMessageBox::Ok);
    info->setWindowTitle("Success");
    info->setText(infoName);
    info->setInformativeText(infoText);
    info->setModal(true);
    info->setMinimumSize(100, 80);
    info->setWindowFlag(Qt::FramelessWindowHint);
    return info->exec();
}

