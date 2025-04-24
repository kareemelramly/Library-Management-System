#include "memberdashboard.h"
#include "ui_memberdashboard.h"
#include "loginpage.h"
MemberDashboard::MemberDashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MemberDashboard)
{
    ui->setupUi(this);
    ui->labelMemberName->setText("Mohammed"); // to set the name of the librarian
    ui->labelTotalBooks->setText("Total books: \n" + QString::number(300)); // to set the total number of books
    ui->labelBorrowedBooks->setText("Borrowed books: \n" + QString::number(50)); // to set the borrowed books
    ui->labelOverdueBooks->setText("Overdue books: \n" + QString::number(20)); // to set the Overdue books
}

MemberDashboard::~MemberDashboard()
{
    delete ui;
}

void MemberDashboard::on_pushButtonLogOut_clicked()
{
    LoginPage * loginPage = new LoginPage();
    loginPage->show();
    this->hide();

}
