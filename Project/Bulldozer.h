#pragma once
#include"Board.h"
#include <random>

namespace twixt {
	class Bulldozer
	{
	private:
		std::pair<int, int> position;
		void destoryRandomDot(Board board);

	public:
		Bulldozer(Board board);
		void flipCoin(Board board);

	};
}
