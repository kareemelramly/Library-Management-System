// #ifndef ADMINPAGE_H
// #define ADMINPAGE_H

// #include <QDialog>
// #include <QComboBox>

// namespace Ui {
// class adminpage; // lowercase to match UI file
// }

// class AdminPage : public QDialog
// {
//     Q_OBJECT

// public:
//     explicit AdminPage(QWidget *parent = nullptr);
//     ~AdminPage();

// private slots:
//     void on_signupButton_clicked();

// private:
//     Ui::adminpage *ui; // lowercase to match UI file
//     QComboBox* roleComboBox;
// };

// #endif // ADMINPAGE_H
#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>
#include <QComboBox>

// Forward declaration
namespace Ui {
class AdminPage; // Note: still using signupForm as the UI class name until you regenerate the UI
}

class AdminPage : public QDialog
{
    Q_OBJECT

public:
    explicit AdminPage(QWidget *parent = nullptr);
    ~AdminPage();

private slots:
    void on_signupButton_clicked();

private:
    Ui::AdminPage *ui;
    QComboBox* roleComboBox;
};

#endif
