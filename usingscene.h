#ifndef USINGSCENE_H
#define USINGSCENE_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>
#include<QLabel>
#include<QTimer>
#include<QMessageBox>
#include<QUrl>
#include<QKeyEvent>
#include<QLineEdit>
#include<QCheckBox>
#include<QVector>
#include<QToolButton>
#include<QtSql/QSqlQuery>
#include<QMenuBar>

#include"enterspace.h"

namespace Ui {
class UsingScene;
}

class UsingScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsingScene(QWidget *parent = nullptr,QString username=NULL,QString countnumber1=NULL);
    ~UsingScene();

public slots:

signals:

private:
    Ui::UsingScene *ui;
};

#endif // USINGSCENE_H
