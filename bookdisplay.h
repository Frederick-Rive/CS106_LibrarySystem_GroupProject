#ifndef BOOKDISPLAY_H
#define BOOKDISPLAY_H

#include <QWidget>
#include <librarysystems.h>

namespace Ui {
class BookDisplay;
}

class BookDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit BookDisplay(QWidget *parent, LibSystems::Book *book = nullptr);
    ~BookDisplay();

private:
    Ui::BookDisplay *ui;
};

#endif // BOOKDISPLAY_H
