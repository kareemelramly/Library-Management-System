#ifndef BORROW_RETURN_BOOK_H
#define BORROW_RETURN_BOOK_H
#include "member.h"
#include <QDialog>
#include<book.h>
#include<library_member.h>
namespace Ui {
class borrow_return_book;
}

class borrow_return_book : public QDialog
{
    Q_OBJECT

public:
    explicit borrow_return_book(member* currentUser,const QMap<QString, library_member*>& users,const QList<book*>& books,bool darkMode, QWidget *parent = nullptr);
    ~borrow_return_book();
    void refreshBooksList();
    void refreshBooksBorrowedList();
private slots:
    void on_borrow_book_button_clicked();

    void on_return_book_button_clicked();

    void on_backButton_clicked();

    void on_pushButton_clicked();

private:
    bool darkMode;
    Ui::borrow_return_book *ui;
    member* user;
    QMap<QString, library_member*> users;
    QList<book*>books;
};

#endif // BORROW_RETURN_BOOK_H
