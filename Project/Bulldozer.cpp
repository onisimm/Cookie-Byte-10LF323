#include "Bulldozer.h"

void twixt::Bulldozer::destoryRandomDot(Board& board)
{
	srand(time(NULL));
	size_t i = rand() % (board.getSize() - 2) + 1;
	size_t j = rand() % (board.getSize() - 2) + 1;
	while (board.getDot(i, j)->getStatus() != Dot::DotStatus::Player1 && board.getDot(i, j)->getStatus() != Dot::DotStatus::Player2)
	{
		i = rand() % (board.getSize() - 2) + 1;
		j = rand() % (board.getSize() - 2) + 1;
	}

	//assign the destroyed dot 
	m_dotDestroyed.push(*board.getDot(i, j));
	//assign the previous position
	m_previousPosition.push(position);

	//delete the random Dot
	std::cout << "The dot " << i << " " << j << " will be destroyed\n";
	board.getDot(i, j)->deleteAllBridgesForADot();

	//eliminate the current bulldozer
	delete board.getDot(position.first, position.second);
	board.getDot(position.first, position.second) = new Dot(position.first, position.second);

	delete board.getDot(i, j);

	

	//set the new position for the bulldozer
	position.first = i;
	position.second = j;
	this->setCoordI(i);
	this->setCoordJ(j);
	this->setStatus(Dot::DotStatus::Bulldozer);
	
	board.getDot(i, j) = new Bulldozer(*this);

	
}

void twixt::Bulldozer::allocateBulldozer(Dot*& dot)
{
	delete dot;
	dot = new Bulldozer(*this);

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
	delete board->getDot(i, j);
	position.first = i;
	position.second = j;
	board->getDot(i, j) = new Bulldozer(*this);
	board->changeDotStatus(i, j, Dot::DotStatus::Bulldozer, didMineExplode);
}

twixt::Bulldozer::Bulldozer(const Bulldozer& bulldozer) : Dot(bulldozer), position{ bulldozer.position }, m_previousPosition{ bulldozer.m_previousPosition }, m_dotDestroyed{ bulldozer.m_dotDestroyed }
{
	this->setCoordI(position.first);
	this->setCoordJ(position.second);
}

//Flipping the coin and deciding whether to destory a Dot or not
bool twixt::Bulldozer::flipCoin(Board& board)
{
	/*srand(time(NULL));
	if (rand() % 2)
	{
		std::cout << "We flipped the coin and nothing will happen.\n";
		return false;
	}*/
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

//uint8_t twixt::Bulldozer::getI() const
//{
//	return position.first;
//}
//
//uint8_t twixt::Bulldozer::getJ() const
//{
//	return position.second;
//}

std::stack<std::pair<size_t, size_t>> twixt::Bulldozer::getPreviousPosition() const
{
	return m_previousPosition;
}

std::stack<twixt::Dot> twixt::Bulldozer::getDotDestroyed() const
{
	return m_dotDestroyed;
}

void twixt::Bulldozer::setToPreviousPosition(Board& board)
{
	//this->setStatus(Dot::DotStatus::Clear);
	position.first = m_previousPosition.top().first;
	position.second = m_previousPosition.top().second;

	bool didMineExplode = false;
	board.changeDotStatus(position.first, position.second, Dot::DotStatus::Bulldozer, didMineExplode);
	m_previousPosition.pop();

	delete board.getDot(position.first, position.second);
	board.getDot(position.first, position.second) = new Bulldozer(*this);
	
}


