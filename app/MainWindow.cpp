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

void MainWindow::updateGameSettings()
{
    if (isGameScreenConnected) {
        uint8_t gameboardSize = static_cast<SettingsWidget*>(settingsWidget)->getGameboardSize();
        static_cast<GameScreenWidget*>(gameScreenWidget)->setGameboardSize(gameboardSize);

        QString gamemode = static_cast<SettingsWidget*>(settingsWidget)->getGamemode();
        static_cast<GameScreenWidget*>(gameScreenWidget)->setGamemode(gamemode);

        QString player1Name = static_cast<SettingsWidget*>(settingsWidget)->getPlayer1Name();
        QString player2Name = static_cast<SettingsWidget*>(settingsWidget)->getPlayer2Name();
        static_cast<GameScreenWidget*>(gameScreenWidget)->setPlayer1Name(player1Name);
        static_cast<GameScreenWidget*>(gameScreenWidget)->setPlayer2Name(player2Name);
        static_cast<GameScreenWidget*>(gameScreenWidget)->setPlayerTurnLabel(); // It will be automatically set to Player1's nickname

        uint8_t maxDots = static_cast<SettingsWidget*>(settingsWidget)->getMaxDots();
        static_cast<GameScreenWidget*>(gameScreenWidget)->setMaxDots(maxDots);

        uint8_t maxBridges = static_cast<SettingsWidget*>(settingsWidget)->getMaxBridges();
        static_cast<GameScreenWidget*>(gameScreenWidget)->setMaxBridges(maxBridges);
    }
}

void MainWindow::switchToGameScreen() {
    if (!isGameScreenConnected) {
        gameScreenWidget = new GameScreenWidget();
        stackedWidget->addWidget(gameScreenWidget);
        isGameScreenConnected = true;

        // Back to Main Menu Button
        connect(static_cast<GameScreenWidget*>(gameScreenWidget), &GameScreenWidget::on_backToMenuButton_clicked, this, &MainWindow::confirmLeaveGame);

        updateGameSettings();

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
