#ifndef LOADING_H
#define LOADING_H

#include <QMainWindow>
#include<QPainter>
#include<QPixmap>
#include<QTimer>
#include<QDebug>

#include"enterspace.h"
#include"mainscene.h"

class Loading : public QMainWindow
{
    Q_OBJECT
public:
    //explicit Loading(QWidget *parent = nullptr);
    Loading(QString username,QString countnumber);
    void paintEvent(QPaintEvent *);

private slots:
    void onconnect();
    void onreadyRead();
    void onError();

private:
    bool status;//状态
    QTcpSocket tcpsocket;
    QHostAddress serverIP;
    quint16 serverPort;
    QString number;
    QString message;

signals:

};

#endif // LOADING_H
