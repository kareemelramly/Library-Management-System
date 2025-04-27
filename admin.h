#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include "library_member.h"

class admin : public library_member
{
public:
    admin(const QString& username, const QString& password);
    QString getRole() const override;
};

#endif // ADMIN_H
