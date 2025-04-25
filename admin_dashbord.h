#ifndef ADMIN_DASHBORD_H
#define ADMIN_DASHBORD_H

#include <QDialog>

namespace Ui {
class Admin_Dashbord;
}

class Admin_Dashbord : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Dashbord(QWidget *parent = nullptr);
    ~Admin_Dashbord();

private:
    Ui::Admin_Dashbord *ui;
};

#endif // ADMIN_DASHBORD_H
