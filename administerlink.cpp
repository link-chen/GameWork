#include "administerlink.h"
#include "ui_administerlink.h"

AdministerLink::AdministerLink(QWidget *parent,QString username1,QString countnumber1) :
    QMainWindow(parent),
    ui(new Ui::AdministerLink)
{
    //
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("联系管理员");
    username=username1;
    //

    //

    //132.232.79.55
    serverIP.setAddress("127.0.0.01");
    //获取服务器端口
    QString port="8080";
    serverPort=port.toShort();
    //获取聊天室昵称
    //向服务器发送连接信号
    tcpsocket.connectToHost(serverIP,serverPort);
    //

    //
    QPushButton *send=new QPushButton(this);
    send->setText("发送");
    send->move(this->width()-send->width(),this->height()-send->height());
    //

    //输入文本框和聊天显示框
    QTextEdit *text=new QTextEdit(this);
    text->setFixedSize(800,170);
    text->move(0,400);
    QTextEdit *talk=new QTextEdit(this);
        talk->setReadOnly(true);//设置在聊天框内不能编辑
    talk->setFixedSize(800,400);
    //

    //发送信息
    connect(send,&QPushButton::clicked,this,[=](){
        QString string=username;
        string+=":";
        string+=text->toPlainText();
        string+="\n";
        talk->insertPlainText(string);
        talk->moveCursor(QTextCursor::End);
        text->clear();
        string+=":";
        string+=countnumber;
        qDebug()<<string;
        tcpsocket.write(string.toUtf8());
        string.clear();
    });
    //
}

AdministerLink::~AdministerLink()
{
    delete ui;
}
