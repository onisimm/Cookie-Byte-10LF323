#include "Undo.h"

twixt::Undo::Undo(GameStack gameStack, Board* gameBoard)
{
	m_lastDot = *gameStack.GetGameStack().top().first;
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
	if (m_lastDot.getExistingBridges().size())
		board->getDot(m_lastDot.getCoordI(), m_lastDot.getCoordJ())->deleteAllBridgesForADot();
	//de verificat possible bridges
		
}

void twixt::Undo::undoBulldozer()
{
}

void twixt::Undo::undoMines()
{
}

void twixt::Undo::undoDeleteBridge()
{
}
