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

	void Board::changeDotStatus(int i, int j, Dot::DotStatus status)
	{
		if (m_matrixDot[i][j].getStatus() == Dot::DotStatus::Clear)
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
				m_matrixDot[i][j].setCoordI(i);
				m_matrixDot[i][j].setCoordJ(j);
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

	int orientation(const Dot& p, const Dot& q, const Dot& r) {
		int val = (q.getCoordJ() - p.getCoordJ()) * (r.getCoordI() - q.getCoordI()) -
			(q.getCoordI() - p.getCoordI()) * (r.getCoordJ() - q.getCoordJ());

		if (val == 0) return 0;
		return (val > 0) ? 1 : 2;
	}

	bool onSegment(const Dot& p, const Dot& q, const Dot& r) {
		if (q.getCoordI() <= std::max(p.getCoordI(), r.getCoordI()) && q.getCoordI() >= std::min(p.getCoordI(), r.getCoordI()) &&
			q.getCoordJ() <= std::max(p.getCoordJ(), r.getCoordJ()) && q.getCoordJ() >= std::min(p.getCoordJ(), r.getCoordJ()))
			return true;
		return false;
	}

	bool doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2) {
		int o1 = orientation(p1, p2, q1);
		int o2 = orientation(p1, p2, q2);
		int o3 = orientation(q1, q2, p1);
		int o4 = orientation(q1, q2, p2);

		if (o1 != o2 && o3 != o4) return true;

		if (o1 == 0 && onSegment(p1, q1, p2)) return true;
		if (o2 == 0 && onSegment(p1, q2, p2)) return true;
		if (o3 == 0 && onSegment(q1, p1, q2)) return true;
		if (o4 == 0 && onSegment(q1, p2, q2)) return true;

		return false;
	}

	bool Board::checkObstructingBridges(const Dot& dot1, const Dot& dot2) const
	{
		int x1 = dot1.getCoordJ();
		int y1 = dot1.getCoordI();
		int x2 = dot2.getCoordJ();
		int y2 = dot2.getCoordI();

		// Check if any existing bridge obstructs the way from dot1 to dot2
		for (int i = std::min(y1, y2); i < std::max(y1, y2); ++i)
		{
			for (int j = std::min(x1, x2); j < std::max(x1, x2); ++j)
			{
				if (m_matrixDot[i][j] == dot1 || m_matrixDot[i][j] == dot2)
				{
					continue;
				}

				for (auto bridgeDot : m_matrixDot[i][j].getExistingBridges())
				{
					if (doIntersect(dot1, dot2, m_matrixDot[i][j], *bridgeDot))
					{
						return false;
					}
				}
			}
		}
		return true;
	}


	void Board::buildPossibleBridges(Dot& dot)
	{
		std::vector<std::pair<int, int>> positions{ { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } };

		int y = dot.getCoordI();
		int x = dot.getCoordJ();

		for (auto pair : positions)
		{
			int newY = y + pair.first;
			int newX = x + pair.second;

			if (newY >= 0 && newY < m_matrixDot.size() && newX >= 0 && newX < m_matrixDot[newY].size()) // check boundaries
			{
				if (m_matrixDot[newY][newX].getStatus() == Dot::DotStatus::Clear &&
					checkObstructingBridges(dot, m_matrixDot[newY][newX])) // check if the possible path for the bridge is not blocked by a bridge
				{
					m_matrixDot[newY][newX].addPossibleBridge(&m_matrixDot[y][x]);
				}
			}
		}
	}
}