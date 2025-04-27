#ifndef MEMBER_H
#define MEMBER_H

#include "library_member.h"

class member : public library_member {
public:
    member(const QString& username, const QString& password);
    QString getRole() const override;
};

#endif // MEMBER_H
