#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "library_system.h"
MainWindow::MainWindow(library_system* system, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , librarySystem(system)
{
    ui->setupUi(this);
    admindashbord = nullptr;
    librarianPage=nullptr;
    userPage=nullptr;
    librarySystem->Users();
    librarySystem->Books();

}

void MainWindow::openAdminDashbord()
{
    qDebug() << "Open admin page called";
    if (!admindashbord)
        admindashbord = new Admin_Dashbord(librarySystem, this);
    admindashbord->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (admindashbord)
        delete admindashbord;
    librarySystem->saveUsers();
}

bool MainWindow::validateCredentials(const QString& username, const QString& password)
{

    if (librarySystem->Users().contains(username)) {
        library_member* member = librarySystem->Users()[username];
        bool valid = (member->getPassword() == password);
        return valid;
    }
    return false;
}

void MainWindow::on_loginButton_clicked()
{
    
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Username and password cannot be empty.");
        return;
    }


    if (librarySystem->Users().contains(username) && librarySystem->Users()[username]->getPassword() == password) {
        QString role = librarySystem->Users()[username]->getRole();


        if (role == "admin") {
            QMessageBox::information(this, "Login", "Admin login successful!");
            if (!admindashbord) {
                admindashbord = new Admin_Dashbord(librarySystem, this);
            }
            this -> hide();
            admindashbord->show();
        } else if (role == "librarian") {
            QMessageBox::information(this, "Login", "Librarian login successful!");
            if (!librarianPage) {
                librarianPage = new librarian_interface_page(username, this);
            }
            this -> hide();
            librarianPage->show();
        } else if (role == "member") {
            QMessageBox::information(this, "Login", "Member login successful!");
            if (!userPage) {
                qDebug()<<"start\n";
                userPage = new User_Interface_Page(username,librarySystem, this);
            }
            this -> hide();
            userPage->show();
        } else {
            QMessageBox::warning(this, "Login Warning", "Unknown user role: " + role);
        }
    } else {
        QMessageBox::critical(this, "Login Error", "Invalid username or password.");
    }
}
