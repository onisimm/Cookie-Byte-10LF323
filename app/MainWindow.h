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
    void switchToSettingsScreen();
    void switchToMainMenu();

    void confirmLeaveGame();

private:
    Ui::MainWindow* ui;

    QStackedWidget* stackedWidget;
    QWidget* mainMenuWidget;
    QWidget* gameScreenWidget;
    QWidget* settingsWidget;

    void setupUi();             // Setup the UI of the main window
    void setupConnections();    // Setup signal-slot connections

    bool isGameScreenConnected = false;
    bool isMenuScreenConnected = false;

    void deleteMenuWidgets();
};
