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
    updateUI();
}

void GameScreenWidget::setupConnections()
{
    connect(ui->backToMenuButton, &QPushButton::clicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
    connect(gameBoard, &GameBoardWidget::dotPressed, this, &GameScreenWidget::handleDotPressed);
}

GameScreenWidget::~GameScreenWidget() {
    delete ui;
}

void GameScreenWidget::setupUIPlayers(const Ui::GameSettings& settings) {
    auto setupPlayer = [this](Ui::UIPlayer& playerUI, QLabel* nameLabel, QLabel* timerLabel, const QString& playerName, const uint16_t& timeLimit) {
        playerUI.nameLabel = nameLabel;
        playerUI.nameLabel->setText(playerName);
        playerUI.timerLabel = timerLabel;
        playerUI.timer = new QTimer(this); // Allocate timer with 'this' as parent to ensure proper cleanup
        playerUI.timer->setInterval(timeLimit * 1000); // Convert to milliseconds
        connect(playerUI.timer, &QTimer::timeout, this, [this, &playerUI]() { updateTimer(playerUI); });
        };

    setupPlayer(player1UI, ui->player1NameLabel, ui->player1TimerLabel, settings.player1Name, settings.timeLimit);

    setupPlayer(player2UI, ui->player2NameLabel, ui->player2TimerLabel, settings.player2Name, settings.timeLimit);
}


void GameScreenWidget::updateUI() {
    resetPlayerUI(player1UI);
    resetPlayerUI(player2UI);

    Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI;
    QFont font = activePlayer.nameLabel->font();
    font.setBold(true);
    font.setPointSize(font.pointSize() + 2);
    activePlayer.nameLabel->setFont(font);
    activePlayer.timerLabel->setFont(font);

    activePlayer.timer->start();
    (currentPlayer == 1 ? player2UI : player1UI).timer->stop();
}

void GameScreenWidget::applyGameSettings(const Ui::GameSettings& settings) {
    ui->mainLayout->addWidget(gameBoard);

    setGameboardSize(settings.gameboardSize);
    setMaxDots(settings.maxDots);
    setMaxBridges(settings.maxBridges);
    setGamemode(settings.gamemode);

    gameBoard->buildBoard();
}

void GameScreenWidget::resetPlayerUI(Ui::UIPlayer& player) {
    QFont font = player.nameLabel->font();
    font.setBold(false);
    font.setPointSize(font.pointSize() - 2);
    player.nameLabel->setFont(font);
    player.timerLabel->setFont(font);
}

void GameScreenWidget::updateTimer(Ui::UIPlayer& player) {
    if (player.timeLimit > 0) {
        player.timeLimit--;
        int minutes = player.timeLimit / 60;
        int seconds = player.timeLimit % 60;
        player.timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    }
    else {
        player.timer->stop();
        // TODO winning player
    }
}

void GameScreenWidget::setGameboardSize(const uint8_t& size)
{
    gameBoard->setGameboardSize(size);
    //this->game->setGameBoardSize(size);
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
    //this->game->setGameMode(gamemode);
}

void GameScreenWidget::handleDotPressed(int row, int col) {
    gameBoard->setDotColor(row, col, Qt::red);
    switchPlayer();
}

void GameScreenWidget::switchPlayer() {
    /*isPlayer1CurrentPlayer = isPlayer1CurrentPlayer ? false : true;
    updatePlayerTurnLabel();*/
}