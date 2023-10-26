#include "Board.cppm"

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
	}
}