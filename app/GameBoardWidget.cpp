#include "DotWidget.h"
#include "GameBoardWidget.h"
#include <QGridLayout>
#include <QPainter>
#include <QRect>

GameBoardWidget::GameBoardWidget(QWidget* parent) : QWidget(parent) {}

void GameBoardWidget::buildBoard()
{
    layout = new QGridLayout(this);

    layout->setSpacing(0.5); // Spacing between dots

    // Adjust the margins around the grid
    int marginHorizontal = 5; // Horizontal margin; adjust as needed
    int marginVertical = 5;
    layout->setContentsMargins(marginHorizontal, marginVertical, marginHorizontal, marginVertical);

    if (gameboardSize == -1) {
        gameboardSize = 24; // Default gameboard size: 24x24
	}

    for (int row = 0; row < gameboardSize; ++row) {
        for (int col = 0; col < gameboardSize; ++col) {
            // Place dots everywhere except the corners of the matrix
            if (!(row == 0 && col == 0) && !(row == 0 && col == (gameboardSize - 1)) &&
                !(row == (gameboardSize - 1) && col == 0) && !(row == (gameboardSize - 1) && col == (gameboardSize - 1))) {
                DotWidget* dot = new DotWidget(this);
                layout->addWidget(dot, row, col);
                connect(dot, &DotWidget::pressedChanged, this, [this, row, col]() {
                    emit dotPressed(row, col);
                });
            }
        }
    }
}

void GameBoardWidget::setGameboardSize(const uint8_t& size)
{
    this->gameboardSize = size;
}

void GameBoardWidget::setDotColor(int row, int col, const QColor& color)
{
    QWidget* widget = layout->itemAtPosition(row, col)->widget();
    DotWidget* dot = qobject_cast<DotWidget*>(widget);
    if (dot) {
        dot->setColor(color);
    }
}

void GameBoardWidget::drawBridge(const int& startRow, const int& startCol, const int& endRow, const int& endCol, const QColor& color) {
    QPair<int, int> key = qMakePair((startRow << 16) | startCol, (endRow << 16) | endCol);
    if (bridges.contains(key)) {
        return; // Bridge already exists
    }

    QWidget* startDotWidget = layout->itemAtPosition(startRow, startCol)->widget();
    QWidget* endDotWidget = layout->itemAtPosition(endRow, endCol)->widget();

    QRect startRect = startDotWidget->geometry();
    QRect endRect = endDotWidget->geometry();

    BridgeWidget* bridge = new BridgeWidget(this);
    bridge->setPositionAndSize(startRect.center().x(), startRect.center().y(),
        endRect.center().x(), endRect.center().y());
    bridge->show();

    bridges.insert(key, bridge);

    bridge->setColor(color);
}

void GameBoardWidget::deleteBridge(const int& startRow, const int& startCol, const int& endRow, const int& endCol) {
    QPair<int, int> key = qMakePair((startRow << 16) | startCol, (endRow << 16) | endCol);
    BridgeWidget* bridge = bridges.value(key, nullptr);
    if (bridge) {
        bridge->deleteLater();
        bridges.remove(key);
    }
}

void GameBoardWidget::paintEvent(QPaintEvent* event) {
    QWidget::paintEvent(event);  // Call the superclass paintEvent

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Set the pen for drawing the lines
    QPen pen;
    pen.setWidth(2); // Set the line width
    painter.setPen(pen);

    // Get the actual positions of the dot widgets
    QRect firstDotRect = layout->itemAtPosition(1, 1)->widget()->geometry();
    QRect lastDotRect = layout->itemAtPosition(gameboardSize - 2, gameboardSize - 2)->widget()->geometry();
    QRect secondDotRect = layout->itemAtPosition(1, 2)->widget()->geometry();
    int dotWidth = firstDotRect.width();

    int distanceBetweenDots = secondDotRect.left() - firstDotRect.left() + dotWidth - (2*firstDotRect.width());
    //int distanceBetweenDots = secondDotRect.left() - firstDotRect.left() + dotWidth;

    // Draw the top border line
    pen.setColor(Qt::red);
    painter.setPen(pen);
    QPoint topLeft(firstDotRect.left(), firstDotRect.top() - (distanceBetweenDots / 2));
    QPoint topRight(lastDotRect.right(), firstDotRect.top() - (distanceBetweenDots / 2));
    painter.drawLine(topLeft, topRight);

    // Draw the bottom border line
    QPoint bottomLeft(firstDotRect.left(), lastDotRect.bottom() + (distanceBetweenDots / 2));
    QPoint bottomRight(lastDotRect.right(), lastDotRect.bottom() + (distanceBetweenDots / 2));
    painter.drawLine(bottomLeft, bottomRight);

    // Set pen color for the vertical lines
    pen.setColor(Qt::black);
    painter.setPen(pen);

    // Draw the left border line
    QPoint leftTop(firstDotRect.left() - (distanceBetweenDots / 2), firstDotRect.top());
    QPoint leftBottom(firstDotRect.left() - (distanceBetweenDots / 2), lastDotRect.bottom());
    painter.drawLine(leftTop, leftBottom);

    // Draw the right border line
    QPoint rightTop(lastDotRect.right() + (distanceBetweenDots / 2), firstDotRect.top());
    QPoint rightBottom(lastDotRect.right() + (distanceBetweenDots / 2), lastDotRect.bottom());
    painter.drawLine(rightTop, rightBottom);
}
