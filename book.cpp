
#include "book.h"
book::book(QString id, QString title, QString auth, QString category,int number_of_copies,int available) {
    ID = id;
    Title = title;
    author = auth;
    Category = category;
    totalCopies = number_of_copies;
    availableCopies=available;
    timesBorrowed=totalCopies-available;
}
void book::borrow(){
    if(availableCopies>0){
        availableCopies--;
        timesBorrowed++;
    }
}
