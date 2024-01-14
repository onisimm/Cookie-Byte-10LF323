#include "GameScreenWidget.h"
#include "ui_GameScreenWidget.h"
#include <QTimer>
#include <QMessageBox>

GameScreenWidget::GameScreenWidget(const Ui::GameSettings& settings, QWidget* parent) :
    QWidget(parent),
    ui(new Ui::GameScreenWidget),
    gameBoard(new GameBoardWidget(this)),
    backendGame(new TwixtGame()),
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
    this->backendGame->setGameBoardSize(size);
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
    this->backendGame->setGameMode(gamemode);
}

void GameScreenWidget::closeMenuDialog()
{
    handleBackToGameButton();
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

    QColor player1Color(255, 80, 80); // for player 1
    setupPlayer(player1UI, ui->player1NameLabel, ui->player1TimerLabel, settings.player1Name, settings.timeLimit, player1Color);
    backendGame->setPlayer1(player1UI.backendPlayer);
    gameBoard->setPlayer1Color(player1UI.color);
    player1UI.backendPlayer->setPlayerType(twixt::PlayerType::Player1);
    player1UI.backendPlayer->setRemainingDots(settings.maxDots);
    player1UI.backendPlayer->setRemainingBridges(settings.maxBridges);

    QColor player2Color(0, 102, 204); // for player 2
    setupPlayer(player2UI, ui->player2NameLabel, ui->player2TimerLabel, settings.player2Name, settings.timeLimit, player2Color);
    backendGame->setPlayer2(player2UI.backendPlayer);
    gameBoard->setPlayer2Color(player2UI.color);
    player2UI.backendPlayer->setPlayerType(twixt::PlayerType::Player2);
    player2UI.backendPlayer->setRemainingDots(settings.maxDots);
    player2UI.backendPlayer->setRemainingBridges(settings.maxBridges);

    initialPlayerFont = player1UI.nameLabel->font();
}


void GameScreenWidget::applyGameSettings(const Ui::GameSettings& settings) {
    ui->mainLayout->addWidget(gameBoard);

    setGameboardSize(settings.gameboardSize);
    setMaxDots(settings.maxDots);
    setMaxBridges(settings.maxBridges);
    setGamemode(settings.gamemode);

    gameBoard->buildBoard();
    backendGame->initializeGame();
    updateGameBoardFromBackend();
}

void GameScreenWidget::setupConnections()
{
    //connect(ui->backToMenuButton, &QPushButton::clicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
    connect(ui->undoButton, &QPushButton::clicked, this, &GameScreenWidget::handleUndoButtonClicked);
    connect(ui->getHintButton, &QPushButton::clicked, this, &GameScreenWidget::handleGetHintButtonClicked);
    connect(gameBoard, &GameBoardWidget::dotPressed, this, &GameScreenWidget::handleDotPressed);
    connect(ui->switchTurnButton, &QPushButton::clicked, this, &GameScreenWidget::switchTurns);
    connect(ui->menuButton, &QPushButton::clicked, this, &GameScreenWidget::showMenu);
}

void GameScreenWidget::updateUIBasedOnPlayerTurn() {
    Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI;
    Ui::UIPlayer& inactivePlayer = (currentPlayer == 1) ? player2UI : player1UI;
    
    QFont font = initialPlayerFont;
    font.setBold(true);
    font.setPointSize(initialPlayerFont.pointSize() + 4);
    activePlayer.nameLabel->setFont(font);
    font.setPointSize(initialPlayerFont.pointSize() + 1);
    activePlayer.timerLabel->setFont(font);
    
    font = initialPlayerFont;
    inactivePlayer.nameLabel->setFont(initialPlayerFont);
    font.setPointSize(initialPlayerFont.pointSize() - 4); // the timer label is smaller than the name label with 2pt always
    inactivePlayer.timerLabel->setFont(initialPlayerFont);

    activePlayer.timer->start();
    inactivePlayer.timer->stop();

    ui->player1RemainingDotsLabel->setText("Remaining dots: " + QString::number(player1UI.backendPlayer->getRemainingDots()));
    ui->player2RemainingDotsLabel->setText("Remaining dots: " + QString::number(player2UI.backendPlayer->getRemainingDots()));
    ui->player1RemainingBridgesLabel->setText("Remaining bridges: " + QString::number(player1UI.backendPlayer->getRemainingBridges()));
    ui->player2RemainingBridgesLabel->setText("Remaining bridges: " + QString::number(player2UI.backendPlayer->getRemainingBridges()));
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
        checkTimerIsOver();
    }
}

