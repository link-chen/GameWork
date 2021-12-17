#include "loginscene.h"
#include "ui_loginscene.h"

int flag=0,flag1=0;

LoginScene::LoginScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScene)
{
    //基本界面设置
    ui->setupUi(this);
    this->setFixedSize(528,370);
    this->setWindowTitle("FalseQQ");

    //qq小图标
    MyLabel *qq=new MyLabel(":/qq.png",1,1);
    qq->setParent(this);
    qq->move(122,-72);
    //

    //密码锁图标
    MyLabel *lock=new MyLabel(":/lock.png",1,1);
    lock->setParent(this);
    lock->move(122,-26);
    //

    //忘记密码按钮
    QPushButton *btn_forgetpassword=new QPushButton(this);
    btn_forgetpassword->setFlat(true);
    btn_forgetpassword->setText("找回密码");
    btn_forgetpassword->move(298,256);
    connect(btn_forgetpassword,&MyPushButton::clicked,this,[=](){
        QDesktopServices::openUrl(QUrl("https://aq.qq.com/v2/uv_aq/html/reset_pwd/pc_reset_pwd_input_account.html?v=3.0&old_ver_account="));
    });
    //

    //注册
    QPushButton *btn_register=new QPushButton(this);
    btn_register->setFlat(true);
    btn_register->setText("注册账号");
    btn_register->move(0,340);
    connect(btn_register,&MyPushButton::clicked,this,[=](){
        QDesktopServices::openUrl(QUrl("https://ssl.zc.qq.com/v3/index-chs.html?from=client&regkey=1CB515A90DD153DFC274F77C2E580803A660D893571B7FE5318C719836BEAA73&ADUIN=0&ADSESSION=0&ADTAG=CLIENT.QQ.5803_NewAccount_Btn.0&ADPUBNO=27129"));
    });
    //

    //登陆账号输入栏
    QLineEdit *count=new QLineEdit(this);
    count->setPlaceholderText("QQ号码/手机/邮箱");
    count->resize(240,30);
    count->move(160,156);
    //

    //密码
    QLineEdit *password=new QLineEdit(this);
    password->resize(240,30);
    password->move(160,196);
    password->setEchoMode(QLineEdit::Password);
    //

    //选择显示密码
    QCheckBox *box=new QCheckBox(this);
    box->move(162,256);
    box->setText("显示密码");
    connect(box,&QCheckBox::stateChanged,this,[=](){
        if(flag%2==0)
        {
            password->setEchoMode(QLineEdit::Normal);
        }
        else
        {
            password->setEchoMode(QLineEdit::Password);
        }
        flag++;
    });
    //

    //

    //二维码显示界面
    MyPushButton *codepicture=new MyPushButton(":/code.png");
    codepicture->setParent(this);
    codepicture->move(488,320);
    connect(codepicture,&MyPushButton::clicked,this,[=](){
        GetMoney *getmoney=new GetMoney(this);
        getmoney->show();
    });
    //

    //
    MyLabel *headportrait=new MyLabel(":/adding.png",0.35,0.35);
    headportrait->setParent(this);
    headportrait->move(232,-136);
    //

    //登录按钮功能区块
    login=new MyPushButton(":/load.png");
    login->setParent(this);
    login->move(118,308);
    //

    //
    connect(login,&MyPushButton::clicked,this,[=](){
        if(password->text().isEmpty()&count->text().isEmpty())
        {
            QMessageBox::critical(this,"Error","请输入账号和密码");
        }
        if(password->text().isEmpty()&!count->text().isEmpty())
        {
            QMessageBox::critical(this,"Error","请输入密码");
        }
        if(!password->text().isEmpty()&!count->text().isEmpty())
        {
            message="x";
            message+=count->text();
            countnumber=count->text();
            message+=":";
            message+=password->text();
            serverIP.setAddress("127.0.0.01");
            //获取服务器端口
            QString port="8080";
            serverPort=port.toShort();
            //获取聊天室昵称
            //向服务器发送连接信号
            tcpsocket.connectToHost(serverIP,serverPort);
            tcpsocket.write(message.toUtf8());
        }

        message.clear();
    });
    //

    //
    connect(&tcpsocket,&QTcpSocket::connected,this,&LoginScene::onconnect);
    connect(&tcpsocket,&QTcpSocket::disconnected,this,&LoginScene::onDisconnected);
    connect(&tcpsocket,&QTcpSocket::readyRead,this,&LoginScene::onReadyRead);
    connect(&tcpsocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError()));
    //

}

void LoginScene::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Return)
    {
        emit login->clicked();
    }
    else
    {
        QMainWindow::keyPressEvent(e);
    }
}

void LoginScene::onconnect()
{
    //设置在线状态
    status=true;
    //转换
    tcpsocket.write(message.toUtf8());
}

void LoginScene::onError()
{
    if(state==false)
    {
        //errorstring获取网络错误原因
        QMessageBox::critical(this,"ERROR",tcpsocket.errorString());

    }
}

void LoginScene::onDisconnected()
{
    if(state==false)
    QMessageBox::critical(this,"Disconnect","Disconnect with the service");
}

void LoginScene::onReadyRead()
{
    if(tcpsocket.bytesAvailable())
    {
        QByteArray buf=tcpsocket.readAll();
        if(buf=="false")
        {
            //此处应该要和服务器断开连接
            countnumber.clear();
            error=new ErrorScene(this);
            error->show();//后期可以考虑删除
            tcpsocket.disconnectFromHost();
        }
        else
        {
            state=true;
            QString username;
            username=QString(buf);
            Loading *loading=new Loading(username,countnumber);

            loading->show();
            tcpsocket.disconnectFromHost();
            this->close();
        }
    }
}

LoginScene::~LoginScene()
{
    delete ui;
}

