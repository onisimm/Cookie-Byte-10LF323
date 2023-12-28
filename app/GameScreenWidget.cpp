#include "GameScreenWidget.h"
#include "ui_GameScreenWidget.h"
#include "DotWidget.h"

GameScreenWidget::GameScreenWidget(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameScreenWidget),
    gameBoard(new GameBoardWidget(this)) // Initialize the game board
{
    ui->setupUi(this);

    ui->mainLayout->addWidget(gameBoard);

    setupConnections();
}

void GameScreenWidget::setupConnections()
{
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
    connect(gameBoard, &GameBoardWidget::dotPressed, this, &GameScreenWidget::handleDotPressed);
}

GameScreenWidget::~GameScreenWidget() {
    delete ui;
}

void GameScreenWidget::setGamemodeLabel(const QString& gamemode)
{
    ui->gamemodeLabel->setText("Gamemode: " + gamemode);
}

void GameScreenWidget::handleDotPressed(int row, int col, QColor color) {
    gameBoard->setDotColor(row, col, color);
    switchPlayer();
}

void GameScreenWidget::setPlayerTurnLabel(const QString& nickname)
{
    if (nickname.isEmpty()) {
        ui->playerTurnLabel->setText(player1Name + "'s turn");
    }
    else {
        ui->playerTurnLabel->setText(nickname + "'s turn");
    }
}

void GameScreenWidget::switchPlayer() {
    isPlayer1CurrentPlayer = isPlayer1CurrentPlayer ? false : true;
    updatePlayerTurnLabel();
}

void GameScreenWidget::updatePlayerTurnLabel() {
    QString currentPlayerName = isPlayer1CurrentPlayer ? player1Name : player2Name;
    gameBoard->setCurrentPlayer(isPlayer1CurrentPlayer);
    setPlayerTurnLabel(currentPlayerName);
}
