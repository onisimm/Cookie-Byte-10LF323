#pragma once

#include <QWidget>
#include <QGridLayout>

class GameBoardWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameBoardWidget(QWidget* parent = nullptr);

    void setCurrentPlayer(const bool& turn);
    void setDotColor(int row, int col, const QColor& color);

signals:
    void dotPressed(int row, int col, QColor color);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QGridLayout* layout; // The layout for the dots
    bool isPlayer1CurrentPlayer;
};
