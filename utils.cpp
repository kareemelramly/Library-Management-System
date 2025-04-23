#include "utils.h"
#include "admin.h"
#include "librarian.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QMap<QString, LibraryMember*> Utils::loadUsersFromFile(const QString& filePath) {
    QMap<QString, LibraryMember*> users;

    QFile file(filePath);
    if (!file.exists()) {
        // File doesn't exist, create the default admin
        createDefaultAdmin(filePath);
    } else {
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return users;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() == 3) {
                QString username = parts[0];
                QString password = parts[1];
                QString role = parts[2];
                if (role == "admin") {
                    users[username] = new Admin(username, password);
                } else if (role == "librarian") {
                    users[username] = new Librarian(username, password);
                }
            }
        }
        file.close();
    }

    return users;
}

// void Utils::saveUsersToFile(const QString& filePath, const QMap<QString, LibraryMember*>& users) {
//     QFile file(filePath);
//     if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return;
//     QTextStream out(&file);
//     for (auto user : users) {
//         out << user->getUsername() << "," << user->getPassword() << "," << user->getRole() << "\n";
//     }
//     file.close();
// }


void Utils::saveUsersToFile(const QString& filePath, const QString& username, const QString& password, const QString& role) {
    QFile file(filePath);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Could not open file for appending: " << filePath;
        return;
    }

    QTextStream out(&file);
    out << username << "," << password << "," << role << "\n";
    file.close();
}

// Keep the original method for backward compatibility
void Utils::saveUsersToFile(const QString& filePath, const QMap<QString, LibraryMember*>& users) {
    // This is now just for full rewrites if needed
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for writing: " << filePath;
        return;
    }

    QTextStream out(&file);
    for (auto it = users.begin(); it != users.end(); ++it) {
        LibraryMember* user = it.value();
        out << user->getUsername() << "," << user->getPassword() << "," << user->getRole() << "\n";
    }
    file.close();
}
void Utils::createDefaultAdmin(const QString& filePath) {
    // Create a default admin user
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "admin,admin123,admin\n";  // Default admin username/password
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
            return false;  // Username already exists
        }
    }
    return true;  // Username is available
}
