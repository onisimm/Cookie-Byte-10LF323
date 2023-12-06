#pragma once
#include<stack>
#include "GameStack.h"
#include "Board.h"

namespace twixt {
	class Undo
	{
	private:
		GameStack m_undoGameStack;
	public:
		Undo(GameStack gameStack);
		void pressed(Board board);

	};
}


