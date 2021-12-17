#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include<QPainter>
#include<QPixmap>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString picturepath);

signals:

};

#endif // MYPUSHBUTTON_H
