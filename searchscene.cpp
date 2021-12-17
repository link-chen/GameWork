#include "searchscene.h"
#include "ui_searchscene.h"

SearchScene::SearchScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SearchScene)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    this->setWindowTitle("查找");
}

SearchScene::~SearchScene()
{
    delete ui;
}
