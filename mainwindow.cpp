#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "utils.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    adminPage = nullptr;

    Utils::createDefaultAdmin("users.csv");
}

void MainWindow::openAdminPage()
{
    qDebug() << "Open admin page called";
    if (!adminPage)
        adminPage = new AdminPage(this);
    adminPage->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    if (adminPage)
        delete adminPage;
}



bool MainWindow::validateCredentials(const QString& username, const QString& password)
{
    // Use Utils to load users from file
    QMap<QString, LibraryMember*> users = Utils::loadUsersFromFile("users.csv");

    // Check if user exists and password matches
    if (users.contains(username)) {
        LibraryMember* member = users[username];
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
    QMap<QString, LibraryMember*> users = Utils::loadUsersFromFile("users.csv");

    // Check if user exists and password matches
    if (users.contains(username) && users[username]->getPassword() == password) {
        // Check the role of the user
        QString role = users[username]->getRole();

        // Clean up memory
        qDeleteAll(users.values());

        // If the user is an admin, show the admin page
        if (role == "admin") {
            QMessageBox::information(this, "Login", "Admin login successful!");
            if (!adminPage) {
                adminPage = new AdminPage(this);
            }
            adminPage->show();
        } else {
            // Regular user login
            QMessageBox::information(this, "Login", "Login successful!");
            // Here you would handle user login differently
            // For example, show a different page or enable different functionality
        }
    } else {
        // Clean up memory
        qDeleteAll(users.values());
        QMessageBox::critical(this, "Login Error", "Invalid username or password.");
    }
}
