#include "Undo.h"

twixt::Undo::Undo(GameStack* gameStack, Board* gameBoard)
{
	Dot* topDot = gameStack->GetGameStack().top().first;


	if (Mine* ptrMine = dynamic_cast<Mine*>(topDot)) {
		m_lastDot = ptrMine;
	}
	else if (Bulldozer* ptrBulldozer = dynamic_cast<Bulldozer*>(topDot))
	{
		m_lastDot = ptrBulldozer;
	}
	else
	{
		m_lastDot = topDot;
	}
	m_type = gameStack->GetGameStack().top().second;
	if (m_type == DELETEBRIDGE)
	{
		m_deletedBridgeDot = gameStack->GetDeletedBridgesDotStack().top();
		gameStack->popDeletedBridgesStack();
	}
	board = gameBoard;
	gameStack->popGameStack();
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
		undoMines(m_lastDot);
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
	board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->setStatus(Dot::DotStatus::Clear);
}

void twixt::Undo::undoBulldozer()
{
	Bulldozer* lastBulldozer = dynamic_cast<Bulldozer*>(m_lastDot);
	size_t coordILastBulldozer = lastBulldozer->getCoordI();
	size_t coordJLastBulldozer = lastBulldozer->getCoordJ();
	//set lastBulldozer to previous position
	lastBulldozer->setToPreviousPosition(*board);

	//make a copy of the last DestroyedDot
	Dot copyOfDot = lastBulldozer->getDotDestroyed().top();
	bool didMineExplode = false;
	//delete the last dot that is on the i and j of the destroyedDot
	delete board->getDot(coordILastBulldozer, coordJLastBulldozer);
	//alocate memory that copies data form copyOfDot
	board->getDot(coordILastBulldozer, coordJLastBulldozer) = new Dot(copyOfDot);
	//delete existing bridges
	board->getDot(coordILastBulldozer, coordJLastBulldozer)->clearExistingBridges();
	//build bridges for both copyOfDot and the other dot in bridge
	for (auto bridges : copyOfDot.getExistingBridges())
	{
		bridges->rebuiltBridge();
	}

}

void twixt::Undo::undoMines(Dot* mine)
{
	Mine* lastMine = dynamic_cast<Mine*>(mine);
	bool didMineExplode = false;

	if (lastMine->getNewPlacedMine())
	{
		board->getMatrixDot(lastMine->getNewPlacedMine()->getCoordI(), lastMine->getNewPlacedMine()->getCoordJ())->setStatus(Dot::DotStatus::Clear);

	}

	for (auto elements : dynamic_cast<Mine*>(lastMine)->getExplodedDots())
	{
		if (Mine* checkMine = dynamic_cast<Mine*>(elements))
		{
			std::cout << "DO the same\n";
			undoMines(checkMine);
		}
		else
		{
			std::cout << "REBUILT DOT " << elements->getCoordI() << " " << elements->getCoordJ() << "\n";
			board->changeDotStatus(elements->getCoordI(), elements->getCoordJ(), elements->getStatus(), didMineExplode);
			//de verificat zona de memorie cum se aloca ( daca elements este mina, sa se dealoce/aloce memorie corespunzator)
			for (auto bridges : elements->getExistingBridges())
			{
				bridges->rebuiltBridge();
			}
		}
	}

	board->placeMine(lastMine->getCoordI(), lastMine->getCoordJ());
}

void twixt::Undo::undoDeleteBridge()
{
	board->getDot(m_lastDot->getCoordI(), m_lastDot->getCoordJ())->addBridge(m_deletedBridgeDot);
}
