#include "Bulldozer.h"

void twixt::Bulldozer::destoryRandomDot(Board& board)
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
	board.getDot(i, j)->setStatus(Dot::DotStatus::Bulldozer);
	board.getDot(position.first, position.second)->setStatus(Dot::DotStatus::Clear);
	position.first = i;
	position.second = j;
	std::cout << "VOm distruge " << i << " " << j << "\n";
	board.getDot(i, j)->deleteAllBridgesForADot();
}

twixt::Bulldozer::Bulldozer(Board& board)
{
	srand(time(NULL));
	auto [i, j] = position;
	i = rand() % (board.getSize() - 2) + 1;
	j = rand() % (board.getSize() - 2) + 1;
	while (board.getDot(i, j)->getStatus() != Dot::DotStatus::Clear)
	{
		i = rand() % (board.getSize() - 2) + 1;
		j = rand() % (board.getSize() - 2) + 1;
	}
	board.changeDotStatus(i, j, Dot::DotStatus::Bulldozer);
}

void twixt::Bulldozer::flipCoin(Board& board)
{
	srand(time(NULL));
	/*if (rand() % 2)
	{
		std::cout << "Nu se va intampla nimic\n";
		return;
	}*/
	std::cout << "vom distruge un dot\n";
	destoryRandomDot(board);
	board.showBoard();
}
