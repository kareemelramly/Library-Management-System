#include "librarymember.h"

LibraryMember::LibraryMember(const QString& username, const QString& password)
    : username(username), password(password) {}

QString LibraryMember::getUsername() const {
    return username;
}

QString LibraryMember::getPassword() const {
    return password;
}

