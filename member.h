#ifndef MEMBER_H
#define MEMBER_H

#include "library_member.h"

class member : public library_member {
public:
    member(const QString& username, const QString& password, QMap<int,int>books,int Fines=0);;
    QString getRole() const override;
    int TotalFine;
    void borrow(int ID,int Date);
    void Return(int ID, int CurrentDate);
    int getOverdueBooks(int CurrentDate);
    void calculateFines(int CurrentDate){
        TotalFine= getOverdueBooks(CurrentDate)*20; //value of one book is 20
    }
    bool isBookBorrowed(int ID){
        if(borrowed_books.contains(ID)){
            return true;
        }else{
            return false;
        }
    }
    QMap<int,int>borrowed_books;
};

#endif // MEMBER_H
