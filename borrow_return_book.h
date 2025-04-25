#ifndef BORROW_RETURN_BOOK_H
#define BORROW_RETURN_BOOK_H

#include <QDialog>

namespace Ui {
class borrow_return_book;
}

class borrow_return_book : public QDialog
{
    Q_OBJECT

public:
    explicit borrow_return_book(QWidget *parent = nullptr);
    ~borrow_return_book();

private:
    Ui::borrow_return_book *ui;
};

#endif // BORROW_RETURN_BOOK_H
