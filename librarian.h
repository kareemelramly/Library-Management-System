#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "librarymember.h"

class Librarian : public LibraryMember {
public:
    Librarian(const QString& username, const QString& password);
    QString getRole() const override;
};

#endif
