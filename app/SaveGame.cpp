#include "SaveGame.h"

std::vector<std::vector<Dot>> SaveGame::getSavedMatrix() const
{
	return m_savedMatrix;
}

GameStack SaveGame::getSavedStack() const
{
	return m_savedStack;
}

void SaveGame::saveMatrix(std::vector<std::vector<Dot*>> m_gameMatrix)
{
	for (uint8_t i = 0; i < m_gameMatrix.size(); i++)
		for (uint8_t j = 0; j < m_gameMatrix.size(); j++)
			m_savedMatrix[i][j] = *m_gameMatrix[i][j];
}

void SaveGame::saveStack(GameStack m_gameStack)
{
	m_savedStack = m_gameStack;
}
