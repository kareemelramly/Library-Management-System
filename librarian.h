#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "library_member.h"

class Librarian : public library_member {
public:
    Librarian(const QString& username, const QString& password);
    QString getRole() const override;
};

#endif
