#include "SaveGame.h"

std::vector<std::vector<Dot>> SaveGame::getSavedMatrix() const
{
	return m_savedMatrix;
}

GameStack SaveGame::getSavedStack() const
{
	return m_savedStack;
}

void SaveGame::saveMatrix(std::vector<std::vector<Dot>> m_gameMatrix)
{
	m_savedMatrix = m_gameMatrix;
}

void SaveGame::saveStack(GameStack m_gameStack)
{
	m_savedStack = m_gameStack;
}
