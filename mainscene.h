#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QTcpServer>
#include<QTcpSocket>
#include<QUrl>
#include<QToolButton>
#include<QVector>
#include<QLineEdit>
#include<QKeyEvent>

#include"enterspace.h"
#include"administerlink.h"
#include"talking.h"
#include"friend.h"

namespace Ui {
class MainScene;
}

class MainScene : public QWidget
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = nullptr,QString username1=NULL,QString countnumber1=NULL,int friendnumber1=15);
    ~MainScene();
    void keyPressEvent(QKeyEvent *e);

private slots:
    //连接
    void onconnect();
    //读取信息
    void onReadyRead();

private:
    //界面
    Ui::MainScene *ui;

    //
    QString countnumber;
    QString username;
    //

    //状态
    bool status=false;
    //

    //联网组件
    QTcpSocket tcpsocket;
    QHostAddress serverIP;
    quint16 serverPort;
    //

    //好友昵称列表
    QList<QString> list;
    QList<QString> list1;
    //

    //按钮组控制
    QVector<QToolButton*> buttonVector;
    QVector<Talking*> talklist;
    //

    //
    int friendnumber;
    //

    //
    struct imformation{
      QString countnumber;
      QString name;
    };
    //

};

#endif // MAINSCENE_H
