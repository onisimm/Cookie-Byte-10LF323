#include "Undo.h"

twixt::Undo::Undo(GameStack gameStack, Board* gameBoard)
{
	Dot* topDot = gameStack.GetGameStack().top().first;

	if (Mine* ptrMine = dynamic_cast<Mine*>(topDot)) {
		m_lastDot = new Mine(*ptrMine);
	}
	else {
		m_lastDot = new Dot(*topDot);
	}
	m_type = gameStack.GetGameStack().top().second;
	if (m_type == DELETEBRIDGE)
	{
		m_deletedBridgeDot = new Dot(*gameStack.GetDeletedBridgesDotStack().top());
	}
	board = gameBoard;
}

void twixt::Undo::pressed()
{

	switch (m_type)
	{
	case 0:
		undoPlayers(Dot::DotStatus::Player1);
		break;
	case 1:
		undoPlayers(Dot::DotStatus::Player2);
		break;
	case 3:
		undoBulldozer();
		break;
	case 4:
		undoMines();
		break;
	case 5:
		undoDeleteBridge();
		break;
	default:
		break;
	}
}

void twixt::Undo::undoPlayers(Dot::DotStatus status)
{
	if (m_lastDot->getExistingBridges().size())
	{
		board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->deleteAllBridgesForADot();
	}

	board->rebuildPossibleBridges(board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ()), status);
	board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->setStatus(Dot::DotStatus::Clear);

	//m_lastDot->setStatus(Dot::DotStatus::Clear);
	// 
	//std::vector<std::pair<int, int>> positions{ { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } };
	//int i = m_lastDot->getCoordI();
	//int j = m_lastDot->getCoordJ();

	//for (auto pair : positions)
	//{
	//	auto [newI, newJ] = pair;
	//	newI += i;
	//	newJ += j;
	//	
	//	if (newI >= 0 && newI < board->getMatrix().size() && newJ >= 0 && newJ < board->getMatrix()[newJ].size()) // check boundaries
	//	{
	//		if (board->getMatrix()[newI][newJ]->getStatus() == status)
	//		{
	//			m_lastDot->addPossibleBridge(board->getMatrix()[newI][newJ]);
	//		}
	//	}
	//}
}

void twixt::Undo::undoBulldozer()
{
	//Livia
}

void twixt::Undo::undoMines()
{
	for (auto elements : dynamic_cast<Mine*>(m_lastDot)->getExplodedDots())
	{
		if (Mine* checkMine = dynamic_cast<Mine*>(elements))
		{
			std::cout << "DO the same\n";
			//do the same
			//Livia
		}
		else
		{
			std::cout << "rebuilt the dot\n";
			//roxana
		}
	}
}

void twixt::Undo::undoDeleteBridge()
{
	board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->buildBridge(m_deletedBridgeDot);
	board->getDot(m_deletedBridgeDot->getCoordI(), m_deletedBridgeDot->getCoordJ())->buildBridge(m_lastDot);	
}
