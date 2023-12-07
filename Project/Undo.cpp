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
		board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->deleteAllBridgesForADot();
	//de verificat possible bridges
	//Rox
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
			//Roxana
		}
	}
}

void twixt::Undo::undoDeleteBridge()
{
	//Roxana
}
