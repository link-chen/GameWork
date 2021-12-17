#ifndef TALKING_H
#define TALKING_H

#include <QMainWindow>
#include<QPushButton>
#include<QTcpServer>
#include<QTcpSocket>
#include<QLabel>
#include<QLineEdit>
#include<QToolBar>
#include<QTextEdit>
#include<QKeyEvent>

namespace Ui {
class Talking;
}

class Talking : public QMainWindow
{
    Q_OBJECT

public:
    explicit Talking(QWidget *parent = nullptr,QString tousername1=NULL,QString countnumber=NULL,QString username=NULL,QString fromcount1=NULL);
    ~Talking();
    QPushButton *send;
    void addmessage(QString string);
    bool status();
    void change();

private slots:

private:
    Ui::Talking *ui;
    QTcpSocket tcpsocket;
    QHostAddress serverIP;
    quint16 serverPort;
    QString tousername;
    bool state=false;
    QString countnumber;
    QString fromcount;
    bool open=false;
    QTextEdit *talk;

};

#endif // TALKING_H
