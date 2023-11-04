#include"Dot.h"
#include "Player.h"
#include<iostream>
using namespace twixt;

int main()
{
	Board board(24);
	Player player1("nume1", Player::Color::Red);
	Player player2("nume2", Player::Color::Black);

	board.showBoard();

	std::cout << "\n";
	bool isPlaying = true;
	std::string response;

	while (isPlaying)
	{
		std::cout << "Este randul lui " << player1.getName() << "\n";
		player1.turn(board);
		board.showBoard();
		std::cout << "\n";
		std::cout << "Doriti sa continuati jocul? ";
		std::cin >> response;

		if (response == "Nu")
		{
			isPlaying = false;
		}

		std::cout << "Este randul lui " << player2.getName() << "\n";
		player2.turn(board);
		board.showBoard();
		std::cout << "\n";
		std::cout << "Doriti sa continuati jocul? ";
		std::cin >> response;

		if (response == "Nu") 
		{
			isPlaying = false;
		}
	}

	/*player.turn(board);
	board.showBoard();*/
	return 0;
}
