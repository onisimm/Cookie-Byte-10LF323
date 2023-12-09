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

private:
    Ui::GameScreenWidget *ui;
};

#endif // GAMESCREENWIDGET_H
