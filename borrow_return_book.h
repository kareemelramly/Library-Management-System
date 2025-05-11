#ifndef BORROW_RETURN_BOOK_H
#define BORROW_RETURN_BOOK_H
#include "member.h"
#include <QDialog>

namespace Ui {
class borrow_return_book;
}

class borrow_return_book : public QDialog
{
    Q_OBJECT

public:
    explicit borrow_return_book(member* currentUser,QWidget *parent = nullptr);
    ~borrow_return_book();
    void refreshBooksList();

private:
    Ui::borrow_return_book *ui;
    member* user;
};

#endif // BORROW_RETURN_BOOK_H
