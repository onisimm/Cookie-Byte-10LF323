#pragma once
#include "Board.h"
namespace twixt {
	class Minimax
	{
	private:
		int evaluate();
		int minimax(Dot::DotStatus status, int depth);
		bool canBlock(Dot* centralDot);
		Dot* blockOpponent(Dot* centralDot, Dot* firstOpponentDot, Dot* secondOpponentDot);

		Board *copyOfBoard;

	public:
		Minimax() = default;
		void suggestMove();

	};
}


