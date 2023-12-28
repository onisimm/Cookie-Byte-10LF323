#pragma once﻿
#include "TwixtGame.h"

#define BOARD_SIZE 24
#define DOTS_NUMBER 50

void TwixtGame::ReadPlayers(Player& player1, Player& player2)
{
	std::cin >> player1 >> player2;
}

void TwixtGame::GameTurns(Player& player, bool& isPlaying, Board& board)
{
	std::string answer;
	std::cout << player.getName() << ", what's you next move?\n";

	// Verificare pentru jucătorul negru în prima tură
	if (!blackPlayerStoleColor && player.getColor() == Player::Color::Black) {
		std::cout << player.getName() << ", do you want to steal the red color? (YES/NO)\n";
		std::cin >> answer;

		for (auto& c : answer) {
			c = toupper(c);
		}
	}
	if (answer == "YES") {
		// Setează culoarea jucătorului negru la roșu
		player.setColor(Player::Color::Red);
		// Setează indicatorul pe true după ce jucătorul a furat culoarea
		blackPlayerStoleColor = true;
		// Increment the number of pawns for the black player
		player.setRemainingDots(player.getRemainingDots() + 1);
		// Mesaj pentru indicarea faptului că jucătorul negru a furat culoarea
		std::cout << "Black player stole the red color!\n";
		std::cout << player.getName() << ", what's you next move?\n";


	}


	Minimax minimaxSuggestion(&board);
	minimaxSuggestion.suggestMove((player.getColor() == Player::Color::Red) ? Dot::DotStatus::Player1 : Dot::DotStatus::Player2);

	std::cin >> answer;

	for (auto& c : answer)
	{
		c = toupper(c);
	}

	if (answer == "ADD")
	{
		std::cout << "It's " << player.getName() << "'s turn!\n";
		// Incrementează numărul de doturi pentru jucătorul negru
		player.setRemainingDots(player.getRemainingDots() + 1);

		std::cout << "REMAINING DOTS for " << player.getName() << ": " << player.getRemainingDots() << "\n";
		ObjectInStack object = player.turn(board);
		m_gameStack.AddInGameStack(object.getDot(), object.getType());
		board.showBoard();
		std::cout << "\n";
	}
	else if (answer == "DELETE")
	{
		std::cout << "Choose the first dot: ";
		int i1, j1, i2, j2;
		std::cin >> i1 >> j1;
		std::cout << "Choose the second dot: ";
		std::cin >> i2 >> j2;
		board.deleteBridge(board.getMatrixDot(i1, j1), board.getMatrixDot(i2, j2));
		m_gameStack.AddInGameStack(board.getMatrixDot(i1, j1), DELETEBRIDGE);
		m_gameStack.AddInDeletedBridgesDotStack(board.getMatrixDot(i2, j2));
	}
	else if (answer == "DELETEALL")
	{
		std::cout << "Choose the dot: ";
		int i, j;
		std::cin >> i >> j;
		board.getDot(i, j)->deleteAllBridgesForADot();
	}
	else if (answer == "SAVE")
	{
		saveGame.saveMatrix(board.getMatrix());
		saveGame.saveStack(m_gameStack);
	}
	else if (answer == "ADDBRIDGE")
	{
		std::cout << "Enter the position of the first dot: ";
		int i1, j1, i2, j2;
		std::cin >> i1 >> j1;
		std::cout << "Enter the position of the second dot: ";
		std::cin >> i2 >> j2;
		if (board.getMatrixDot(i1, j1)->getStatus() == board.getMatrixDot(i2, j2)->getStatus() && board.getMatrixDot(i1, j1)->getStatus() != Dot::DotStatus::Clear)
		{
			if (((abs(i1 - i2) == 1 && abs(j1 - j2) == 2) || (abs(i1 - i2) == 2 && abs(j1 - j2) == 1)) && board.checkObstructingBridges(*board.getMatrixDot(i1, j1), *board.getMatrixDot(i2, j2)))
				board.getMatrixDot(i1, j1)->addBridge(board.getMatrixDot(i2, j2));
		}
		else std::cout << "the dots does not exist\n";
	}
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
		std::cout << "You won!\n";
		isPlaying = false;
		return;
	}
	//nu se adauga automat bridge-uri
	std::cout << "Do you want to undo the move? ";
	std::cin >> answer;
	while (answer != "no")
	{


		for (auto& c : answer)
		{
			c = toupper(c);
		}

		if (answer == "YES")
		{
			Undo undo(&m_gameStack, &board);
			undo.pressed();
			board.showBoard();
		}
		std::cout << "\nDo you want to undo the move? ";
		std::cin >> answer;
	}

}

