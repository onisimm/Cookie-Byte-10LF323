#include "BridgeWidget.h"
#include <QPainter>

BridgeWidget::BridgeWidget(QWidget* parent) : QWidget(parent) {}

void BridgeWidget::setPositionAndSize(int startX, int startY, int endX, int endY) {
    // Set geometry based on start and end coordinates
    bridgeRect.setRect(startX, startY, endX - startX, endY - startY);
    setGeometry(bridgeRect);
}

void BridgeWidget::setColor(const QColor& color)
{
    currentColor = color;
	update(); // repaint
}

void BridgeWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(currentColor);
    painter.drawLine(bridgeRect.topLeft(), bridgeRect.bottomRight());
}
