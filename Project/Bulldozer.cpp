#include "Bulldozer.h"

void twixt::Bulldozer::destoryRandomDot(Board board)
{
	srand(time(NULL));
	auto [i, j] = position;
	i = rand() % (board.getSize() - 2) + 1;
	j = rand() % (board.getSize() - 2) + 1;
	while (board.getDot(i, j)->getStatus() != Dot::DotStatus::Player1 && board.getDot(i, j)->getStatus() != Dot::DotStatus::Player2)
	{
		i = rand() % (board.getSize() - 2) + 1;
		j = rand() % (board.getSize() - 2) + 1;
	}
	//now i have the correct position for the dot
}

twixt::Bulldozer::Bulldozer(Board board)
{
	srand(time(NULL));
	auto [i, j] = position;
	i = rand() % (board.getSize() - 2) + 1;
	j = rand() % (board.getSize() - 2) + 1;
	board.changeDotStatus(i, j, Dot::DotStatus::Bulldozer);
}

void twixt::Bulldozer::flipCoin(Board board)
{
	srand(time(NULL));
	if (rand() % 2)
		return;
	destoryRandomDot(board);
}
