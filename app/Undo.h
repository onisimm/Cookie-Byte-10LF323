#pragma once

#include "Board.h"
#include "Bulldozer.h"
#include "GameStack.h"
#include <stack>

namespace twixt {
	class Undo
	{
	private:
		twixt::Dot* m_lastDot;
		int m_type;
		Board* board;
		Dot* m_deletedBridgeDot;
	public:
		Undo(GameStack* gameStack, Board* gameBoard);
		void pressed();
		void undoPlayers(Dot::DotStatus status);
		void undoBulldozer();
		void undoMines(Dot* mine);
		void undoDeleteBridge();
		
	};
}


