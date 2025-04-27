#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "admin_dashbord.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    /*void on_actionSignup_triggered(); */// Rename this to something like on_actionAdminPage_triggered if you update your UI
    void openAdminDashbord();
    bool validateCredentials(const QString& username, const QString& password);
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    Admin_Dashbord *admindashbord;


};
#endif // LOGIN_H

