#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <QDebug>
#include <QMessageBox>
#include <QResizeEvent> //调整窗口大小的事件类
#include <QTimer>
#include <QString>
#include <QLayout>
#include <complex>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QWidget>
#include <QSignalMapper>

static int timerCount = 0;

#define PI 3.14159265358979323846
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    this->resize(QSize(800, 600)); //初始化窗体大小
    this->setMinimumSize(QSize(800, 600));
//    this->setMaximumSize(QSize(800, 600));





    btn_list = ui->centralWidget->findChildren<LightButton*>();
    for (int i = 0; i < btn_list.size(); i++) {
        connect(btn_list[i], SIGNAL(clicked(bool)), this, SLOT(toggleState(bool)));
        QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
        shadow_effect->setOffset(1, 1);             //阴影的偏移量
        shadow_effect->setColor(QColor(43, 43, 43, 150)); //阴影的颜色
        shadow_effect->setBlurRadius(8);             // 阴影圆角的大小
//        effect_list.append(shadow_effect);

        btn_list[i]->setLightGreen();
        btn_list[i]->resize(120, 120);
        btn_list[i]->setText(QString::number(i + 1));
        btn_list[i]->setGraphicsEffect(shadow_effect);

//        btn_list[i]->setCheckable(true);
    }


    MainWindow::setCircleLayout();
    if (!ui->groupBox->isVisible()) {

        QTimer *pTimer = new QTimer(this);
        pTimer->start(0);

        connect(pTimer, &QTimer::timeout, [ = ]() {

            MainWindow::setCircleLayout();
            timerCount++;
            if (timerCount > 1)
                pTimer->stop();
        });

    }
//    ui->groupBox->setObjectName("mainWidget");
//    ui->groupBox->setStyleSheet("#mainWidget{background-color:rgba(255,0,0,30); border-image: url(:/banner.png); color:rgba(0,0,0,50); }");

//    连接信号和槽
//    串口在收到数据后，会将数据存入接收缓冲区。此时，我们可以通过readAll()函数将接收缓冲区的数据读出来。当串口的接收缓冲区有数据时，QSerilaPort对象会发出一个readyRead()的信号。因此，我们可以编写一个槽函数来读数据：
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);

    //发送按键失能
    ui->btn_send->setEnabled(false);

//下拉框默认设置
    comboBoxDefaultSetting();

    MainWindow::on_btn_search_clicked();
    MainWindow::setCircleLayout();

}
void MainWindow::toggleState(bool) {
    //发送信号者的对象
    QPushButton *optBtn = qobject_cast<QPushButton *>(sender());
    //发送信号者的对象名
    QString name = sender()->objectName();
    for(int i = 0; i < 4; i++) { //通过i可以获得你点击的按钮btn[i]
        if(btn_list[i] == optBtn) {
            qDebug() << " click :" << i;
        }

    }
    qDebug() << "name = " << name;

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::comboBoxDefaultSetting() {

    //默认选择下拉第0项

}

void MainWindow::setCircleLayout() {

    int centerX = ui->groupBox->geometry().width() / 2 - btn_list[0]->geometry().width() / 2;
    int centerY = ui->groupBox->geometry().height() / 2 - btn_list[0]->geometry().height() / 2;

    qDebug() << "centerX" << centerX;
    qDebug() << "btn_list.size()" << btn_list.size();

    for(int i = 0; i < btn_list.size(); i++) {
        qDebug() << centerY - 200 * cos(40.0 * i * PI / 180.0);
        btn_list[i]-> move(centerX + 200 * sin(40.0 * i * PI / 180.0), centerY - 200 * cos(40.0 * i * PI / 180.0));
    }
}


void MainWindow::serialPort_readyRead() {
    //从接收缓冲区中读取数据
    QByteArray buffer = serial.readAll();
    //从界面中读取以前收到的数据
    QString recv = ui->textEdit_recv->toPlainText();
    recv += QString(buffer);
    //清空以前的显示
    ui->textEdit_recv->clear();
    //重新显示
    ui->textEdit_recv->append(recv);
}



void MainWindow::on_btn_recvClear_clicked() {
    ui->textEdit_recv->clear();
}

void MainWindow::on_btn_send_clicked() {
    QByteArray data = ui->textEdit_send->toPlainText().toUtf8();
    serial.write(data);
}

void MainWindow::on_btn_search_clicked() {
    MainWindow::setCircleLayout();
    ui->comboBox_portName->clear();
    //通过QSerialPortInfo查找可用串口
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->comboBox_portName->addItem(info.portName());
    }

}

void MainWindow::on_btn_open_clicked() {
    if(ui->btn_open->text() == QString("打开串口")) {
        //设置串口名
        serial.setPortName(ui->comboBox_portName->currentText());
        //设置波特率
        serial.setBaudRate(9600);

        //设置数据位数
        serial.setDataBits(QSerialPort::Data8);


        serial.setParity(QSerialPort::NoParity);
        //设置停止位

        serial.setStopBits(QSerialPort::OneStop);

        serial.setFlowControl(QSerialPort::NoFlowControl);

        //打开串口
        if(!serial.open(QIODevice::ReadWrite)) {
            QMessageBox::about(NULL, "提示", "无法打开串口！");
            return;
        }

        //下拉菜单控件失能
        ui->comboBox_portName->setEnabled(false);
        ui->btn_open->setText(QString("关闭串口"));

        //发送按键使能
        ui->btn_send->setEnabled(true);

    } else {
        //关闭串口
        serial.close();
        //下拉菜单控件使能
        ui->comboBox_portName->setEnabled(true);
        ui->btn_open->setText(QString("打开串口"));

        //发送按键失能
        ui->btn_send->setEnabled(false);
    }
}


void MainWindow::resizeEvent(QResizeEvent * event) {

//    MainWindow::setCircleLayout();

//    if (!ui->groupBox->isVisible()) {

//        QTimer *pTimer = new QTimer(this);
//        pTimer->start(0);

//        connect(pTimer, &QTimer::timeout, [ = ]() {

//            MainWindow::setCircleLayout();

//            timerCount++;
//            if (timerCount > 4)
//                pTimer->stop();
//        });

//    }



}
