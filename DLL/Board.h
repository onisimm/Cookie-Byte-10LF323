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
	__declspec(dllexport) int orientation(const Dot& p, const Dot& q, const Dot& r);
	__declspec(dllexport) bool onSegment(const Dot& p, const Dot& q, const Dot& r);
	__declspec(dllexport) bool doIntersect(const Dot& p1, const Dot& p2, const Dot& q1, const Dot& q2);
	class Board {
	public:
		// Constructors
		__declspec(dllexport) Board();
		__declspec(dllexport) Board(uint32_t size);
		__declspec(dllexport) Board(const Board& newBoard);
		//Add move constructor
		__declspec(dllexport) Board(Board&& other) noexcept;

		// Destructor
		__declspec(dllexport) ~Board();

		// Getters
		__declspec(dllexport) std::unique_ptr<Dot>& getDot(size_t row, size_t column);
		__declspec(dllexport) uint32_t getSize() const;
		__declspec(dllexport) std::vector<std::vector<std::unique_ptr<Dot>>>& getMatrix();
		__declspec(dllexport) std::unique_ptr<Dot>& getMatrixDot(size_t, size_t);
		__declspec(dllexport) std::vector<std::unique_ptr<Bridge>>& getBridges();

		// Setters
		//void setDot(size_t i, size_t j, const Dot& dot);
		//void setNewDot(size_t i, size_t j);

		// Move assignment operator
		__declspec(dllexport) Board& operator=(Board&& other) noexcept;

		// Operators Overload
		__declspec(dllexport) Board& operator=(const Board& newBoard);

		//Print the board in console
		__declspec(dllexport) void showBoard() const;

		//place Dot
		//de creat un dot in spate si apoi adaugat in place Dot
		//change the Status to a dot
		__declspec(dllexport) void placePiece(size_t row, size_t column, Dot::Status status, bool& didMineExplode);
		__declspec(dllexport) void placePiece(size_t row, size_t column, Dot::Status status);

		//placePeg
		__declspec(dllexport) bool checkObstructingBridges(const Peg& dot1, const Peg& dot2) const;

		__declspec(dllexport) bool checkPath(Dot::Status status);

		//void deleteBridge(Observer_ptr<Peg> firstDot, Observer_ptr<Peg> secondDot);

		__declspec(dllexport) void placeMine(size_t row, size_t column);
		__declspec(dllexport) void placeRandomMine();
		__declspec(dllexport) void placePeg(size_t row, size_t column, Dot::Status status);

		__declspec(dllexport) void addBridgeInBoard(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg);
		__declspec(dllexport) void deleteBridgeInBoard(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg);
		__declspec(dllexport) void deleteAllBridgesForAPegInBoard(Observer_ptr<Peg> peg);

		//Function that we use when a mine explodes, in placePiece
		__declspec(dllexport) void explodeMine(Observer_ptr<Mine> mine);

	private:
		//function that is used in checkPossibleObstructingBridges
		//std::unordered_set<Peg*> buildPossibleBridges(Peg* dot) const;

		//Functions that are used in CheckPath
		__declspec(dllexport) std::vector<Observer_ptr<Peg>> FindDotInMargins(Dot::Status status);
		__declspec(dllexport) bool checkFinalMargin(Observer_ptr<Peg> dotToCheck, Dot::Status status);

		//daca vrem array ne trb variabile cunoscute la compilare (intr un namespace: const size_t, SAU variabila statice cosnt intr-o clasa
		std::vector<std::vector<std::unique_ptr<Dot>>> m_matrixDot;
		std::vector<std::unique_ptr<Bridge>> m_bridges;
	public:
		Observer_ptr<Bulldozer> m_bulldozer;
	};
}

#include "Bulldozer.h"
#endif