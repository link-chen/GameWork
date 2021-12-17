#ifndef ERRORSCENE_H
#define ERRORSCENE_H

#include <QMainWindow>
#include <QPushButton>

class ErrorScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ErrorScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *e);
    QPushButton *backBtn;

signals:
    void back();

};

#endif // ERRORSCENE_H
