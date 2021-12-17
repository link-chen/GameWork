#include "talking.h"
#include "ui_talking.h"

Talking::Talking(QWidget *parent,QString tousername1,QString countnumber,QString username,QString fromcout1) :
    QMainWindow(parent),
    ui(new Ui::Talking)
{
    //
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle(tousername);
    fromcount=fromcout1;
    tousername=tousername1;
    //

    //
    send=new QPushButton(this);
    send->setText("发送");
    send->move(this->width()-send->width(),this->height()-send->height());
    //

    //
    serverIP.setAddress("132.232.79.55");
    //获取服务器端口
    QString port="8080";
    serverPort=port.toShort();
    //获取聊天室昵称
    //向服务器发送连接信号
    tcpsocket.connectToHost(serverIP,serverPort);
    //

    //输入文本框和聊天显示框
    QTextEdit *text=new QTextEdit(this);
    text->setFixedSize(800,170);
    text->move(0,400);
    talk=new QTextEdit(this);
        talk->setReadOnly(true);//设置在聊天框内不能编辑
    talk->setFixedSize(800,400);
    //

    //发送信息
    connect(send,&QPushButton::clicked,this,[=](){
        QString string="U";
        string+=username;
        string+=":";
        string+=text->toPlainText();
        talk->insertPlainText(username+":"+text->toPlainText()+'\n');
        talk->moveCursor(QTextCursor::End);
        text->clear();
        string+=":";
        string+=countnumber;
        string+=":";
        string+=fromcount;
        qDebug()<<string;
        tcpsocket.write(string.toUtf8());
        string.clear();
    });
    //
}

void Talking::addmessage(QString string)
{
    talk->insertPlainText(tousername+":"+string+"\n");
}

bool Talking::status()
{
    return state;
}

void Talking::change()
{
    if(state==false)
    {
        state=true;
    }
}

Talking::~Talking()
{
    delete ui;
}
