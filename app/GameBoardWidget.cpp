#include "GameBoardWidget.h"
#include "DotWidget.h"
#include <QGridLayout>
#include <QPainter>
#include <QRect>

GameBoardWidget::GameBoardWidget(QWidget* parent) : QWidget(parent) {
    layout = new QGridLayout(this);
    layout->setSpacing(0.5); // Set this to the desired spacing between dots

    // Adjust the margins around the grid
    int marginHorizontal = 5; // Horizontal margin; adjust as needed
    int marginVertical = 5;
    layout->setContentsMargins(marginHorizontal, marginVertical, marginHorizontal, marginVertical);

    for (int row = 0; row < 24; ++row) {
        for (int col = 0; col < 24; ++col) {
            if (!(row == 0 && col == 0) && !(row == 0 && col == 23) &&
                !(row == 23 && col == 0) && !(row == 23 && col == 23)) {
                DotWidget* dot = new DotWidget(this);
                layout->addWidget(dot, row, col);
                connect(dot, &DotWidget::pressedChanged, this, [this, row, col]() {
                    emit dotPressed(row, col);
                });
            }
        }
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
    QRect lastDotRect = layout->itemAtPosition(22, 22)->widget()->geometry();

    int dotWidth = firstDotRect.width();

    // Draw the top border line
    pen.setColor(Qt::red);
    painter.setPen(pen);
    QPoint topLeft(firstDotRect.left(), firstDotRect.top() - (dotWidth / 2));
    QPoint topRight(lastDotRect.right(), firstDotRect.top() - (dotWidth / 2));
    painter.drawLine(topLeft, topRight);

    // Draw the bottom border line
    QPoint bottomLeft(firstDotRect.left(), lastDotRect.bottom() + (dotWidth / 2));
    QPoint bottomRight(lastDotRect.right(), lastDotRect.bottom() + (dotWidth / 2));
    painter.drawLine(bottomLeft, bottomRight);

    // Set pen color for the vertical lines
    pen.setColor(Qt::black);
    painter.setPen(pen);

    // Draw the left border line
    QPoint leftTop(firstDotRect.left() - (dotWidth / 2), firstDotRect.top());
    QPoint leftBottom(firstDotRect.left() - (dotWidth / 2), lastDotRect.bottom());
    painter.drawLine(leftTop, leftBottom);

    // Draw the right border line
    QPoint rightTop(lastDotRect.right() + (dotWidth / 2), firstDotRect.top());
    QPoint rightBottom(lastDotRect.right() + (dotWidth / 2), lastDotRect.bottom());
    painter.drawLine(rightTop, rightBottom);
}

