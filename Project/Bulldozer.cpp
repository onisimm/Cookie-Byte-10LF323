#include "Bulldozer.h"

void twixt::Bulldozer::destoryRandomDot(Board& board)
{
	srand(time(NULL));
	int i = rand() % (board.getSize() - 2) + 1;
	int j = rand() % (board.getSize() - 2) + 1;
	while (board.getDot(i, j)->getStatus() != Dot::DotStatus::Player1 && board.getDot(i, j)->getStatus() != Dot::DotStatus::Player2)
	{
		i = rand() % (board.getSize() - 2) + 1;
		j = rand() % (board.getSize() - 2) + 1;
	}

	//assign the destroied dot 
	m_dotDestroied.push(*board.getDot(i, j));
	//assign the previous position
	m_previousPosition.push(position);

	//delete the random Dot
	board.getDot(i, j)->setStatus(Dot::DotStatus::Bulldozer);
	std::cout << "The dot " << i << " " << j << " will be destroyed\n";
	board.getDot(i, j)->deleteAllBridgesForADot();

	//eliminate the current bulldozer
	board.getDot(position.first, position.second)->setStatus(Dot::DotStatus::Clear);

	//set the new position for the bulldozer
	position.first = i;
	position.second = j;

	
}

void twixt::Bulldozer::allocateBulldozer(Dot*& dot)
{
	delete dot;
	dot = this;
}

//Constructor 
twixt::Bulldozer::Bulldozer(Board* board)
{
	srand(time(NULL));
	auto [i, j] = position;
	i = rand() % (board->getSize() - 2) + 1;
	j = rand() % (board->getSize() - 2) + 1;
	bool didMineExplode = false;
	//find a clear Dot and set it as a bulldozer
	while (board->getDot(i, j)->getStatus() != Dot::DotStatus::Clear)
	{
		i = rand() % (board->getSize() - 2) + 1;
		j = rand() % (board->getSize() - 2) + 1;
	}
	allocateBulldozer(board->getDot(i, j));
	board->changeDotStatus(i, j, Dot::DotStatus::Bulldozer, didMineExplode);
	position.first = i;
	position.second = j;
}

//Flipping the coin and deciding whether to destory a Dot or not
bool twixt::Bulldozer::flipCoin(Board& board)
{
	srand(time(NULL));
	if (rand() % 2)
	{
		std::cout << "We flipped the coin and nothing will happen.\n";
		return false;
	}
	//If it did not exist the function, we will destory a Dot
	destoryRandomDot(board);
	board.showBoard();
	return true;
}

bool twixt::Bulldozer::exists()
{
	if (position.first != 0)
		return true;
	return false;
}

uint8_t twixt::Bulldozer::getI() const
{
	return position.first;
}

uint8_t twixt::Bulldozer::getJ() const
{
	return position.second;
}

std::stack<std::pair<int, int>> twixt::Bulldozer::getPreviousPosition() const
{
	return m_previousPosition;
}

std::stack<twixt::Dot> twixt::Bulldozer::getDotDestroied() const
{
	return m_dotDestroied;
}

void twixt::Bulldozer::setToPreviousPosition(Board& board)
{
	this->setStatus(Dot::DotStatus::Clear);
	position.first = m_previousPosition.top().first;
	position.second = m_previousPosition.top().second;

	bool didMineExplode = false;
	board.changeDotStatus(position.first, position.second, Dot::DotStatus::Bulldozer, didMineExplode);
}

