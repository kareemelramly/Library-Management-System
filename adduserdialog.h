#ifndef ADDUSERDIALOG_H
#define ADDUSERDIALOG_H

#include <QDialog>

namespace Ui {
class AddUserDialog;
}

class AddUserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddUserDialog(QWidget *parent = nullptr);
    ~AddUserDialog();

private slots:
    void on_comboBox_currentIndexChanged(int index);


    void on_pushButtonCancel_clicked();

private:
    Ui::AddUserDialog *ui;
};

#endif // ADDUSERDIALOG_H
