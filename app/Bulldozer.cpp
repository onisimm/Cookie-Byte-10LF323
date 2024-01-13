#include "Bulldozer.h"

void twixt::Bulldozer::destoryRandomDot(Board& board)
{
	srand(time(NULL));
	size_t i = rand() % (board.getSize() - 2) + 1;
	size_t j = rand() % (board.getSize() - 2) + 1;
	while (board.getDot(i, j)->getStatus() != Dot::Status::Player1 && board.getDot(i, j)->getStatus() != Dot::Status::Player2)
	{
		i = rand() % (board.getSize() - 2) + 1;
		j = rand() % (board.getSize() - 2) + 1;
	}
	
	

	//delete the random Dot
	std::cout << "The dot " << i << " " << j << " will be destroyed\n";
	board.deleteAllBridgesForAPegInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getDot(i, j).get())));

	//assign the previous position
	m_previousPosition.push(position);
	//assign the destroyed dot 
	m_dotDestroyed.push(*dynamic_cast<Peg*>(board.getDot(i, j).get()));

	//set the new position for the bulldozer
	position.first = i;
	position.second = j;
	this->setCoordI(i);
	this->setCoordJ(j);
	this->setStatus(Dot::Status::Bulldozer);

	board.getDot(i, j).reset(new Bulldozer(*this));
	board.m_bulldozer = Observer_ptr<Bulldozer>(dynamic_cast<Bulldozer*>(board.getDot(i, j).get()));

	//eliminate the current bulldozer
	board.getDot(m_previousPosition.top().first, m_previousPosition.top().second).reset(new Dot(m_previousPosition.top().first, m_previousPosition.top().second));

}


//Constructor 
twixt::Bulldozer::Bulldozer(Board& board)
{
	srand(time(NULL));
	auto [i, j] = position;
	i = rand() % (board.getSize() - 2) + 1;
	j = rand() % (board.getSize() - 2) + 1;
	//find a clear Dot and set it as a bulldozer
	while (board.getDot(i, j)->getStatus() != Dot::Status::Empty)
	{
		i = rand() % (board.getSize() - 2) + 1;
		j = rand() % (board.getSize() - 2) + 1;
	}
	position.first = i;
	position.second = j;
	board.getDot(i, j).reset(new Bulldozer(*this));
	board.m_bulldozer = Observer_ptr<Bulldozer>(dynamic_cast<Bulldozer*>(board.getDot(i, j).get()));
	//board->placePiece(i, j, Dot::DotStatus::Bulldozer, didMineExplode);
}

twixt::Bulldozer::Bulldozer(const Bulldozer& bulldozer) : Dot(bulldozer), position{ bulldozer.position }, m_previousPosition{ bulldozer.m_previousPosition }, m_dotDestroyed{ bulldozer.m_dotDestroyed }
{
	this->setCoordI(position.first);
	this->setCoordJ(position.second);
	this->setStatus(Dot::Status::Bulldozer);
}

twixt::Bulldozer& twixt::Bulldozer::operator=(const Bulldozer& Bulldozer)
{
	position = Bulldozer.position;
	m_previousPosition = Bulldozer.m_previousPosition;
	m_dotDestroyed =  Bulldozer.m_dotDestroyed;
	this->setCoordI(position.first);
	this->setCoordJ(position.second);
	this->setStatus(Dot::Status::Bulldozer);
	return *this;
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

std::stack<std::pair<size_t, size_t>> twixt::Bulldozer::getPreviousPosition() const
{
	return m_previousPosition;
}

std::stack<twixt::Peg> twixt::Bulldozer::getPegDestroyed() const
{
	return m_dotDestroyed;
}

void twixt::Bulldozer::setToPreviousPosition(Board& board)
{
	position.first = m_previousPosition.top().first;
	position.second = m_previousPosition.top().second;

	m_previousPosition.pop();

	board.getDot(position.first, position.second).reset(new Bulldozer(*this));
	board.m_bulldozer = Observer_ptr<Bulldozer>(dynamic_cast<Bulldozer*>(board.getDot(position.first, position.second).get()));

}


