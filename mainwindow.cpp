#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

QLabel *backgroundLabel;  // Add this as a member variable in mainwindow.h

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    backgroundLabel = new QLabel(this);
    backgroundLabel->setScaledContents(true); // Make image scale
    backgroundLabel->setPixmap(QPixmap(":/Images/ylswjsy7stw-2048x1201.jpg"));
    backgroundLabel->lower();  // Keep it behind other widgets
    backgroundLabel->resize(this->size()); // Initial size

}

MainWindow::~MainWindow()
{
    delete ui;
}

