#include <vector>
#include <iostream>
#include "Dot.h"

namespace twixt {
	class Board {
	public:
		// Constructor
		Board();
		Board(uint32_t size);
		Board(const Board& newBoard);
		~Board();
		Board& operator=(const Board& newBoard);
		//void addPossibleBridges(std::vector<std::vector<std::vector<std::pair<int, int>>>>& possible, int x, int y, Dot::DotStatus status);
		void showBoard();

		void makeStatus(int i, int j, Dot::DotStatus status);

	private:
		std::vector<std::vector<std::vector<std::pair<int, int>>>> m_possibleBridges;
		std::vector<std::vector<Dot>> m_matrixDot;

	};

}