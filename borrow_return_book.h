#ifndef BORROW_RETURN_BOOK_H
#define BORROW_RETURN_BOOK_H
#include "member.h"
#include <QDialog>
#include "library_system.h"
namespace Ui {
class borrow_return_book;
}

class borrow_return_book : public QDialog
{
    Q_OBJECT

public:
    explicit borrow_return_book(member* currentUser,library_system *system,  QWidget *parent = nullptr);
    ~borrow_return_book();
    void refreshBooksList();
    void refreshBooksBorrowedList();
private slots:
    void on_borrow_book_button_clicked();

    void on_return_book_button_clicked();

private:
    Ui::borrow_return_book *ui;
    member* user;
    library_system* librarySystem;
};

#endif // BORROW_RETURN_BOOK_H
