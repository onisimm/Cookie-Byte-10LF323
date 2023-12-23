#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class gameScreenWidget;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void switchToGameScreen();
    void switchToMainMenu();

private:
    Ui::MainWindow* ui;

    QStackedWidget* stackedWidget;
    QWidget* mainMenuWidget;
    QWidget* gameScreenWidget;

    void setupUi();             // Setup the UI of the main window
    void setupConnections();    // Setup signal-slot connections
};
#endif // MAINWINDOW_H
