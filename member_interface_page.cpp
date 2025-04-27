#include "member_interface_page.h"
#include "ui_member_interface_page.h"

User_Interface_Page::User_Interface_Page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::User_Interface_Page)
{
    ui->setupUi(this);
}

User_Interface_Page::~User_Interface_Page()
{
    delete ui;
}
