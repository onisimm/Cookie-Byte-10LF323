#pragma once
#ifndef UNDO_H
#define UNDO_H


#include<stack>
#include "GameStack.h"
#include "../DLL/Board.h"
#include "../DLL/Bulldozer.h"

namespace twixt {
	class Undo
	{
	private:
		std::unique_ptr<Dot> m_lastDot;
		int m_type;
		std::reference_wrapper<Board> board;
		Peg m_deletedBridgeDot;
		Peg m_addedBridgeDot;
	public:
		Undo(std::reference_wrapper<GameStack> gameStack, Board* gameBoard);
		void pressed();
		void undoPlayers(Dot::Status status);
		void undoBulldozer();
		void undoMines(std::unique_ptr<Dot>& mine);
		void undoDeleteBridge();
		void undoAddBridge();
	};
}

#endif // !UNDO_H
