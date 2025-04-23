#include "adduserdialog.h"
#include "ui_adduserdialog.h"

AddUserDialog::AddUserDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddUserDialog)
{
    ui->setupUi(this);
    QVariant v(0);
    ui->comboBoxRole->setItemData(0, v, Qt::UserRole - 1);
}

AddUserDialog::~AddUserDialog()
{
    delete ui;
}

void AddUserDialog::on_comboBox_currentIndexChanged(int index)
{

}

