#include "enterspace.h"
#include "ui_enterspace.h"

EnterSpace::EnterSpace(QWidget *parent,QString username,QString countnumber) :
    QMainWindow(parent),
    ui(new Ui::EnterSpace)
{
    ui->setupUi(this);
    this->setFixedSize(372,620);
    if(!username.isEmpty())
    {
        username1=username;
        this->setWindowTitle(username1);
        ui->lineEdit_4->setText(username1);
    }
    ui->lineEdit_2->setText("127.0.0.01");
    ui->lineEdit_3->setText("8080");

    status=false;

    connect(&tcpsocket,&QTcpSocket::connected,this,&EnterSpace::onConnect);
    connect(&tcpsocket,&QTcpSocket::disconnected,this,&EnterSpace::onDisconnect);
    connect(&tcpsocket,&QTcpSocket::readyRead,this,&EnterSpace::onReadyRead);
    connect(&tcpsocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError()));
}

EnterSpace::~EnterSpace()
{
    delete ui;
}

//
void EnterSpace::onConnect()
{
    //设置在线状态
    status=true;
    //
    ui->pushButton->setEnabled(true);
    ui->lineEdit_2->setEnabled(false);
    ui->lineEdit_3->setEnabled(false);
    ui->lineEdit_4->setEnabled(false);
    ui->pushButton_2->setText("离开聊天室");
    //

    //向服务器发送进入聊天室提示消息
    QString msg=username1+":进入了聊天室";
    //转换
    tcpsocket.write(msg.toUtf8());
}

//
void EnterSpace::onDisconnect()
{
    //
    status=false;
    //
    ui->pushButton->setEnabled(false);
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_3->setEnabled(true);
    ui->lineEdit_4->setEnabled(true);
    ui->pushButton_2->setText("link");
}

//
void EnterSpace::onReadyRead()
{
    if(tcpsocket.bytesAvailable())
    {
        //
        QByteArray buf=tcpsocket.readAll();

        //
        ui->listWidget->addItem(buf);
        ui->listWidget->scrollToBottom();
    }
}

//
void EnterSpace::onError()
{
    //errorstring获取网络错误原因
    QMessageBox::critical(this,"ERROR",tcpsocket.errorString());
}

void EnterSpace::on_pushButton_2_clicked()
{
    //离线状态
    if(status==false)
    {
        //获取服务器IP
        serverIP.setAddress(ui->lineEdit_2->text());
        //获取服务器端口
        serverPort=ui->lineEdit_3->text().toShort();
        //获取聊天室昵称
        username1=ui->lineEdit_4->text();

        //向服务器发送连接信号
        tcpsocket.connectToHost(serverIP,serverPort);
    }
    //在线
    else
    {
        //
        QString msg=username1+":leave";
        tcpsocket.write(msg.toUtf8());
        tcpsocket.disconnectFromHost();
    }
}

void EnterSpace::on_pushButton_clicked()
{
    //
    QString msg=ui->lineEdit->text();
    if(msg=="")
    {
        return;
    }
    else
    {
        msg=username1+":"+msg;
    }
    tcpsocket.write(msg.toUtf8());
    ui->lineEdit->clear();
}

void EnterSpace::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Return)
    {
        emit ui->pushButton->clicked();
    }
    else
    {
        QMainWindow::keyPressEvent(e);
    }
}
