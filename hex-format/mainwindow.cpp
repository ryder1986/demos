#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->centralWidget->setLayout(ui->gridLayout_2);
    ui->groupBox->setFixedWidth(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}
