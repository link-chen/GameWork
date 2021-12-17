#include "errorscene.h"

#include<QPushButton>
#include<QPainter>
#include<QPixmap>
#include<QKeyEvent>

ErrorScene::ErrorScene(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(528,370);
    backBtn=new QPushButton(this);
    backBtn->setText("确定");
    backBtn->resize(106,38);
    backBtn->move(410,330);
    connect(backBtn,&QPushButton::clicked,this,&ErrorScene::close);
}

void ErrorScene::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/error.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
