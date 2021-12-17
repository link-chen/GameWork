#ifndef GETMONEY_H
#define GETMONEY_H

#include <QMainWindow>
#include<QKeyEvent>
#include"mypushbutton.h"

class GetMoney : public QMainWindow
{
    Q_OBJECT
public:
    explicit GetMoney(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *e);
    MyPushButton *back;

signals:

};

#endif // GETMONEY_H
