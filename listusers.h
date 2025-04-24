#ifndef LISTUSERS_H
#define LISTUSERS_H

#include <QWidget>

namespace Ui {
class ListUsers;
}

class ListUsers : public QWidget
{
    Q_OBJECT

public:
    explicit ListUsers(QWidget *parent = nullptr);
    ~ListUsers();

private:
    Ui::ListUsers *ui;
};

#endif // LISTUSERS_H
