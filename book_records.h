#ifndef BOOK_RECORDS_H
#define BOOK_RECORDS_H
#include "librarian.h"
#include "book.h"
#include <QDialog>
#include "add_edit_book.h"
namespace Ui {
class book_records;
}

class book_records : public QDialog
{
    Q_OBJECT

public:
    explicit book_records(Librarian* userIn,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,QWidget *parent = nullptr);
    ~book_records();
    void refreshBooksList();
    void refreshBooksListByTitle(QString name);
    void refreshBooksListByCategory(QString name);
    void refreshBooksListByAuthor(QString name);
    void refreshComboBox();
    QList<book*>books;
private slots:
    void on_search_button_clicked();

    void on_add_book_button_clicked();

    void on_edit_book_button_clicked();

    void on_delete_book_button_clicked();

private:
    Ui::book_records *ui;
    Librarian* user;
    QMap<QString, library_member*> users;
    add_edit_book* addBookPage;
};

#endif // BOOK_RECORDS_H
