#ifndef ADMIN_DASHBORD_H
#define ADMIN_DASHBORD_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class Admin_Dashbord;
}

class Admin_Dashbord : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Dashbord(QWidget *parent = nullptr);
    void refreshUserList();
    ~Admin_Dashbord();

private slots:
    void on_signupButton_clicked();

    void on_delete_user_button_clicked();

private:
    Ui::Admin_Dashbord *ui;
    QComboBox* roleComboBox;
};

#endif // ADMIN_DASHBORD_H


