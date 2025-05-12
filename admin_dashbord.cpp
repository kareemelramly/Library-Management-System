#include "admin_dashbord.h"
#include "build/Desktop_Qt_6_8_2_MinGW_64_bit-Debug/ui_admin_dashbord.h"
#include "ui_admin_dashbord.h"
#include "library_member.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QMap>
#include <QDebug>

Admin_Dashbord::Admin_Dashbord(library_system* system, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin_Dashbord)
    , librarySystem(system)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    setWindowTitle("Admin Page - User Management");
    refreshUserList();
}

Admin_Dashbord::~Admin_Dashbord()
{
    delete ui;
    librarySystem->saveUsers();
    librarySystem->saveBooks();
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

    QFile file("users.csv");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << "," << password << "," << role;
        if(role=="member"){
            out<<","<<0;
        }
        out<<"\n";
        file.close();

        QMessageBox::information(this, "User Registration", "User registered successfully.");

        ui->usernameEdit->clear();
        ui->passwordEdit->clear();

        refreshUserList();
    } else {
        QMessageBox::critical(this, "File Error", "Could not open file for writing.");
    }
}

void Admin_Dashbord::refreshUserList()
{
    ui->usersTable->setRowCount(0);
    
    if (ui->usersTable->columnCount() < 2) {
        ui->usersTable->setColumnCount(2);
        QStringList headers;
        headers << "Username" << "Role";
        ui->usersTable->setHorizontalHeaderLabels(headers);
    }


    int row = 0;
    for (auto it = librarySystem->Users().begin(); it != librarySystem->Users().end(); ++it) {
        QString username = it.key();
        QString role = it.value()->getRole();

        ui->usersTable->insertRow(row);
        ui->usersTable->setItem(row, 0, new QTableWidgetItem(username));
        ui->usersTable->setItem(row, 1, new QTableWidgetItem(role));
        QColor rowColor;
        if (role == "admin") {
            rowColor = QColor(255, 230, 230); 
        } else if (role == "librarian") {
            rowColor = QColor(230, 230, 255); 
        }

        if (rowColor.isValid()) {
            for (int col = 0; col < ui->usersTable->columnCount(); col++) {
                ui->usersTable->item(row, col)->setBackground(rowColor);
            }
        }

        row++;
    }
    ui->usersTable->resizeColumnsToContents();

}

void Admin_Dashbord::on_delete_user_button_clicked()
{
    auto items = ui->usersTable->selectedItems();
    for(auto item: items){
        QString name = item->text();
        if(librarySystem->Users().contains(name)){
            auto it = librarySystem->Users().find(name);
            librarySystem->Users().erase(it);
        }
    }
    librarySystem->saveUsers();
    refreshUserList();

}

