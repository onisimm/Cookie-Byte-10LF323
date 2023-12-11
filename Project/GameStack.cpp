#include "GameStack.h"

GameStack::GameStack(uint8_t mode): m_mode{mode}
{}

std::stack<std::pair<Dot*, uint8_t>> GameStack::GetGameStack() const
{
	return m_stack;
}

std::stack<Dot*> GameStack::GetDeletedBridgesDotStack() const
{
	return m_deletedBridgesDotStack;
}

void GameStack::popGameStack()
{
	m_stack.pop();
}

void GameStack::popDeletedBridgesStack()
{
	m_deletedBridgesDotStack.pop();
}

void GameStack::AddInGameStack(Dot* dot, uint8_t type)
{
	m_stack.push({ dot, type });
	//type o sa fie player1, player2, bulldozer, mina, deletebridge
}

void GameStack::AddInDeletedBridgesDotStack(Dot* dot)
{
	m_deletedBridgesDotStack.push(dot);
}

//void GameStack::Clear()
//{
//	while (m_stack.empty())
//	{
//		m_stack.pop();
//	}
//}
