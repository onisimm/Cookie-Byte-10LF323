#ifndef GAMEBOARDWIDGET_H
#define GAMEBOARDWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "DotWidget.h" // Make sure to include the header for DotWidget

class GameBoardWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameBoardWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QGridLayout *layout; // The layout for the dots
};

#endif // GAMEBOARDWIDGET_H
