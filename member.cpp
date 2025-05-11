#include "member.h"

// Constructor: calls the parent (library_member) constructor
member::member(const QString& username, const QString& password,QMap<int,int>books,int Fines)
    : library_member(username, password){
    TotalFine=Fines;
    borrowed_books= books;
}
// getRole function returns "member"
QString member::getRole() const {
    return "member";
}

void member::borrow(int ID, int Date){
    if(!borrowed_books.contains(ID)){
        borrowed_books[ID]= Date;
    }
}
void member::Return(int ID,int Date){
    if(borrowed_books.contains(ID)){
        auto item = borrowed_books.find(ID);
        if(item.value()>Date){
            TotalFine -= 20; //anyValue
        }
        borrowed_books.erase(item);
    }
}
int member::getOverdueBooks(int CurrentDate){
    auto item = borrowed_books.begin();
    int counter=0;
    for(item=borrowed_books.begin();item!=borrowed_books.end();item++){
        if(item.value()<CurrentDate){
            counter++;
        }
    }
    return counter;
}
