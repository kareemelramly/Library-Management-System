// #ifndef UTILS_H
// #define UTILS_H

// #include <QString>
// #include <QMap>
// #include "librarymember.h"

// class Utils {
// public:
//     static QMap<QString, LibraryMember*> loadUsersFromFile(const QString& filePath);
//     static void saveUsersToFile(const QString& filePath, const QMap<QString, LibraryMember*>& users);
//     static void createDefaultAdmin(const QString& filePath);
//     static bool isUsernameAvailable(const QString& filePath, const QString& username);
// };

// #endif // UTILS_H
#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QMap>
#include "librarymember.h"

class Utils {
public:
    static QMap<QString, LibraryMember*> loadUsersFromFile(const QString& filePath);
    static void saveUsersToFile(const QString& filePath, const QMap<QString, LibraryMember*>& users);
    static void saveUsersToFile(const QString& filePath, const QString& username, const QString& password, const QString& role);
    static void createDefaultAdmin(const QString& filePath);
    static bool isUsernameAvailable(const QString& filePath, const QString& username);
};

#endif // UTILS_H
