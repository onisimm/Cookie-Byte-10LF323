#pragma once

#include <QDialog>
#include "ui_GameScreenMenuDialog.h" // Include generated UI header file

namespace Ui {
	class GameScreenMenuDialog;
}

class GameScreenMenuDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameScreenMenuDialog(QWidget* parent = nullptr);
    ~GameScreenMenuDialog();
signals:
    void backToMenuButtonClicked();
    void resetGameButtonClicked();
    void backToGameButtonClicked();


private:
    Ui::GameScreenMenuDialog* ui; // Pointer to the UI class
    void setupConnections();
};
