#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>        //提供访问串口的功能
#include <QSerialPortInfo>    //提供系统中存在的串口的信息
#include <QDebug>
#include <QMessageBox>
#include <QResizeEvent> //调整窗口大小的事件类
#include <QTimer>
#include <QString>
#include <QHBoxLayout>
#include <complex>
#include <QPixmap>
#include <QPainter>
#include <QLabel>

#define PI 3.14159265358979323846
static int timerCount = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {


    this->resize(QSize(1000, 1000)); //初始化窗体大小
    ui->setupUi(this);


    QHBoxLayout *vbox = new QHBoxLayout;
    vbox->addStretch(1);

//    m_label = new QLabel();
//    m_label->setScaledContents(true);
//    m_label->resize(200, 200);
////    m_label->setGeometry(10, 10, 200, 200);
////    m_label->lower();
//    m_label->show();

//    QPixmap pix1_(":/banner.png");
//    qDebug() << "                    " << pix1_.size();
//    QPixmap temp(pix1_.size());
//    temp.fill(Qt::transparent);

//    QPainter p1(&temp);
//    p1.setCompositionMode(QPainter::CompositionMode_Source);
//    p1.drawPixmap(0, 0, pix1_);
//    p1.setCompositionMode(QPainter::CompositionMode_DestinationIn);

//    qDebug() << "                    " << temp.rect();

//    //根据QColor中第四个参数设置透明度，此处position的取值范围是0～255
//    p1.fillRect(temp.rect(), QColor(0, 0, 0, 50));
//    p1.end();

//    pix1_ = temp;

//    m_label->setPixmap(pix1_);
//    vbox->addWidget(m_label);





    for (int i = 0 ; i < 9 ; i ++) {
        QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
        shadow_effect->setOffset(5, 5);              //阴影的偏移量
        shadow_effect->setColor(QColor(43, 43, 43)); //阴影的颜色
        shadow_effect->setBlurRadius(8);             // 阴影圆角的大小
        effect_list.append(shadow_effect);

        QPushButton *btn = new QPushButton;
        btn_list.append(btn);
        btn_list[i]->setObjectName("BlueButton");
        btn_list[i]->setText(QString::number(i + 1));
        btn_list[i]->setGraphicsEffect(effect_list[i]);
        btn_list[i]->setCheckable(true);
        vbox->addWidget(btn_list[i]);
    }



//    ui->groupBox->setObjectName("mainWidget");
//    ui->groupBox->setStyleSheet("#mainWidget{background-color:rgba(255,0,0,30); border-image: url(:/banner.png); color:rgba(0,0,0,50); }");


    ui->groupBox->setLayout(vbox);


//    连接信号和槽
//    串口在收到数据后，会将数据存入接收缓冲区。此时，我们可以通过readAll()函数将接收缓冲区的数据读出来。当串口的接收缓冲区有数据时，QSerilaPort对象会发出一个readyRead()的信号。因此，我们可以编写一个槽函数来读数据：
    QObject::connect(&serial, &QSerialPort::readyRead, this, &MainWindow::serialPort_readyRead);

    //发送按键失能
    ui->btn_send->setEnabled(false);


//下拉框默认设置
    comboBoxDefaultSetting();

    MainWindow::on_btn_search_clicked();


}
//void MainWindow::on_chkBoxBold(bool checked) {
//}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::comboBoxDefaultSetting() {

    //默认选择下拉第0项

}

void MainWindow::setCircleLayout() {
    int centerX = ui->groupBox->geometry().width() / 2 - btn_list[0]->geometry().width() / 2;
    int centerY = ui->groupBox->geometry().height() / 2 - btn_list[0]->geometry().height() / 2;
    for(int i = 0; i < 9; i++) {
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

    MainWindow::setCircleLayout();

    if (!ui->groupBox->isVisible()) {

        QTimer *pTimer = new QTimer(this);
        pTimer->start(0);

        connect(pTimer, &QTimer::timeout, [ = ]() {

            MainWindow::setCircleLayout();

            timerCount++;
            if (timerCount > 4)
                pTimer->stop();
        });

    }



}
