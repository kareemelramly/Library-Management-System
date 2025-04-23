#include "memberdashboard.h"
#include "ui_memberdashboard.h"

MemberDashboard::MemberDashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MemberDashboard)
{
    ui->setupUi(this);
}

MemberDashboard::~MemberDashboard()
{
    delete ui;
}
