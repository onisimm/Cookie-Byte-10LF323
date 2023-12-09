#include "mainmenuwidget.h"
#include "ui_mainmenuwidget.h"
#include <iostream>

MainMenuWidget::MainMenuWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenuWidget)
{
    ui->setupUi(this);
    setupConnections();
}

void MainMenuWidget::setupConnections()
{
    connect(ui->playButton, &QPushButton::clicked, this, &MainMenuWidget::playButtonClicked);
}

MainMenuWidget::~MainMenuWidget()
{
    delete ui;
}

