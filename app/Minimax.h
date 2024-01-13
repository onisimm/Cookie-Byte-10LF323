#pragma once

#ifndef MINIMAX_H
#define MINIMAX_H



#include "Board.h"
#include<unordered_map>
namespace twixt {
	class Minimax
	{
	private:
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

		std::unordered_map<std::pair<Peg*, Peg*>, uint16_t, PairDotHash> mapBridges;
		Board* copyOfBoard;

		//Function that returns the score for each possible bridge
		uint16_t evaluate(std::pair<twixt::Peg*, twixt::Peg*> bridgeToEvaluate);
		//Function that returns the possible bridge with the highest score
		std::pair<twixt::Peg*, twixt::Peg*> minimax(Dot::DotStatus status);
		//Function that 
		void canBlock(Peg* centralDot);
		Peg* blockOpponent(Peg* centralDot, Peg* firstOpponentDot, Peg* secondOpponentDot);
		uint16_t longestPath(Peg* dot);
		void scorePossibleBridges(Peg* dot);

	public:
		Minimax() = default;
		Minimax(Board* board);
		void suggestMove(Dot::DotStatus status);


	};
}

#endif // !MINIMAX_H