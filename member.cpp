#include "member.h"

// Constructor: calls the parent (library_member) constructor
member::member(const QString& username, const QString& password,QMap<int,QString>books,int Fines)
    : library_member(username, password){
    TotalFine=Fines;
    borrowed_books= books;
}
// getRole function returns "member"
QString member::getRole() const {
    return "member";
}

void member::borrow(int ID){
    QString Date=QDate::currentDate().toString("yyyy-MM-dd");
    if(!borrowed_books.contains(ID)){
        borrowed_books[ID]= Date;
    }
}
void member::Return(int ID){
    if(borrowed_books.contains(ID)){
        auto item = borrowed_books.find(ID);
        borrowed_books.erase(item);
    }
}
int member::getOverdueBooks(){
    QString CurrentDate = QDate::currentDate().toString("yyyy-MM-dd");
    auto item = borrowed_books.begin();
    int counter=0;
    for(item=borrowed_books.begin();item!=borrowed_books.end();item++){
        if(item.value()<=CurrentDate){
            counter++;
        }
    }
    return counter;
}
