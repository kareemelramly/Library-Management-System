#ifndef LIBRARIAN_INTERFACE_PAGE_H
#define LIBRARIAN_INTERFACE_PAGE_H

#include <QDialog>

namespace Ui {
class librarian_interface_page;
}

class librarian_interface_page : public QDialog
{
    Q_OBJECT

public:
    explicit librarian_interface_page(QString name, QWidget *parent = nullptr);
    ~librarian_interface_page();

private:
    Ui::librarian_interface_page *ui;
};

#endif // LIBRARIAN_INTERFACE_PAGE_H



