#include "library_system.h"
#include "utils.h"

library_system::library_system() {
    Utils::createDefaultAdmin("users.csv");
    Utils::createDefaultBook("books.csv");

    users = *new QMap<QString, library_member*>(Utils::loadUsersFromFile("users.csv"));
    books = *new QList<book*>(Utils::loadBooksFromFile("books.csv"));
}


 QList<book*> library_system::Books(){
    return books;
}

 QMap<QString, library_member *> library_system::Users()
{
    return users;
}
void library_system::saveBooks(){
    Utils::saveBookstoFile("books.csv", books);

}

void library_system::saveUsers()
{
    Utils::saveUsersToFile("users.csv", users);
}
library_system::~library_system(){
    saveBooks();
    saveUsers();
}
