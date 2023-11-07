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
		void changeDotStatus(int i, int j, Dot::DotStatus status);

		void possibleToExistingBridges(Dot& dot);

		friend int orientation(const Dot& p, const Dot& q, const Dot& r);
		friend bool onSegment(const Dot& p, const Dot& q, const Dot& r);
		friend bool doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2);

		bool checkObstructingBridges(const Dot& dot1, const Dot& dot2) const;
		void buildPossibleBridges(Dot& dot);

		bool checkPath(Dot::DotStatus status);
		std::vector<Dot> FindDotInMargins(Dot::DotStatus status);
		bool checkFinalMargin(Dot dotToCheck, Dot::DotStatus status);

	private:
		std::vector<std::vector<Dot>> m_matrixDot;
	};
}