#ifndef GAMESCREENWIDGET_H
#define GAMESCREENWIDGET_H

#include <QWidget>
#include "GameBoardWidget.h"

namespace Ui {
class GameScreenWidget;
}

class GameScreenWidget : public QWidget {
    Q_OBJECT

public:
    explicit GameScreenWidget(QWidget *parent = nullptr);
    ~GameScreenWidget();

signals:
    void on_backToMenuButton_clicked();

private:
    Ui::GameScreenWidget *ui;
    GameBoardWidget *gameBoard; // Pointer to the GameBoardWidget
    void setupConnections();
};

#endif // GAMESCREENWIDGET_H
