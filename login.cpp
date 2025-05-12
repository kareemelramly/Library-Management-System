#include "login.h"
#include "ui_login.h"
#include "utils.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    admindashbord = nullptr;
    librarianPage=nullptr;
    userPage=nullptr;
    Utils::createDefaultAdmin("users.csv");
    Utils::createDefaultBook("books.csv");
    books = Utils::loadBooksFromFile("books.csv");
    users = Utils::loadUsersFromFile("users.csv");
}

void MainWindow::openAdminDashbord()
{
    qDebug() << "Open admin page called";
    if (!admindashbord)
        admindashbord = new Admin_Dashbord(this,users);
    admindashbord->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (admindashbord)
        delete admindashbord;
}

bool MainWindow::validateCredentials(const QString& username, const QString& password)
{
    if (users.contains(username)) {
        library_member* member = users[username];
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

    if (users.contains(username) && users[username]->getPassword() == password) {
        QString role = users[username]->getRole();
        if (role == "admin") {
            QMessageBox::information(this, "Login", "Admin login successful!");
            if (!admindashbord) {
                admindashbord = new Admin_Dashbord(this,users);
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
                userPage = new User_Interface_Page(username,users,books,this);
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
