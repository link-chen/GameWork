#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent,QString username1,QString countnumber1,int friendnumber1) :
    QWidget(parent),
    ui(new Ui::MainScene)
{
    //
    ui->setupUi(this);
    this->setFixedSize(360,610);
    this->setWindowTitle("QQ 2021");
    //

    //
    username=username1;
    friendnumber=friendnumber1;
    countnumber=countnumber1;
    //

    //
    QLabel *label=new QLabel(this);
    label->setText("Username:"+username);
    label->setFixedSize(360,25);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);
    label->setPalette(pa);
    //

    //
    QToolButton *connect_with_administer=new QToolButton(this);
    connect_with_administer->setFixedSize(96,96);
    connect_with_administer->setText("与管理员联系呀");
    ui->Layout->addWidget(connect_with_administer);
    connect(connect_with_administer,&QToolButton::clicked,this,[=](){
        AdministerLink *administer=new AdministerLink(this,username,countnumber);
        administer->show();
    });
    //

    //
    serverIP.setAddress("127.0.0.01");
    //获取服务器端口
    QString port="8080";
    serverPort=port.toShort();
    //获取聊天室昵称
    //向服务器发送连接信号
    tcpsocket.connectToHost(serverIP,serverPort);
    QString string="Yselect name from user";
    tcpsocket.write(string.toUtf8());
    //

    //
    connect(&tcpsocket,&QTcpSocket::connected,this,&MainScene::onconnect);
    connect(&tcpsocket,&QTcpSocket::readyRead,this,&MainScene::onReadyRead);
    //

    //
    QToolButton *enter=new QToolButton(this);
    enter->setFixedSize(96,96);
    enter->setText("进入群聊");
    ui->Layout->addWidget(enter);
    connect(enter,&QToolButton::clicked,this,[=](){
        EnterSpace *enterspace=new EnterSpace(this,username,countnumber1);
        enterspace->show();
    });

    for(int i=0;i<friendnumber;i++)
    {
        QToolButton *btn=new QToolButton(this);
        btn->setIcon(QPixmap(":/adding.png"));
        btn->setIconSize(QPixmap(":/adding.png").size()*0.5);
        btn->setText("我的好友");
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        btn->setFixedSize(300,75);
        ui->Layout->addWidget(btn);
        buttonVector.push_back(btn);
    }

    //
    for(int i=0;i<friendnumber;i++)
    {
        connect(buttonVector[i],&QToolButton::clicked,this,[=](){
            QString string=buttonVector[i]->text();
            if(!string.isEmpty())
            {
                qDebug()<<string;
                QString t;
                int i=0;
                while(string[i]!='\n')
                {
                    t[i]=string[i];
                    i++;
                }
                while(string[i]!=':')
                {
                    i++;
                }
                i++;
                QString t1;
                int j=0;
                while(string[i]!='\n')
                {
                    t1[j]=string[i];
                    j++;
                    i++;
                }
                Talking *talking=new Talking(this,t,t1,username,countnumber);
                talklist.push_back(talking);
                talking->show();
            }
        });
    }
    //

    //
    QTimer::singleShot(50,this,[=](){
        QString stringt="Zselect count from user";
        qDebug()<<stringt;
        tcpsocket.write(stringt.toUtf8());
    });
    //

    //
    QTimer::singleShot(1000,this,[=](){
       QString stringsearch="Rselect *from unread where count=";
       stringsearch+=countnumber;
       qDebug()<<stringsearch;
       tcpsocket.write(stringsearch.toUtf8());
    });

    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        QString search="Hselect *from user where count =";
        search+=ui->lineEdit->text();
        qDebug()<<search;
        tcpsocket.write(search.toUtf8());
    });
}

void MainScene::onconnect()
{
    status=true;
}

void MainScene::onReadyRead()
{
    if(tcpsocket.bytesAvailable())
    {
        QByteArray buf=tcpsocket.readAll();
        if(buf[0]=='Y')
        {
            QString name1=QString(buf);
            QString name;
            int t=0;
            qDebug()<<name1;
            for(int i=1;i<name1.length();i++)
            {
                name[i-1]=name1[i];
            }
            QString z;
            for(int i=0;i<name.length();i++)
            {
                if(name[i]!=':')
                {
                    z[t]=name[i];
                    t++;
                }
                else
                {
                    z.append('\n');
                    list.append(z);
                    t=0;
                    z.clear();
                }
            }
            qDebug()<<list;
            for(int i=0;i<list.size();i++)
            {

            }
            for(int i=0;i<friendnumber;i++)
            {
                buttonVector[i]->setText(list.at(i));
            }
        }
        else if(buf[0]=='Z')
        {
            QString number1=QString(buf);
            QString number;
            qDebug()<<number1;
            for(int i=1;i<number1.length();i++)
            {
                number[i-1]=number1[i];
            }
            QString z;
            int t=0;
            for(int i=0;i<number.length();i++)
            {
                if(number[i]!=':')
                {
                    z[t]=number[i];
                    t++;
                }
                else
                {
                    z.append('\n');
                    list1.append(z);
                    t=0;
                    z.clear();
                }
            }
            for(int i=0;i<friendnumber;i++)
            {
                buttonVector[i]->setText(list.at(i)+"count:"+list1.at(i));
            }
        }
        else if(buf[0]=='R')
        {
            QString message,messagecount,message1;
            message1=QString(buf);
            for (int i=1;i<message1.size();i++ )
            {
                message[i-1]=message1[i];
            }
            QString count;
            QString sender;
            QString unreadmessage;
            int i=0;
            while(message[i]!=":")
            {
                count[i]=message[i];
                i++;
            }
            i++;
            int t=0;
            while(message[i]!=":")
            {
                sender[t]=message[i];
                t++;
                i++;
            }
            i++;
            t=0;
            while(message[i]!='\0')
            {
                  unreadmessage[t]=message[i];
                  t++;
                  i++;
            }
            for(i=0;i<buttonVector.size();i++)
            {
                QString name_count,name;
                name_count=buttonVector[i]->text();
                int j=0;
                while(name_count[j]!=":")
                {
                    j++;
                }
                j++;
                int place=0;
                while(name_count[j]!='\0')
                {
                    name[place]=name_count[j];
                    place++;
                    j++;
                }
                QString realcount;
                j=0;
                while(j<name.size()-1)
                {
                    realcount[j]=name[j];
                    j++;
                }
                if(sender==realcount)
                {
                    qDebug()<<true;
                    buttonVector[i]->clicked();
                }
                qDebug()<<i;
            }
        }
    }
}

void MainScene::keyPressEvent(QKeyEvent *e)
{
    if(e->key()==Qt::Key_Return)
    {
        emit ui->pushButton->clicked();
    }
    else
    {
        MainScene::keyPressEvent(e);
    }
}

MainScene::~MainScene()
{
    delete ui;
}