bool TwixtGame::IsTie(Player player1, Player player2)
{
	return !player1.hasRemainingDots() && !player2.hasRemainingDots();
}

void TwixtGame::GameLoop(Board& board, Player player1, Player player2, Bulldozer bulldozer)
{
	board.showBoard();
	std::cout << "\n";

	bool isPlaying = true;

	while (isPlaying)
	{
		GameTurns(player1, isPlaying, board);

		if (!isPlaying)
		{
			break;
		}

		if (IsTie(player1, player2))
		{
			std::cout << "It's a tie! Both players are out of dots!\n";
			isPlaying = false;
			break;
		}

		GameTurns(player2, isPlaying, board);
		std::string answer;
		if (bulldozer.exists())
		{
			if (bulldozer.flipCoin(board))
			{
				m_gameStack.AddInGameStack(board.getDot(bulldozer.getI(), bulldozer.getJ()), int(Dot::DotStatus::Bulldozer));

				std::cout << "Do you want to undo the move? ";
				std::cin >> answer;

				for (auto& c : answer)
				{
					c = toupper(c);
				}

				if (answer == "YES")
				{
					Undo undo(&m_gameStack, &board);
					undo.pressed();
					board.showBoard();
				}
			}
		}

		if (IsTie(player1, player2))
		{
			std::cout << "It's a tie! Both players are out of dots!\n";
			isPlaying = false;
			break;
		}
	}
}

//void TwixtGame::ResetGame()
//{
//	//Reset board game
//	Board board(BOARD_SIZE);
//	Reset stack
//	m_gameStack.Clear();
//	Reset players
//	Player player1("player1", Player::Color::Red, DOTS_NUMBER);
//	Player player2("player2", Player::Color::Black, DOTS_NUMBER);
//	std::cout << "The game has been reset.\n";
//	GameLoop(board, player1, player2);
//}

void TwixtGame::Run()
{
	Board board(BOARD_SIZE);

	Player player1("player1", Player::Color::Red, DOTS_NUMBER);
	Player player2("player2", Player::Color::Black, DOTS_NUMBER);

	std::cout << "Choose your game mode:\n1->DEFAULT\n2->BULLDOZER\n3->MINES.\n\n";
	int mode;
	std::cin >> mode;
	//GameStack gameStack;
	std::cout << "add - add dot\ndelete - delete a bridge\ndeleteall - delete existing bridges for a dot\naddbridge - add a bridge between two existing dots\n\n";
	switch (mode)
	{
	case 1:
		m_gameStack = GameStack(0);
		m_gameMode = GameMode::Default;
		GameLoop(board, player1, player2);
		break;
	case 3:
		m_gameStack = GameStack(2);
		m_gameMode = GameMode::Mines;
		for (int i = 0; i < 3; i++)
		{
			board.placeRandomMine();
		}
		//board.placeMine(board.copieI, board.copieJ + 1);
		GameLoop(board, player1, player2);
		break;
	case 2:
		m_gameStack = GameStack(1);
		m_gameMode = GameMode::Bulldozer;
		Bulldozer bulldozer(&board);
		GameLoop(board, player1, player2, bulldozer);
		break;
	}
}
GameStack TwixtGame::getGameStack() const
{
	return m_gameStack;
}
