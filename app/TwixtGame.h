#pragma once

#include "../DLL/Bulldozer.h"
#include "../DLL/Dot.h"
#include "GameStack.h"
#include "Minimax.h"
#include "Player.h"
#include "Undo.h"
#include <cstdint>
#include <iostream>
#include <QString>

using namespace twixt;

class TwixtGame
{
public:
	enum class GameModeType {
		Default,
		Bulldozer,
		Mines
	};

	bool IsTie(Player player1, Player player2);
	void ResetGame(const uint8_t& maxDots, const uint8_t& maxBridges);

	void setGameMode(const QString& gamemode);
	void setMaxDots(const uint8_t& maxDots);
	void setMaxBridges(const uint8_t& maxBridges);
	void setGameBoardSize(const uint8_t& size);
	void setPlayer1(Player* player1);
	void setPlayer2(Player* player2);

	uint8_t getGameboardSize() const;
	GameModeType getGameMode() const;

	GameStack getGameStack() const;

	void initializeGame();
	bool isTie();
	bool checkPathWin(Player* currentPlayer) const;

	// ableToPlaceDot will return:
	// 0 if the dot was placed successfully
	// 1 if the dot is already occupied
	// 2 if the dot is occupied by a mine
	// 3 if the dot is a mine exploded, where there can't be a dot placed
	// 4 if the dot is occupied by a bulldozer
	// 5 if the player has no more dots to place
	uint8_t ableToPlaceDot(uint8_t row, uint8_t col, Player* currentPlayer);
	void placeDot(uint8_t row, uint8_t col, Player* currentPlayer);

	bool ableToBuildBridge(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2);
	void buildBridge(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2, Player* currentPlayer);
	void deleteBridge(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2, Player* currentPlayer);
	bool existsBridge(uint8_t row1, uint8_t col1, uint8_t row2, uint8_t col2, Player* currentPlayer);

	void explodeMine(uint8_t row, uint8_t col, Player* currentPlayer);
	void placeMine(uint8_t row, uint8_t col);

	void moveBulldozer();
	std::pair<uint8_t, uint8_t> getBulldozerPosition() const;

	bool undo();
	std::vector<std::unique_ptr<Bridge>>& getBridges();
	Dot::Status getDotStatus(uint8_t row, uint8_t col) const;

	std::pair<std::pair<int,int>, std::pair<int, int>> getHintByMinimax(Player* currentPlayer);


private:
	Board* m_board;
	Player* m_player1, * m_player2;
	GameModeType m_gameMode;
	GameStack m_gameStack;
	bool blackPlayerStoleColor = false;

	uint8_t m_gameBoardSize;
	uint8_t m_maxDots;
	uint8_t m_maxBridges;
};
