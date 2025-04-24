#include "librariandashboard.h"
#include "ui_librariandashboard.h"
#include "loginpage.h"
LibrarianDashboard::LibrarianDashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibrarianDashboard)
{
    ui->setupUi(this);
    ui->labelLibrarianName->setText("Mohammed"); // to set the name of the librarian
    ui->labelTotalBooks->setText("Total books: \n" + QString::number(300)); // to set the total number of books
    ui->labelBorrowedBooks->setText("Borrowed books: \n" + QString::number(50)); // to set the borrowed books
     ui->labelOverdueBooks->setText("Overdue books: \n" + QString::number(20)); // to set the Overdue books
     // modify above instructions to read momental records

}

LibrarianDashboard::~LibrarianDashboard()
{
    delete ui;
}







void LibrarianDashboard::on_pushButtonLogOut_clicked()
{
    LoginPage * loginPage = new LoginPage();
    loginPage->show();
    this->hide();

}

