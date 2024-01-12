#include "GameScreenWidget.h"
#include "ui_GameScreenWidget.h"
#include <QTimer>

GameScreenWidget::GameScreenWidget(const Ui::GameSettings& settings, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameScreenWidget),
    gameBoard(new GameBoardWidget(this)),
    game(new TwixtGame()),
    currentPlayer(1) {  // Assuming Player 1 starts first

    ui->setupUi(this);
    setupUIPlayers(settings);
    applyGameSettings(settings);
    setupConnections();
    updateUIBasedOnPlayerTurn();
}

GameScreenWidget::~GameScreenWidget() {
    delete ui;
}

void GameScreenWidget::setupUIPlayers(const Ui::GameSettings& settings) {
    auto setupPlayer = [this](Ui::UIPlayer& playerUI, QLabel* nameLabel, QLabel* timerLabel,
        const QString& playerName, const uint16_t& timeLimit) {
            playerUI.nameLabel = nameLabel;
            playerUI.nameLabel->setText(playerName);

            playerUI.timerLabel = timerLabel;
            playerUI.timer = new QTimer(this);
            playerUI.timer->setInterval(1000);
            int minutes = timeLimit / 60;
            int seconds = timeLimit % 60;
            playerUI.timeLimit = timeLimit;
            playerUI.timeLeft = timeLimit;
            playerUI.timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));

            connect(playerUI.timer, &QTimer::timeout, this, [this, &playerUI]() { updateTimer(playerUI); });
        };

    setupPlayer(player1UI, ui->player1NameLabel, ui->player1TimerLabel, settings.player1Name, settings.timeLimit);

    setupPlayer(player2UI, ui->player2NameLabel, ui->player2TimerLabel, settings.player2Name, settings.timeLimit);

    initialPlayerFont = player1UI.nameLabel->font();
}


void GameScreenWidget::applyGameSettings(const Ui::GameSettings& settings) {
    ui->mainLayout->addWidget(gameBoard);

    setGameboardSize(settings.gameboardSize);
    setMaxDots(settings.maxDots);
    setMaxBridges(settings.maxBridges);
    setGamemode(settings.gamemode);

    gameBoard->buildBoard();
}

void GameScreenWidget::setupConnections()
{
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
    connect(gameBoard, &GameBoardWidget::dotPressed, this, &GameScreenWidget::handleDotPressed);
    connect(ui->switchTurnButton, &QPushButton::clicked, this, &GameScreenWidget::switchPlayer);
}

void GameScreenWidget::updateUIBasedOnPlayerTurn() {}

void GameScreenWidget::updateTimer(Ui::UIPlayer& player) {
    if (player.timeLeft > 0) {
        player.timeLeft--;
        int minutes = player.timeLeft / 60;
        int seconds = player.timeLeft % 60;
        player.timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    }
    else {
        player.timer->stop();
        // TODO: Handle time up situation
    }
}

void GameScreenWidget::setGameboardSize(const uint8_t& size)
{
    gameBoard->setGameboardSize(size);
    this->game->setGameBoardSize(size);
}

void GameScreenWidget::setMaxDots(const uint8_t& maxDots)
{
    this->maxDots = maxDots;
}

void GameScreenWidget::setMaxBridges(const uint8_t& maxBridges)
{
    this->maxBridges = maxBridges;
}

void GameScreenWidget::setGamemode(const QString& gamemode)
{
    ui->gamemodeLabel->setText("Gamemode: " + gamemode);
    //gameBoard->setGameMode(gamemode);
    this->game->setGameMode(gamemode);
}

void GameScreenWidget::handleDotPressed(int row, int col) {
    gameBoard->setDotColor(row, col, Qt::red);
}

void GameScreenWidget::switchPlayer() {
    // TOOD be able to press it only after a player has made a move
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    updateUIBasedOnPlayerTurn();
}