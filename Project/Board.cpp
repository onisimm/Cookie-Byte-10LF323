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
			buildPossibleBridges(m_matrixDot[i][j]); // adding this dot as possible bridge in dots around
			if (!m_matrixDot[i][j].getPossibleBridges().empty())
			{
				possibleToExistingBridges(m_matrixDot[i][j]); // building current dot's possible bridges
			}
		}
		else
		{
			std::cout << "Node already occupied!\n";
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

	Board::Board(const Board& newBoard) : m_matrixDot{ newBoard.m_matrixDot } {}

	Board::~Board() {}

	Dot* Board::getDot(int i, int j)
	{
		if (i >= 0 && i < m_matrixDot.size() && j >= 0 && j < m_matrixDot[i].size())
		{
			return &(m_matrixDot[i][j]);
		}

		throw std::out_of_range("Index out of bounds while trying to get Dot.");
	}

	uint32_t Board::getSize() const
	{
		//Getter for matrixSize;
		return m_matrixDot.size();
	}

	std::vector<std::vector<Dot>> Board::getMatrix()
	{
		return m_matrixDot;
	}

	Dot& Board::getMatrixDot(int i, int j)
	{
		return m_matrixDot[i][j];
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

	void Board::possibleToExistingBridges(Dot& dot)
	{
		for (auto dotForBridge : dot.getPossibleBridges())
		{
			if (dot.getStatus() == dotForBridge->getStatus() && dot.getStatus() != Dot::DotStatus::Clear)
			{
				if (checkObstructingBridges(dot, *dotForBridge))
				{
					dot.buildBridge(dotForBridge);
				}
			}
		}

		dot.clearPossibleBridges();
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
		for (int i = std::min(y1, y2); i <= std::max(y1, y2); ++i)
		{
			for (int j = std::min(x1, x2); j <= std::max(x1, x2); ++j)
			{
				if (m_matrixDot[i][j] == dot1 || m_matrixDot[i][j] == dot2)
				{
					continue;
				}

				for (auto bridgeDot : m_matrixDot[i][j].getExistingBridges())
				{
					if (doIntersect(dot1, dot2, m_matrixDot[i][j], *bridgeDot))
					{
						// std::cout << "Couldn't build a bridge between (" << dot1 << " and " << dot2 << " because of the bridge between " << m_matrixDot[i][j] << " and " << *bridgeDot << "\n";
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
			auto [newY, newX] = pair;
			newY += y;
			newX += x;
			/*int newY = y + pair.first;
			int newX = x + pair.second;*/

			if (newY >= 0 && newY < m_matrixDot.size() && newX >= 0 && newX < m_matrixDot[newY].size()) // check boundaries
			{
				if (m_matrixDot[newY][newX].getStatus() == Dot::DotStatus::Clear)
				{
					m_matrixDot[newY][newX].addPossibleBridge(&m_matrixDot[y][x]);
				}
			}
		}
	}

	bool Board::checkPath(twixt::Dot::DotStatus status)
	{
		std::vector<Dot> margins = FindDotInMargins(status);
		if (margins.empty()) return false;
		int index = 0;
		Dot firstDot = margins[index];
		Dot newDot;
		/*Dot checkDot, newDot;
		int position;*/

		//Creating path vector: pair of dot in path and position of existing bridges for the dot.
		std::vector<std::pair<Dot, int>> path;

		bool isFinalDot = false;
		path.push_back({ firstDot, 0 });
		while (!isFinalDot && !path.empty())
		{
			auto [checkDot, position] = path[path.size() - 1];
			/*checkDot = path[path.size() - 1].first;
			position = path[path.size() - 1].second;*/
			if (position < checkDot.getExistingBridges().size())
			{
				newDot = *(checkDot.getExistingBridges())[position];
				if (!newDot.isDotInPath(path))
				{
					path.push_back({ newDot, -1 });
					checkDot = path[path.size() - 1].first;
					if (checkFinalMargin(checkDot, status))
					{
						isFinalDot = true;
					}
				}
			}
			else
			{
				path.pop_back();
			}
			if (!path.empty())
				path[path.size() - 1].second++;
			else
			{
				index++;
				if (index < margins.size())
				{
					path.push_back({ margins[index], 0 });
				}
			}

		}
		return isFinalDot;
	}

	std::vector<Dot> Board::FindDotInMargins(Dot::DotStatus status)
	{
		std::vector<Dot> margin;
		if (status == Dot::DotStatus::Player1)
		{
			for (int i = 0; i < m_matrixDot.size(); i++)
			{
				if (m_matrixDot[0][i].getStatus() == Dot::DotStatus::Player1)
				{
					margin.push_back(m_matrixDot[0][i]);
				}
				if (m_matrixDot[1][i].getStatus() == Dot::DotStatus::Player1)
				{
					margin.push_back(m_matrixDot[1][i]);
				}
			}
		}
		else
		{
			for (int i = 0; i < m_matrixDot.size(); i++)
			{
				if (m_matrixDot[i][0].getStatus() == Dot::DotStatus::Player2)
				{
					margin.push_back(m_matrixDot[i][0]);
				}
				if (m_matrixDot[i][1].getStatus() == Dot::DotStatus::Player2)
				{
					margin.push_back(m_matrixDot[i][1]);
				}
			}
		}
		return margin;
	}
	bool Board::checkFinalMargin(Dot dotToCheck, Dot::DotStatus status)
	{
		if (status == Dot::DotStatus::Player1)
		{
			for (int i = 0; i < m_matrixDot.size(); i++)
			{
				if (dotToCheck == m_matrixDot[m_matrixDot.size() - 1][i] || dotToCheck== m_matrixDot[m_matrixDot.size() - 2][i])
				{
					return true;
				}
			}
		}
		else
		{
			for (int i = 0; i < m_matrixDot.size(); i++)
			{
				if (dotToCheck == m_matrixDot[i][m_matrixDot.size() - 1] || dotToCheck== m_matrixDot[m_matrixDot.size() - 2][i])
				{
					return true;
				}
			}
		}
		return false;
	}
	void Board::deleteBridge(Dot& firstDot, Dot& secondDot)
	{

		std::vector<Dot*> firstExistingBridges = firstDot.getExistingBridges();
		firstExistingBridges.erase(find(firstExistingBridges.begin(), firstExistingBridges.end(), &secondDot));
		std::vector<Dot*> secondExistingBridges = secondDot.getExistingBridges();
		secondExistingBridges.erase(find(secondExistingBridges.begin(), secondExistingBridges.end(), &firstDot));
		std::cout << "DELETE BRIDGE between " << firstDot.getCoordI() << " " << firstDot.getCoordJ() << " and " << secondDot.getCoordI() << " " << secondDot.getCoordJ();

	}
	
	void Board::mineExplodes(Dot& mine)
	{
		std::vector<std::pair<int, int>> positions{ {-1, -1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1} };
		int i = mine.getCoordI();
		int j = mine.getCoordJ();
		std::cout << "Mine " << i << " " << j << " exploded!\n";
		for (auto pair : positions)
		{
			auto [newI, newJ] = pair;
			newI += i;
			newJ += j;
			if (newI >= 0 && newI < m_matrixDot.size() && newJ >= 0 && newJ < m_matrixDot[newI].size()) // check boundaries
			{
				if (m_matrixDot[newI][newJ].getStatus() == Dot::DotStatus::Player1 || m_matrixDot[newI][newJ].getStatus() == Dot::DotStatus::Player2)
				{
					m_matrixDot[newI][newJ].setStatus(Dot::DotStatus::Clear);
					m_matrixDot[newI][newJ].deleteAllBridgesForADot();
					std::cout << "Dot " << newI << " " << newJ << " was erased!\n";
				}
				if (m_matrixDot[newI][newJ].getStatus() == Dot::DotStatus::Mines)
				{
					mineExplodes(m_matrixDot[newI][newJ]);
				}
			}
		}
		m_matrixDot[i][j].setStatus(Dot::DotStatus::Clear);
	}
}