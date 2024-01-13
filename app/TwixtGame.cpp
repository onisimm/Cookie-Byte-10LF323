#pragma once

#include"TwixtGame.h"

bool TwixtGame::IsTie(Player player1, Player player2)
{
	if (!player1.hasRemainingDots() && !player2.hasRemainingDots() || !player1.hasRemainingBridges() && !player2.hasRemainingBridges())
	{
		return true;
	}
	return false;
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

	// TODO: if gamemode is mines, place random mines on the board

	// TODO: if gamemode is bulldozer, place a random bulldozer on the board
}

void TwixtGame::placeDot(uint8_t row, uint8_t col, Player* currentPlayer)
{
	m_board->getMatrix()[row][col].reset(new Peg());

	if (currentPlayer->getPlayerType() == twixt::PlayerType::Player1)
		m_board->getMatrix()[row][col]->setStatus(Dot::Status::Player1);
	else
		m_board->getMatrix()[row][col]->setStatus(Dot::Status::Player2);

	m_gameStack.AddInGameStack(Observer_ptr<Dot>(m_board->getMatrix()[row][col].get()), uint16_t(m_board->getMatrix()[row][col]->getStatus()));
	currentPlayer->setRemainingDots(currentPlayer->getRemainingDots() - 1);
}

uint8_t TwixtGame::ableToPlaceDot(uint8_t row, uint8_t col, Player* currentPlayer)
{
	if (currentPlayer->hasRemainingDots())
	{
		if (m_board->getMatrix()[row][col]->getStatus() == Dot::Status::Empty)
		{
			return 0; // can place dot
		}
		else if (m_board->getMatrix()[row][col]->getStatus() == Dot::Status::Player1 ||
				m_board->getMatrix()[row][col]->getStatus() == Dot::Status::Player2)
		{
			return 1; // dot is already occupied
		}
		else if (m_board->getMatrix()[row][col]->getStatus() == Dot::Status::Mine)
		{
			return 2; // dot is occupied by a mine
		}
		else if (m_board->getMatrix()[row][col]->getStatus() == Dot::Status::Exploded)
		{
			return 3; // dot is a mine exploded, where there can't be a dot placed
		}
		else if (m_board->getMatrix()[row][col]->getStatus() == Dot::Status::Bulldozer)
		{
			return 4; // dot is occupied by a bulldozer
		}
		
	}
	else
	{
		return 5; // player has no more dots to place
	}

	return -1; // error
}

void TwixtGame::buildBridge(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2, Player* currentPlayer)
{
	m_board->addBridgeInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(m_board->getMatrixDot(row1, col1).get())), Observer_ptr<Peg>(dynamic_cast<Peg*>(m_board->getMatrixDot(row2, col2).get())));
	m_gameStack.AddInGameStack(Observer_ptr<Dot>(m_board->getMatrixDot(row1, col1).get()), ADDBRIDGE);
	m_gameStack.AddInAddedBridgesDotStack(*(dynamic_cast<Peg*>(m_board->getMatrixDot(row2, col2).get())));

	currentPlayer->setRemainingBridges(currentPlayer->getRemainingBridges() - 1);
}

bool TwixtGame::ableToBuildBridge(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2)
{
	if (m_board->getMatrixDot(row1, col1).get()->getStatus() == m_board->getMatrixDot(row2, col2).get()->getStatus() && m_board->getMatrixDot(row1, col1).get()->getStatus() != Dot::Status::Empty)
	{
		Peg* peg1 = dynamic_cast<Peg*>(m_board->getMatrixDot(row1, col1).get());
		Peg* peg2 = dynamic_cast<Peg*>(m_board->getMatrixDot(row2, col2).get());

		bool pathClear = m_board->checkObstructingBridges(*peg1, *peg2); // check if there are no bridges between the two dots
		bool bridgeExistsBetweenDots = (peg1->getBridgeFromPegs(Observer_ptr<Peg>(peg2)) == nullptr);
		bool rightDistanceBetweenDots = ((abs(row1 - row2) == 1 && abs(col1 - col2) == 2) || (abs(row1 - row2) == 2 && abs(col1 - col2) == 1));

		if (rightDistanceBetweenDots && pathClear && bridgeExistsBetweenDots)
		{
			return true;
		}
		return false;
	}
	return false;
}

void TwixtGame::explodeMine(uint8_t row, uint8_t col, Player* currentPlayer)
{
	m_board->explodeMine(Observer_ptr<Mine>(dynamic_cast<Mine*>(m_board->getMatrixDot(row, col).get())));
	m_gameStack.AddInGameStack(Observer_ptr<Dot>(m_board->getMatrixDot(row, col).get()), uint16_t(m_board->getMatrixDot(row, col)->getStatus()));
}

Dot::Status TwixtGame::getDotStatus(uint8_t row, uint8_t col) const
{
	return m_board->getMatrixDot(row, col)->getStatus();
}

void TwixtGame::placeMine(uint8_t row, uint8_t col)
{
	m_board->placeMine(row, col);
}

void TwixtGame::moveBulldozer()
{
	if (m_board->m_bulldozer.GetPointer()->exists())
	{
		if (m_board->m_bulldozer.GetPointer()->flipCoin(*m_board))
		{
			size_t bulldozerCoordI = m_board->m_bulldozer.GetPointer()->getCoordI();
			size_t bulldozerCoordJ = m_board->m_bulldozer.GetPointer()->getCoordJ();
			m_gameStack.AddInGameStack(Observer_ptr<Dot>(m_board->getDot(bulldozerCoordI, bulldozerCoordJ).get()), size_t(Dot::Status::Bulldozer));
		}
	}
}