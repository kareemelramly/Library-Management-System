#include "book_records.h"
#include "ui_book_records.h"
#include<QStringListModel>
#include "add_edit_book.h"
#include<QMessageBox>
#include"utils.h"
#include "librarian_interface_page.h"
book_records::book_records(Librarian* userIn,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,bool darkmode,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::book_records),user(userIn),users(usersIn),books(booksIn)
{
    ui->setupUi(this);
    refreshBooksList();
    this->darkMode = darkmode;
    QStringList list;
    list<<"All"<<"Title"<<"Author"<<"Category";
    QStringListModel* model;
    model = new QStringListModel(this);
    model->setStringList(list);
    ui->functionality->setModel(model);
    refreshComboBox();
    if (!darkMode) {
        // Light mode
        qApp->setStyleSheet(""); // Reset to default
    } else {
        // Dark mode stylesheet
        QString darkStyle = R"(
            QWidget {
                background-color: #121212;
                color: #ffffff;
            }
            QPushButton {
                background-color: #2c2c2c;
                border: 1px solid #444;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: #3d3d3d;
            }
            QLabel{
                color:white;
            }
            QTableWidget{
                color:black;
            }
        )";
        qApp->setStyleSheet(darkStyle);
    }
    this->setAttribute(Qt::WA_DeleteOnClose);
}

book_records::~book_records()
{
    Utils::saveUsersToFile("users.csv",users);
    Utils::saveBookstoFile("books.csv",books);
    qDebug()<<"hello2";
    delete ui;
}

void book_records::refreshBooksList(){
    ui->booksList->setRowCount(0);

    if (ui->booksList->columnCount() < 2) {
        ui->booksList->setColumnCount(6);
        QStringList headers;
        headers << "ID" << "Title"<<"Author"<<"Category"<<"Number Of Compies"<<"Availability";
        ui->booksList->setHorizontalHeaderLabels(headers);
    }

    int row = 0;
    for (auto it = books.begin(); it != books.end(); ++it) {
        QString id = (*it)->ID;
        QString title = (*it)->Title;
        QString auth = (*it)->author;
        QString cat = (*it)->Category;
        QString numOfCopies = QString::number((*it)->totalCopies);
        QString availability = QString::number((*it)->availableCopies);
        ui->booksList->insertRow(row);
        ui->booksList->setItem(row, 0, new QTableWidgetItem(id));
        ui->booksList->setItem(row, 1, new QTableWidgetItem(title));
        ui->booksList->setItem(row, 2, new QTableWidgetItem(auth));
        ui->booksList->setItem(row, 3, new QTableWidgetItem(cat));
        ui->booksList->setItem(row, 4, new QTableWidgetItem(numOfCopies));
        ui->booksList->setItem(row, 5, new QTableWidgetItem(availability));
        QColor rowColor;
        if (availability.toInt() <= 3) {
            rowColor = QColor(255, 230, 230);
        } else{
            rowColor = QColor(230, 230, 255);
        }
        if (rowColor.isValid()) {
            for (int col = 0; col < ui->booksList->columnCount(); col++) {
                ui->booksList->item(row, col)->setBackground(rowColor);
            }
        }

        row++;
    }
    ui->booksList->resizeColumnsToContents();
}

void book_records::on_search_button_clicked()
{
    QString selection = ui->functionality->currentText();
    QString wanted_to_search = ui->searchName->text();
    if(selection=="All"){
        refreshBooksList();
    }else if(selection=="Title"){
        refreshBooksListByTitle(wanted_to_search);
    }else if(selection=="Author"){
        refreshBooksListByAuthor(wanted_to_search);
    }else if(selection=="Category"){
        refreshBooksListByCategory(wanted_to_search);
    }
}

void book_records::refreshBooksListByAuthor(QString name){
    ui->booksList->setRowCount(0);

    if (ui->booksList->columnCount() < 2) {
        ui->booksList->setColumnCount(6);
        QStringList headers;
        headers << "ID" << "Title"<<"Author"<<"Category"<<"Number Of Compies"<<"Availability";
        ui->booksList->setHorizontalHeaderLabels(headers);
    }

    int row = 0;
    for (auto it = books.begin(); it != books.end(); ++it) {
        QString id = (*it)->ID;
        QString title = (*it)->Title;
        QString auth = (*it)->author;
        QString cat = (*it)->Category;
        QString numOfCopies = QString::number((*it)->totalCopies);
        QString availability = QString::number((*it)->availableCopies);
        if(auth!=name){
            continue;
        }
        ui->booksList->insertRow(row);
        ui->booksList->setItem(row, 0, new QTableWidgetItem(id));
        ui->booksList->setItem(row, 1, new QTableWidgetItem(title));
        ui->booksList->setItem(row, 2, new QTableWidgetItem(auth));
        ui->booksList->setItem(row, 3, new QTableWidgetItem(cat));
        ui->booksList->setItem(row, 4, new QTableWidgetItem(numOfCopies));
        ui->booksList->setItem(row, 5, new QTableWidgetItem(availability));
        QColor rowColor;
        if (availability.toInt() <= 3) {
            rowColor = QColor(255, 230, 230);
        } else{
            rowColor = QColor(230, 230, 255);
        }

        if (rowColor.isValid()) {
            for (int col = 0; col < ui->booksList->columnCount(); col++) {
                ui->booksList->item(row, col)->setBackground(rowColor);
            }
        }

        row++;
    }
    ui->booksList->resizeColumnsToContents();
}

