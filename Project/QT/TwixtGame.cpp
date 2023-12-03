#include"TwixtGame.h"

#ifndef TWIXTGAME_H
#define TWIXTGAME_H
#define BOARD_SIZE 24
#define DOTS_NUMBER 50

void TwixtGame::ReadPlayers(Player& player1, Player& player2)
{
	std::cin >> player1 >> player2;
}

void TwixtGame::GameTurns(Player& player, bool& isPlaying, Board& board)
{
	std::cout << "It's " << player.getName() << "'s turn!\n";
	std::cout << "REMAINING DOTS for " << player.getName() << ": " << player.getRemainingDots() << "\n";
	ObjectInStack object = player.turn(board);
	m_gameStack.AddInGameStack(object.getDot(), object.getType());
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
		std::cout << "You won!\n";
		isPlaying = false;
	}
}

bool TwixtGame::IsTie(Player player1, Player player2)
{
	return !player1.hasRemainingDots() && !player2.hasRemainingDots();
}

void TwixtGame::GameLoop(Board board, Player player1, Player player2, Bulldozer bulldozer)
{
	board.showBoard();
	std::cout << "\n";

	bool isPlaying = true;
	std::string response;

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

		if (bulldozer.exists())
		{
			if (bulldozer.flipCoin(board))
				m_gameStack.AddInGameStack(board.getDot(bulldozer.getI(), bulldozer.getJ()), int(Dot::DotStatus::Bulldozer));
		}

		if (IsTie(player1, player2))
		{
			std::cout << "It's a tie! Both players are out of dots!\n";
			isPlaying = false;
			break;
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
			m_gameStack.AddInGameStack(&board.getMatrixDot(i1, j1), DELETEBRIDGE);
			m_gameStack.AddInDeletedBridgesDotStack(&board.getMatrixDot(i2, j2));
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

void TwixtGame::Run()
{
	Board board(BOARD_SIZE);

	Player player1("player1", Player::Color::Red, DOTS_NUMBER);
	Player player2("player2", Player::Color::Black, DOTS_NUMBER);

	std::cout << "Choose you game mode:\n1->DEFAULT\n2->BULLDOZER\n3->MINES.\n";
	int mode;
	std::cin >> mode;
	//GameStack gameStack;
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
		GameLoop(board, player1, player2);
    break;
	case 2:
		m_gameStack = GameStack(1);
		m_gameMode = GameMode::Bulldozer;
		Bulldozer bulldozer(board);
		GameLoop(board, player1, player2, bulldozer);
		break;
	}
  default: {
    std::cout << "Not a valid option.\n";
  }
}
GameStack TwixtGame::getGameStack() const
{
	return m_gameStack;
}

void TwixtGame::runGameMode(int mode) {
    // TODO
    // Implement Run method, but using signals to interact with the GUI
}
