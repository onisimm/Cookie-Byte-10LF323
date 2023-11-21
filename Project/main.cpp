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


void Game(Board board, Player player1, Player player2, Bulldozer bulldozer = Bulldozer())
{
	board.showBoard();

	std::cout << "\n";
	bool isPlaying = true;
	std::string response;

	while (isPlaying)
	{
		GameTurns(player1, isPlaying, board);
		if (isPlaying == false) break;
		GameTurns(player2, isPlaying, board);
		if (bulldozer.exists())
		{
			bulldozer.flipCoin(board);
		}
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
			int i, j;
			std::cin >> i >> j;
			board.getDot(i, j)->deleteAllBridgesForADot();
		}
	}
	
}

int main()
{
	Board board(BOARD_SIZE);

	Player player1("player1", Player::Color::Red);
	Player player2("player2", Player::Color::Black);

	std::cout << "Choose you game mode:\n1->DEFAULT\n2->BULLDOZER\n3->MINES.\n";
	int mode;
	std::cin >> mode;
	switch (mode)
	{
	case 1:
		Game(board, player1, player2);
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			board.placeRandomMine();
		}
		Game(board, player1, player2);
		break;
	case 2:
		Bulldozer bulldozer(board);
		Game(board, player1, player2, bulldozer);
		break;
	}
	
	return 0;
}
