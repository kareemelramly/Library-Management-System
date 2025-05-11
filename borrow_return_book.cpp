#include "borrow_return_book.h"
#include "ui_borrow_return_book.h"
#include "utils.h"
borrow_return_book::borrow_return_book(member* currentUser,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::borrow_return_book),user(currentUser)
{
    ui->setupUi(this);
    ui->fines_money->setText(QString::number(user->TotalFine));
}

borrow_return_book::~borrow_return_book()
{
    delete ui;
}

void borrow_return_book::refreshBooksList()
{
    QList<book*>books = Utils::loadBooksFromFile("boos.csv");
}
