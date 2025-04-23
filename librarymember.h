#ifndef LIBRARYMEMBER_H
#define LIBRARYMEMBER_H

#include <QString>

class LibraryMember {
public:
    LibraryMember(const QString& username, const QString& password);
    virtual ~LibraryMember() {}

    virtual QString getRole() const = 0;
    QString getUsername() const;
    QString getPassword() const;

protected:
    QString username;
    QString password;
};

#endif
