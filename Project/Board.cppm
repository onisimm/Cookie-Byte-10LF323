export module Board;

export import Dot;

import <vector>;

namespace twixt {
	export class Board {
		// Constructor goes here
	private:
		std::vector<std::vector<std::vector<std::pair<int, int>>>> m_possibleBridgesPlayer1, m_possibleBridgesPlayer2;
		std::vector<std::vector<Dot>> m_matrixDot;
	public:
		void addPossibleBridges(std::vector<std::vector<std::vector<std::pair<int, int>>>>& possible, int x, int y, twixt::Dot::DotStatus status);
	};
}