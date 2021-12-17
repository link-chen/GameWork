#ifndef LOGINSCENE_H
#define LOGINSCENE_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QMessageBox>
#include<QDebug>
#include<QUrl>
#include<QDesktopServices>
#include<QLineEdit>
#include<QCheckBox>
#include<QKeyEvent>
#include<QTimer>

#include"mypushbutton.h"
#include"mylabel.h"
#include"errorscene.h"
#include"getmoney.h"
#include"loading.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScene; }
QT_END_NAMESPACE

class LoginScene : public QMainWindow
{
    Q_OBJECT

public:
    LoginScene(QWidget *parent = nullptr);
    ~LoginScene();
    MyPushButton *login;
    void keyPressEvent(QKeyEvent *e);
    void onconnect();
    QString message;

private slots:
    void onError();
    void onDisconnected();
    void onReadyRead();

private:
    Ui::LoginScene *ui;
    bool status;//状态
    QTcpSocket tcpsocket;
    QHostAddress serverIP;
    quint16 serverPort;
    QString username;
    ErrorScene *error;
    bool state=false;
    QString countnumber;

};
#endif // LOGINSCENE_H
