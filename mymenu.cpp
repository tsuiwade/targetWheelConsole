#include "mymenu.h"
#include <QWidget>
#include "qevent.h"
#include <QDebug>

MyMenu::MyMenu(QWidget *parent) : QMenu(parent)

{
    this->installEventFilter(this);
}

bool MyMenu::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) //鼠标进入
    {
        qDebug()<<"3";
    }
    else if (event->type() == QEvent::HoverEnter)    //鼠标离开
    {

        //        this->update();
    }
    return QWidget::eventFilter(watched, event);
}
