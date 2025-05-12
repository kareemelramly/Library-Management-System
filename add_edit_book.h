#ifndef ADD_EDIT_BOOK_H
#define ADD_EDIT_BOOK_H
#include <QDialog>
#include "book.h"
#include "library_member.h"
#include "librarian.h"
namespace Ui {
class add_edit_book;
}

class add_edit_book : public QDialog
{
    Q_OBJECT

public:
    explicit add_edit_book(QDialog* mainPage, Librarian* userIn,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,bool addStatue=true,QString ID="", QString title="", QString author="", QString Category="",QWidget *parent = nullptr);
    ~add_edit_book();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    bool addingCondition;
    Ui::add_edit_book *ui;
    QDialog* mainP;
    Librarian* user;
    QMap<QString, library_member*> users;
    QList<book*>books;
};

#endif // ADD_EDIT_BOOK_H
