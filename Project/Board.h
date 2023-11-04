#include <vector>
#include <iostream>
#include "Dot.h"

namespace twixt {
	class Board {
	public:
		// Constructors
		Board();
		Board(uint32_t size);
		Board(const Board& newBoard);

		// Destructor
		~Board();

		// Operators Overload
		Board& operator=(const Board& newBoard);

		void showBoard();
		bool isAvailableDot(Dot dot);
		void makeStatus(int i, int j, Dot::DotStatus status);

		void buildPossibleBridges(Dot & dot);

	private:
		std::vector<std::vector<Dot>> m_matrixDot;
	};

}