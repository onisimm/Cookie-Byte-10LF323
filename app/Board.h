#pragma once
#include <vector>
#include <array>
#include <iostream>
#include "Dot.h"
#include <random>

#ifndef BOARD_H
#define BOARD_H

namespace twixt {
	int orientation(const Dot& p, const Dot& q, const Dot& r);
	bool onSegment(const Dot& p, const Dot& q, const Dot& r);
	bool doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2);
	class Board {
	public:
		// Constructors
		Board();
		Board(uint32_t size);
		Board(const Board& newBoard);
		//Add move constructor
		Board(Board&& other) noexcept;

		// Destructor
		~Board();

		// Getters
		Dot*& getDot(size_t i, size_t j);
		uint32_t getSize() const;
		std::vector<std::vector<Dot*>> getMatrix();
		Dot* getMatrixDot(size_t, size_t);

		// Setters
		void setDot(size_t i, size_t j, const Dot& dot);
		void setNewDot(size_t i, size_t j);

		// Move assignment operator
		Board& operator=(Board&& other) noexcept;

		// Operators Overload
		Board& operator=(const Board& newBoard);

		//Print the board in console
		void showBoard() const;

		//place Dot
		//de cresaat un dot in spate si apoi adaugat in place Dot
		//change the Status to a dot
		void changeDotStatus(size_t i, size_t j, Dot::DotStatus status, bool& didMineExplode);
		void changeDotStatus(size_t i, size_t j, Dot::DotStatus status);

		/*friend int orientation(const Dot& p, const Dot& q, const Dot& r);
		friend bool onSegment(const Dot& p, const Dot& q, const Dot& r);
		friend bool doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2);*/

		//placePeg
		bool checkObstructingBridges(const Dot& dot1, const Dot& dot2) const;
		bool checkPossibleObstructingBridges(const Dot& dot1, const Dot& dot2) const;


		bool checkPath(Dot::DotStatus status);

		void deleteBridge(Peg* firstDot, Peg* secondDot);

		void placeMine(size_t i, size_t j);
		void placeRandomMine();
		//de modificat in mina


		size_t copieI;
		size_t copieJ;
	private:

		//function that is used in checkPossibleObstructingBridges
		std::unordered_set<Peg*> buildPossibleBridges(Peg* dot) const;

		//Functions that are used in CheckPath
		std::vector<Peg*> FindDotInMargins(Dot::DotStatus status);
		bool checkFinalMargin(Dot* dotToCheck, Dot::DotStatus status);

		//Function that we use when a mine explodes, in changeDotStatus
		void mineExplodes(Mine* mine);

		//daca vrem array ne trb variabile cunoscute la compilare (intr un namespace: const size_t, SAU variabila statice cosnt intr-o clasa
		std::vector<std::vector<Dot*>> m_matrixDot;
	};
}

#endif