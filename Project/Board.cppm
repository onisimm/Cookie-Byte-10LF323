export module Board;

export import Dot;

import <vector>;

namespace twixt {
	export class Board {
		// Constructor
	private:
		std::vector<std::vector<std::vector<std::pair<int, int>>>> m_possibleBridgesPlayer1, m_possibleBridgesPlayer2;
		std::vector<std::vector<Dot>> m_matrixDot;
	};
}