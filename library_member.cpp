#include "library_member.h"

library_member::library_member(const QString& username, const QString& password)
    : username(username), password(password) {}

QString library_member::getUsername() const {
    return username;
}

QString library_member::getPassword() const {
    return password;
}

