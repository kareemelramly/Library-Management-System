#include "utils.h"
#include "admin.h"
#include "librarian.h"
#include "library_member.h"
#include "member.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

QMap<QString, library_member*> Utils::loadUsersFromFile(const QString& filePath) {
    QMap<QString, library_member*> users;
    QFile file(filePath);

    if (!file.exists()) {
        // File doesn't exist, create the default admin
        createDefaultAdmin(filePath);
    }

    // Try to open the file after possibly creating it
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading: " << filePath;
        return users;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3) {
            QString username = parts[0];
            QString password = parts[1];
            QString role = parts[2];

            // Assign the user based on the role
            if (role == "admin") {
                users[username] = new admin(username, password);
            } else if (role == "librarian") {
                users[username] = new Librarian(username, password);
            } else if (role == "member") {
                users[username] = new member(username, password);
            }
        }
    }
    file.close();
    return users;
}

// Keep the original method for backward compatibility
void Utils::saveUsersToFile(const QString& filePath, const QMap<QString, library_member*>& users) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for writing: " << filePath;
        return;
    }
    QTextStream out(&file);
    for (auto it = users.begin(); it != users.end(); ++it) {
        library_member* user = it.value();
        out << user->getUsername() << "," << user->getPassword() << "," << user->getRole() << "\n";
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

bool Utils::isUsernameAvailable(const QString& filePath, const QString& username) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return true;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3 && parts[0] == username) {
            file.close();
            return false;  // Username already exists
        }
    }
    file.close();
    return true;  // Username is available
}
