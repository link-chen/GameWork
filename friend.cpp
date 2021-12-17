#include "friend.h"
#include "ui_friend.h"

Friend::Friend(QWidget *parent) :
    QToolBox(parent),
    ui(new Ui::Friend)
{
    ui->setupUi(this);
}

Friend::~Friend()
{
    delete ui;
}
