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
    explicit report_paper(const QMap<QString,library_member*>& users,const QList<book*>& books,bool darkmode,QWidget *parent = nullptr);
    ~report_paper();

private:
    void refreshBooksList();
    void refreshOverdueList();
    Ui::report_paper *ui;
    QMap<QString, library_member*> users;
    QList<book*>books;
    bool darkMode;
};

#endif // REPORT_PAPER_H
