#include "Board.h"

namespace twixt 
{
	void Board::showBoard()
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

	bool Board::isAvailableDot(Dot dot)
	{
		return dot.getStatus() == Dot::DotStatus::Clear;
	}

	void Board::makeStatus(int i, int j, Dot::DotStatus status)
	{
		if (isAvailableDot(m_matrixDot[i][j]))
		{
			m_matrixDot[i][j].setStatus(status);
		}
		else
		{
			std::cout << "Nodul este deja ocupat!\n";
		}
	}

	Board::Board() {}

	Board::Board(uint32_t size)
	{
		m_matrixDot.resize(size);
		for (int i=0;i<m_matrixDot.size();i++)
		{
			m_matrixDot[i].resize(size);
		}
	}

	Board::Board(const Board & newBoard)
	{
		m_matrixDot = newBoard.m_matrixDot;
	}

	Board::~Board() {}

	Board& Board::operator=(const Board & newBoard)
	{
		m_matrixDot = newBoard.m_matrixDot;
		return *this;
	}
}