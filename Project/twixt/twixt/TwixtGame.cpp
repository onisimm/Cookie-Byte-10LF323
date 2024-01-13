#include"TwixtGame.h"

#ifndef TWIXTGAME_H
#define TWIXTGAME_H

//de sters macro-uri

#define BOARD_SIZE 24
#define DOTS_NUMBER 50
#define BRIDGES_NUMBER 50

void TwixtGame::ReadPlayers(Player& player1, Player& player2)
{
	std::cin >> player1 >> player2;
}

void TwixtGame::GameTurns(Player& player, bool& isPlaying, Board& board, bool& isReseted)
{
	std::string answer;

	std::cout << player.getName() << ", what's your next move?\n";

	Minimax minimaxSuggestion(board);
	minimaxSuggestion.suggestMove((player.getColor() == Player::Color::Red) ? Dot::DotStatus::Player1 : Dot::DotStatus::Player2);

	std::cin >> answer;

	for (auto& c : answer)
	{
		c = toupper(c);
	}

	if (answer == "ADD")
	{
		std::cout << "It's " << player.getName() << "'s turn!\n";

		std::cout << "REMAINING DOTS for " << player.getName() << ": " << player.getRemainingDots() << "\n";
		auto [dot, type] = player.turn(board);
		m_gameStack.AddInGameStack(dot, type);
		board.showBoard();
		std::cout << "\n";
	}
	else if (answer == "DELETE")
	{
		std::cout << "Choose the first dot: ";
		size_t i1, j1, i2, j2;
		std::cin >> i1 >> j1;
		std::cout << "Choose the second dot: ";
		std::cin >> i2 >> j2;
		board.deleteBridgeInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getMatrixDot(i1, j1).get())), Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getMatrixDot(i2, j2).get())));
		m_gameStack.AddInGameStack(Observer_ptr<Dot>(board.getMatrixDot(i1, j1).get()), DELETEBRIDGE);
		m_gameStack.AddInDeletedBridgesDotStack(*(dynamic_cast<Peg*>(board.getMatrixDot(i2, j2).get())));
	}
	else if (answer == "DELETEALL")
	{
		std::cout << "Choose the dot: ";
		size_t i, j;
		std::cin >> i >> j;
		board.deleteAllBridgesForAPegInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getDot(i, j).get())));
		//de implementat undo pt asta
	}
	else if (answer == "ADDBRIDGE")
	{
		std::cout << "Enter the position of the first dot: ";
		int i1, j1, i2, j2;
		std::cin >> i1 >> j1;
		std::cout << "Enter the position of the second dot: ";
		std::cin >> i2 >> j2;
		if (board.getMatrixDot(i1, j1).get()->getStatus() == board.getMatrixDot(i2, j2).get()->getStatus() && board.getMatrixDot(i1, j1).get()->getStatus() != Dot::DotStatus::Clear)
		{
			if (((abs(i1 - i2) == 1 && abs(j1 - j2) == 2) || (abs(i1 - i2) == 2 && abs(j1 - j2) == 1)) && board.checkObstructingBridges(*dynamic_cast<Peg*>(board.getMatrixDot(i1, j1).get()), *dynamic_cast<Peg*>(board.getMatrixDot(i2, j2).get())))
			{
				//de adaugat in board
				board.addBridgeInBoard(Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getMatrixDot(i1, j1).get())), Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getMatrixDot(i2, j2).get())));
				//(dynamic_cast<Peg*>(board.getMatrixDot(i1, j1).get()))->addBridge(Observer_ptr<Peg>(dynamic_cast<Peg*>(board.getMatrixDot(i2, j2).get())));
				m_gameStack.AddInGameStack(Observer_ptr<Dot>(board.getMatrixDot(i1, j1).get()), ADDBRIDGE);
				m_gameStack.AddInAddedBridgesDotStack(*(dynamic_cast<Peg*>(board.getMatrixDot(i2, j2).get())));
				player.setRemainingBridges(player.getRemainingBridges() - 1);
			}
			else
			{
				std::cout << "Couldn't build a bridge!\n";
			}
		}
		else std::cout << "the dots do not exist\n";
	}
	else if (answer == "RESET")
	{
		isReseted = true;
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
		std::cout << player.getName() << " won!\n";
		isPlaying = false;
		return;
	}
		//nu se adauga automat bridge-uri
	std::cout << "Do you want to undo the move? ";
	std::cin >> answer;
	while (answer!="no")
	{
		

		for (auto& c : answer)
		{
			c = toupper(c);
		}

		if (answer == "YES")
		{
			Undo undo(m_gameStack, board);
			undo.pressed();
			board.showBoard();
		}
		std::cout << "\nDo you want to undo the move? ";
		std::cin >> answer;
	}
	
}

bool TwixtGame::IsTie(Player player1, Player player2)
{
	if (!player1.hasRemainingDots() && !player2.hasRemainingDots() || !player1.hasRemainingBridges() && !player2.hasRemainingBridges())
	{
		return true;
	}
	return false;
}

