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

void GameScreenWidget::setupUIPlayers(const Ui::GameSettings& settings) {
    auto setupPlayer = [this](Ui::UIPlayer& playerUI, QLabel* nameLabel, QLabel* timerLabel,
        const QString& playerName, const uint16_t& timeLimit, const QColor& color) {
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

            playerUI.color = color;

            QPalette palette;
            palette.setColor(QPalette::WindowText, color);  // Set text color
            playerUI.nameLabel->setPalette(palette);
            playerUI.timerLabel->setPalette(palette);

            connect(playerUI.timer, &QTimer::timeout, this, [this, &playerUI]() { updateTimer(playerUI); });

            // TODO create a Player object and set the backendPlayer pointer to it, and initialize the Player object
        };

    setupPlayer(player1UI, ui->player1NameLabel, ui->player1TimerLabel, settings.player1Name, settings.timeLimit, Qt::red);

    setupPlayer(player2UI, ui->player2NameLabel, ui->player2TimerLabel, settings.player2Name, settings.timeLimit, Qt::black);

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

void GameScreenWidget::updateUIBasedOnPlayerTurn() {
    Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI;
    Ui::UIPlayer& inactivePlayer = (currentPlayer == 1) ? player2UI : player1UI;
    
    QFont font = initialPlayerFont;
    font.setBold(true);
    font.setPointSize(initialPlayerFont.pointSize() + 3);
    activePlayer.nameLabel->setFont(font);
    font.setPointSize(initialPlayerFont.pointSize() + 1);
    activePlayer.timerLabel->setFont(font);
    
    font = initialPlayerFont;
    inactivePlayer.nameLabel->setFont(initialPlayerFont);
    font.setPointSize(initialPlayerFont.pointSize() - 2); // the timer label is smaller than the name label with 2pt always
    inactivePlayer.timerLabel->setFont(initialPlayerFont);

    activePlayer.timer->start();
    inactivePlayer.timer->stop();

    ableToSwitchPlayer = false;
}

void GameScreenWidget::updateTimer(Ui::UIPlayer& player) {
    if (player.timeLeft > 0) {
        player.timeLeft--;
        int minutes = player.timeLeft / 60;
        int seconds = player.timeLeft % 60;
        player.timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));
    }
    else {
        player.timer->stop();
        endGame();
    }
}

void GameScreenWidget::endGame()
{
    // TODO check if there is a winner based on a full path of bridges
    // TODO check if there is a tie

    // check if there is a player with no more time left
    if (player1UI.timeLeft == 0) {
        ui->gameMessageLabel->setText(player1UI.nameLabel->text() + " ran out of time. " 
            + player2UI.nameLabel->text() + " wins!");
        isGameOver = true;
    }
    else if (player2UI.timeLeft == 0) {
        ui->gameMessageLabel->setText(player2UI.nameLabel->text() + " ran out of time. "
            + player1UI.nameLabel->text() + " wins!");
        isGameOver = true;
	}
}

void GameScreenWidget::handleDotPressed(int row, int col) {
    if (!isGameOver) {
        gameBoard->setDotColor(row, col, Qt::red);
        ableToSwitchPlayer = true;
    }
}

void GameScreenWidget::switchPlayer() {
    if (ableToSwitchPlayer && !isGameOver) {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        updateUIBasedOnPlayerTurn();
    }
    else {
        if (isGameOver)
			ui->gameMessageLabel->setText("The game is over. Please return to the main menu.");
		else if (!ableToSwitchPlayer)
            ui->gameMessageLabel->setText("Unable to switch the player.");
    }
}