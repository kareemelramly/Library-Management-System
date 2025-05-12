#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H
#include "book.h"
#include "library_member.h"
class library_system
{
    QList<book*>books;
    QMap<QString,library_member*>users;

public:
    void run();
    library_system();
};

#endif // LIBRARY_SYSTEM_H
