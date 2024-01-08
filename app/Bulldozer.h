#pragma once

#ifndef BULLDOZER_H
#define BULLDOZER_H

#include"Board.h"
#include <random>
#include <stack>

namespace twixt {
	class Bulldozer : public Dot
	{
	private:
		std::pair<size_t, size_t> position;
		std::stack<std::pair<size_t, size_t>> m_previousPosition;
		std::stack<Peg> m_dotDestroyed;
		void destoryRandomDot(Board& board);
		void allocateBulldozer(Dot*& dot);

	public:
		Bulldozer(Board* board);
		Bulldozer(const Bulldozer& Bulldozer);
		Bulldozer() {};
		~Bulldozer()override
		{}
		bool flipCoin(Board& board);
		bool exists();
		//uint8_t getI() const;
		//uint8_t getJ() const;
		std::stack<std::pair<size_t, size_t>> getPreviousPosition() const;
		std::stack<Peg> getPegDestroyed() const;
		void setToPreviousPosition(Board& board);
	};
}


#endif