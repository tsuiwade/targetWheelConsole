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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
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
#include "mymenu.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action111;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame;
    LightButton *pushButton;
    LightButton *pushButton_2;
    LightButton *pushButton_3;
    LightButton *pushButton_4;
    LightButton *pushButton_5;
    LightButton *pushButton_6;
    LightButton *pushButton_7;
    LightButton *pushButton_8;
    LightButton *pushButton_9;
    QGroupBox *frame_2;
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
    MyMenu *menuaaa;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        action111 = new QAction(MainWindow);
        action111->setObjectName(QString::fromUtf8("action111"));
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
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        pushButton = new LightButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 60, 93, 28));
        pushButton->setCheckable(true);
        pushButton_2 = new LightButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 60, 93, 28));
        pushButton_2->setCheckable(true);
        pushButton_3 = new LightButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(310, 60, 93, 28));
        pushButton_3->setCheckable(true);
        pushButton_4 = new LightButton(frame);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(440, 60, 93, 28));
        pushButton_4->setCheckable(true);
        pushButton_5 = new LightButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 150, 93, 28));
        pushButton_5->setCheckable(true);
        pushButton_6 = new LightButton(frame);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(230, 130, 93, 28));
        pushButton_6->setCheckable(true);
        pushButton_7 = new LightButton(frame);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(340, 150, 93, 28));
        pushButton_7->setCheckable(true);
        pushButton_8 = new LightButton(frame);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(480, 160, 93, 28));
        pushButton_8->setCheckable(true);
        pushButton_9 = new LightButton(frame);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(340, 270, 93, 28));
        pushButton_9->setCheckable(true);
        frame_2 = new QGroupBox(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(630, 20, 150, 400));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMaximumSize(QSize(150, 400));
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btn_search = new QPushButton(frame_2);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));
        btn_search->setCheckable(false);
        btn_search->setChecked(false);

        verticalLayout->addWidget(btn_search);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_portName = new QLabel(frame_2);
        label_portName->setObjectName(QString::fromUtf8("label_portName"));

        horizontalLayout_2->addWidget(label_portName);

        comboBox_portName = new QComboBox(frame_2);
        comboBox_portName->setObjectName(QString::fromUtf8("comboBox_portName"));

        horizontalLayout_2->addWidget(comboBox_portName);


        verticalLayout->addLayout(horizontalLayout_2);

        btn_open = new QPushButton(frame_2);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_open->sizePolicy().hasHeightForWidth());
        btn_open->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(btn_open);

        label_txt_recv = new QLabel(frame_2);
        label_txt_recv->setObjectName(QString::fromUtf8("label_txt_recv"));

        verticalLayout->addWidget(label_txt_recv);

        textEdit_send = new QTextEdit(frame_2);
        textEdit_send->setObjectName(QString::fromUtf8("textEdit_send"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(textEdit_send->sizePolicy().hasHeightForWidth());
        textEdit_send->setSizePolicy(sizePolicy2);
        textEdit_send->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(textEdit_send);

        label_txt_send = new QLabel(frame_2);
        label_txt_send->setObjectName(QString::fromUtf8("label_txt_send"));

        verticalLayout->addWidget(label_txt_send);

        textEdit_recv = new QTextEdit(frame_2);
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
        btn_recvClear = new QPushButton(frame_2);
        btn_recvClear->setObjectName(QString::fromUtf8("btn_recvClear"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btn_recvClear->sizePolicy().hasHeightForWidth());
        btn_recvClear->setSizePolicy(sizePolicy4);
        btn_recvClear->setCheckable(false);

        horizontalLayout->addWidget(btn_recvClear);

        btn_send = new QPushButton(frame_2);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));
        sizePolicy4.setHeightForWidth(btn_send->sizePolicy().hasHeightForWidth());
        btn_send->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(btn_send);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_3->addWidget(frame);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 26));
        menuaaa = new MyMenu(menuBar);
        menuaaa->setObjectName(QString::fromUtf8("menuaaa"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuaaa->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action111->setText(QCoreApplication::translate("MainWindow", "111", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        btn_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242\344\270\262\345\217\2431", nullptr));
        label_portName->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        btn_open->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_txt_recv->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        label_txt_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        btn_recvClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\346\224\266", nullptr));
        btn_send->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        menuaaa->setTitle(QCoreApplication::translate("MainWindow", "aaa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
