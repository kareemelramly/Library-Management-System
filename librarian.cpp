#include "librarian.h"

Librarian::Librarian(const QString& username, const QString& password)
    : LibraryMember(username, password) {}

QString Librarian::getRole() const {
    return "librarian";
}

