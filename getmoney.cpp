#include "getmoney.h"
#include"mypushbutton.h"

#include<QPixmap>
#include<QPainter>

GetMoney::GetMoney(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(528,370);
    this->setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint|Qt::WindowStaysOnTopHint);
    back=new MyPushButton(":/back.png");
    back->setParent(this);
    back->move(118,308);
    connect(back,&MyPushButton::clicked,this,&QMainWindow::close);
}

void GetMoney::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/test.png");
    painter.drawPixmap(188,80,164,164,pix);
}

void GetMoney::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Return)
    {
        emit back->clicked();
    }
    else
    {
        QMainWindow::keyPressEvent(e);
    }
}
