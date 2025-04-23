// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include "adminpage.h"

// namespace Ui {
// class MainWindow;
// }

// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     explicit MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private slots:
//     void on_actionSignup_triggered(); // Replace with your actual slot name
//     void openAdminPage();
//     bool validateCredentials(const QString& username, const QString& password);
//     void on_loginButton_clicked();
// private:
//     Ui::MainWindow *ui;
//     AdminPage *adminpage;
// };

// #endif
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "adminpage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    /*void on_actionSignup_triggered(); */// Rename this to something like on_actionAdminPage_triggered if you update your UI
    void openAdminPage();
    bool validateCredentials(const QString& username, const QString& password);
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    AdminPage *adminPage;
};

#endif
