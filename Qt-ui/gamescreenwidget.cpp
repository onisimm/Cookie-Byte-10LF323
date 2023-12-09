#include "gamescreenwidget.h"
#include "ui_gamescreenwidget.h"

GameScreenWidget::GameScreenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScreenWidget)
{
    ui->setupUi(this);
}

GameScreenWidget::~GameScreenWidget()
{
    delete ui;
}
