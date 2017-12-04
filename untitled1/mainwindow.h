#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    typedef struct NumNode{
        int type;
        int value;
        int times;
    }NumNode_t;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QList <NumNode_t> list;
};

#endif // MAINWINDOW_H
