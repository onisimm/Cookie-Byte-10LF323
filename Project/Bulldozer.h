#pragma once

#ifndef BULLDOZER_H
#define BULLDOZER_H

#include"Board.h"
#include <random>
#include <stack>

namespace twixt {
	class Bulldozer
	{
	private:
		std::pair<int, int> position;
		std::stack<std::pair<int, int>> m_previousPosition;
		std::stack<Dot> m_dotDestroied;
		void destoryRandomDot(Board& board);

	public:
		Bulldozer(Board& board);
		Bulldozer() {};
		bool flipCoin(Board& board);
		bool exists();
		uint8_t getI() const;
		uint8_t getJ() const;
		std::stack<std::pair<int, int>> getPreviousPosition() const;
		std::stack<Dot> getDotDestroied() const;
	};
}


#endif