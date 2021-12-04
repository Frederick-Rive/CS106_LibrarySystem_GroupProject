#include "messageboxes.h"
#include <QLayout>
#include <QLabel>
#include <QMessageBox>

int LibMessageBoxes::ErrorMessageBox(QString errorName, QString errorText) //maybe have some functions that make basic error messages? idk
{
    QMessageBox *error = new QMessageBox;
    error->setStandardButtons(QMessageBox::Retry);
    error->setWindowTitle("Error");
    error->setText(errorName);
    error->setInformativeText(errorText);
    error->setModal(true);
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
    return info->exec();
}
