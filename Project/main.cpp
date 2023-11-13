#include"Dot.h"
#include "Player.h"
#include<iostream>
using namespace twixt;

void ReadPlayers(Player& player1, Player& player2)
{
	std::cin >> player1 >> player2;
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
		std::cout << "It's " << player1.getName() << "'s turn!\n";
		player1.turn(board);
		board.showBoard();
		std::cout << "\n";

		if (board.checkPath(Dot::DotStatus::Player1)) {
			if (player1.getColor() == Player::Color::Red)
			{
				std::cout << "Red won!";
			}
			else
			{
				std::cout << "Black won!";
			}
			isPlaying = false;
			break;
		}
	
		std::cout << "It's " << player2.getName() << "'s turn!\n";
		player2.turn(board);
		board.showBoard();
		std::cout << "\n";

		if (board.checkPath(Dot::DotStatus::Player2)) {
			std::cout << "Black won!";
			isPlaying = false;
			break;
		}

		std::cout << "Do you want to continue the game? ";
		std::cin >> response;
		if (response == "No" || response == "no")
		{
			isPlaying = false;
		}
	}
	return 0;
}
