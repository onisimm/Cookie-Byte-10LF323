#ifndef GAMESCREENWIDGET_H
#define GAMESCREENWIDGET_H

#include <QWidget>

namespace Ui {
class GameScreenWidget;
}

class GameScreenWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameScreenWidget(QWidget *parent = nullptr);
    ~GameScreenWidget();

signals:
    void on_backToMenuButton_clicked();

private:
    Ui::GameScreenWidget *ui;

    void setupConnections();    // Setup signal-slot connections
};

#endif // GAMESCREENWIDGET_H
