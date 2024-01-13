#pragma once

#include"TwixtGame.h"

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
	this->m_maxDots = maxDots;
}

void TwixtGame::setMaxBridges(const uint8_t& maxBridges)
{
	this->m_maxBridges = maxBridges;
}

void TwixtGame::setGameBoardSize(const uint8_t& size)
{
	this->m_gameBoardSize = size;
}

void TwixtGame::setPlayer1(Player* player1)
{
	this->m_player1 = player1;
}

void TwixtGame::setPlayer2(Player* player2)
{
	this->m_player2 = player2;
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

void TwixtGame::initializeGame()
{
	m_board = new Board(m_gameBoardSize);


}
