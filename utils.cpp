#include "utils.h"
#include "admin.h"
#include "librarian.h"
#include "library_member.h"
#include "member.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "book.h"
QMap<QString, library_member*> Utils::loadUsersFromFile(const QString& filePath) {
    QMap<QString, library_member*> users;
    QFile file(filePath);

    if (!file.exists()) {
        // File doesn't exist, create the default admin
        createDefaultAdmin(filePath);
    }

    // Try to open the file after possibly creating it
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return users;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 3) {
            QString username = parts[0];
            QString password = parts[1];
            QString role = parts[2];
            // Assign the user based on the role
            if (role == "admin") {
                users[username] = new admin(username, password);
            } else if (role == "librarian") {
                users[username] = new Librarian(username, password);
            } else if (role == "member") {
                int Fines= parts[3].toInt()*20; //20 is a value
                QMap<int,QString>books;
                for(int i=4;i<parts.size();i+=2){
                    books[parts[i].toInt()]=parts[i+1];
                }
                users[username] = new member(username, password,books,Fines);
            }
        }
    }
    file.close();
    return users;
}

QList<book*> Utils::loadBooksFromFile(const QString& filePath) {
    QList<book*>books;
    QFile file(filePath);

    if (!file.exists()) {
        // File doesn't exist, create the default admin
        createDefaultBook(filePath);
    }

    // Try to open the file after possibly creating it
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return books;
    }
    //book(QString id, QString title, QString auth, QString categ, int number_of_copies, int available);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        qDebug()<<parts.size()<<"\n";
        if (parts.size() >= 6) {
            QString bookID = parts[0];
            QString title = parts[1];
            QString author = parts[2];
            QString category = parts[3];
            int number_of_copies = parts[4].toInt();
            int availability = parts[5].toInt();
            // Add the book
            books.push_back(new book(bookID,title,author,category,number_of_copies,availability));
    }
}
    file.close();
    return books;
}
void Utils::saveUsersToFile(const QString& filePath, const QMap<QString, library_member*>users) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open file!" << filePath;
        return;
    }
    QTextStream out(&file);
    for (auto it = users.begin(); it != users.end(); ++it) {
        library_member* user = it.value();
        out << user->getUsername() << "," << user->getPassword() << "," << user->getRole();
        if(user->getRole()=="member"){
            member* userMember= dynamic_cast<member*>(user);
            out<<","<<userMember->TotalFine;
            for(auto item=userMember->borrowed_books.begin();item!=userMember->borrowed_books.end();item++){
                out<<","<<item.key()<<","<<item.value();
            }
        }
        out<<"\n";
    }
    file.close();
}
void Utils::saveBookstoFile(const QString& filePath,const QList<book*> books) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open file!" << filePath;
        return;
    }
    QTextStream out(&file);
    QList<book*>::const_iterator it = books.begin();
    for (it = books.begin(); it != books.end(); ++it) {
        out<<(*it)->ID<<","<<(*it)->Title<<","<<(*it)->author<<","<<(*it)->Category<<","<<(*it)->totalCopies<<","<<(*it)->availableCopies<<"\n";
    }
    file.close();
}
void Utils::createDefaultAdmin(const QString& filePath) {
    QFile file(filePath);

    // Check if file already exists - don't overwrite
    if (file.exists()) {
        return;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "admin,admin123,admin\n";  // Default admin username/password
        file.close();
    }
}

void Utils::createDefaultBook(const QString& filePath) {
    QFile file(filePath);

    // Check if file already exists - don't overwrite
    if (file.exists()) {
        return;
    }

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        file.close();
    }
}

bool Utils::isUsernameAvailable(const QString& filePath, const QString& username) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return true;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3 && parts[0] == username) {
            file.close();
            return false;  
        }
    }
    file.close();
    return true;  
}
bool Utils::isBookAvailable(const QString& filePath, const int ID) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return true;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 6 && parts[0].toInt() == ID) {
            file.close();
            return false;
        }
    }
    file.close();
    return true;
}
 int Utils::getTotalNumberOfBooks(const QString& filePath){
    int counter=0;
    QFile file(filePath);

    if (!file.exists()) {
        // File doesn't exist, create the default admin
        createDefaultBook(filePath);
    }

    // Try to open the file after possibly creating it
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return counter;
    }
    //book(QString id, QString title, QString auth, QString categ, int number_of_copies, int available);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() >= 6) {
            counter++;

        }
    }
    file.close();
    return counter;
}
