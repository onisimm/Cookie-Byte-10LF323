#pragma once

#include"TwixtGame.h"

//de sters macro-uri

void TwixtGame::GameTurns(Player& player, bool& isPlaying, Board& board)
{
	std::string answer;
	std::cout << player.getName() << ", what's you next move?\n";

	// Verificare pentru jucătorul negru în prima tură
	if (!blackPlayerStoleColor && player.getColor() == Player::Color::Black) {
		std::cout << player.getName() << ", do you want to steal the red color? (YES/NO)\n";
		std::cin >> answer;

		for (auto& c : answer) {
			c = toupper(c);
		}
	}
	if (answer == "YES") {
		// Setează culoarea jucătorului negru la roșu
		player.setColor(Player::Color::Red);
		// Setează indicatorul pe true după ce jucătorul a furat culoarea
		blackPlayerStoleColor = true;
		// Increment the number of pawns for the black player
		player.setRemainingDots(player.getRemainingDots() + 1);
		// Mesaj pentru indicarea faptului că jucătorul negru a furat culoarea
		std::cout << "Black player stole the red color!\n";
		std::cout << player.getName() << ", what's you next move?\n";


	}


	Minimax minimaxSuggestion(&board);
	minimaxSuggestion.suggestMove((player.getColor() == Player::Color::Red) ? Dot::DotStatus::Player1 : Dot::DotStatus::Player2);

	std::cin >> answer;

	for (auto& c : answer)
	{
		c = toupper(c);
	}

	if (answer == "ADD")
	{
		std::cout << "It's " << player.getName() << "'s turn!\n";
		// Incrementează numărul de doturi pentru jucătorul negru
		player.setRemainingDots(player.getRemainingDots() + 1);

		std::cout << "REMAINING DOTS for " << player.getName() << ": " << player.getRemainingDots() << "\n";
		//auto [dot, type] = player.turn(board);
		//m_gameStack.AddInGameStack(dot, type);
		board.showBoard();
		std::cout << "\n";
	}
	else if (answer == "DELETE")
	{
		std::cout << "Choose the first dot: ";
		size_t i1, j1, i2, j2;
		std::cin >> i1 >> j1;
		std::cout << "Choose the second dot: ";
		std::cin >> i2 >> j2;
		board.deleteBridge(board.getMatrixDot(i1, j1), board.getMatrixDot(i2, j2));
		m_gameStack.AddInGameStack(board.getMatrixDot(i1, j1), DELETEBRIDGE);
		m_gameStack.AddInDeletedBridgesDotStack(board.getMatrixDot(i2, j2));
	}
	else if (answer == "DELETEALL")
	{
		std::cout << "Choose the dot: ";
		size_t i, j;
		std::cin >> i >> j;
		board.getDot(i, j)->deleteAllBridgesForADot();
	}
	else if (answer == "SAVE")
		{
			saveGame.saveMatrix(board.getMatrix());
			saveGame.saveStack(m_gameStack);
		}
	else if (answer == "ADDBRIDGE")
	{
		std::cout << "Enter the position of the first dot: ";
		int i1, j1, i2, j2;
		std::cin >> i1 >> j1;
		std::cout << "Enter the position of the second dot: ";
		std::cin >> i2 >> j2;
		if (board.getMatrixDot(i1, j1)->getStatus() == board.getMatrixDot(i2, j2)->getStatus() && board.getMatrixDot(i1, j1)->getStatus() != Dot::DotStatus::Clear)
		{
			if (((abs(i1 - i2) == 1 && abs(j1 - j2) == 2) || (abs(i1 - i2) == 2 && abs(j1 - j2) == 1)) && board.checkObstructingBridges(*board.getMatrixDot(i1, j1), *board.getMatrixDot(i2, j2)))
				board.getMatrixDot(i1, j1)->addBridge(board.getMatrixDot(i2, j2));
		}
		else std::cout << "the dots does not exist\n";
	}
	Dot::DotStatus status;
	if (player.getColor() == Player::Color::Red)
	{
		status = Dot::DotStatus::Player1;
	}
	else
	{
		status = Dot::DotStatus::Player2;
	}
	if (board.checkPath(status))
	{
		std::cout << "You won!\n";
		isPlaying = false;
		return;
	}
		//nu se adauga automat bridge-uri
	std::cout << "Do you want to undo the move? ";
	std::cin >> answer;
	while (answer!="no")
	{
		

		for (auto& c : answer)
		{
			c = toupper(c);
		}

		if (answer == "YES")
		{
			Undo undo(&m_gameStack, &board);
			undo.pressed();
			board.showBoard();
		}
		std::cout << "\nDo you want to undo the move? ";
		std::cin >> answer;
	}
	
}

bool TwixtGame::IsTie(Player player1, Player player2)
{
	return !player1.hasRemainingDots() && !player2.hasRemainingDots();
}

void TwixtGame::setGameMode(const QString& gamemode)
{
	if (gamemode == "Mines")
		m_gameMode = GameModeType::Mines;
	else if (gamemode == "Bulldozer")
		m_gameMode = GameModeType::Bulldozer;
	else
		m_gameMode = GameModeType::Default;
}

void TwixtGame::setMaxDots(const uint8_t& maxDots)
{
	m_maxDots = maxDots;
}

void TwixtGame::setMaxBridges(const uint8_t& maxBridges)
{
	m_maxBridges = maxBridges;
}

void TwixtGame::setGameBoardSize(const uint8_t& size)
{
	m_gameBoardSize = size;
}

//void TwixtGame::ResetGame()
//{
//	//Reset board game
//	Board board(BOARD_SIZE);
//	//Reset stack
//	m_gameStack.Clear();
//	//Reset players
//	Player player1("player1", Player::Color::Red, DOTS_NUMBER);
//	Player player2("player2", Player::Color::Black, DOTS_NUMBER);
//	std::cout << "The game has been reset.\n";
//	GameLoop(board, player1, player2);
//}

GameStack TwixtGame::getGameStack() const
{
	return m_gameStack;
}
