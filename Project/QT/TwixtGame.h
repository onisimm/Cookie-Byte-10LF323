#pragma once
#include"Dot.h"
#include"Player.h"
#include"Bulldozer.h"
#include "GameStack.h"
#include<iostream>
#include<QObject>
using namespace twixt;

class TwixtGame : public QObject {
    Q_OBJECT
public:
	enum class GameMode {
		Default,
		Bulldozer,
		Mines
	};

	void ReadPlayers(Player& player1, Player& player2);
	void GameTurns(Player& player, bool& isPlaying, Board& board);
	bool IsTie(Player player1, Player player2);
	void GameLoop(Board board, Player player1, Player player2, Bulldozer bulldozer = Bulldozer());
	void Run();


signals:
  void updateBoard(); // Signal to update the GUI game board
  void displayMessage(QString message); // Signal to display a message in the GUI
  void gameEnded(QString result); // Signal to indicate the game has ended

public slots:
  void runGameMode(int mode); // Slot to start the game with a selected mode
};

	//getter
	GameStack getGameStack() const;
private:
	GameMode m_gameMode;
	GameStack m_gameStack;
};
