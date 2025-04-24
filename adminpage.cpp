#include "adminpage.h"
#include "ui_adminpage.h"
#include "adduserdialog.h"
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

