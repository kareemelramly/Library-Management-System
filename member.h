#ifndef MEMBER_H
#define MEMBER_H

#include "library_member.h"
#include<QDate>
class member : public library_member {
public:
    member(const QString& username, const QString& password, QMap<int,QString>books,int Fines=0);;
    QString getRole() const override;
    int TotalFine;
    void borrow(int ID);
    void Return(int ID);
    int getOverdueBooks();
    void calculateFines(){
        TotalFine= getOverdueBooks()*20; //value of one book is 20
    }
    bool isBookBorrowed(int ID){
        if(borrowed_books.contains(ID)){
            return true;
        }else{
            return false;
        }
    }
    QMap<int,QString>borrowed_books;
};

#endif // MEMBER_H
