#pragma once

#include <QGridLayout>
#include <QWidget>

class GameBoardWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameBoardWidget(QWidget* parent = nullptr);

    void setGameboardSize(const uint8_t& size);
    void setDotColor(int row, int col, const QColor& color);
    void buildBoard();

signals:
    void dotPressed(int row, int col);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QGridLayout* layout; // The dots layout (the board UI)
    uint8_t gameboardSize = -1; // Value -1 means the gameboard size has not been initialized yet
};
