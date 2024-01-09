#pragma once

#include <QWidget>
#include <QGridLayout>
#include "TwixtGame.h"

class GameBoardWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameBoardWidget(QWidget* parent = nullptr);

    void setGameMode(const QString& gamemode);
    void setGameboardSize(const uint8_t& size);
    void setMaxDots(const uint8_t& maxDots);
    void setMaxBridges(const uint8_t& maxBridges);
    void setCurrentPlayer(const bool& turn);
    void setDotColor(int row, int col, const QColor& color);

signals:
    void dotPressed(int row, int col, QColor color);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QGridLayout* layout; // The dots layout (the board UI)
    TwixtGame* game;
    uint8_t gameboardSize;

    bool isPlayer1CurrentPlayer;
    void buildBoard();
};
