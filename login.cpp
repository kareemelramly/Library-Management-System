#include "login.h"
#include "ui_login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Clear_push_button_clicked()
{
    ui->Password_login->clear();
    ui->Username_login->clear();
}


