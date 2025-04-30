#include "admin.h"
#include <QString>
admin::admin(const QString& username, const QString& password)
    : library_member(username, password) {}

QString admin::getRole() const {
    return "admin";
}

