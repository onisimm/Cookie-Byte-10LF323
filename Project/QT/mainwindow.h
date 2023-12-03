#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDefaultButtonClicked();
    void onBulldozerButtonClicked();
    void onMinesButtonClicked();

private:
    // UI components
    QLabel *titleLabel;
    QPushButton *defaultButton;
    QPushButton *bulldozerButton;
    QPushButton *minesButton;

    // Private methods
    void createUI();
    void setupConnections();
};

#endif // MAINWINDOW_H
