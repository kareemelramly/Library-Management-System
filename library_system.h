#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H
#include <Qstring>
#include <QMap>
#include "book.h"
#include "library_member.h"

class library_system
{
private:
    QMap<QString, library_member*> users ;
    QList<book*>   books;


public:
    library_system();
    QList<book*> Books();
    QMap<QString, library_member*>Users();

    ~library_system();
    void saveBooks();
    void saveUsers();

};

#endif // LIBRARY_SYSTEM_H
