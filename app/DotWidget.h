#pragma once

#include <QWidget>

class DotWidget : public QWidget {
    Q_OBJECT

public:
    explicit DotWidget(QWidget* parent = nullptr);

    void setColor(const QColor& color);
    QColor getColor() const;

signals:
    void pressedChanged();

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;

private:
    QColor currentColor;
};
