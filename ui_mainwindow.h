/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "lightbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    LightButton *widget;
    LightButton *widget_2;
    LightButton *widget_3;
    LightButton *widget_4;
    LightButton *widget_5;
    LightButton *widget_6;
    LightButton *widget_7;
    LightButton *widget_8;
    LightButton *widget_9;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btn_search;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_portName;
    QComboBox *comboBox_portName;
    QPushButton *btn_open;
    QLabel *label_txt_recv;
    QTextEdit *textEdit_send;
    QLabel *label_txt_send;
    QTextEdit *textEdit_recv;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_recvClear;
    QPushButton *btn_send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        widget = new LightButton(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 120, 80));
        widget_2 = new LightButton(groupBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(180, 30, 120, 80));
        widget_3 = new LightButton(groupBox);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(350, 60, 120, 80));
        widget_4 = new LightButton(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(500, 50, 120, 80));
        widget_5 = new LightButton(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(40, 160, 120, 80));
        widget_6 = new LightButton(groupBox);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(230, 170, 120, 80));
        widget_7 = new LightButton(groupBox);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(360, 170, 120, 80));
        widget_8 = new LightButton(groupBox);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        widget_8->setGeometry(QRect(500, 190, 120, 80));
        widget_9 = new LightButton(groupBox);
        widget_9->setObjectName(QString::fromUtf8("widget_9"));
        widget_9->setGeometry(QRect(210, 310, 120, 80));

        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(150, 400));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_search = new QPushButton(groupBox_2);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setCheckable(false);
        btn_search->setChecked(false);

        verticalLayout->addWidget(btn_search);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_portName = new QLabel(groupBox_2);
        label_portName->setObjectName(QString::fromUtf8("label_portName"));

        horizontalLayout_2->addWidget(label_portName);

        comboBox_portName = new QComboBox(groupBox_2);
        comboBox_portName->setObjectName(QString::fromUtf8("comboBox_portName"));

        horizontalLayout_2->addWidget(comboBox_portName);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_open = new QPushButton(groupBox_2);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_open->sizePolicy().hasHeightForWidth());
        btn_open->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(btn_open);

        label_txt_recv = new QLabel(groupBox_2);
        label_txt_recv->setObjectName(QString::fromUtf8("label_txt_recv"));

        verticalLayout->addWidget(label_txt_recv);

        textEdit_send = new QTextEdit(groupBox_2);
        textEdit_send->setObjectName(QString::fromUtf8("textEdit_send"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(textEdit_send->sizePolicy().hasHeightForWidth());
        textEdit_send->setSizePolicy(sizePolicy2);
        textEdit_send->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(textEdit_send);

        label_txt_send = new QLabel(groupBox_2);
        label_txt_send->setObjectName(QString::fromUtf8("label_txt_send"));

        verticalLayout->addWidget(label_txt_send);

        textEdit_recv = new QTextEdit(groupBox_2);
        textEdit_recv->setObjectName(QString::fromUtf8("textEdit_recv"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(textEdit_recv->sizePolicy().hasHeightForWidth());
        textEdit_recv->setSizePolicy(sizePolicy3);
        textEdit_recv->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(textEdit_recv);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_recvClear = new QPushButton(groupBox_2);
        btn_recvClear->setObjectName(QString::fromUtf8("btn_recvClear"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btn_recvClear->sizePolicy().hasHeightForWidth());
        btn_recvClear->setSizePolicy(sizePolicy4);
        btn_recvClear->setCheckable(false);

        horizontalLayout->addWidget(btn_recvClear);

        btn_send = new QPushButton(groupBox_2);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        sizePolicy4.setHeightForWidth(btn_send->sizePolicy().hasHeightForWidth());
        btn_send->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(btn_send);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(groupBox_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        btn_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\344\270\262\345\217\243", nullptr));
        label_portName->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        btn_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_txt_recv->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        label_txt_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        btn_recvClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        btn_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
