// DotWidget.cpp
#include "DotWidget.h"
#include <QPainter>
#include <QMouseEvent>

DotWidget::DotWidget(QWidget* parent)
    : QWidget(parent), currentColor(Qt::lightGray), pressed(false) {
    setFixedSize(9, 9);  // Adjust size to be smaller
}

bool DotWidget::isPressed() const {
    return pressed;
}

void DotWidget::setPressed(bool pressed) {
    if (!isPressed() && pressed) {
        this->pressed = true;
        currentColor = Qt::black;
        update(); // Trigger a repaint whenever the state changes
        emit pressedChanged();
    }
}

void DotWidget::mousePressEvent(QMouseEvent* event) {
    setPressed(true);
    QWidget::mousePressEvent(event);
}

void DotWidget::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    // The ellipse now fills the smaller widget while maintaining a border.
    painter.setBrush(QBrush(currentColor));
    int margin = 2; // Margin for the ellipse border
    QRect dotRect = rect().adjusted(margin, margin, -margin, -margin);
    painter.drawEllipse(dotRect);
}

void DotWidget::setColor(const QColor& color) {
    currentColor = color;
    update();
}
