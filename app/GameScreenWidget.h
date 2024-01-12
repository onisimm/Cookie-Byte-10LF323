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
        int timeLimit;  // Time limit for the player in seconds

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

private:
    Ui::GameScreenWidget* ui;
    GameBoardWidget* gameBoard; // The game board UI
    TwixtGame* game; // The game logic
    Ui::UIPlayer player1UI, player2UI;
    uint8_t currentPlayer : 4; // 1 = player 1, 2 = player 2
    uint8_t maxDots;
    uint8_t maxBridges;

    void setupUIPlayers(const Ui::GameSettings& settings);
    void setupConnections();

    void applyGameSettings(const Ui::GameSettings& settings);
    void resetPlayerUI(Ui::UIPlayer& player);
    void updateUI();
    void updateTimer(Ui::UIPlayer& player);

    void switchPlayer();
};