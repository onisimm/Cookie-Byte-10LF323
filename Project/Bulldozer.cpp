#include "Bulldozer.h"

twixt::Bulldozer::Bulldozer(Board board)
{
	srand(time(NULL));
	auto [i, j] = position;
	i = rand() % (board.getSize() - 2) + 1;
	j = rand() % (board.getSize() - 2) + 1;
	board.changeDotStatus(i, j, Dot::DotStatus::Bulldozer);
}
