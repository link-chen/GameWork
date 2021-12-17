#ifndef ENTERSPACE_H
#define ENTERSPACE_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QTimer>
#include<QMessageBox>
#include<QUrl>
#include<QKeyEvent>
#include<QLineEdit>
#include<QCheckBox>

namespace Ui {
class EnterSpace;
}

class EnterSpace : public QMainWindow
{
    Q_OBJECT

public:
    explicit EnterSpace(QWidget *parent = nullptr,QString username=NULL,QString countnumber=NULL);
    ~EnterSpace();
    void keyPressEvent(QKeyEvent *e);

private slots:
    //建立连接按钮
    void on_pushButton_2_clicked();
    //发送消息
    void on_pushButton_clicked();
    //
    void onConnect();

    //
    void onDisconnect();

    //
    void onReadyRead();

    //
    void onError();

private:
    Ui::EnterSpace *ui;
    bool status;//状态
    QTcpSocket tcpsocket;
    QHostAddress serverIP;
    quint16 serverPort;
    QString username1;

};

#endif // ENTERSPACE_H
