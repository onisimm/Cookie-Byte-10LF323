#pragma once
#include"Board.h"
#include <random>

namespace twixt {
	class Bulldozer
	{
	private:
		std::pair<int, int> position;

	public:
		Bulldozer(Board board);

	};
}
