#include"Dot.h"
#include "Player.h"
#include "Bulldozer.h"
#include<iostream>
using namespace twixt;

#define BOARD_SIZE 24

void ReadPlayers(Player& player1, Player& player2)
{
	std::cin >> player1 >> player2;
}

void GameTurns(Player player, bool& isPlaying, Board& board)
{
	std::cout << "It's " << player.getName() << "'s turn!\n";
	player.turn(board);
	board.showBoard();
	std::cout << "\n";
	Dot::DotStatus status;
	if (player.getColor() == Player::Color::Red)
	{
		status = Dot::DotStatus::Player1;
	}
	else
	{
		status = Dot::DotStatus::Player2;
	}
	if (board.checkPath(status))
	{
		std::cout << "You won!";
		isPlaying = false;
	}
}

int main()
{
	std::cout << "Hello";
	Board board(BOARD_SIZE);
	Player player1("player1", Player::Color::Red);
	Player player2("player2", Player::Color::Black);
	Bulldozer bulldozer(board);

	board.showBoard();

	std::cout << "\n";
	bool isPlaying = true;
	std::string response;

	while (isPlaying)
	{
		GameTurns(player1, isPlaying, board);
		if (isPlaying == false) break;
		GameTurns(player2, isPlaying, board);
		std::cout << "Do you want to continue the game? ";
		std::cin >> response;
		if (response == "No" || response == "no")
		{
			isPlaying = false;
		}
		if (response == "delete" || response == "Delete")
		{
			std::cout << "Choose the first dot: ";
			int i1, j1, i2, j2;
			std::cin >> i1 >> j1;
			std::cout << "Choose the second dot: ";
			std::cin >> i2 >> j2;
			board.deleteBridge(board.getMatrixDot(i1, j1), board.getMatrixDot(i2, j2));
		}
		if (response == "deleteall" || response == "DeleteAll")
		{
			std::cout << "Choose the dot: ";
			int i,j;
			std::cin >> i >> j;
			board.getDot(i, j)->deleteAllBridgesForADot();
		}
		if (response == "bulldozer")
		{
			bulldozer.flipCoin(board);
		}
	}
	return 0;
}
