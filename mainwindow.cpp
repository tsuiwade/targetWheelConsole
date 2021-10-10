#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QString>
#include <QLayout>
#include <complex>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
//#include <QWidget>
#include <QAction>
#include <QFont>


static int timerCount = 0;
#define PI 3.14159265358979323846

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("靶轮控制系统");
    this->resize(QSize(800, 600)); //初始化窗体大小
    this->setMinimumSize(QSize(800, 600));
    this->setMaximumSize(QSize(800, 600));
    connect(ui->menuSerial, &QMenu::aboutToShow, this, [ = ]() {
        if (ui->menuSerial->title() == QString("选择串口")) {
            ui->menuSerial->clear();
            foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
                ui->menuSerial->addAction(QIcon(":/target.png"), info.portName() + ": " + info.description());

                ui->menuSerial->addSeparator();
            }
        } else {
            ui->menuSerial->clear();
            ui->menuSerial->addAction(QString("关闭串口"));
        }
    });

    connect(ui->menuSerial, &QMenu::triggered, this, [ = ](QAction * _action) {
        if (ui->menuSerial->title() == QString("选择串口")) {
            qDebug() << "点击 选择串口";
            qDebug() << _action->text();
            QString spTxt =  _action->text();
//            ui->menuSerial->setTitle(spTxt) ;
            QString spTxt1 = spTxt.section(':', 0, 0);
            serial.setPortName(spTxt1);
            serial.setBaudRate(9600);
            serial.setDataBits(QSerialPort::Data8);
            serial.setParity(QSerialPort::NoParity);
            serial.setStopBits(QSerialPort::OneStop);
            serial.setFlowControl(QSerialPort::NoFlowControl);
            if(!serial.open(QIODevice::ReadWrite)) {
                QMessageBox::about(NULL, "提示", "无法打开串口！");
                return;
            }
            ui->menuSerial->setTitle(spTxt) ;
            ui->menuSerial->clear();
        } else {
            qDebug() << "点击 else";
            serial.close();
            ui->menuSerial->clear();
            ui->menuSerial->setTitle(QString("选择串口"));
        }
    });


    btn_list = ui->centralWidget->findChildren<LightButton*>();
    for (int i = 0; i < btn_list.size(); i++) {
        connect(btn_list[i], &QPushButton::clicked, this, [ = ](bool checked) {
            if(checked)
                btn_list[i]->setLightRed();
            else
                btn_list[i]->setLightGreen();
        });
        connect(btn_list[i],  &QPushButton::pressed, this, [ = ]() {
            btn_list[i]->setBgRadius(70);
            btn_list[i]->setOverlayRadius(70);
        });
        connect(btn_list[i],  &QPushButton::released, this, [ = ]() {
            btn_list[i]->setBgRadius(80);
            btn_list[i]->setOverlayRadius(80);
        });

        QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
        shadow_effect->setOffset(1, 1);             //阴影的偏移量
        shadow_effect->setColor(QColor(43, 43, 43, 150)); //阴影的颜色
        shadow_effect->setBlurRadius(8);             // 阴影圆角的大小

        btn_list[i]->setLightGreen();
        btn_list[i]->resize(120, 120);
        btn_list[i]->setText(QString::number(i + 1));
        btn_list[i]->setGraphicsEffect(shadow_effect);

    }

    MainWindow::setCircleLayout();
    if (!ui->frame->isVisible()) {

        QTimer *pTimer = new QTimer(this);
        pTimer->start(0);

        connect(pTimer, &QTimer::timeout, [ = ]() {

            MainWindow::setCircleLayout();
            timerCount++;
            if (timerCount > 1)
                pTimer->stop();
        });

    }

    //    连接信号和槽
    //    串口在收到数据后，会将数据存入接收缓冲区。此时，我们可以通过readAll()函数将接收缓冲区的数据读出来。当串口的接收缓冲区有数据时，QSerilaPort对象会发出一个readyRead()的信号。因此，我们可以编写一个槽函数来读数据：
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);

    //发送按键失能
    MainWindow::setCircleLayout();
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::setCircleLayout() {
    int centerX = ui->frame->geometry().width() / 2 - btn_list[0]->geometry().width() / 2;
    int centerY = ui->frame->geometry().height() / 2 - btn_list[0]->geometry().height() / 2;
    for(int i = 0; i < btn_list.size(); i++) {
        btn_list[i]-> move(centerX + 200 * sin(40.0 * i * PI / 180.0), centerY - 200 * cos(40.0 * i * PI / 180.0));
    }
}


void MainWindow::serialPort_readyRead() {
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
}



