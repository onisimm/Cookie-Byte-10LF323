#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainmenuwidget.h"
#include "gamescreenwidget.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    :   QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setupUi();
    setupConnections();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    mainMenuWidget = new MainMenuWidget();
    gameScreenWidget = new GameScreenWidget();

    stackedWidget->addWidget(mainMenuWidget);
    stackedWidget->addWidget(gameScreenWidget);

    stackedWidget->setCurrentWidget(mainMenuWidget);
    this->setMinimumSize(mainMenuWidget->frameSize());
}

void MainWindow::setupConnections() {};

