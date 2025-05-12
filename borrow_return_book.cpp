#include "borrow_return_book.h"
#include "ui_borrow_return_book.h"
#include "utils.h"
#include<QStringListModel>
borrow_return_book::borrow_return_book(member* currentUser,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,bool darkmode,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::borrow_return_book),user(currentUser),users(usersIn),books(booksIn)
{
    this->darkMode = darkmode;
    ui->setupUi(this);
    user->calculateFines();
    ui->fines_money->setText(QString::number(user->TotalFine));
    refreshBooksList();
    refreshBooksBorrowedList();
    if (!darkMode) {
        // Light mode
        qApp->setStyleSheet(""); // Reset to default
    } else {
        // Dark mode stylesheet
        QString darkStyle = R"(
            QWidget {
                background-color: #121212;
                color: #ffffff;
            }
            QPushButton {
                background-color: #2c2c2c;
                border: 1px solid #444;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: #3d3d3d;
            }
            QLabel{
                color:white;
            }
            QTableWidget{
                color:black;
            }
            QListView{
                color:black;
            }
        )";
        qApp->setStyleSheet(darkStyle);
    }
    this->setAttribute(Qt::WA_DeleteOnClose);
}

borrow_return_book::~borrow_return_book()
{
    Utils::saveBookstoFile("books.csv",books);
    Utils::saveUsersToFile("users.csv",users);
    delete ui;
}

void borrow_return_book::refreshBooksList()
{
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
    QList<book*>borrowed_books = books;
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
                auto userList = users;
                userList[user->getUsername()]=user;
                return ;
            }
        }
    }
}


void borrow_return_book::on_return_book_button_clicked()
{
    QString Text= ui->borrowed_books_combo_box->currentText();
    QList<book*>borrowed_books = books;

    for(auto item = borrowed_books.begin();item!=borrowed_books.end();item++){
        if((*item)->Title==Text){
            user->Return((*item)->ID.toInt());
            user->calculateFines();
            ui->fines_money->setText(QString::number(user->TotalFine));
            (*item)->returning();
            refreshBooksBorrowedList();
            refreshBooksList();
            auto userList =users;
            userList[user->getUsername()]=user;
            return ;
        }
    }
}

