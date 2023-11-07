#include"Dot.h"
#include "Player.h"
#include<iostream>
using namespace twixt;

int main()
{
	Board board(5);
	Player player1("nume1", Player::Color::Red);
	Player player2("nume2", Player::Color::Black);

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
	
		std::cout << "It's " << player2.getName() << "'s turn!\n";
		player2.turn(board);
		board.showBoard();
		std::cout << "\n";

		if (board.checkPath(Dot::DotStatus::Player1)) {
			std::cout << "Red won!";
			isPlaying = false;
			break;
		}

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
