#include "addbook.h"
#include "ui_addbook.h"
#include "QFileDialog"
#include "messageboxes.h"

AddBook::AddBook(QWidget *parent, LibSystems::Book *lastBook, LibSystems::Book *editBook) :
    QWidget(parent),
    ui(new Ui::AddBook) //constructor
{
    ui->setupUi(this);

    book = lastBook; //initialize data member

    this->setStyleSheet // set the css code for this window
            (
                "QLabel { color: #5A98D1; }"
                "QPushButton { background-color: #5A98D1; }"
                "QPushButton:hover { background-color: #5687d1; }"
                "QLineEdit { border-radius: 6px; border-style: outset; font: 10pt 'Roboto Regular'; }"
                "QSpinBox { border-radius: 6px; border-style: outset; font: 10pt 'Roboto Regular'; }"
                "QComboBox { font: 10pt 'Roboto Regular'; }"
                "QTextEdit { border-radius: 25px; border-style: solid; border-width: 1px; background-color: white; padding: 10px; font: 10pt 'Roboto Regular'; }"
                "QSlider::handle { background-color: #5A98D1; border-radius: 2px; border-style: outset; }"
                "QLineEdit#coverpathEntry { border-radius: 0px; }"
            );

    edit = editBook; //initialize data member

    if (edit == nullptr) //adding a new book to the program
    {
        QPixmap defaultCover;
        defaultCover.load(":/resources/images/defaultbookcover.jpg");
        ui->coverlabel->setPixmap(defaultCover.scaled(ui->coverlabel->size()));
    }
    else //editing an existing book (code inside sets all entry widgets to have the existing values by default)
    {
        ui->titleEdit->setText(edit->GetTitle()); ui->authorEdit->setText(edit->GetAuthor()); ui->genreBox->setCurrentText(edit->GetGenre()); ui->ddCounter->setValue(edit->GetDeweyDecimal());
        ui->ddSlider->setValue(edit->GetDeweyDecimal()); ui->dayEntry->setValue(edit->GetReleaseDate().day()); ui->monthEntry->setValue(edit->GetReleaseDate().month());
        ui->yearEntry->setValue(edit->GetReleaseDate().year()); ui->blurbEdit->setText(edit->GetBlurb()); ui->coverpathEntry->setText(edit->GetCoverPath());
        ui->coverlabel->setPixmap(edit->GetCover().scaled(ui->coverlabel->size())); ui->pgEntry->setValue(edit->GetPageCount()); ui->isbnEdit->setText(edit->GetISBN());
    }
}

AddBook::~AddBook() //destructor
{
    delete ui;
}

void AddBook::on_ddSlider_valueChanged(int value) //keeps the counter value equal to the slider
{
    ui->ddCounter->setValue(value);
}

void AddBook::on_ddCounter_valueChanged(int arg1) //keeps the slider value equal to the counter
{
    ui->ddSlider->setValue(arg1);
}

void AddBook::on_coverpathSearch_clicked() //search for an image file to use as the cover
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

void AddBook::on_saveButton_clicked() //save book
{
    if (edit == nullptr) //if adding a new book
    {
        QDate releaseDate;
        releaseDate.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value()); //merge data from date entrys into Qdate

        QPixmap cover;
        cover.load(ui->coverpathEntry->text());
        QString filePath = QString("storage/covers/") + QString::number(LibSystems::Book::Count()) + QString(".png");
        cover.save(filePath); //save book cover to a new, more accessible position.

        LibSystems::Book *newBook = new LibSystems::Book(ui->isbnEdit->text(), ui->titleEdit->text(), ui->authorEdit->text(), ui->genreBox->currentText(), filePath, ui->blurbEdit->toPlainText(),
                                               ui->pgEntry->value(), ui->ddCounter->value(), releaseDate, book); //make a new book object using the users entrys
        newBook->WriteToMemory(); //write new book to memory
        if (book != nullptr) { book->SetNext(newBook); } //link new book into the linked list

        LibMessageBoxes::InformationMessageBox("Success", "The new book has been added to the database"); //give success message
    }
    else //if editing existing book
    {
        QDate releaseDate;
        releaseDate.setDate(ui->yearEntry->value(), ui->monthEntry->value(), ui->dayEntry->value());//merge data from date entrys into Qdate

        if (ui->coverpathEntry->text() != edit->GetCoverPath()) //if the user has changed the cover image
        {
            QPixmap cover;
            cover.load(ui->coverpathEntry->text());
            ui->coverpathEntry->setText(QString("storage/covers/") + QString::number(edit->GetIndex()) + QString(".png"));
            cover.save(ui->coverpathEntry->text());//save book cover to a new, more accessible position.=
        }

        //edit the book
        edit->EditBook(ui->isbnEdit->text(), ui->titleEdit->text(), ui->authorEdit->text(), ui->genreBox->currentText(), ui->coverpathEntry->text(), ui->blurbEdit->toPlainText(), ui->pgEntry->value(), ui->ddCounter->value(), releaseDate);

        while (book->Prev() != nullptr) //send book pointer to the head node of linked list
        {
            book = book->Prev();
        }

        LibSystems::RewriteBooks(book); //rewrite the book file to save the new data

        LibMessageBoxes::InformationMessageBox("Success", "The changes have been saved to the database"); //give success message
    }

    emit Finish(); //emit finish signal to adminwindow
}

void AddBook::on_monthEntry_valueChanged(int arg1) //restrict max value of date entry by current month entry, to ensure entry is valid
{
    switch (arg1)
    {
    case 2:
        if (ui->yearEntry->value() % 4 != 0)
        {
            ui->dayEntry->setMaximum(28);
        }
        else
        {
            ui->dayEntry->setMaximum(29);
        }
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        ui->dayEntry->setMaximum(31);
        break;
    default:
        ui->dayEntry->setMaximum(30);
    }
}

