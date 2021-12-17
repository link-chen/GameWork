#ifndef SEARCHSCENE_H
#define SEARCHSCENE_H

#include <QMainWindow>
#include<QTcpSocket>
#include<QTcpServer>
#include<QUrl>
#include<QLineEdit>

namespace Ui {
class SearchScene;
}

class SearchScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit SearchScene(QWidget *parent = nullptr);
    ~SearchScene();

private:
    Ui::SearchScene *ui;
};

#endif // SEARCHSCENE_H
