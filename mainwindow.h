#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QList>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include "lightbutton.h"
#include <dialog.h>
#include "maskwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//    void on_pushButton_pressed(LightButton *a);

  public slots:
//    void checkedLibAction(QAction*);

  private slots:
    void serialPort_readyRead();
    //    void toggleState(bool);



    //    void on_pushButton_clicked();



//    void on_pushButton_released(LightButton * );

    //    void on_pushButton_clicked(bool checked);



  private:
    bool recFlag;
    Dialog *tipDialog ;
    QByteArray sumData;
    Ui::MainWindow *ui;
    QSerialPort serial;
    void comboBoxDefaultSetting();
    void setCircleLayout();

    QPushButton     *btn_center;
    QLabel *m_label;
    QList<LightButton*> btn_list;
    QList<QLabel*> lbl_list;
    //    QList<QGraphicsDropShadowEffect*> effect_list;


    // https://qtguide.ustclug.org/ch06-01.htm


};

#endif // MAINWINDOW_H
