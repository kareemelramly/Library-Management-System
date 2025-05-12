#ifndef BOOK_H
#define BOOK_H
#include<QString>
#include<QPixmap>
class book
{
    public:
    QString ID;
    QString Title;
    QString author;
    //QPixmap CoverPage;
    QString Category;
    int totalCopies;
    int availableCopies;
    int timesBorrowed;
    book(QString id, QString title, QString auth, QString categ, int number_of_copies, int available);
    void borrow();
    void returning(){
        availableCopies++;
        timesBorrowed--;
    }
};

#endif // BOOK_H
