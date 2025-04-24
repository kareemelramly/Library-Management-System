#include "loginpage.h"
#include "ui_loginpage.h"
#include "adminpage.h"
#include "librariandashboard.h"
#include "memberdashboard.h"
LoginPage::LoginPage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    ui->PushButtonLogin->setEnabled(false);
    connect(ui->lineEditUserName, &QLineEdit::textChanged, this, &LoginPage::updatePushButtonLoginState);
    connect(ui->lineEditPassword, &QLineEdit::textChanged, this, &LoginPage::updatePushButtonLoginState);
}

LoginPage::~LoginPage()
{
    delete ui;
}
void LoginPage::updatePushButtonLoginState() {
    bool enable = !ui->lineEditUserName->text().isEmpty() && !ui->lineEditPassword->text().isEmpty();
    ui->PushButtonLogin->setEnabled(enable);
}
void LoginPage::on_PushButtonLogin_clicked()
{

    if (ui->lineEditPassword->text() == "111"){
        AdminPage *adminpage = new AdminPage();
        this->hide();
        adminpage->show();
    }
    else if (ui->lineEditPassword->text() == "222"){

    LibrarianDashboard * librarianDashboard = new LibrarianDashboard();
        this->hide();
    librarianDashboard->show();
    }
    else if (ui->lineEditPassword->text() == "333")
    {
        MemberDashboard * memberdashboard = new MemberDashboard();
        this->hide();
        memberdashboard->show();
    }

    // just to test that windows work propably after login
}



void LoginPage::on_PushButtonCancel_clicked()
{
    ui->lineEditUserName->clear();
    ui->lineEditPassword->clear();

}



void LoginPage::on_lineEditUserName_textChanged(const QString &arg1)
{

}


void LoginPage::on_lineEditPassword_textChanged(const QString &arg1)
{

}

