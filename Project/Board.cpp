#include "Board.h"

namespace twixt
{
	void Board::showBoard() const
	{
		for (int i = 0; i < m_matrixDot.size(); i++)
		{
			for (int j = 0; j < m_matrixDot[i].size(); j++)
			{
				if (m_matrixDot[i][j].getStatus() == Dot::DotStatus::Clear)
					std::cout << "_";
				if (m_matrixDot[i][j].getStatus() == Dot::DotStatus::Player1)
					std::cout << "R";
				if (m_matrixDot[i][j].getStatus() == Dot::DotStatus::Player2)
					std::cout << "B";
				std::cout << " ";
			}
			std::cout << "\n";
		}

	}

	bool Board::isAvailableDot(const Dot& dot) const
	{
		return dot.getStatus() == Dot::DotStatus::Clear;
	}

	void Board::makeStatus(int i, int j, Dot::DotStatus status)
	{
		if (isAvailableDot(m_matrixDot[i][j]))
		{
			m_matrixDot[i][j].setStatus(status);
			buildPossibleBridges(m_matrixDot[i][j]); // building possible bridges in the dots around
			m_matrixDot[i][j].possibleToExistingBridges();
		}
		else
		{
			std::cout << "Nodul este deja ocupat!\n";
		}
	}

	void Board::buildPossibleBridges(Dot& dot)
	{
		std::vector<std::pair<int, int>> positions{ { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } };

		int x = dot.getCoordX();
		int y = dot.getCoordY();

		std::cout << "Build possible bridges called for " << x << " " << y << std::endl;

		for (auto pair : positions)
		{
			int newX = x + pair.first;
			int newY = y + pair.second;

			if (newX >= 0 && newX < m_matrixDot.size() && newY >= 0 && newY < m_matrixDot[newX].size()) // check boundaries
			{
				if (m_matrixDot[newX][newY].getStatus() == Dot::DotStatus::Clear &&
					!m_matrixDot[newX][y].checkExistingBridge(&m_matrixDot[x][newY])) // check if the possible path for the bridge is not blocked on the other diagonal
				{
					std::cout << "Possible bridge added between " << x << " " << y << "    and  " << newX << " " << newY << std::endl;
					m_matrixDot[newX][newY].addPossibleBridge(&m_matrixDot[x][y]);
				}
			}
		}
	}

	Board::Board() {}

	Board::Board(uint32_t size)
	{
		m_matrixDot.resize(size);
		for (int i = 0; i < size; ++i)
		{
			m_matrixDot[i].resize(size);
		}

		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				m_matrixDot[i][j].setCoordX(i);
				m_matrixDot[i][j].setCoordY(j);
			}
		}
	}

	Board::Board(const Board& newBoard)
	{
		m_matrixDot = newBoard.m_matrixDot;
	}

	Board::~Board() {}

	Dot Board::getDot(int i, int j) const
	{
		if (i >= 0 && i < m_matrixDot.size() && j >= 0 && j < m_matrixDot[i].size()) 
		{
			return m_matrixDot[i][j];
		}

		throw std::out_of_range("Index out of bounds while trying to get Dot.");
	}

	void Board::setDot(int i, int j, const Dot& dot) 
	{
		if (i >= 0 && i < m_matrixDot.size() && j >= 0 && j < m_matrixDot[i].size()) 
		{
			m_matrixDot[i][j] = dot;
			return;
		}

		throw std::out_of_range("Index out of bounds while trying to set Dot.");
	}


	Board& Board::operator=(const Board& newBoard)
	{
		m_matrixDot = newBoard.m_matrixDot;
		return *this;
	}
}