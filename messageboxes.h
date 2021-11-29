#ifndef MESSAGEBOXES_H
#define MESSAGEBOXES_H

#include <Qt>
#include <QMessageBox>

namespace LibMessageBoxes
{
    int ErrorMessageBox(QString errorName, QString errorText);
    int InformationMessageBox(QString infoName, QString infoText);
}

#endif // MESSAGEBOXES_H
