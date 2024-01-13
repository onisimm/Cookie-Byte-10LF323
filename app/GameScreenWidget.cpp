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

            playerUI.backendPlayer = new twixt::Player(maxDots, maxBridges);
        };

    setupPlayer(player1UI, ui->player1NameLabel, ui->player1TimerLabel, settings.player1Name, settings.timeLimit, Qt::red);
    game->setPlayer1(player1UI.backendPlayer);

    setupPlayer(player2UI, ui->player2NameLabel, ui->player2TimerLabel, settings.player2Name, settings.timeLimit, Qt::black);
    game->setPlayer2(player2UI.backendPlayer);

    initialPlayerFont = player1UI.nameLabel->font();
}


void GameScreenWidget::applyGameSettings(const Ui::GameSettings& settings) {
    ui->mainLayout->addWidget(gameBoard);

    setGameboardSize(settings.gameboardSize);
    setMaxDots(settings.maxDots);
    setMaxBridges(settings.maxBridges);
    setGamemode(settings.gamemode);

    gameBoard->buildBoard();
    game->initializeGame();
}

void GameScreenWidget::setupConnections()
{
    // TOOD back to menu button becomes menu
    // inside menu there will be a button to go back to the main menu
    // a Save Game button, a Reset Game button,
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
        Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI; // current player's turn
        gameBoard->setDotColor(row, col, activePlayer.color);
        ableToSwitchPlayer = true;
        // TODO
        // after the first dot, make available  the possibility to build bridges (e.g. bool ableToBuildBridges = true)
        // if dotPlaced is true, then the player can build bridges 
        // if dotPicked is available -> firstDotForBridge is picked, make the dot Blue (maybe a pair of row col of the dot) 
        // while firstDotForBridge & !secondDotForBridge -> Popup when clicking switch player (do you want to cancel the bridge?)
                // ooorrr, just make a cancel button (show / hide when the player clicks on the first dot)
        // if dotPicked is available -> secondDotForBridge is picked, make the first dot player color again (maybe a pair of row col of the dot)
        // if distance is right for a bridge, then build the bridge of playercolor (bridge between firstDotForBridge and secondDotForBridge)
        // if distance is wrong, then cancel the bridge, make the dots playerColor again (unassign firstDotForBridge and secondDotForBridge)

    }
}

void GameScreenWidget::switchPlayer() {
    if (ableToSwitchPlayer && !isGameOver) {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        updateUIBasedOnPlayerTurn();
    }
    else {
        // TODO make screen logging more descriptive
        // Also, clear the message when the player is able to switch again / after 3 seconds
        if (isGameOver)
			ui->gameMessageLabel->setText("The game is over. Please return to the main menu.");
		else if (!ableToSwitchPlayer) 
            ui->gameMessageLabel->setText("Unable to switch the player.");
    }
}