void GameScreenWidget::resetTimer(Ui::UIPlayer& playerUI)
{
    if (playerUI.timer->isActive()) {
        playerUI.timer->stop();
    }
    playerUI.timeLeft = playerUI.timeLimit;
    int minutes = playerUI.timeLeft / 60;
    int seconds = playerUI.timeLeft % 60;
    playerUI.timerLabel->setText(QString("%1:%2").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')));

    playerUI.timer->start(1000);
}

void GameScreenWidget::endGame() {
    isGameOver = true;
    player1UI.timer->stop();
    player2UI.timer->stop();
}

void GameScreenWidget::checkWinningPath(const Ui::UIPlayer& player)
{
    if (this->backendGame->checkPathWin(player.backendPlayer))
    {
        ui->gameMessageLabel->setText(player.nameLabel->text() + " wins by building a brigde from end to end!");
        endGame();
    }

    updateUIBasedOnPlayerTurn();
}

void GameScreenWidget::checkIsTie()
{
    if (this->backendGame->isTie(*player1UI.backendPlayer, *player2UI.backendPlayer))
    {
        ui->gameMessageLabel->setText("It's a tie! No more options left.");
        endGame();
    }
    updateUIBasedOnPlayerTurn();
}

void GameScreenWidget::checkTimerIsOver()
{
    if (player1UI.timeLeft == 0) {
        ui->gameMessageLabel->setText(player1UI.nameLabel->text() + " ran out of time. " 
            + player2UI.nameLabel->text() + " wins!");
        endGame();
        return;
    }
    else if (player2UI.timeLeft == 0) {
        ui->gameMessageLabel->setText(player2UI.nameLabel->text() + " ran out of time. "
            + player1UI.nameLabel->text() + " wins!");
        endGame();
        return;
	}

    updateUIBasedOnPlayerTurn();
}

void GameScreenWidget::clearHint()
{
    if (hintOnScreen) {
        twixt::Dot::Status firstDotStatus = this->backendGame->getDotStatus(firstHintDot.first, firstHintDot.second);
        QColor colorToRedrawDots = Qt::lightGray;
        if (firstDotStatus == twixt::Dot::Status::Player1) {
            colorToRedrawDots = player1UI.color;
        }
        else if (firstDotStatus == twixt::Dot::Status::Player2) {
			colorToRedrawDots = player2UI.color;
		}

        gameBoard->setDotColor(firstHintDot.first, firstHintDot.second, colorToRedrawDots);
		gameBoard->setDotColor(secondHintDot.first, secondHintDot.second, colorToRedrawDots);
        firstHintDot = { -1, -1 };
        secondHintDot = { -1, -1 };
		hintOnScreen = false;
    }
}

void GameScreenWidget::updateGameBoardFromBackend()
{
    this->gameBoard->clearBoard();

    for (int i = 0; i < this->backendGame->getGameboardSize(); i++) {
		for (int j = 0; j < this->backendGame->getGameboardSize(); j++) {
			twixt::Dot::Status dotStatus = this->backendGame->getDotStatus(i, j);
			if (dotStatus == twixt::Dot::Status::Player1) {
				gameBoard->setDotColor(i, j, player1UI.color);
			}
			else if (dotStatus == twixt::Dot::Status::Player2) {
				gameBoard->setDotColor(i, j, player2UI.color);
			}
			else if (dotStatus == twixt::Dot::Status::Mine) {
				gameBoard->setDotColor(i, j, QColor(102, 51, 0));
			}
            else if (dotStatus == twixt::Dot::Status::Exploded) {
                gameBoard->setDotColor(i, j, Qt::black);
            }
            else if (dotStatus == twixt::Dot::Status::Bulldozer) {
                gameBoard->setDotColor(i, j, QColor(255, 153, 51));
            }
			else if (dotStatus == twixt::Dot::Status::Empty) {
				gameBoard->setDotColor(i, j, Qt::lightGray);
			}
		}
	}

    for (auto& bridge : this->backendGame->getBridges()) {
        std::pair<uint8_t, uint8_t> firstPeg = { bridge.get()->getFirstPillar().GetPointer()->getCoordI(), bridge.get()->getFirstPillar().GetPointer()->getCoordJ() };
        std::pair<uint8_t, uint8_t> secondPeg = { bridge.get()->getSecondPillar().GetPointer()->getCoordI(), bridge.get()->getSecondPillar().GetPointer()->getCoordJ() };
        Ui::UIPlayer& bridgeOwner = (bridge.get()->getFirstPillar().GetPointer()->getStatus() == Dot::Status::Player1) ? player1UI : player2UI;

		gameBoard->drawBridge(firstPeg.first, firstPeg.second, secondPeg.first, secondPeg.second, bridgeOwner.color);
	}

    this->gameBoard->update();
}

void GameScreenWidget::handleDotPressed(int row, int col) {
    if (!isGameOver) {
        ui->gameMessageLabel->setText("");
        Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI; // current player's turn

        twixt::Dot::Status dotStatus = this->backendGame->getDotStatus(row, col);
        bool dotBelongsToAPlayer = (dotStatus == twixt::Dot::Status::Player1 || dotStatus == twixt::Dot::Status::Player2);
        
        if (ableToBuildBridges && dotBelongsToAPlayer) {
            twixt::PlayerType dotOwner = (dotStatus == twixt::Dot::Status::Player1) ? twixt::PlayerType::Player1 : twixt::PlayerType::Player2;

            if (firstDotForBridge == std::make_tuple(0, 0)) { // if it hasn't been initialized
                if ((dotStatus == twixt::Dot::Status::Player1 || dotStatus == twixt::Dot::Status::Player2) && 
                    dotOwner == activePlayer.backendPlayer->getPlayerType())  // if the dot is occupied by the current player
                {
                    firstDotForBridge = { row, col };
                    gameBoard->setDotColor(row, col, QColor(0, 204, 102));
                    ableToSwitchTurns = false;
                }
            }
            else { // if there is already a first dot picked, we're gonna pick the second
                if ((dotStatus == twixt::Dot::Status::Player1 || dotStatus == twixt::Dot::Status::Player2) &&
                    dotOwner == activePlayer.backendPlayer->getPlayerType()) // if the dot is occupied by the current player
                {
                    bool isPossibleToBuildBridge = backendGame->ableToBuildBridge(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), row, col);

                    if (isPossibleToBuildBridge) {
                        gameBoard->drawBridge(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), row, col, activePlayer.color);
                        this->backendGame->buildBridge(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), row, col, activePlayer.backendPlayer);
                        gameBoard->setDotColor(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), activePlayer.color);
                        gameBoard->setDotColor(row, col, activePlayer.color);
                        firstDotForBridge = { 0, 0 };
                        secondDotForBridge = { 0, 0 };
                        ableToSwitchTurns = true;
                        checkWinningPath(activePlayer);
                        clearHint();
                    }
                    else 
                    {
                        if (this->backendGame->existsBridge(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), row, col, activePlayer.backendPlayer))
                        { 
                            this->backendGame->deleteBridge(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), row, col, activePlayer.backendPlayer); 
                            updateGameBoardFromBackend();
                        } 

                    }

                }

                if (firstDotForBridge != std::make_tuple(0, 0))
                    gameBoard->setDotColor(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), activePlayer.color);
                firstDotForBridge = { 0, 0 };
                secondDotForBridge = { 0, 0 };
                ableToSwitchTurns = true;
            }
		}
        else if (!dotBelongsToAPlayer && ableToBuildBridges) {
            if (firstDotForBridge != std::make_tuple(0, 0))
                gameBoard->setDotColor(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), activePlayer.color);
            firstDotForBridge = { 0, 0 };
            secondDotForBridge = { 0, 0 };
            ableToSwitchTurns = true;
        }
        else if (!ableToBuildBridges) { // If it's not able to build bridges, it means the player is placing a dot
            uint8_t ableToPlaceDotResult = this->backendGame->ableToPlaceDot(row, col, activePlayer.backendPlayer);
            if (ableToPlaceDotResult == 0) {
                gameBoard->setDotColor(row, col, activePlayer.color);
                this->backendGame->placeDot(row, col, activePlayer.backendPlayer);
                ableToSwitchTurns = true;
                ableToBuildBridges = true;
                ui->gameMessageLabel->setText("Wanna build some bridges?? Just press on two of your pegs");
            }
            else if (ableToPlaceDotResult == 2) {
				ui->gameMessageLabel->setText("Oh no, a mine was there! I've never seen such a big explosion!");
                this->backendGame->explodeMine(row, col, activePlayer.backendPlayer);
                this->gameBoard->setDotColor(row, col, QColor(102, 51, 0));
                updateGameBoardFromBackend();

                ableToSwitchTurns = true;
                ableToBuildBridges = true;
			}
            else if (ableToPlaceDotResult == 3) {
                ui->gameMessageLabel->setText("That spot is still a mess.. Can't build there yet.");
            }
            else if (ableToPlaceDotResult == 5) {
				ui->gameMessageLabel->setText("You have no more pegs to place.");
			}
		}
    }

    checkIsTie();
    updateUIBasedOnPlayerTurn();
}

