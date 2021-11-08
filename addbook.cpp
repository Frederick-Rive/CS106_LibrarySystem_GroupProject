#include "addbook.h"
#include "ui_addbook.h"
#include "QFileDialog"

AddBook::AddBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);

    QPixmap defaultCover;
    defaultCover.load(":/resources/images/defaultbookcover.jpg");
    ui->coverlabel->setPixmap(defaultCover.scaled(ui->coverlabel->size()));
}

AddBook::~AddBook()
{
    delete ui;
}

void AddBook::on_ddSlider_valueChanged(int value)
{
    ui->ddCounter->setValue(value);
}

void AddBook::on_ddCounter_valueChanged(int arg1)
{
    ui->ddSlider->setValue(arg1);
}


