#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_pushButton_regroup_clicked();

    void on_pushButton_generate_clicked();

    void on_comboBox_activated(int index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
     int loops;
};

#endif // MAINWINDOW_H
