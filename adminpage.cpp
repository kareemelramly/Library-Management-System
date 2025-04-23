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

void AdminPage::on_pushButton_clicked()
{
    AddUserDialog *adduserdialog = new AddUserDialog();
    adduserdialog->exec();
}

