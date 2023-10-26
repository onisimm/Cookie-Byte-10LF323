#include "Board.cppm"

<<<<<<< HEAD
namespace twixt {
	void Board::addPossibleBridges(std::vector<std::vector<std::vector<std::pair<int, int>>>>& possible, int x, int y, twixt::Dot::DotStatus status)
	{
		std::vector<std::pair<int, int>> positions{ { -2, -1 }, { -1, -2 }, { 1,-2 }, { 2, -1 }, { 2,1 }, { 1,2 }, { -1, 2 }, { -2, 1 } };
		for (auto pair : positions)
		{
			if (m_matrixDot[x + pair.first][y + pair.second].getStatus() == twixt::Dot::DotStatus:Clear)
				possible[x + pair.first][y + pair.second].push_back({ x,y });
		}
	}
=======
namespace twixt
{
	Board::Board(){}

	Board::Board(uint32_t size)
	{
		m_matrixDot.resize(size);
		for (auto line : m_matrixDot)
		{
			line.resize(size);
		}
	}
	Board::Board(const Board & newBoard)
	{
		m_possibleBridgesPlayer1 = newBoard.m_possibleBridgesPlayer1;
		m_possibleBridgesPlayer2 = newBoard.m_possibleBridgesPlayer2;
		m_matrixDot = newBoard.m_matrixDot;
	}
	Board::~Board(){}
	Board& Board::operator=(const Board & newBoard)
	{
		m_possibleBridgesPlayer1 = newBoard.m_possibleBridgesPlayer1;
		m_possibleBridgesPlayer2 = newBoard.m_possibleBridgesPlayer2;
		m_matrixDot = newBoard.m_matrixDot;
>>>>>>> bcec62e (Added constructor of Board class)
	}
}