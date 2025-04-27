#include "librarian_interface_page.h"
#include "ui_librarian_interface_page.h"

librarian_interface_page::librarian_interface_page(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::librarian_interface_page)
{
    ui->setupUi(this);
}

librarian_interface_page::~librarian_interface_page()
{
    delete ui;
}
