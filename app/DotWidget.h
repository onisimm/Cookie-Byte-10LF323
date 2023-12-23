#pragma once

#include <QWidget>

class DotWidget : public QWidget {
    Q_OBJECT

public:
    explicit DotWidget(QWidget* parent = nullptr);

    bool isPressed() const;
    void setPressed(bool pressed);

signals:
    void pressedChanged(int row, int col);  // Signal to notify when the dot is pressed

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    QColor currentColor;
    bool pressed;
};
