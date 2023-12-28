#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mainmenuwidget.h"
#include "gamescreenwidget.h"
#include "settingsWidget.h"
#include <QStackedWidget>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
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
    settingsWidget = new SettingsWidget();

    stackedWidget->addWidget(mainMenuWidget);
    stackedWidget->addWidget(gameScreenWidget);
    stackedWidget->addWidget(settingsWidget);

    stackedWidget->setCurrentWidget(mainMenuWidget);
    this->setMinimumSize(mainMenuWidget->frameSize());
}

void MainWindow::setupConnections() {
    // Play button
    connect(static_cast<MainMenuWidget*>(mainMenuWidget), &MainMenuWidget::on_playButton_clicked, this, &MainWindow::switchToGameScreen);

    // Settings button
    connect(static_cast<MainMenuWidget*>(mainMenuWidget), &MainMenuWidget::on_settingsButton_clicked, this, &MainWindow::switchToSettingsScreen);
};

void MainWindow::switchToGameScreen() {
    stackedWidget->setCurrentWidget(gameScreenWidget);

    if (!isGameScreenConnected) {
        connect(static_cast<GameScreenWidget*>(gameScreenWidget), &GameScreenWidget::on_backToMenuButton_clicked, this, &MainWindow::confirmLeaveGame);
        isGameScreenConnected = true;
    }
}

void MainWindow::switchToSettingsScreen() {
    stackedWidget->setCurrentWidget(settingsWidget);

    if (!isSettingsScreenConnected) {
        connect(static_cast<SettingsWidget*>(settingsWidget), &SettingsWidget::on_backToMenuButton_clicked, this, &MainWindow::switchToMainMenu);
        isSettingsScreenConnected = true;
    }
}

void MainWindow::switchToMainMenu() {
    stackedWidget->setCurrentWidget(mainMenuWidget);

    if (isGameScreenConnected) {
        disconnect(static_cast<GameScreenWidget*>(gameScreenWidget), &GameScreenWidget::on_backToMenuButton_clicked, this, &MainWindow::confirmLeaveGame);
        isGameScreenConnected = false;
    }

    if (isSettingsScreenConnected) {
        disconnect(static_cast<SettingsWidget*>(settingsWidget), &SettingsWidget::on_backToMenuButton_clicked, this, &MainWindow::switchToMainMenu);
        isSettingsScreenConnected = false;
    }

}

void MainWindow::confirmLeaveGame() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Are you sure you want to leave the game?\nAll your progress will be lost.",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        switchToMainMenu();
    }

    return;
}