#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    setupConnections();
}

void MainMenuWidget::setupConnections()
{
    connect(ui->playButton, &QPushButton::clicked, this, &MainMenuWidget::on_playButton_clicked);
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

