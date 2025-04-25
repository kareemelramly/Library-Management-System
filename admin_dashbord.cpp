#include "admin_dashbord.h"
#include "ui_admin_dashbord.h"

Admin_Dashbord::Admin_Dashbord(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin_Dashbord)
{
    ui->setupUi(this);
}

Admin_Dashbord::~Admin_Dashbord()
{
    delete ui;
}
