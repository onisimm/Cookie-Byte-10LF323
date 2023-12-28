#pragma once

#include <QWidget>

class DotWidget : public QWidget {
    Q_OBJECT

public:
    explicit DotWidget(QWidget* parent = nullptr);

    bool isPressed() const;
    void setPressed(bool pressed);

signals:
    void pressedChanged();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    QColor currentColor;
    bool pressed = false;
};
