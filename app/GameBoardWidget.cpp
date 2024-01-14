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
            DotWidget* dot = new DotWidget(this, (3000 / gameboardSize) / 12);
            layout->addWidget(dot, row, col);
            connect(dot, &DotWidget::pressedChanged, this, [this, row, col]() {
                emit dotPressed(row, col);
                });
            // Place dots everywhere except the corners of the matrix
            if ((row == 0 && col == 0) || (row == 0 && col == (gameboardSize - 1)) ||
                (row == (gameboardSize - 1) && col == 0) || (row == (gameboardSize - 1) && col == (gameboardSize - 1))) {
                dot->setVisible(false);
                bool isDotVisible = dot->isVisible();
            }
        }
    }

    update();
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

void GameBoardWidget::setPlayer1Color(const QColor& color)
{
    this->player1Color = color;
}

void GameBoardWidget::setPlayer2Color(const QColor& color)
{
    this->player2Color = color;
}

QColor GameBoardWidget::getDotColor(int row, int col) const
{
    QWidget* widget = layout->itemAtPosition(row, col)->widget();
    DotWidget* dot = qobject_cast<DotWidget*>(widget);
    return dot->getColor();
}

void GameBoardWidget::drawBridge(const int& startRow, const int& startCol, const int& endRow, const int& endCol, const QColor& color) {
    // Assume DotWidget size is uniform and calculate the center point for start and end dots
    QRect startDotRect = layout->itemAtPosition(startRow, startCol)->widget()->geometry();
    QRect endDotRect = layout->itemAtPosition(endRow, endCol)->widget()->geometry();
    QPoint startPoint = startDotRect.center();
    QPoint endPoint = endDotRect.center();

    // Create a BridgeWidget or find it if it already exists
    QPair<int, int> startPair = qMakePair(startRow, startCol);
    QPair<int, int> endPair = qMakePair(endRow, endCol);
    BridgeWidget* bridge;

    // Check if the bridge already exists
    if (bridges.contains(startPair) && bridges[startPair] == bridges[endPair]) {
        bridge = bridges[startPair];
    }
    else {
        bridge = new BridgeWidget(this);
        bridge->setObjectName(QStringLiteral("Bridge_%1_%2_to_%3_%4").arg(startRow).arg(startCol).arg(endRow).arg(endCol));
        bridges[startPair] = bridge;
        bridges[endPair] = bridge;
    }

    // Configure the BridgeWidget
    bridge->setStartPosition(startPoint);
    bridge->setEndPosition(endPoint);
    bridge->setLineColor(color);
    bridge->show(); // Make sure the bridge is visible

    update(); // Update the GameBoardWidget to repaint
}

void GameBoardWidget::clearBoard()
{
    // Delete all bridge widgets and remove them from the map
    for (auto bridge : qAsConst(bridges)) {
        bridge->deleteLater();
    }
    bridges.clear();

    // Force the game board widget to update and redraw without the bridges
    update();
}


void GameBoardWidget::deleteBridge(const int& startRow, const int& startCol, const int& endRow, const int& endCol) {
    QPair<int, int> startPair = qMakePair(startRow, startCol);
    QPair<int, int> endPair = qMakePair(endRow, endCol);

    // Check if the bridge exists with the given start and end pair
    if (bridges.contains(startPair) && bridges[startPair] == bridges[endPair]) {
        BridgeWidget* bridge = bridges.take(startPair); // Take the bridge out of the map
        bridge->deleteLater(); // Schedule the bridge for deletion
        bridges.remove(endPair); // Remove the corresponding end pair
    }
    // Check if the bridge exists with the start and end pair reversed
    else if (bridges.contains(endPair) && bridges[endPair] == bridges[startPair]) {
        BridgeWidget* bridge = bridges.take(endPair); // Take the bridge out of the map
        bridge->deleteLater(); // Schedule the bridge for deletion
        bridges.remove(startPair); // Remove the corresponding start pair
    }

    update(); // Ensure the widget is updated to reflect the removal
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
    pen.setColor(player1Color);
    painter.setPen(pen);
    QPoint topLeft(firstDotRect.left(), firstDotRect.top() - (distanceBetweenDots / 2));
    QPoint topRight(lastDotRect.right(), firstDotRect.top() - (distanceBetweenDots / 2));
    painter.drawLine(topLeft, topRight);

    // Draw the bottom border line
    QPoint bottomLeft(firstDotRect.left(), lastDotRect.bottom() + (distanceBetweenDots / 2));
    QPoint bottomRight(lastDotRect.right(), lastDotRect.bottom() + (distanceBetweenDots / 2));
    painter.drawLine(bottomLeft, bottomRight);

    // Set pen color for the vertical lines
    pen.setColor(player2Color);
    painter.setPen(pen);

    // Draw the left border line
    QPoint leftTop(firstDotRect.left() - (distanceBetweenDots / 2), firstDotRect.top());
    QPoint leftBottom(firstDotRect.left() - (distanceBetweenDots / 2), lastDotRect.bottom());
    painter.drawLine(leftTop, leftBottom);

    // Draw the right border line
    QPoint rightTop(lastDotRect.right() + (distanceBetweenDots / 2), firstDotRect.top());
    QPoint rightBottom(lastDotRect.right() + (distanceBetweenDots / 2), lastDotRect.bottom());
    painter.drawLine(rightTop, rightBottom);

    for (auto bridge : bridges) {
		pen.setColor(bridge->getLineColor());
		painter.setPen(pen);
		painter.drawLine(bridge->getStartPosition(), bridge->getEndPosition());
	}
}