void TwixtGame::GameLoop(Board& board, Player player1, Player player2)
{
	board.showBoard();
	std::cout << "\n";

	bool isPlaying = true;
	bool isFirstRound = true;
	bool isReseted = false;

	std::string response;
	while (isPlaying)
	{
		GameTurns(player1, isPlaying, board, isReseted);

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

		if (isReseted)
		{
			ResetGame(board, player1, player2);
			isReseted = false;
			isFirstRound = false;
			GameLoop(board, player1, player2);
			break;
		}

		//check if it is the first round
		if (isFirstRound)
		{
			std::cout << player2.getName() << ", do you want to steal the red pegs?\n";
			std::cin >> response;

			for (auto& c : response)
			{
				c = toupper(c);
			}

			if (response == "YES")
			{
				std::cout << "Black player stole the red color!\n";
				std::cout << player1.getName() << " now you own the black pegs!\n";
				std::cout << player2.getName() << " now you own the red pegs!\n";

				player1.setColor(Player::Color::Black);
				player2.setColor(Player::Color::Red);
				player1.setRemainingDots(player1.getRemainingDots() + 1);
				player2.setRemainingDots(player2.getRemainingDots() - 1);

				std::pair<size_t, size_t> firstRedDot = { m_gameStack.getGameStack().top().first->getCoordI(),m_gameStack.getGameStack().top().first->getCoordJ() };
				board.getDot(firstRedDot.first, firstRedDot.second).get()->setStatus(Dot::DotStatus::Player2);
				m_gameStack.getGameStack().top().first->setStatus(Dot::DotStatus::Player2);

				if(!isReseted)
				{
					GameTurns(player1, isPlaying, board, isReseted);
				}
			}
			isFirstRound = false;
		}

		GameTurns(player2, isPlaying, board, isReseted);
		std::string answer;
		if (board.m_bulldozer.GetPointer()->exists())
		{
			if (board.m_bulldozer.GetPointer()->flipCoin(board))
			{
				m_gameStack.AddInGameStack(Observer_ptr<Dot>(board.getDot(board.m_bulldozer.GetPointer()->getCoordI(), board.m_bulldozer.GetPointer()->getCoordJ()).get()), size_t(Dot::DotStatus::Bulldozer));

				std::cout << "Do you want to undo the move? ";
				std::cin >> answer;

				for (auto& c : answer)
				{
					c = toupper(c);
				}

				if (answer == "YES")
				{
					Undo undo(m_gameStack, board);
					undo.pressed();
					board.showBoard();
				}
			}
		}

		if (IsTie(player1, player2))
		{
			std::cout << "It's a tie! Both players are out of dots or bridges!\n";
			isPlaying = false;
			break;
		}

		if (isReseted)
		{
			ResetGame(board, player1, player2);
			isReseted = false;
			isFirstRound = false;
			GameLoop(board, player1, player2);
			break;
		}
	}
}

void TwixtGame::ResetGame(Board& board, Player& player1, Player& player2)
{
	//Reset board game
	board.getBridges().clear();
	for (size_t row = 0; row < board.getSize(); row++)
	{
		for (size_t column = 0; column < board.getSize(); column++)
		{
			board.getMatrix()[row][column].reset(new Dot(row, column));
		}
	}

	//Reset stack
	m_gameStack.Clear();

	//Reset players
	player1.setRemainingBridges(BRIDGES_NUMBER);
	player1.setRemainingDots(DOTS_NUMBER);
	player1.setColor(Player::Color::Red);

	player2.setRemainingBridges(BRIDGES_NUMBER);
	player2.setRemainingDots(DOTS_NUMBER);
	player2.setColor(Player::Color::Black);

	if (m_gameMode == GameMode::Bulldozer)
	{
		board.m_bulldozer = Observer_ptr<Bulldozer>(new Bulldozer(board));
	}
	else if (m_gameMode == GameMode::Mines)
	{
		for (size_t i = 0; i < 3; i++)
		{
			board.placeRandomMine();
		}
	}

	std::cout << "The game has been reset!\n\n";
}

//void TwixtGame::LoadGame(Board& board, Player& player1, Player& player2)
//{
//	board. = m_savedGame.getSavedMatrix();
//	m_gameStack = m_savedGame.getSavedStack();
//	player1
//}

void TwixtGame::Run()
{
	Board board(BOARD_SIZE);

	Player player1("player1", Player::Color::Red, DOTS_NUMBER, BRIDGES_NUMBER);
	Player player2("player2", Player::Color::Black, DOTS_NUMBER, BRIDGES_NUMBER);

	std::cout << "Choose your game mode:\n1->DEFAULT\n2->BULLDOZER\n3->MINES.\n\n";
	uint16_t mode; //cel mai mic tip pur numeric
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
		for (size_t i = 0; i < 3; i++)
		{
			board.placeRandomMine();
		}
		GameLoop(board, player1, player2);
		break;
	case 2:
		m_gameStack = GameStack(1);
		m_gameMode = GameMode::Bulldozer;
		board.m_bulldozer = Observer_ptr<Bulldozer>(new Bulldozer(board));
		GameLoop(board, player1, player2);
		break;
	}
}
GameStack TwixtGame::getGameStack() const
{
	return m_gameStack;
}
#endif