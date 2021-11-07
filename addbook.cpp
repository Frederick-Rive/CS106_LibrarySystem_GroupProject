#include "addbook.h"
#include "ui_addbook.h"

AddBook::AddBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}
