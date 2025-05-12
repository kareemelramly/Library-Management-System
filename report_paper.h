#ifndef REPORT_PAPER_H
#define REPORT_PAPER_H

#include <QDialog>
#include "library_member.h"
#include "book.h"
namespace Ui {
class report_paper;
}

class report_paper : public QDialog
{
    Q_OBJECT

public:
    explicit report_paper(QString name,const QMap<QString,library_member*>& users,const QList<book*>& books,bool darkmode,QWidget *parent = nullptr);
    ~report_paper();

private slots:
    void on_pushButton_clicked();

    void on_save_button_clicked();

private:
    void refreshBooksList();
    void refreshOverdueList();
    QString name;
    Ui::report_paper *ui;
    QMap<QString, library_member*> users;
    QList<book*>books;
    bool darkMode;
};

#endif // REPORT_PAPER_H
