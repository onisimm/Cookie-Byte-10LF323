#include "Undo.h"

twixt::Undo::Undo(GameStack gameStack, Board* gameBoard)
{
	Dot* topDot = gameStack.GetGameStack().top().first;

	if (Mine* ptrMine = dynamic_cast<Mine*>(topDot)) {
		//m_lastDot = new Mine(*ptrMine);
		//m_lastMine = new Mine(*ptrMine);
		m_lastMine = ptrMine;
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

	board->rebuildPossibleBridges(board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ()));
	board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->setStatus(Dot::DotStatus::Clear);
}

void twixt::Undo::undoBulldozer()
{
	//Livia
}

void twixt::Undo::undoMines()
{
	bool didMineExplode = false;

	board->getMatrixDot(m_lastMine->getNewPlacedMine()->getCoordI(), m_lastMine->getNewPlacedMine()->getCoordJ())->setStatus(Dot::DotStatus::Clear);
	
	for (auto elements : dynamic_cast<Mine*>(m_lastMine)->getExplodedDots())
	{
		if (Mine* checkMine = dynamic_cast<Mine*>(elements))
		{
			std::cout << "DO the same\n";
			//do the same
			//Livia
		}
		else
		{
			std::cout << "REBUILT DOT " << elements->getCoordI() << " " << elements->getCoordJ() << "\n";
			board->changeDotStatus(elements->getCoordI(), elements->getCoordJ(), elements->getStatus(), didMineExplode);
		}
	}

	board->placeMine(m_lastMine->getCoordI(), m_lastMine->getCoordJ());
}

void twixt::Undo::undoDeleteBridge()
{
	board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->buildBridge(m_deletedBridgeDot);
	board->getDot(m_deletedBridgeDot->getCoordI(), m_deletedBridgeDot->getCoordJ())->buildBridge(m_lastDot);	
}
