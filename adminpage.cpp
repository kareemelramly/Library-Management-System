#include "adminpage.h"
#include "member.h"
#include "ui_signupform.h" // Still using the original UI file until you regenerate it
#include "utils.h"
#include "admin.h"
#include "librarian.h"
#include <QMessageBox>
#include <QRegularExpression>
#include <QMap>
#include <QFile>

#include "ui_adminpage.h"  // this should be correct now

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)  // <- make sure it's AdminPage, not signupForm
{
    ui->setupUi(this);
     // Set password echo mode for security
        ui->passwordEdit->setEchoMode(QLineEdit::Password);

    // Make sure the combo box has the right items
    ui->roleComboBox->clear();
    ui->roleComboBox->addItem("member");
    ui->roleComboBox->addItem("librarian");

    // Change the window title to reflect the new purpose
    setWindowTitle("Admin Page - User Management");
}


AdminPage::~AdminPage()
{
    delete ui;
}


void AdminPage::on_signupButton_clicked()
{
    QString username = ui->usernameEdit->text();
    QString password = ui->passwordEdit->text();
    QString role = ui->roleComboBox->currentText();

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
    } else {
        QMessageBox::critical(this, "File Error", "Could not open file for writing.");
    }
}
