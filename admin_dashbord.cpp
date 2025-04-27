#include "admin_dashbord.h"
#include "ui_admin_dashbord.h"
#include "library_member.h"  // Ensure you have the correct path for the library_member class
#include "utils.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QMap>
#include <QDebug>

Admin_Dashbord::Admin_Dashbord(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin_Dashbord)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);

    // Change the window title to reflect the new purpose
    setWindowTitle("Admin Page - User Management");
}

Admin_Dashbord::~Admin_Dashbord()
{
    delete ui;
}

void Admin_Dashbord::on_signupButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();

    QString role;
    if (ui->librarianRadioButton->isChecked()) {
        role = "librarian";
    } else if (ui->memberRadioButton->isChecked()) {
        role = "member";
    } else {
        QMessageBox::warning(this, "Role Not Selected", "Please select a role (librarian or member).");
        return;
    }

    // Validate input
    if (username.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Username cannot be empty.");
        return;
    }

    if (password.length() < 8 || !password.contains(QRegularExpression("\\d"))) {
        QMessageBox::warning(this, "Invalid Input", "Password must be at least 8 characters long and include a number.");
        return;
    }

    if (!Utils::isUsernameAvailable("users.csv", username)) {
        QMessageBox::warning(this, "Username Taken", "This username is already in use. Please choose another.");
        return;
    }

    // Append new user to file
    QFile file("users.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << "," << password << "," << role << "\n";
        file.close();

        QMessageBox::information(this, "User Registration", "User registered successfully.");

        // Clear input fields
        ui->usernameEdit->clear();
        ui->passwordEdit->clear();

        // Refresh the user list to reflect the new user
        refreshUserList();
    } else {
        QMessageBox::critical(this, "File Error", "Could not open file for writing.");
    }
}

void Admin_Dashbord::refreshUserList()
{
    // Find the QTableWidget named "usersTable" in the UI
    QTableWidget* usersTable = findChild<QTableWidget*>("usersTable");
    if (!usersTable) {
        qDebug() << "User table widget not found in UI";
        return;
    }

    // Clear existing rows
    usersTable->setRowCount(0);

    // Set up columns if not already done
    if (usersTable->columnCount() < 2) {
        usersTable->setColumnCount(2);
        QStringList headers;
        headers << "Username" << "Role";
        usersTable->setHorizontalHeaderLabels(headers);
    }

    // Load all users from the file
    QMap<QString, library_member*> users = Utils::loadUsersFromFile("users.csv");

    // Debug output to check loaded users
    qDebug() << "Loaded users:" << users.keys();

    // Add each user to the table
    int row = 0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        QString username = it.key();
        QString role = it.value()->getRole();

        // Debug output for each user added
        qDebug() << "Adding user:" << username << "with role:" << role;

        usersTable->insertRow(row);
        usersTable->setItem(row, 0, new QTableWidgetItem(username));
        usersTable->setItem(row, 1, new QTableWidgetItem(role));

        // Color code by role
        QColor rowColor;
        if (role == "admin") {
            rowColor = QColor(255, 230, 230); // Light red
        } else if (role == "librarian") {
            rowColor = QColor(230, 230, 255); // Light blue
        }

        // Apply color to the row if valid
        if (rowColor.isValid()) {
            for (int col = 0; col < usersTable->columnCount(); col++) {
                usersTable->item(row, col)->setBackground(rowColor);
            }
        }

        row++;
    }

    // Resize columns to fit the content
    usersTable->resizeColumnsToContents();

    // Clean up memory used by user data
    qDeleteAll(users.values());
    users.clear();
}
