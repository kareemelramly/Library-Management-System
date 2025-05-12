#ifndef ADMIN_DASHBORD_H
#define ADMIN_DASHBORD_H
#include<book.h>
#include <QDialog>
#include <QComboBox>
#include<QList>
#include "library_member.h"
namespace Ui {
class Admin_Dashbord;
}

class Admin_Dashbord : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Dashbord(QWidget *parent,const QMap<QString, library_member*>& usersInput);
    void refreshUserList();
    ~Admin_Dashbord();

private slots:
    void on_signupButton_clicked();

    void on_delete_user_button_clicked();

private:
    Ui::Admin_Dashbord *ui;
    QComboBox* roleComboBox;
    QMap<QString, library_member*> users;
    //QList<book*>books;
};

#endif // ADMIN_DASHBORD_H


