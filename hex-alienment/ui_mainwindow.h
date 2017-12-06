/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_hex;
    QGroupBox *groupBox;
    QPushButton *pushButton_regroup;
    QTextEdit *textEdit_format;
    QPushButton *pushButton_generate;
    QComboBox *comboBox;
    QLabel *label;
    QCheckBox *checkBox_tru;
    QCheckBox *checkBox_highlight;
    QPushButton *pushButton_recover;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(750, 531);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 60, 551, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEdit_hex = new QTextEdit(gridLayoutWidget);
        textEdit_hex->setObjectName(QStringLiteral("textEdit_hex"));

        gridLayout->addWidget(textEdit_hex, 0, 1, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        pushButton_regroup = new QPushButton(groupBox);
        pushButton_regroup->setObjectName(QStringLiteral("pushButton_regroup"));
        pushButton_regroup->setGeometry(QRect(10, 280, 101, 22));
        textEdit_format = new QTextEdit(groupBox);
        textEdit_format->setObjectName(QStringLiteral("textEdit_format"));
        textEdit_format->setGeometry(QRect(10, 80, 231, 171));
        pushButton_generate = new QPushButton(groupBox);
        pushButton_generate->setObjectName(QStringLiteral("pushButton_generate"));
        pushButton_generate->setGeometry(QRect(110, 280, 91, 22));
        comboBox = new QComboBox(groupBox);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 30, 79, 22));
        comboBox->setEditable(true);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 71, 31));
        checkBox_tru = new QCheckBox(groupBox);
        checkBox_tru->setObjectName(QStringLiteral("checkBox_tru"));
        checkBox_tru->setGeometry(QRect(10, 310, 71, 16));
        checkBox_highlight = new QCheckBox(groupBox);
        checkBox_highlight->setObjectName(QStringLiteral("checkBox_highlight"));
        checkBox_highlight->setGeometry(QRect(120, 310, 71, 16));
        pushButton_recover = new QPushButton(groupBox);
        pushButton_recover->setObjectName(QStringLiteral("pushButton_recover"));
        pushButton_recover->setGeometry(QRect(10, 340, 75, 23));

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        pushButton_regroup->setText(QApplication::translate("MainWindow", "regroup ", 0));
        pushButton_generate->setText(QApplication::translate("MainWindow", "generate ", 0));
        comboBox->setCurrentText(QString());
        label->setText(QApplication::translate("MainWindow", "loops", 0));
        checkBox_tru->setText(QApplication::translate("MainWindow", "trucate", 0));
        checkBox_highlight->setText(QApplication::translate("MainWindow", "highlight", 0));
        pushButton_recover->setText(QApplication::translate("MainWindow", "recover", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
