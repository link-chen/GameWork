#include "loading.h"

Loading::Loading(QString username,QString countnumber)
{
    this->setFixedSize(528,370);

    connect(&tcpsocket,&QTcpSocket::connected,this,&Loading::onconnect);
    connect(&tcpsocket,&QTcpSocket::readyRead,this,&Loading::onreadyRead);

    //查找好友数量字符串
    message='S';
    message+="select friend from user where count=";
    message+=countnumber;
    //

    //连接服务器
    serverIP.setAddress("127.0.0.01");
    //获取服务器端口
    QString port="8080";
    serverPort=port.toShort();
    //获取聊天室昵称
    //向服务器发送连接信号
    tcpsocket.connectToHost(serverIP,serverPort);
    //

    if(true)
    {
        QTimer::singleShot(1000,this,[=](){
            //关闭当前界面
            //
            this->close();
            //创建用户使用的主界面
            MainScene *mainscene=new MainScene(nullptr,username,countnumber,number.toInt());
            mainscene->show();
            //
        });
    }
}

void Loading::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/loadon.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

void Loading::onconnect()
{
    //设置在线状态
    status=true;
    //转换
    tcpsocket.write(message.toUtf8());
    message.clear();
}

void Loading::onError()
{
    if(status==false)
    {
        //errorstring获取网络错误原因
        QMessageBox::critical(this,"ERROR",tcpsocket.errorString());

    }
}

void Loading::onreadyRead()
{
    if(tcpsocket.bytesAvailable())
    {
        QByteArray buf=tcpsocket.readAll();
        QString string=QString(buf);
        for(int i=1;i<string.length();i++)
        {
            number[i-1]=string[i];
        }
    }
}
