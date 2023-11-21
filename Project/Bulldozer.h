#pragma once

#ifndef BULLDOZER_H
#define BULLDOZER_H

#include"Board.h"
#include <random>

namespace twixt {
	class Bulldozer
	{
	private:
		std::pair<int, int> position;
		void destoryRandomDot(Board& board);

	public:
		Bulldozer(Board& board);
		Bulldozer() {};
		void flipCoin(Board& board);
		bool exists();

	};
}


#endif