#pragma once

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QPoint>

class BridgeWidget : public QWidget {
    Q_OBJECT

public:
    explicit BridgeWidget(QWidget* parent = nullptr);

    void setStartPosition(const QPoint& startPos);
    void setEndPosition(const QPoint& endPos);
    void setLineColor(const QColor& color);

    QColor getLineColor() const;
    QPoint getStartPosition() const;
    QPoint getEndPosition() const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QPoint startPosition;
    QPoint endPosition;
    QColor lineColor;
};