#include "librarian.h"

Librarian::Librarian(const QString& username, const QString& password)
    : library_member(username, password) {}

QString Librarian::getRole() const {
    return "librarian";
}

