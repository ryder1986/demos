#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setCentralWidget(ui->groupBox);

}

MainWindow::~MainWindow()
{
    delete ui;
}
#include <QDebug>
void MainWindow::on_pushButton_2_clicked()
{
    QString str= ui->lineEdit_3->text();
    QStringList sl(str.split(','));
    foreach (QString s, sl) {
        if(!s.contains('['))
        {
            NumNode_t t;
            t.value=s.toInt();
            t.type=1;
            t.times=1;
            qDebug()<<t.value;
            list.append(t);
            //   list.append(s);
        }
        else{
            NumNode_t t;
            QString s1=s;
             t.type=2;
            // s.section('[',1);
            //   qDebug()<<s;
            QRegularExpression sep("\\[+");
            //  QRegularExpression sep1("\[,$");
            QRegExp sp("\\[[0-9]*");
           // qDebug()<<s.section(sep,1).remove(']');
          //  qDebug()<<s.remove(sp).remove(']');
            t.value=s.remove(sp).remove(']').toInt();
            t.times=s1.section(sep,1).remove(']').toInt();
            list.append(t);
        }

    }
    int i;
  //  QString str_tmp= ui->lineEdit_4->text();
   // str_tmp.append("sssssssssssss");
 //   ui->textEdit->setText("123");
    QString txt=ui->textEdit->toPlainText();
    int offset=0;
    foreach (NumNode_t tmp, list) {
        if(tmp.type==1){
          //  txt.insert(tmp.value*3,"\n");
            txt.replace(offset+tmp.value*3-1,1,"\n");
            offset+=tmp.value*3;
            }else{
            for(i=0;i<tmp.times;i++){
                 txt.replace(offset+tmp.value*3-1,1,"\n");
                   offset+=tmp.value*3;
            }

        }
    }
    ui->textEdit->setText(txt);

 //ui->lineEdit_4->setText(str_tmp);

}
