#include "member_interface_page.h"
#include "ui_member_interface_page.h"
#include "utils.h"
User_Interface_Page::User_Interface_Page(QString username, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::User_Interface_Page)
{
    ui->setupUi(this);
    ui->welcome_label->setText("Welcome "+username);
    setWindowTitle("Member Page");
    library_member* userInput = Utils::loadUsersFromFile("users.csv")[username];
    user = dynamic_cast<member*>(userInput);
    ui->number_of_books->setText(""+QString::number(Utils::getTotalNumberOfBooks("books.csv")));
    ui->number_of_borrowed->setText(""+QString::number(user->borrowed_books.size()));
    ui->number_of_overdue->setText(""+QString::number(user->getOverdueBooks(20251020)));
}

User_Interface_Page::~User_Interface_Page()
{
    delete ui;
}

void User_Interface_Page::on_borrow_book_clicked()
{
    borrowBookPage = new borrow_return_book(user,this);
    borrowBookPage->show();
    this->hide();
}

