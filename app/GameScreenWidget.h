#pragma once

#include "GameBoardWidget.h"
#include "TwixtGame.h"
#include <QWidget>
#include <QLabel>
#include <QTimer>

namespace Ui {
    class GameScreenWidget;

    struct GameSettings {
        QString player1Name;
        QString player2Name;
        uint16_t timeLimit;
        QString gamemode;
        uint8_t gameboardSize;
        uint8_t maxDots;
        uint8_t maxBridges;
    };

    using Player = twixt::Player;

    struct UIPlayer {
        QLabel* nameLabel;
        QLabel* timerLabel;
        QTimer* timer;
        QColor color;
        uint16_t timeLimit;  // Time limit for the player in seconds
        uint16_t timeLeft;  // Time left for the player in seconds

        twixt::Player* backendPlayer; // Pointer to the backend Player object
    };
}

class GameScreenWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameScreenWidget(const Ui::GameSettings& settings, QWidget* parent = nullptr);
    ~GameScreenWidget();

    void handleDotPressed(int row, int col);

    void setGameboardSize(const uint8_t& size);
    void setMaxDots(const uint8_t& maxDots);
    void setMaxBridges(const uint8_t& maxBridges);
    void setGamemode(const QString& gamemode);

signals:
    void on_backToMenuButton_clicked();

public slots:
    void switchTurns();

private:
    Ui::GameScreenWidget* ui;
    GameBoardWidget* gameBoard; // The game board UI
    TwixtGame* backendGame; // The game logic
    Ui::UIPlayer player1UI, player2UI;
    QFont initialPlayerFont;
    uint8_t currentPlayer : 4; // 1 = player 1, 2 = player 2
    uint8_t maxDots;
    uint8_t maxBridges;

    // Used to check if the Switch Player button is available
    // The button isn't available if:
    //  1. The current player hasn't placed a dot yet
    //  2. The current player is in the middle of placing a bridge
    bool ableToSwitchTurns = false;
    bool ableToBuildBridges = false; // will be true if the current player has placed a dot
    std::tuple<uint8_t, uint8_t> firstDotForBridge = { 0, 0 };
    std::tuple<uint8_t, uint8_t> secondDotForBridge = { 0, 0 };

    void setupUIPlayers(const Ui::GameSettings& settings);
    void setupConnections();

    void applyGameSettings(const Ui::GameSettings& settings);
    void updateUIBasedOnPlayerTurn();
    void updateTimer(Ui::UIPlayer& player);

    bool isGameOver = false;
    void checkEndGame();
};