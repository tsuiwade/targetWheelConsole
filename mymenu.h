#ifndef MYMENU_H
#define MYMENU_H
#include <QMenu>
#include <QWidget>

class MyMenu: public QMenu
{
//     Q_OBJECT

public:
//    MyMenu();
    explicit MyMenu(QWidget *parent = 0);


protected:
    bool eventFilter(QObject *watched, QEvent *event);

};

#endif // MYMENU_H
