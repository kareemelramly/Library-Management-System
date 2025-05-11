#include "borrow_return_book.h"
#include "ui_borrow_return_book.h"
#include "utils.h"
#include<QStringListModel>
borrow_return_book::borrow_return_book(member* currentUser,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::borrow_return_book),user(currentUser)
{
    ui->setupUi(this);
    user->calculateFines();
    ui->fines_money->setText(QString::number(user->TotalFine));
    refreshBooksList();
    refreshBooksBorrowedList();
}

borrow_return_book::~borrow_return_book()
{
    delete ui;
}

void borrow_return_book::refreshBooksList()
{
    QList<book*>books = Utils::loadBooksFromFile("books.csv");
    QStringList list;
    for(auto item: books){
        if(!(user->isBookBorrowed(item->ID.toInt()))){
            list<<item->Title;
        }
    }
    QStringListModel* model;
    model = new QStringListModel(this);
    model->setStringList(list);
    ui->book_list->setModel(model);
    ui->book_list->setSelectionMode(QAbstractItemView::SingleSelection);
}
void borrow_return_book::refreshBooksBorrowedList()
{
    QList<book*>books = Utils::loadBooksFromFile("books.csv");
    QStringList list;
    for(auto item: books){
        if(user->isBookBorrowed(item->ID.toInt())){
        list<<item->Title;
        }
    }
    QStringListModel* model;
    model = new QStringListModel(this);
    model->setStringList(list);
    ui->borrowed_books_combo_box->setModel(model);
}

void borrow_return_book::on_borrow_book_button_clicked()
{
    QModelIndexList selectedIndexes = ui->book_list->selectionModel()->selectedIndexes();
    QList<book*>borrowed_books = Utils::loadBooksFromFile("books.csv");
    if(!selectedIndexes.isEmpty()){
        QModelIndex selectedIndex = selectedIndexes.first();
        QVariant data = selectedIndex.data();
        for(auto item = borrowed_books.begin();item!=borrowed_books.end();item++){
            if((*item)->Title==data){
                if((*item)->availableCopies<=0)
                    return ;
                user->borrow((*item)->ID.toInt());
                (*item)->borrow();
                user->calculateFines();
                ui->fines_money->setText(QString::number(user->TotalFine));
                refreshBooksBorrowedList();
                refreshBooksList();
                Utils::saveBookstoFile("books.csv",borrowed_books);
                auto userList = Utils::loadUsersFromFile("users.csv");
                userList[user->getUsername()]=user;
                Utils::saveUsersToFile("users.csv",userList);
                return ;
            }
        }
    }
}


void borrow_return_book::on_return_book_button_clicked()
{
    QString Text= ui->borrowed_books_combo_box->currentText();
    QList<book*>borrowed_books = Utils::loadBooksFromFile("books.csv");

    for(auto item = borrowed_books.begin();item!=borrowed_books.end();item++){
        if((*item)->Title==Text){
            user->Return((*item)->ID.toInt());
            user->calculateFines();
            ui->fines_money->setText(QString::number(user->TotalFine));
            (*item)->returning();
            refreshBooksBorrowedList();
            refreshBooksList();
            Utils::saveBookstoFile("books.csv",borrowed_books);
            auto userList = Utils::loadUsersFromFile("users.csv");
            userList[user->getUsername()]=user;
            Utils::saveUsersToFile("users.csv",userList);
            return ;
        }
    }
}

