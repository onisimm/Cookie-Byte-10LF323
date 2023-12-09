#ifndef MAINMENUWIDGET_H
#define MAINMENUWIDGET_H

#include <QWidget>

namespace Ui {
class MainMenuWidget;
}

class MainMenuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuWidget(QWidget *parent = nullptr);
    ~MainMenuWidget();

signals:
    void on_playButton_clicked();

private:
    Ui::MainMenuWidget *ui;

    void setupConnections();    // Setup signal-slot connections
};

#endif // MAINMENUWIDGET_H
