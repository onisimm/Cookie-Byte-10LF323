#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <array>
#include <iostream>
#include "Dot.h"
#include "Peg.h"


#include <random>



namespace twixt {
	class Bulldozer;
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
		std::unique_ptr<Dot>& getDot(size_t i, size_t j);
		uint32_t getSize() const;
		std::vector<std::vector<std::unique_ptr<Dot>>>& getMatrix();
		std::unique_ptr<Dot>& getMatrixDot(size_t, size_t);
		std::vector<std::unique_ptr<Bridge>>& getBridges();

		// Setters
		//void setDot(size_t i, size_t j, const Dot& dot);
		//void setNewDot(size_t i, size_t j);

		// Move assignment operator
		Board& operator=(Board&& other) noexcept;

		// Operators Overload
		Board& operator=(const Board& newBoard);

		//Print the board in console
		void showBoard() const;

		//place Dot
		//de creat un dot in spate si apoi adaugat in place Dot
		//change the Status to a dot
		void placePiece(size_t i, size_t j, Dot::Status status, bool& didMineExplode);
		void placePiece(size_t i, size_t j, Dot::Status status);

		//placePeg
		bool checkObstructingBridges(const Peg& dot1, const Peg& dot2) const;

		bool checkPath(Dot::Status status);

		//void deleteBridge(Observer_ptr<Peg> firstDot, Observer_ptr<Peg> secondDot);

		void placeMine(size_t i, size_t j);
		void placeRandomMine();
		void placePeg(size_t i, size_t j, Dot::Status status);

		void addBridgeInBoard(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg);
		void deleteBridgeInBoard(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg);
		void deleteAllBridgesForAPegInBoard(Observer_ptr<Peg> peg);

		//Function that we use when a mine explodes, in placePiece
		void explodeMine(Observer_ptr<Mine> mine);

	private:
		//function that is used in checkPossibleObstructingBridges
		//std::unordered_set<Peg*> buildPossibleBridges(Peg* dot) const;

		//Functions that are used in CheckPath
		std::vector<Observer_ptr<Peg>> FindDotInMargins(Dot::Status status);
		bool checkFinalMargin(Observer_ptr<Peg> dotToCheck, Dot::Status status);

		//daca vrem array ne trb variabile cunoscute la compilare (intr un namespace: const size_t, SAU variabila statice cosnt intr-o clasa
		std::vector<std::vector<std::unique_ptr<Dot>>> m_matrixDot;
		std::vector<std::unique_ptr<Bridge>> m_bridges;
	public:
		Observer_ptr<Bulldozer> m_bulldozer;
	};
}

#include "Bulldozer.h"
#endif