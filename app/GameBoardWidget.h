#pragma once

#include "BridgeWidget.h"
#include <QGridLayout>
#include <QWidget>

class GameBoardWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameBoardWidget(QWidget* parent = nullptr);

    void buildBoard();

    void setGameboardSize(const uint8_t& size);
    void setDotColor(int row, int col, const QColor& color);
    void setPlayer1Color(const QColor& color);
    void setPlayer2Color(const QColor& color);

    QColor getDotColor(int row, int col) const;

    void drawBridge(const int& startRow, const int& startCol, const int& endRow, const int& endCol, const QColor& color);
    void deleteBridges();
    void deleteBridge(const int& startRow, const int& startCol, const int& endRow, const int& endCol);

signals:
    void dotPressed(int row, int col);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QGridLayout* layout; // The dots layout (the board UI)
    QMap<QPair<int, int>, BridgeWidget*> bridges; // The bridges layout (the bridges UI)
    uint8_t gameboardSize = -1; // Value -1 means the gameboard size has not been initialized yet
    QColor player1Color = Qt::red;
    QColor player2Color = Qt::blue;
};
