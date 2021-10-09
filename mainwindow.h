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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

  private slots:
    void on_btn_recvClear_clicked();

    void on_btn_send_clicked();
    void on_btn_search_clicked();
    void on_btn_open_clicked();

    void serialPort_readyRead();
    void toggleState(bool);



  private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    void comboBoxDefaultSetting();
    void setCircleLayout();

    QPushButton     *btn_center;
    QLabel *m_label;
    QList<LightButton*> btn_list;
//    QList<QGraphicsDropShadowEffect*> effect_list;


    // https://qtguide.ustclug.org/ch06-01.htm

  protected:
    virtual void resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
