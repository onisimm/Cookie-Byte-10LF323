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
		std::pair<int, int> position;
		std::stack<std::pair<int, int>> m_previousPosition;
		std::stack<Dot> m_dotDestroyed;
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
		uint8_t getI() const;
		uint8_t getJ() const;
		std::stack<std::pair<int, int>> getPreviousPosition() const;
		std::stack<Dot> getDotDestroyed() const;
		void setToPreviousPosition(Board& board);
	};
}


#endif