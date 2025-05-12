#ifndef LIBRARIAN_INTERFACE_PAGE_H
#define LIBRARIAN_INTERFACE_PAGE_H

#include <QDialog>
#include "library_member.h"
#include "librarian.h"
#include "book.h"
#include "book_records.h"
namespace Ui {
class librarian_interface_page;
}

class librarian_interface_page : public QDialog
{
    Q_OBJECT

public:
    explicit librarian_interface_page(QString name,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,bool darkMode, QWidget *parent);
    ~librarian_interface_page();

private slots:
    void on_book_records_button_clicked();

private:
    bool darkMode;
    Ui::librarian_interface_page *ui;
    Librarian* user;
    QMap<QString, library_member*> users;
    QList<book*>books;
    book_records* booksPage;
};

#endif // LIBRARIAN_INTERFACE_PAGE_H




