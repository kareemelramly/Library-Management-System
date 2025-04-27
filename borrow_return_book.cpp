#include "borrow_return_book.h"
#include "ui_borrow_return_book.h"

borrow_return_book::borrow_return_book(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::borrow_return_book)
{
    ui->setupUi(this);
}

borrow_return_book::~borrow_return_book()
{
    delete ui;
}

