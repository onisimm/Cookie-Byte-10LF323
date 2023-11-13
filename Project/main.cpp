#include"Dot.h"
#include "Player.h"
#include<iostream>
using namespace twixt;

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
	Board board(24);
	Player player1("player1", Player::Color::Red);
	Player player2("player2", Player::Color::Black);

	board.showBoard();

	std::cout << "\n";
	bool isPlaying = true;
	std::string response;

	while (isPlaying)
	{
		GameTurns(player1, isPlaying, board);
		GameTurns(player2, isPlaying, board);
		std::cout << "Do you want to continue the game? ";
		std::cin >> response;
		if (response == "No" || response == "no")
		{
			isPlaying = false;
		}
	}
	return 0;
}
