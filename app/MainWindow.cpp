#include "./ui_mainwindow.h"
#include "gamescreenwidget.h"
#include "mainmenuwidget.h"
#include "mainwindow.h"
#include "settingsWidget.h"
#include <QMessageBox>
#include <QStackedWidget>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setupUi();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUi() {
    stackedWidget = new QStackedWidget(this);
    setCentralWidget(stackedWidget);

    switchToMainMenu();
    this->setMinimumSize(mainMenuWidget->frameSize());
}

void MainWindow::deleteMenuWidgets()
{
    delete mainMenuWidget;
    stackedWidget->removeWidget(mainMenuWidget);
    delete settingsWidget;
    stackedWidget->removeWidget(settingsWidget);
    isMenuScreenConnected = false;
}

void MainWindow::switchToGameScreen() {
    if (!isGameScreenConnected) {
        Ui::GameSettings settings;
        settings.player1Name = static_cast<SettingsWidget*>(settingsWidget)->getPlayer1Name();
        settings.player2Name = static_cast<SettingsWidget*>(settingsWidget)->getPlayer2Name();
        settings.timeLimit = static_cast<SettingsWidget*>(settingsWidget)->getTimeLimit();
        settings.gamemode = static_cast<SettingsWidget*>(settingsWidget)->getGamemode();
        settings.gameboardSize = static_cast<SettingsWidget*>(settingsWidget)->getGameboardSize();
        settings.maxDots = static_cast<SettingsWidget*>(settingsWidget)->getMaxDots();
        settings.maxBridges = static_cast<SettingsWidget*>(settingsWidget)->getMaxBridges();

        gameScreenWidget = new GameScreenWidget(settings);
        stackedWidget->addWidget(gameScreenWidget);
        isGameScreenConnected = true;

        // Back to Main Menu Button
        connect(static_cast<GameScreenWidget*>(gameScreenWidget), &GameScreenWidget::on_backToMenuButton_clicked, this, &MainWindow::confirmLeaveGame);

        stackedWidget->setCurrentWidget(gameScreenWidget);
    }
}

void MainWindow::switchToSettingsScreen() {
    connect(static_cast<SettingsWidget*>(settingsWidget), &SettingsWidget::on_backToMenuButton_clicked, this, &MainWindow::switchToMainMenu);
    stackedWidget->setCurrentWidget(settingsWidget);
}

void MainWindow::switchToMainMenu() {
    if (!isMenuScreenConnected) {
        mainMenuWidget = new MainMenuWidget();
        stackedWidget->addWidget(mainMenuWidget);
        isMenuScreenConnected = true;
        settingsWidget = new SettingsWidget();
        stackedWidget->addWidget(settingsWidget);

        // Play button
        connect(static_cast<MainMenuWidget*>(mainMenuWidget), &MainMenuWidget::on_playButton_clicked, this, &MainWindow::switchToGameScreen);

        // Settings button
        connect(static_cast<MainMenuWidget*>(mainMenuWidget), &MainMenuWidget::on_settingsButton_clicked, this, &MainWindow::switchToSettingsScreen);
    }

    stackedWidget->setCurrentWidget(mainMenuWidget);


    if (isGameScreenConnected) {
        disconnect(static_cast<GameScreenWidget*>(gameScreenWidget), &GameScreenWidget::on_backToMenuButton_clicked, this, &MainWindow::confirmLeaveGame);
        delete gameScreenWidget;
        stackedWidget->removeWidget(gameScreenWidget);
        isGameScreenConnected = false;
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
