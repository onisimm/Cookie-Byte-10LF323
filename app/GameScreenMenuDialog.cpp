#include "GameScreenMenuDialog.h"
#include <QPushButton>

GameScreenMenuDialog::GameScreenMenuDialog(QWidget* parent) : QDialog(parent), ui(new Ui::GameScreenMenuDialog) {
    ui->setupUi(this);
    setupConnections();
}

GameScreenMenuDialog::~GameScreenMenuDialog() {
    delete ui;
}

void GameScreenMenuDialog::setupConnections() {
    connect(ui->backToGameButton, &QPushButton::clicked, this, &GameScreenMenuDialog::backToGameButtonClicked);

    connect(ui->resetButton, &QPushButton::clicked, this, &GameScreenMenuDialog::resetGameButtonClicked);

    connect(ui->backToMainMenuButton, &QPushButton::clicked, this, &GameScreenMenuDialog::backToMenuButtonClicked);
}