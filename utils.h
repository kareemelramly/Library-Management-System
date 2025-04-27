#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QMap>
#include "library_member.h"

class Utils {
public:
    // Load users from file, returning a map of users with their username as key
    static QMap<QString, library_member*> loadUsersFromFile(const QString& filePath);

    // Save all users to file (overwrites the file)
    static void saveUsersToFile(const QString& filePath, const QMap<QString, library_member*>& users);

    // Save a new user to the file (used when registering a new user)
    static void saveUsersToFile(const QString& filePath, const QString& username, const QString& password, const QString& role);

    // Create a default admin user if the file doesn't exist
    static void createDefaultAdmin(const QString& filePath);

    // Check if a username is available (not already used)
    static bool isUsernameAvailable(const QString& filePath, const QString& username);
};

#endif // UTILS_H
