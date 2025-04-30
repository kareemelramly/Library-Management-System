#include "member.h"

// Constructor: calls the parent (library_member) constructor
member::member(const QString& username, const QString& password)
    : library_member(username, password)
{
}

// getRole function returns "member"
QString member::getRole() const {
    return "member";
}
