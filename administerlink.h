#ifndef ADMINISTERLINK_H
#define ADMINISTERLINK_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QToolBar>
#include<QTextEdit>

namespace Ui {
class AdministerLink;
}

class AdministerLink : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministerLink(QWidget *parent = nullptr,QString username1=NULL,QString countnumber1=NULL);
    ~AdministerLink();

private slots:

private:
    Ui::AdministerLink *ui;
    QTcpSocket tcpsocket;
    QHostAddress serverIP;
    quint16 serverPort;
    QString username;
    bool state=false;
    QString countnumber;

};

#endif // ADMINISTERLINK_H
