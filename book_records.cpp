#include "book_records.h"
#include "ui_book_records.h"

book_records::book_records(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::book_records)
{
    ui->label_5->setStyleSheet("{color:#COBBFE}");
    ui->setupUi(this);
}

book_records::~book_records()
{
    delete ui;
}