void GameScreenWidget::switchTurns() {
    if (ableToSwitchTurns && !isGameOver) {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI;
        if (firstDotForBridge != std::make_tuple(0, 0))
            gameBoard->setDotColor(std::get<0>(firstDotForBridge), std::get<1>(firstDotForBridge), activePlayer.color);

        ableToSwitchTurns = false;
        ableToBuildBridges = false;

        ui->gameMessageLabel->setText("");
        updateUIBasedOnPlayerTurn();

        if (firstTurn) {
            firstTurn = false;

            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirm", "Do you want to steal " + player1UI.nameLabel->text() + "'s color?",
                QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                QString player1Name = player1UI.nameLabel->text();
                player1UI.nameLabel->setText(player2UI.nameLabel->text());
                player2UI.nameLabel->setText(player1Name);

                switchTurns();
                ui->gameMessageLabel->setText("Thief! Thief!!!\nI guess we're back to " + player2UI.nameLabel->text() + "'s turn again.");
            }
        }
        else {
            if (this->backendGame->getGameMode() == TwixtGame::GameModeType::Bulldozer) {
                if (bulldozerModeMoveCount == true) {
                    this->backendGame->moveBulldozer();
                    bulldozerModeMoveCount = false;
                    updateGameBoardFromBackend();
                    updateUIBasedOnPlayerTurn();
                }
                else
                    bulldozerModeMoveCount = true;
            }
        }
    }
    else {
        if (isGameOver)
            ui->gameMessageLabel->setText("The game is over. Please return to the main menu.");
        else if (ableToBuildBridges && (firstDotForBridge != std::make_tuple(0, 0)) && (secondDotForBridge == std::make_tuple(0, 0)))
            ui->gameMessageLabel->setText("Finish building your bridge first, buddy. Unless you want to cancel it..\n just press on a random peg I guess");
		else if (!ableToSwitchTurns) 
            ui->gameMessageLabel->setText("Maybe put a peg down first.. you don't wanna lose your turn");
    }

    clearHint();
}

