#pragma once
#include<stack>
#include "GameStack.h"
#include "Board.h"

namespace twixt {
	class Undo
	{
	private:
		twixt::Dot* m_lastDot;
		int m_type;
		Board* board;
		Dot* m_deletedBridgeDot;
		Mine* m_lastMine;
	public:
		Undo(GameStack gameStack, Board* gameBoard);
		void pressed();
		void undoPlayers(Dot::DotStatus status);
		void undoBulldozer();
		void undoMines();
		void undoDeleteBridge();

	};
}


