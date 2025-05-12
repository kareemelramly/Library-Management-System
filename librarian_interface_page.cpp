#include "librarian_interface_page.h"
#include "ui_librarian_interface_page.h"
librarian_interface_page::librarian_interface_page(QString name,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::librarian_interface_page),users(usersIn),books(booksIn)
{
    ui->setupUi(this);
    ui->welcome->setText("Welcome "+name);
    user = dynamic_cast<Librarian*>(users[name]);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

librarian_interface_page::~librarian_interface_page()
{
    delete ui;
}

void librarian_interface_page::on_book_records_button_clicked()
{
    booksPage = new book_records(user,users,books,this);
    this->hide();
    booksPage->show();
}

