#include "adminpage.h"
#include "ui_adminpage.h"
#include "adduserdialog.h"
#include "loginpage.h"
AdminPage::AdminPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminPage)
{
    ui->setupUi(this);
}

AdminPage::~AdminPage()
{
    delete ui;
}



void AdminPage::on_pushButtonAddUser_clicked()
{
    AddUserDialog *adduserdialog = new AddUserDialog();
    adduserdialog->exec();
}


void AdminPage::on_pushButtonListUsers_clicked()
{

}


void AdminPage::on_pushButtonLogOut_clicked()
{
    LoginPage * loginPage = new LoginPage();
    loginPage->show();
    this->hide();

}

