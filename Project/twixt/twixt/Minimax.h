#pragma once

#ifndef MINIMAX_H
#define MINIMAX_H



#include "Board.h"
#include<unordered_map>
namespace twixt {
	class Minimax
	{
		using DotPair = std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>>;
	private:
		struct DotHash {
			size_t operator()(Observer_ptr<Peg> dot) const {
				// Combine the hashes of x and y using a simple hash combining algorithm
				return std::hash<size_t>()(dot.GetPointer()->getCoordI()) ^ (std::hash<size_t>()(dot.GetPointer()->getCoordJ()) << 1);
			}
		};

		struct PairDotHash {
			size_t operator()(const DotPair& p) const {
				// Combine the hashes of the two Dot instances in the pair
				size_t hash1 = DotHash()(p.first);
				size_t hash2 = DotHash()(p.second);
				return hash1 ^ hash2;
			}
		};

		struct DotPairEqual {
			bool operator()(const DotPair& pair1, const DotPair& pair2) const
			{
				return pair1.first.GetPointer() == pair2.first.GetPointer() &&
					pair2.second.GetPointer() == pair1.second.GetPointer();
			}
		};

		std::unordered_map<std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>>, uint16_t, PairDotHash, DotPairEqual> mapBridges;
		std::reference_wrapper<Board> copyOfBoard;

		//Function that returns the score for each possible bridge
		uint16_t evaluate(std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> bridgeToEvaluate);
		//Function that returns the possible bridge with the highest score
		std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> minimax(Dot::DotStatus status);
		//Function that 
		void canBlock(Observer_ptr<Peg> centralDot);
		Observer_ptr<Peg> blockOpponent(Observer_ptr<Peg> centralDot, Observer_ptr<Peg> firstOpponentDot, Observer_ptr<Peg> secondOpponentDot);
		uint16_t longestPath(Observer_ptr<Peg> dot);
		void scorePossibleBridges(Observer_ptr<Peg> dot);
		bool existsBridgeBetween(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg);

	public:
		Minimax() = default;
		Minimax(Board& board);
		void suggestMove(Dot::DotStatus status);


	};
}

#endif // !MINIMAX_H