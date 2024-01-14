#include "Bulldozer.h"

void twixt::Bulldozer::destoryRandomDot(Board& board)
{
	srand(time(NULL));
	size_t row = rand() % (board.getSize() - 2) + 1;
	size_t column = rand() % (board.getSize() - 2) + 1;
	while (board.getDot(row, column)->getStatus() != Dot::Status::Player1 && board.getDot(row, column)->getStatus() != Dot::Status::Player2)
	{
		row = rand() % (board.getSize() - 2) + 1;
		column = rand() % (board.getSize() - 2) + 1;
	}

	//assign the destroyed dot 
	m_dotDestroyed.push(*dynamic_cast<Peg*>(board.getDot(row, column).get()));
	for (int index = 0; index < m_dotDestroyed.top().getExistingBridges().size(); index++)
	{
		m_dotBridgesDestroyed.push(*(m_dotDestroyed.top().getExistingBridges()[index].GetPointer()->returnTheOtherPillar(Observer_ptr<Dot>(board.getDot(row, column).get()).To<Peg>())).GetPointer());
	}

	//delete the random Dot
	board.deleteAllBridgesForAPegInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getDot(row, column).get())));

	//assign the previous position
	m_previousPosition.push(position);


	//set the new position for the bulldozer
	position.first = row;
	position.second = column;
	this->setCoordI(row);
	this->setCoordJ(column);
	this->setStatus(Dot::Status::Bulldozer);

	board.getDot(row, column).reset(new Bulldozer(*this));
	board.m_bulldozer = Observer_ptr<Bulldozer>(dynamic_cast<Bulldozer*>(board.getDot(row, column).get()));

	//eliminate the current bulldozer
	board.getDot(m_previousPosition.top().first, m_previousPosition.top().second).reset(new Dot(m_previousPosition.top().first, m_previousPosition.top().second));

}


//Constructor 
twixt::Bulldozer::Bulldozer(Board& board)
{
	srand(time(NULL));
	auto [row, column] = position;
	row = rand() % (board.getSize() - 2) + 1;
	column = rand() % (board.getSize() - 2) + 1;
	//find a clear Dot and set it as a bulldozer
	while (board.getDot(row, column)->getStatus() != Dot::Status::Empty)
	{
		row = rand() % (board.getSize() - 2) + 1;
		column = rand() % (board.getSize() - 2) + 1;
	}
	position.first = row;
	position.second = column;
	board.getDot(row, column).reset(new Bulldozer(*this));
	board.m_bulldozer = Observer_ptr<Bulldozer>(dynamic_cast<Bulldozer*>(board.getDot(row, column).get()));
}

twixt::Bulldozer::Bulldozer(const Bulldozer& bulldozer) : Dot(bulldozer), position{ bulldozer.position }, m_previousPosition{ bulldozer.m_previousPosition }, m_dotDestroyed{ bulldozer.m_dotDestroyed }, m_dotBridgesDestroyed{ bulldozer.m_dotBridgesDestroyed }
{
	this->setCoordI(position.first);
	this->setCoordJ(position.second);
	this->setStatus(Dot::Status::Bulldozer);
}

twixt::Bulldozer& twixt::Bulldozer::operator=(const Bulldozer& Bulldozer)
{
	position = Bulldozer.position;
	m_previousPosition = Bulldozer.m_previousPosition;
	m_dotDestroyed = Bulldozer.m_dotDestroyed;
	m_dotBridgesDestroyed = Bulldozer.m_dotBridgesDestroyed;
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

std::stack<twixt::Peg>& twixt::Bulldozer::getPegDestroyed()
{
	return m_dotDestroyed;
}

std::stack<twixt::Peg>& twixt::Bulldozer::getPegBridgeDestroyed()
{
	return m_dotBridgesDestroyed;
}

void twixt::Bulldozer::setToPreviousPosition(Board& board)
{
	position.first = m_previousPosition.top().first;
	position.second = m_previousPosition.top().second;

	m_previousPosition.pop();

	board.getDot(position.first, position.second).reset(new Bulldozer(*this));
	board.m_bulldozer = Observer_ptr<Bulldozer>(dynamic_cast<Bulldozer*>(board.getDot(position.first, position.second).get()));

}


