#include "addbook.h"
#include "ui_addbook.h"
#include "QFileDialog"

AddBook::AddBook(QWidget *parent, std::vector<LibSystems::Book*> b) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);

    bookVec = b;

    this->setStyleSheet
            (
                "QLineEdit { border-radius: 6px; border-style: outset; }"
                "QSpinBox { border-radius: 6px; border-style: outset; }"
            );

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

void AddBook::on_coverpathSearch_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select an image", "C:", tr("Image Files (*.png *.jpg *.bmp)"));
    if (filePath.length() > 0)
    {
        QPixmap cover;
        cover.load(filePath);
        ui->coverlabel->setPixmap(cover.scaled(ui->coverlabel->size()));
        ui->coverpathEntry->setText(filePath);
    }
}


void AddBook::on_saveButton_clicked()
{
    QDate releaseDate;
    releaseDate.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value());

    QPixmap cover;
    cover.load(ui->coverpathEntry->text());
    QString filePath = QString("databases/covers/") + QString::number(LibSystems::Book::Count()) + QString(".png");
    cover.save(filePath);

    bookVec.push_back(new LibSystems::Book(LibSystems::Book::Count(), ui->titleEdit->text(), ui->authorEdit->text(), ui->genreBox->currentText(), filePath,
                                           ui->pgEntry->value(), ui->ddCounter->value(), releaseDate));
    bookVec[LibSystems::Book::Count() - 1]->WriteToMemory();
}

