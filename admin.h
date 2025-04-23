#ifndef ADMIN_H
#define ADMIN_H

#include "librarymember.h"

class Admin : public LibraryMember {
public:
    Admin(const QString& username, const QString& password);
    QString getRole() const override;
};

#endif
