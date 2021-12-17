#include "mypushbutton.h"

MyPushButton::MyPushButton(QString picturepath)
{
    QPixmap pixmap;
    pixmap.load(picturepath);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}
