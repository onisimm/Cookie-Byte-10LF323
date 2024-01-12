#pragma once

#include "Dot.h"
#include <iostream>
#include <random>
#include <vector>

namespace twixt {
	class Board {
	public:
		Board();
		Board(uint32_t size);
		Board(const Board& newBoard);
		Board(Board&& other) noexcept;

		~Board();

		Dot*& getDot(int i, int j);
		uint32_t getSize() const;
		std::vector<std::vector<Dot*>> getMatrix();
		Dot* getMatrixDot(int, int);

		void setDot(int i, int j, const Dot& dot);
		void setNewDot(int i, int j);

		// Move assignment operator
		Board& operator=(Board&& other) noexcept;

		// Operators Overload
		Board& operator=(const Board& newBoard);

		void showBoard() const;
		void changeDotStatus(int i, int j, Dot::DotStatus status, bool& didMineExplode);

		void possibleToExistingBridges(Dot* dot);

		friend int orientation(const Dot& p, const Dot& q, const Dot& r);
		friend bool onSegment(const Dot& p, const Dot& q, const Dot& r);
		friend bool doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2);

		bool checkObstructingBridges(const Dot& dot1, const Dot& dot2) const;
		bool checkPossibleObstructingBridges(const Dot& dot1, const Dot& dot2) const;
		std::vector<Bridge*> buildPossibleBridges(Dot* dot) const;

		void rebuildPossibleBridges(Dot* dot);

		bool checkPath(Dot::DotStatus status);
		std::vector<Dot*> FindDotInMargins(Dot::DotStatus status);
		bool checkFinalMargin(Dot* dotToCheck, Dot::DotStatus status);

		void deleteBridge(Dot* firstDot, Dot* secondDot);

		void placeMine(int i, int j);
		void placeRandomMine();
		void mineExplodes(Mine* mine);

		int copieI;
		int copieJ;
	private:
		std::vector<std::vector<Dot*>> m_matrixDot;
	};
}
