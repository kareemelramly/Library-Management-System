#include "library_system.h"
#include "utils.h"

library_system::library_system() {
    userPath = "users.csv";
    bookPath = "books.csv";

    Utils::createDefaultAdmin(userPath);
    Utils::createDefaultBook(bookPath);

    users = *new QMap<QString, library_member*>(Utils::loadUsersFromFile(userPath));
    books = *new QList<book*>(Utils::loadBooksFromFile(bookPath));
}


QList<book *> &library_system::Books(){
    return books;
}

QMap<QString, library_member *> &library_system::Users()
{
    return users;
}
QString library_system::bookFilePath()
{
    return bookPath;
}
QString library_system::userFilePath()
{
    return userPath;
}
void library_system::saveBooks(){
    Utils::saveBookstoFile(bookPath, books);

}

void library_system::saveUsers()
{
    Utils::saveUsersToFile(userPath, users);
}
library_system::~library_system(){
    saveBooks();
    saveUsers();
}
