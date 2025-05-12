#include "borrow_return_book.h"
#include "build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/ui_borrow_return_book.h"
#include "ui_borrow_return_book.h"
#include<QStringListModel>
borrow_return_book::borrow_return_book(member* currentUser,library_system * system,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::borrow_return_book),user(currentUser), librarySystem(system)
{
    ui->setupUi(this);
    user->calculateFines();
    ui->fines_money->setText(QString::number(user->TotalFine));
    refreshBooksList();
    refreshBooksBorrowedList();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

borrow_return_book::~borrow_return_book()
{
    delete ui;
    librarySystem->saveBooks();
    librarySystem->saveUsers();
}

void borrow_return_book::refreshBooksList()
{

    QStringList list;
    for(auto &item: librarySystem->Books()){
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
    QStringList list;
    for(auto &item: librarySystem->Books()){
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
    if(!selectedIndexes.isEmpty()){
        QModelIndex selectedIndex = selectedIndexes.first();
        QVariant data = selectedIndex.data();
        for(auto item = librarySystem->Books().begin();item!=librarySystem->Books().end();item++){
            if((*item)->Title==data){
                if((*item)->availableCopies<=0)
                    return ;
                user->borrow((*item)->ID.toInt());
                (*item)->borrow();
                user->calculateFines();
                ui->fines_money->setText(QString::number(user->TotalFine));
                refreshBooksBorrowedList();
                refreshBooksList();
                librarySystem->saveBooks();
                auto userList = librarySystem->Users();
                userList[user->getUsername()]=user;
                librarySystem->saveBooks();
                return ;
            }
        }
    }
}


void borrow_return_book::on_return_book_button_clicked()
{
    QString Text= ui->borrowed_books_combo_box->currentText();
    const auto& users = librarySystem->Books();

    for(auto item =  users.begin();item!= users.end();item++){
        if((*item)->Title==Text){
            user->Return((*item)->ID.toInt());
            user->calculateFines();
            ui->fines_money->setText(QString::number(user->TotalFine));
            (*item)->returning();
            refreshBooksBorrowedList();
            refreshBooksList();
            librarySystem->saveBooks();
            auto userList = librarySystem->Users();
            userList[user->getUsername()]=user;
            librarySystem->saveUsers();
            return ;
        }
    }
}

