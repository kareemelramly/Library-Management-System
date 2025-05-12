#include "admin_dashbord.h"
#include "ui_admin_dashbord.h"
#include "library_member.h" 
#include "utils.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QMap>
#include <QDebug>
#include "member.h"
#include "librarian.h"
Admin_Dashbord::Admin_Dashbord(QWidget *parent,const QMap<QString, library_member*>& usersInput)
    : QDialog(parent)
    , ui(new Ui::Admin_Dashbord),users(usersInput)
{
    ui->setupUi(this);
    ui->passwordEdit->setEchoMode(QLineEdit::Password);
    setWindowTitle("Admin Page - User Management");
    refreshUserList();
    this->setAttribute(Qt::WA_DeleteOnClose);
}

Admin_Dashbord::~Admin_Dashbord()
{
    Utils::saveUsersToFile("users.csv",users);
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

    if (username.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Username cannot be empty.");
        return;
    }

    if (password.length() < 8 || !password.contains(QRegularExpression("\\d"))) {
        QMessageBox::warning(this, "Invalid Input", "Password must be at least 8 characters long and include a number.");
        return;
    }

    if (users.contains(username)) {
        QMessageBox::warning(this, "Username Taken", "This username is already in use. Please choose another.");
        return;
    }
    if(role=="member"){
        QMap<int,QString>books;
        users[username] = new member(username,password,books,0);
    }else if(role=="librarian"){
        users[username]= new Librarian(username,password);
    }
    refreshUserList();
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
    for (auto it = users.begin(); it != users.end(); ++it) {
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
        if(users.contains(name)){
            auto it = users.find(name);
            users.erase(it);
        }
    }
    refreshUserList();
}

