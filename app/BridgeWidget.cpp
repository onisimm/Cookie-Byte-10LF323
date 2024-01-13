#include "BridgeWidget.h"

BridgeWidget::BridgeWidget(QWidget* parent) : QWidget(parent), lineColor(Qt::black) {}

void BridgeWidget::setStartPosition(const QPoint& startPos) {
    startPosition = startPos;
}

void BridgeWidget::setEndPosition(const QPoint& endPos) {
    endPosition = endPos;
}

void BridgeWidget::setLineColor(const QColor& color) {
    lineColor = color;
}

QColor BridgeWidget::getLineColor() const
{
    return lineColor;
}

QPoint BridgeWidget::getStartPosition() const
{
    return startPosition;
}

QPoint BridgeWidget::getEndPosition() const
{
    return endPosition;
}

void BridgeWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen pen(lineColor, 2); // Line width 2, can be adjusted as needed
    painter.setPen(pen);
    painter.drawLine(startPosition, endPosition);
}