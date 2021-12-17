#include "mylabel.h"

MyLabel::MyLabel(QString picturepath,float x,float y)
{
    QPixmap pix;
    pix.load(picturepath);
    QPixmap scaledPixmap=pix.scaled(pix.width()*x,pix.height()*y);
    this->setPixmap(scaledPixmap);
    this->setAttribute(Qt::WA_TransparentForMouseEvents,true);
}
