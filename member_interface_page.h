#ifndef MEMBER_INTERFACE_PAGE_H
#define MEMBER_INTERFACE_PAGE_H
#include "library_member.h"
#include "member.h"
#include <QDialog>
#include "book.h"
#include "borrow_return_book.h"
namespace Ui {
class User_Interface_Page;
}

class User_Interface_Page : public QDialog
{
    Q_OBJECT

public:
    explicit User_Interface_Page(QString username,library_system* system, QWidget *parent = nullptr);
    ~User_Interface_Page();

private slots:
    void on_borrow_book_clicked();

private:
    Ui::User_Interface_Page *ui;
    member* user;
    borrow_return_book* borrowBookPage;
    QMap<QString, library_member*> users;
    QList<book*>books;
    library_system *librarySystem;
};

#endif // MEMBER_INTERFACE_PAGE_H
