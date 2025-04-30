#ifndef MEMBER_INTERFACE_PAGE_H
#define MEMBER_INTERFACE_PAGE_H

#include <QDialog>

namespace Ui {
class User_Interface_Page;
}

class User_Interface_Page : public QDialog
{
    Q_OBJECT

public:
    explicit User_Interface_Page(QString name, QWidget *parent = nullptr);
    ~User_Interface_Page();

private:
    Ui::User_Interface_Page *ui;
};

#endif // MEMBER_INTERFACE_PAGE_H
