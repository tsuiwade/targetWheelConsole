# targetWheelConsole



源代码： https://github.com/tsuiwade/targetWheelConsole

这是一个简单的靶轮控制软件，主要用到的是串口功能。实现了一些现代化的按钮立体显示效果、动态交互激活按钮状态、菜单栏选择串口。

![image-20211010180956933](https://gitee.com/tsuiwade/images/raw/master/image-20211010180956933.png)

1. 现代化的按钮立体显示效果，借鉴自https://www.jianshu.com/p/952637f9958f

   ![image-20211010181447085](https://gitee.com/tsuiwade/images/raw/master/image-20211010181447085.png)

   1:可设置文本,居中显示

   2:可设置文本颜色

   3:可设置外边框渐变颜色

   4:可设置里边框渐变颜色

   5:可设置背景色

   6:可直接调用内置的设置 绿色/红色/黄色/黑色/蓝色 等公有槽函数

   7:可设置是否在容器中可移动,当成一个对象使用

   8:可设置是否显示矩形

   9:可设置报警颜色+非报警颜色

   10:可控制启动报警和停止报警,报警时闪烁

   

   ```c++
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
   ```

   

   ```c++
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
   ```

   

   

   

2. 动态交互激活按钮状态

   ![image-20211010181553606](https://gitee.com/tsuiwade/images/raw/master/image-20211010181553606.png)

   ```c++
           connect(btn_list[i],  &QPushButton::pressed, this, [ = ]() {
               btn_list[i]->setBgRadius(70);
               btn_list[i]->setOverlayRadius(70);
           });
           connect(btn_list[i],  &QPushButton::released, this, [ = ]() {
               btn_list[i]->setBgRadius(80);
               btn_list[i]->setOverlayRadius(80);
           });
   ```

   

   

   

3. 3

   

   

   
