#ifndef LIBRARY_MEMBER_H
#define LIBRARY_MEMBER_H

#include <QString>

class library_member
{
public:
    library_member(const QString& username, const QString& password);
    virtual ~library_member() {}

    virtual QString getRole() const =0;
    QString getUsername() const;
    QString getPassword() const;
protected:
    QString username;
    QString password;
};

#endif // LIBRARY_MEMBER_H

