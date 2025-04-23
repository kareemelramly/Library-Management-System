#include "librariandashboard.h"
#include "ui_librariandashboard.h"

LibrarianDashboard::LibrarianDashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibrarianDashboard)
{
    ui->setupUi(this);
}

LibrarianDashboard::~LibrarianDashboard()
{
    delete ui;
}
