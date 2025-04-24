#include "listusers.h"
#include "ui_listusers.h"

ListUsers::ListUsers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ListUsers)
{
    ui->setupUi(this);
}

ListUsers::~ListUsers()
{
    delete ui;
}
