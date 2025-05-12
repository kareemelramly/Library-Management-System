#include "report_paper.h"
#include "ui_report_paper.h"
#include "librarian_interface_page.h"
#include "utils.h"
#include<QMessageBox>
#include<QFile>
#include "member.h"
report_paper::report_paper(QString name,const QMap<QString,library_member*>& usersIn,const QList<book*>& booksIn,bool darkmode,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::report_paper),users(usersIn),books(booksIn),darkMode(darkmode)
{
    ui->setupUi(this);
    refreshBooksList();
    refreshOverdueList();
    this->name=name;
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
                color:white;
            }
        )";
        qApp->setStyleSheet(darkStyle);
    }
    this->setAttribute(Qt::WA_DeleteOnClose);
}

report_paper::~report_paper()
{
    delete ui;
}

void report_paper::refreshBooksList(){
    std::sort(books.begin(), books.end(), [](book* a, book* b) {
        return a->timesBorrowed > b->timesBorrowed;
    });
    ui->borrowed_books->setRowCount(0);

    if (ui->borrowed_books->columnCount() < 2) {
        ui->borrowed_books->setColumnCount(2);
        QStringList headers;
        headers << "Name"<<"Times being borrowed";
        ui->borrowed_books->setHorizontalHeaderLabels(headers);
    }

    int row = 0;
    for (auto it = books.begin(); it != books.end(); ++it) {
        QString title = (*it)->Title;
        QString borrowing = QString::number((*it)->timesBorrowed);
        ui->borrowed_books->insertRow(row);
        ui->borrowed_books->setItem(row, 0, new QTableWidgetItem(title));
        ui->borrowed_books->setItem(row, 1, new QTableWidgetItem(borrowing));
        row++;
    }
    ui->borrowed_books->resizeColumnsToContents();
}
void report_paper::refreshOverdueList(){
    ui->overdue_books->setRowCount(0);
    if (ui->overdue_books->columnCount() < 2) {
        ui->overdue_books->setColumnCount(2);
        QStringList headers;
        headers<<"book Title"<<"user";
        ui->overdue_books->setHorizontalHeaderLabels(headers);
    }
    int row = 0;
    for(auto user: users){
        member* currUser = dynamic_cast<member*>(user);
            if(currUser){
            QString CurrentDate = QDate::currentDate().toString("yyyy-MM-dd");
            auto item = currUser->borrowed_books.begin();
            for(item=currUser->borrowed_books.begin();item!=currUser->borrowed_books.end();item++){
                if(item.value()<=CurrentDate){
                    for(auto book: books){
                        if(book->ID.toInt()==item.key()){
                            ui->overdue_books->insertRow(row);
                            qDebug()<<book->Title<<' '<<currUser->getUsername()<<"\n";
                            ui->overdue_books->setItem(row,0,new QTableWidgetItem(book->Title));
                            ui->overdue_books->setItem(row,1,new QTableWidgetItem(currUser->getUsername()));
                            row++;
                        }
                    }
                }
            }
            }
    }
    ui->overdue_books->resizeColumnsToContents();
}

void report_paper::on_pushButton_clicked()
{
    librarian_interface_page* newPage = new librarian_interface_page(name,users,books,darkMode,this);
    newPage->show();
    newPage = nullptr;
    this->hide();
}


void report_paper::on_save_button_clicked()
{
    QFile file("reports.csv");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    out << "Borrowed Books,number of times being borrowed:\n";
    for (int row = 0; row < ui->borrowed_books->rowCount(); ++row) {
        for (int col = 0; col < ui->borrowed_books->columnCount(); ++col) {
            QTableWidgetItem* item = ui->borrowed_books->item(row, col);
            out << (item ? item->text() : "") << (col < ui->borrowed_books->columnCount() - 1 ? "," : "");
        }
        out << "\n";
    }
    out<<"....................\n";
    out << "Overdue Books, the user who borrowed:\n";
    for (int row = 0; row < ui->overdue_books->rowCount(); ++row) {
        for (int col = 0; col < ui->overdue_books->columnCount(); ++col) {
            QTableWidgetItem* item = ui->overdue_books->item(row, col);
            out << (item ? item->text() : "") << (col < ui->overdue_books->columnCount() - 1 ? "," : "");
        }
        out << "\n";
    }
    QMessageBox::information(this,"notification","saving is done");
    file.close();
}

