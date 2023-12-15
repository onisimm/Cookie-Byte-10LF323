#pragma once
#include "Board.h"
#include<unordered_map>
namespace twixt {
	class Minimax
	{
	private:
		int evaluate(Bridge* bridgeToEvaluate);
		Bridge* minimax(Dot::DotStatus status);
		void canBlock(Dot* centralDot);
		Dot* blockOpponent(Dot* centralDot, Dot* firstOpponentDot, Dot* secondOpponentDot);
		int longestPath(Dot* dot);
		void scorePossibleBridges(Dot* dot);

		Board *copyOfBoard;
		std::unordered_map<Bridge*, int> mapBridges;

	public:
		Minimax() = default;
		void suggestMove();

	};
}