void book_records::refreshBooksListByTitle(QString name){
    ui->booksList->setRowCount(0);

    if (ui->booksList->columnCount() < 2) {
        ui->booksList->setColumnCount(6);
        QStringList headers;
        headers << "ID" << "Title"<<"Author"<<"Category"<<"Number Of Compies"<<"Availability";
        ui->booksList->setHorizontalHeaderLabels(headers);
    }

    int row = 0;
    for (auto it = books.begin(); it != books.end(); ++it) {
        QString id = (*it)->ID;
        QString title = (*it)->Title;
        QString auth = (*it)->author;
        QString cat = (*it)->Category;
        QString numOfCopies = QString::number((*it)->totalCopies);
        QString availability = QString::number((*it)->availableCopies);
        if(title!=name){
            continue;
        }
        ui->booksList->insertRow(row);
        ui->booksList->setItem(row, 0, new QTableWidgetItem(id));
        ui->booksList->setItem(row, 1, new QTableWidgetItem(title));
        ui->booksList->setItem(row, 2, new QTableWidgetItem(auth));
        ui->booksList->setItem(row, 3, new QTableWidgetItem(cat));
        ui->booksList->setItem(row, 4, new QTableWidgetItem(numOfCopies));
        ui->booksList->setItem(row, 5, new QTableWidgetItem(availability));
        QColor rowColor;
        if (availability.toInt() <= 3) {
            rowColor = QColor(255, 230, 230);
        } else{
            rowColor = QColor(230, 230, 255);
        }

        if (rowColor.isValid()) {
            for (int col = 0; col < ui->booksList->columnCount(); col++) {
                ui->booksList->item(row, col)->setBackground(rowColor);
            }
        }

        row++;
    }
    ui->booksList->resizeColumnsToContents();
}

void book_records::refreshBooksListByCategory(QString name){
    ui->booksList->setRowCount(0);

    if (ui->booksList->columnCount() < 2) {
        ui->booksList->setColumnCount(6);
        QStringList headers;
        headers << "ID" << "Title"<<"Author"<<"Category"<<"Number Of Compies"<<"Availability";
        ui->booksList->setHorizontalHeaderLabels(headers);
    }

    int row = 0;
    for (auto it = books.begin(); it != books.end(); ++it) {
        QString id = (*it)->ID;
        QString title = (*it)->Title;
        QString auth = (*it)->author;
        QString cat = (*it)->Category;
        QString numOfCopies = QString::number((*it)->totalCopies);
        QString availability = QString::number((*it)->availableCopies);
        if(cat!=name){
            continue;
        }
        ui->booksList->insertRow(row);
        ui->booksList->setItem(row, 0, new QTableWidgetItem(id));
        ui->booksList->setItem(row, 1, new QTableWidgetItem(title));
        ui->booksList->setItem(row, 2, new QTableWidgetItem(auth));
        ui->booksList->setItem(row, 3, new QTableWidgetItem(cat));
        ui->booksList->setItem(row, 4, new QTableWidgetItem(numOfCopies));
        ui->booksList->setItem(row, 5, new QTableWidgetItem(availability));
        QColor rowColor;
        if (availability.toInt() <= 3) {
            rowColor = QColor(255, 230, 230);
        } else{
            rowColor = QColor(230, 230, 255);
        }

        if (rowColor.isValid()) {
            for (int col = 0; col < ui->booksList->columnCount(); col++) {
                ui->booksList->item(row, col)->setBackground(rowColor);
            }
        }

        row++;
    }
    ui->booksList->resizeColumnsToContents();
}


void book_records::on_add_book_button_clicked()
{
    addBookPage = new add_edit_book(this,user,users,books,darkMode);
    addBookPage->show();
}
void book_records::refreshComboBox(){
    QStringList list;
    for(auto item: books){
            list<<item->Title;
    }
    QStringListModel* model;
    model = new QStringListModel(this);
    model->setStringList(list);
    ui->functionality_2->setModel(model);
}

void book_records::on_edit_book_button_clicked()
{
    QString selectedName = ui->functionality_2->currentText();
    book* currentBook;
    for(auto item: books){
        if(item->Title==selectedName){
            currentBook = item;
            break;
        }
    }
    QString ID = currentBook->ID;
    QString Title = currentBook->Title;
    QString Category = currentBook->Category;
    QString Author = currentBook->author;
    addBookPage = new add_edit_book(this,user,users,books,darkMode,false,ID,Title,Author,Category);
    addBookPage->show();
}


void book_records::on_delete_book_button_clicked()
{
    QString selectedName = ui->functionality_2->currentText();
    auto it = books.begin();
    for(it=books.begin();it!=books.end();it++){
        if((*it)->Title==selectedName){
            //qDebug()<<(*it)->Title<<"\n";
            //qDebug()<<(*it)->totalCopies<<","<<(*it)->availableCopies<<(*it)->timesBorrowed<<"\n";
            break;
        }
    }
    if((*it)->timesBorrowed>0){
        QMessageBox::warning(this, "note", "someone borrowed it");
        return;
    }
    books.erase(it);
    refreshBooksList();
    refreshComboBox();
     QMessageBox::information(this, "Deleting a book", "book is successfully deleted");
}


void book_records::on_backButton_clicked()
{
    librarian_interface_page* newPage = new librarian_interface_page(user->getUsername(),users,books,darkMode,this);
    this->hide();
    newPage->show();

}

