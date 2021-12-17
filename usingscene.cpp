#include "usingscene.h"
#include "ui_usingscene.h"

UsingScene::UsingScene(QWidget *parent,QString username,QString countnumber1) :
    QMainWindow(parent),
    ui(new Ui::UsingScene)
{
    //
    ui->setupUi(this);
    this->setFixedSize(360,610);
    this->setWindowTitle("qq 2021");
    //

    //设置昵称
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::blue);
    QLabel *label=new QLabel(this);
    label->setText("name:"+username);
    label->setFixedSize(360,25);
    label->setPalette(pa);
    //

    //与管理员联系
    QToolButton *connect_with_adminnister=new QToolButton(this);
    connect_with_adminnister->setText("联系管理员");
    connect_with_adminnister->setFixedSize(106,106);
    ui->scrollArea->addScrollBarWidget(connect_with_adminnister,Qt::AlignRight);
    connect(connect_with_adminnister,&QToolButton::clicked,this,[=](){
        qDebug()<<"联系管理员";
    });
    //

    //进入群聊
    QToolButton *enter=new QToolButton(this);
    enter->setText("进入聊天室");
    enter->setFixedSize(106,106);
    ui->scrollArea->addScrollBarWidget(enter,Qt::AlignRight);
    connect(enter,&QToolButton::clicked,this,[=](){
        EnterSpace *enterscene=new EnterSpace(this,username,countnumber1);
        enterscene->show();
    });
    //

    for(int i=0;i<15;i++)
    {
        QToolButton *btn=new QToolButton(this);
        ui->scrollArea->addScrollBarWidget(btn,Qt::AlignRight);
    }
}


UsingScene::~UsingScene()
{
    delete ui;
}
