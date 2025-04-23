#include "admin.h"

Admin::Admin(const QString& username, const QString& password)
    : LibraryMember(username, password) {}

QString Admin::getRole() const {
    return "admin";
}


