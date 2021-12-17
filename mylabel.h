#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include<QPainter>
#include<QPixmap>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    //explicit MyLabel(QWidget *parent = nullptr);
    MyLabel(QString picturepath,float x,float y);

signals:

};

#endif // MYLABEL_H
