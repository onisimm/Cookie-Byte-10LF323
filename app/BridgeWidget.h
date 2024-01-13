#pragma once

#include <QWidget>

class BridgeWidget : public QWidget {
    Q_OBJECT

public:
    explicit BridgeWidget(QWidget* parent = nullptr);

    void setPositionAndSize(int startX, int startY, int endX, int endY);
    void setColor(const QColor& color);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QColor currentColor;
    QRect bridgeRect;
};
