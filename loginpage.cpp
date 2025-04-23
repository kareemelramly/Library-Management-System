#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
}

LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_PushButtonLogin_clicked()
{

}



void LoginPage::on_PushButtonCancel_clicked()
{
    ui->lineEditUserName->clear();
    ui->lineEditPassword->clear();

}


