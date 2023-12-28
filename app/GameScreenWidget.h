#pragma once

#include <QWidget>
#include "GameBoardWidget.h"

namespace Ui {
    class GameScreenWidget;
}

class GameScreenWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameScreenWidget(QWidget* parent = nullptr);
    ~GameScreenWidget();

    void setGamemodeLabel(const QString& gamemode);

    void handleDotPressed(int row, int col, QColor color);

    void setPlayer1Name(const QString& nickname) { player1Name = nickname; }
    void setPlayer2Name(const QString& nickname) { player2Name = nickname; }
    void setPlayerTurnLabel(const QString& nickname = "");

    QString getPlayer1Name() const { return player1Name; }
    QString getPlayer2Name() const { return player2Name; }

signals:
    void on_backToMenuButton_clicked();

private:
    Ui::GameScreenWidget* ui;
    GameBoardWidget* gameBoard;
    QString player1Name;
    QString player2Name;
    bool isPlayer1CurrentPlayer; // currentPlayer variable -> true for player1, false for player2

    void setupConnections();
    void switchPlayer();
    void updatePlayerTurnLabel();
};