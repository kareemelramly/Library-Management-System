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

private:
    Ui::LibrarianDashboard *ui;
};

#endif // LIBRARIANDASHBOARD_H
