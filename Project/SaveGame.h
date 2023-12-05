#pragma once
#include "Board.h"
#include "GameStack.h"
using namespace twixt;

class SaveGame
{
private:
	std::vector<std::vector<Dot>> m_savedMatrix;
	GameStack m_savedStack;
public:
	void saveMatrix(std::vector<std::vector<Dot>> m_gameMatrix);
	void saveStack(GameStack m_gameStack);
};

