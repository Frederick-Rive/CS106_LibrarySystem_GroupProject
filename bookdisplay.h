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
    explicit BookDisplay(QWidget *parent, LibSystems::Book *b = nullptr);
    ~BookDisplay();

signals:
    void Edit(LibSystems::Book *book);

private slots:
    void SendBook();

private:
    Ui::BookDisplay *ui;
    LibSystems::Book *book;

    bool eventFilter(QObject *obj, QEvent *event);

};

#endif // BOOKDISPLAY_H
