#pragma once

#include "Board.h"
#include <unordered_map>

namespace twixt {
	class Minimax
	{
	private:
		int evaluate(std::pair<twixt::Dot*, twixt::Dot*> bridgeToEvaluate);
		std::pair<twixt::Dot*, twixt::Dot*> minimax(Dot::DotStatus status);
		void canBlock(Dot* centralDot);
		Dot* blockOpponent(Dot* centralDot, Dot* firstOpponentDot, Dot* secondOpponentDot);
		int longestPath(Dot* dot);
		void scorePossibleBridges(Dot* dot);

		Board *copyOfBoard;

		struct DotHash {
			size_t operator()(const Dot* dot) const {
				// Combine the hashes of x and y using a simple hash combining algorithm
				return std::hash<int>()(dot->getCoordI()) ^ (std::hash<int>()(dot->getCoordJ()) << 1);
			}
		};

		struct PairDotHash {
			size_t operator()(const std::pair<Dot*, Dot*>& p) const {
				// Combine the hashes of the two Dot instances in the pair
				size_t hash1 = DotHash()(p.first);
				size_t hash2 = DotHash()(p.second);
				return hash1 ^ hash2;
			}
		};
		std::unordered_map<std::pair<Dot*, Dot*>, int, PairDotHash> mapBridges;


	public:
		Minimax() = default;
		Minimax(Board* board);
		void suggestMove(Dot::DotStatus status);
	

	};
}
