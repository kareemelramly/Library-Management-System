#include "member_interface_page.h"
#include "ui_member_interface_page.h"
#include "utils.h"
User_Interface_Page::User_Interface_Page(QString username,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::User_Interface_Page),users(usersIn),books(booksIn)
{
    ui->setupUi(this);
    ui->welcome_label->setText("Welcome "+username);
    setWindowTitle("Member Page");
    library_member* userInput = users[username];
    user = dynamic_cast<member*>(userInput);
    ui->number_of_books->setText(""+QString::number(Utils::getTotalNumberOfBooks(books)));
    ui->number_of_borrowed->setText(""+QString::number(user->borrowed_books.size()));
    ui->number_of_overdue->setText(""+QString::number(user->getOverdueBooks()));
    this->setAttribute(Qt::WA_DeleteOnClose);
}

User_Interface_Page::~User_Interface_Page()
{
    Utils::saveUsersToFile("users.csv",users);
    Utils::saveBookstoFile("books.csv",books);
    delete ui;
}

void User_Interface_Page::on_borrow_book_clicked()
{
    borrowBookPage = new borrow_return_book(user,users,books,this);
    borrowBookPage->show();
    this->hide();
}

