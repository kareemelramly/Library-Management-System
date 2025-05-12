#include "add_edit_book.h"
#include "ui_add_edit_book.h"
#include<QMessageBox>
#include "book_records.h"
#include "utils.h"
add_edit_book::add_edit_book(QDialog* mainPage, Librarian* userIn,const QMap<QString, library_member*>& usersIn,const QList<book*>& booksIn,bool add,QString ID, QString title, QString author, QString Category,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_edit_book),users(usersIn),books(booksIn),user(userIn),addingCondition(add),mainP(mainPage)
{
    ui->setupUi(this);
    ui->ID_label->setText(ID);
    ui->title_line_edit->setText(title);
    ui->author_line_edit->setText(author);
    ui->category_line_edit->setText(Category);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

add_edit_book::~add_edit_book()
{
    Utils::saveBookstoFile("books.csv",books);
    book_records* mainPage= dynamic_cast<book_records*>(mainP);
    mainPage->books = books;
    mainPage->refreshBooksList();
    mainPage->refreshComboBox();
    mainPage=nullptr;
    mainP=nullptr;
    qDebug()<<"hello";
}
void add_edit_book::on_pushButton_clicked()
{
    QString ID = ui->ID_label->text();
    QString Title = ui->title_line_edit->text();
    QString Author = ui->author_line_edit->text();
    QString Category = ui->category_line_edit->text();
    bool isNumber;
    int number = ID.toInt(&isNumber);
    if(!isNumber){
        QMessageBox::warning(this, "warning","invalid ID");
        return ;
    }
    if(ID=="" || Title=="" || Author=="" || Category==""){
         QMessageBox::warning(this, "Some field not filled", "Please fill it");
        return ;
    }
    bool conditionTitleFound=false;
    for(auto item: books){
        if(item->Title==Title){
            conditionTitleFound=true;
        }
        if(item->ID==ID){
            if(!addingCondition){
                item->Title=Title;
                item->author=Author;
                item->Category=Category;
                 QMessageBox::information(this,"editing a book","editing is done");
                this->hide();
                delete this;
                return ;
            }
            if(item->Title==Title && item->author==Author && item->Category==Category){
                item->totalCopies++;
                QMessageBox::information(this,"adding a book","adding is done");
                this->hide();
                delete this;
                return ;

            }else{
                QMessageBox::warning(this, "problem happened", "The book exists");
                return ;
            }
        }
    }
    if(!addingCondition){
        QMessageBox::information(this,"issue happened","ID can't change");
        return ;
    }
    if(conditionTitleFound){
        QMessageBox::information(this,"adding a book","title is there");
        return ;
    }
    books.push_back(new book(ID,Title,Author,Category,1,1));
    QMessageBox::information(this,"adding a book","adding is done");
    this->hide();
    delete this;
}


void add_edit_book::on_pushButton_2_clicked()
{
    if(addingCondition)
    ui->ID_label->setText("");
    ui->title_line_edit->setText("");
    ui->author_line_edit->setText("");
    ui->category_line_edit->setText("");
}

