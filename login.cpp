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
    Utils::createDefaultAdmin("users.csv");
}

void MainWindow::openAdminDashbord()
{
    qDebug() << "Open admin page called";
    if (!admindashbord)
        admindashbord = new Admin_Dashbord(this);
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
    // Use Utils to load users from file
    QMap<QString, library_member*> users = Utils::loadUsersFromFile("users.csv");
    // Check if user exists and password matches
    if (users.contains(username)) {
        library_member* member = users[username];
        bool valid = (member->getPassword() == password);
        // Clean up memory
        qDeleteAll(users.values());
        return valid;
    }
    // Clean up memory
    qDeleteAll(users.values());
    return false;
}

void MainWindow::on_loginButton_clicked()
{
    QLineEdit* usernameEdit = findChild<QLineEdit*>("usernameEdit");
    QLineEdit* passwordEdit = findChild<QLineEdit*>("passwordEdit");
    if (!usernameEdit || !passwordEdit) {
        QMessageBox::critical(this, "Error", "UI elements not found");
        return;
    }
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();

    // Check if fields are empty
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Error", "Username and password cannot be empty.");
        return;
    }

    // Load all users
    QMap<QString, library_member*> users = Utils::loadUsersFromFile("users.csv");

    // Check if user exists and password matches
    if (users.contains(username) && users[username]->getPassword() == password) {
        // Check the role of the user
        QString role = users[username]->getRole();

        // Clean up memory before proceeding
        qDeleteAll(users.values());
        users.clear();

        // Handle user based on role
        if (role == "admin") {
            QMessageBox::information(this, "Login", "Admin login successful!");
            if (!admindashbord) {
                admindashbord = new Admin_Dashbord(this);
            }
            admindashbord->show();
        } else if (role == "librarian") {
            QMessageBox::information(this, "Login", "Librarian login successful!");
            // Here you would show librarian interface
            // For now, we'll show the admin dashboard as a placeholder
            if (!admindashbord) {
                admindashbord = new Admin_Dashbord(this);
            }
            admindashbord->show();
        } else if (role == "member") {
            QMessageBox::information(this, "Login", "Member login successful!");
            // Here you would show member interface
            // This would be implemented separately
        } else {
            QMessageBox::warning(this, "Login Warning", "Unknown user role: " + role);
        }
    } else {
        // Clean up memory
        qDeleteAll(users.values());
        users.clear();
        QMessageBox::critical(this, "Login Error", "Invalid username or password.");
    }
}
