#ifndef MEMBERDASHBOARD_H
#define MEMBERDASHBOARD_H

#include <QWidget>

namespace Ui {
class MemberDashboard;
}

class MemberDashboard : public QWidget
{
    Q_OBJECT

public:
    explicit MemberDashboard(QWidget *parent = nullptr);
    ~MemberDashboard();
    void on_pushButtonLogOut_clicked();

private:
    Ui::MemberDashboard *ui;
};

#endif // MEMBERDASHBOARD_H
