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

		// Getters
		Dot getDot(int i, int j) const;

		// Setters
		void setDot(int i, int j, const Dot& dot);

		// Operators Overload
		Board& operator=(const Board& newBoard);

		void showBoard() const;
		bool isAvailableDot(const Dot& dot) const;
		void makeStatus(int i, int j, Dot::DotStatus status);

		void buildPossibleBridges(Dot & dot);

	private:
		std::vector<std::vector<Dot>> m_matrixDot;
	};
}