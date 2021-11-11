#include "addbook.h"
#include "ui_addbook.h"
#include "QFileDialog"

AddBook::AddBook(QWidget *parent, LibSystems::Book *lastBook) :
    QWidget(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);

    book = lastBook;

    this->setStyleSheet
            (
                "QPushButton { background-color: #6895e8; }"
                "QPushButton:hover { background-color: #5687d1; }"
                "QLineEdit { border-radius: 6px; border-style: outset; }"
                "QSpinBox { border-radius: 6px; border-style: outset; }"
                "QSlider::groove {  }"
                "QTextEdit { border-radius: 2px; border-style: outset; border: 1px; }"
                "QSlider::handle { background-color: #6895e8; border-radius: 2px; border-style: outset; }"
                "QLineEdit#coverpathEntry { border-radius: 0px; }"
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

    LibSystems::Book *newBook = new LibSystems::Book(LibSystems::Book::Count(), ui->titleEdit->text(), ui->authorEdit->text(), ui->genreBox->currentText(), filePath, ui->blurbEdit->toPlainText(),
                                           ui->pgEntry->value(), ui->ddCounter->value(), releaseDate, book);
    newBook->WriteToMemory();
    if (book != nullptr) { book->SetNext(newBook); }
    book = newBook;

    QtHelpers::InformationMessageBox("Success", "The new book has been added to the database");
}

