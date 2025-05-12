#include "librarian_interface_page.h"
#include "ui_librarian_interface_page.h"

librarian_interface_page::librarian_interface_page(QString name,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,bool darkmode, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::librarian_interface_page),users(usersIn),books(booksIn)
{
    this->darkMode = darkmode;
    ui->setupUi(this);
    ui->welcome->setText("Welcome "+name);
    user = dynamic_cast<Librarian*>(users[name]);
    if (!darkMode) {
        // Light mode
        qApp->setStyleSheet(""); // Reset to default
    } else {
        // Dark mode stylesheet
        QString darkStyle = R"(
            QWidget {
                background-color: #121212;
                color:white;
            }
            QLabel{
                color:white;
            }
            QPushButton {
                background-color: #2c2c2c;
                border: 1px solid #444;
                padding: 5px;
            }
            QPushButton:hover {
                background-color: #3d3d3d;
            }
            QTableWidget{
                color:white;
            }
            QRadioButton{
                color:white;
            }
        )";
        qApp->setStyleSheet(darkStyle);
    }
    this->setAttribute(Qt::WA_DeleteOnClose);
}

librarian_interface_page::~librarian_interface_page()
{
    delete ui;
}

void librarian_interface_page::on_book_records_button_clicked()
{
    booksPage = new book_records(user,users,books,this);
    this->hide();
    booksPage->show();
}


void librarian_interface_page::on_generate_report_button_clicked()
{
    reportPage= new report_paper(user->getUsername(),users,books,darkMode);
    this->hide();
    reportPage->show();
}

