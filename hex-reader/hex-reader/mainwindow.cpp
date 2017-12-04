#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstring>
#include <cstdio>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setLayout(ui->gridLayout);
    ui->comboBox->setItemData(3,3);
    char buf[10];
    memset(buf,0,10);
    for(int i=0;i<10;i++)
      {
        sprintf(buf,"%d",i);
        ui->comboBox->insertItem(i, QString::fromLatin1(buf));
         memset(buf,0,10);
    }
    ui->comboBox->setCurrentIndex(1);
    loops=1;
      ui->groupBox->setFixedWidth(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

typedef struct format{
    int value;
    int times;
}format_t;

void MainWindow::on_pushButton_regroup_clicked()
{
    QString str_format=ui->textEdit_format->toPlainText();
    QString str_text=ui->textEdit_hex->toPlainText();
    QRegExp ex("\ +");
    QRegExp ex1("\n");
    str_text.replace(ex," ");
    str_text.replace(ex1," ");
    ui->textEdit_hex->setText(str_text);
    //    QList<format_t> list;

    //    QStringList sl(str_format.split(','));
    //    foreach (QString s, sl) {
    //        if(!s.contains('['))
    //        {
    //            format_t t;
    //            t.value=s.toInt();
    //            t.times=1;
    //       //     qDebug()<<t.value;
    //            list.append(t);
    //            //   list.append(s);
    //        }
    //        else{
    //            format_t t;
    //            QString s1=s;
    //          //  t.type=2;
    //            // s.section('[',1);
    //            //   qDebug()<<s;
    //            QRegularExpression sep("\\[+");
    //            //  QRegularExpression sep1("\[,$");
    //            QRegExp sp("\\[[0-9]*");
    //            // qDebug()<<s.section(sep,1).remove(']');
    //            //  qDebug()<<s.remove(sp).remove(']');
    //            t.value=s.remove(sp).remove(']').toInt();
    //            t.times=s1.section(sep,1).remove(']').toInt();
    //            list.append(t);
    //        }

    //    }



    //    int offset=0;
    //    int i;
    //    foreach (format_t tmp, list) {
    //        if(tmp.times==1){
    //            //  txt.insert(tmp.value*3,"\n");
    //            str_text.replace(offset+tmp.value*3-1,1,"\n");
    //            offset+=tmp.value*3;
    //        }else{
    //            for(i=0;i<tmp.times;i++){
    //                str_text.replace(offset+tmp.value*3-1,1,"\n");
    //                offset+=tmp.value*3;
    //            }

    //        }
    //    }

}

void MainWindow::on_pushButton_generate_clicked()
{
    QString str_format=ui->textEdit_format->toPlainText();

    QString str_text=ui->textEdit_hex->toPlainText();
    bkup_str=str_text;
    QRegExp ex("\ +");
    QRegExp ex1("\n");
    str_text.replace(ex," ");
    str_text.replace(ex1," ");
    ui->textEdit_hex->setText(str_text);
    QList<format_t> list;

    QStringList sl(str_format.split(','));
    foreach (QString s, sl) {
        if(!s.contains('['))
        {
            format_t t;
            t.value=s.toInt();
            t.times=1;
            //     qDebug()<<t.value;
            list.append(t);
            //   list.append(s);
        }
        else{
            format_t t;
            QString s1=s;
            //  t.type=2;
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



    int offset=0;
    int i;
    int loop;
    for(loop=0;loop<loops;loop++)
    foreach (format_t tmp, list) {
        if(tmp.times==1){
            //  txt.insert(tmp.value*3,"\n");
            str_text.replace(offset+tmp.value*3-1,1,"\n");
            offset+=tmp.value*3;
        }else{
            for(i=0;i<tmp.times;i++){
                str_text.replace(offset+tmp.value*3-1,1,"\n");
                offset+=tmp.value*3;
            }

        }
    }
    qDebug()<<"offset"<<offset;
    if(ui->checkBox_tru->isChecked())
        str_text.truncate(offset);
    ui->textEdit_hex->setText(str_text);

    //ui->textEdit_hex->setFixedWidth(30);
}

void MainWindow::on_comboBox_activated(int index)
{
    loops=index;
    qDebug()<<"index"<<index;
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
  // qDebug()<<arg1;

}

void MainWindow::on_pushButton_recover_clicked()
{
    ui->textEdit_hex->setText(bkup_str);
}
