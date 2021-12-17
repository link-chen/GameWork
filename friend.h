#ifndef FRIEND_H
#define FRIEND_H

#include <QToolBox>

namespace Ui {
class Friend;
}

class Friend : public QToolBox
{
    Q_OBJECT

public:
    explicit Friend(QWidget *parent = nullptr);
    ~Friend();

private:
    Ui::Friend *ui;
};

#endif // FRIEND_H
