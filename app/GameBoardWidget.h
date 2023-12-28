#pragma once

#include <QWidget>
#include <QGridLayout>

class GameBoardWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameBoardWidget(QWidget* parent = nullptr);

signals:
    void dotPressed(int row, int col);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QGridLayout* layout; // The layout for the dots
};
