#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginPage;
}
QT_END_NAMESPACE

class LoginPage : public QMainWindow
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    void on_pushButtonLogin_clicked();

    void on_PushButtonCancel_clicked();

    void on_PushButtonLogin_clicked();

    void updatePushButtonLoginState();

    void on_lineEditUserName_textChanged(const QString &arg1);

    void on_lineEditPassword_textChanged(const QString &arg1);

private:
    Ui::LoginPage *ui;
};
#endif // LOGINPAGE_H
