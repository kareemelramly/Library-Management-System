#ifndef BOOK_RECORDS_H
#define BOOK_RECORDS_H

#include <QDialog>

namespace Ui {
class book_records;
}

class book_records : public QDialog
{
    Q_OBJECT

public:
    explicit book_records(QWidget *parent = nullptr);
    ~book_records();

private:
    Ui::book_records *ui;
};

#endif // BOOK_RECORDS_H
