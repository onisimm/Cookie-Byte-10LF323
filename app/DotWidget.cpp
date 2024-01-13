#include "DotWidget.h"
#include <QMouseEvent>
#include <QPainter>

DotWidget::DotWidget(QWidget* parent)
    : QWidget(parent), currentColor(Qt::lightGray) {
    setFixedSize(9, 9);  // Adjust size to be smaller
}

DotWidget::DotWidget(QWidget* parent, const uint8_t& size) : QWidget(parent), currentColor(Qt::lightGray)
{
	setFixedSize(size, size);
}

void DotWidget::mousePressEvent(QMouseEvent* event) {
    emit pressedChanged();
    QWidget::mousePressEvent(event);
}

void DotWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(currentColor));
    int margin = 2; // Margin for the ellipse border
    QRect dotRect = rect().adjusted(margin, margin, -margin, -margin);
    painter.drawEllipse(dotRect);
}

void DotWidget::setColor(const QColor& color) {
    currentColor = color;
    update(); // repaint
}

QColor DotWidget::getColor() const
{
    return currentColor;
}