void GameScreenWidget::handleUndoButtonClicked() 
{
    if (!isGameOver) {
        if (!this->backendGame->undo()) {
            ui->gameMessageLabel->setText("Time travel ain't possible that far away");
        }
        updateGameBoardFromBackend();
        updateUIBasedOnPlayerTurn();
    }
}

void GameScreenWidget::handleGetHintButtonClicked()
{
	if (!isGameOver) {
        Ui::UIPlayer& activePlayer = (currentPlayer == 1) ? player1UI : player2UI;

        std::pair<std::pair<int, int>, std::pair<int, int>> hint = this->backendGame->getHintByMinimax(activePlayer.backendPlayer);
        if (hint.first.first == -1 && hint.first.second == -1) {
			ui->gameMessageLabel->setText("No more hints available. You're on your own until you place some more pegs.");
			return;
		}

		gameBoard->setDotColor(hint.first.first, hint.first.second, Qt::yellow);
		gameBoard->setDotColor(hint.second.first, hint.second.second, Qt::yellow);
		ui->gameMessageLabel->setText("A bridge there might work!");
        hintOnScreen = true;
        firstHintDot = hint.first;
        secondHintDot = hint.second;
	}
}

void GameScreenWidget::showMenu()
{
    menuDialog = new GameScreenMenuDialog();

    connect(menuDialog, &GameScreenMenuDialog::backToMenuButtonClicked, this, &GameScreenWidget::on_backToMenuButton_clicked);
    connect(menuDialog, &GameScreenMenuDialog::resetGameButtonClicked, this, &GameScreenWidget::confirmResetGame);
    connect(menuDialog, &GameScreenMenuDialog::backToGameButtonClicked, this, &GameScreenWidget::handleBackToGameButton);

    menuDialog->setModal(true);
    menuDialog->show();
}

void GameScreenWidget::handleBackToGameButton()
{
    menuDialog->setVisible(false);
    delete menuDialog;
}

void GameScreenWidget::confirmResetGame() {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Are you sure you want to reset the game?\nAll your progress will be lost.",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        this->backendGame->resetGame(this->backendGame->getMaxDots(), this->backendGame->getMaxBridges());
        updateGameBoardFromBackend();
        currentPlayer = 1;
        resetTimer(player1UI);
        resetTimer(player2UI);
        updateUIBasedOnPlayerTurn();
        handleBackToGameButton();
    }
    if (reply == QMessageBox::No) {
        return;
    }

    return;
}