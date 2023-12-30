#pragma once
#include"Dot.h"
#include"Player.h"
#include "Bulldozer.h"
#include "GameStack.h"
#include "Undo.h"
#include "SaveGame.h"
#include "Minimax.h"
#include <iostream>
#include <QString>
using namespace twixt;

class TwixtGame
{
public:
	enum class GameMode {
		Default,
		Bulldozer,
		Mines
	};

	void GameTurns(Player& player, bool& isPlaying, Board& board);
	bool IsTie(Player player1, Player player2);
	void ResetGame();
	void Run();

	void setGameMode(const QString& gamemode);
	void setMaxDots(const uint8_t& maxDots);
	void setMaxBridges(const uint8_t& maxBridges);
	void setGameBoardSize(const uint8_t& size);

	//getter
	GameStack getGameStack() const;
private:
	GameMode m_gameMode;
	GameStack m_gameStack;
	SaveGame saveGame;
	bool blackPlayerStoleColor = false;

	uint8_t gameBoardSize;
	uint8_t maxDots;
	uint8_t maxBridges;
};
