#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    resizeEvent(QResizeEvent *event);

private:
    Ui::MainWindow *ui;
    QLabel *backgroundLabel;

};

#endif // MAINWINDOW_H
