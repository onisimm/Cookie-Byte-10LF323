#include "gamescreenwidget.h"
#include "ui_gamescreenwidget.h"

GameScreenWidget::GameScreenWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScreenWidget)
{
    ui->setupUi(this);
    setupConnections();
}

void GameScreenWidget::setupConnections()
{
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
}

GameScreenWidget::~GameScreenWidget()
{
    delete ui;
}

