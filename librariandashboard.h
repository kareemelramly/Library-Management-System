#ifndef LIBRARIANDASHBOARD_H
#define LIBRARIANDASHBOARD_H

#include <QWidget>

namespace Ui {
class LibrarianDashboard;
}

class LibrarianDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit LibrarianDashboard(QWidget *parent = nullptr);
    ~LibrarianDashboard();



private slots:
    void on_pushButtonLogOut_clicked();

private:
    Ui::LibrarianDashboard *ui;
};

#endif // LIBRARIANDASHBOARD_H
