#include "GameStack.h"

GameStack::GameStack(uint16_t mode) : m_mode{ mode }
{}

std::stack<std::pair<Dot*, uint16_t>> GameStack::GetGameStack() const
{
	return m_stack;
}

std::stack<Peg> GameStack::GetDeletedBridgesDotStack() const
{
	return m_deletedBridgesDotStack;
}

std::stack<Peg> GameStack::GetAddedBridgesDotStack() const
{
	return m_addedBridgesDotStack;
}

void GameStack::popGameStack()
{
	m_stack.pop();
}

void GameStack::popDeletedBridgesStack()
{
	m_deletedBridgesDotStack.pop();
}

void GameStack::popAddedBridgesStack()
{
	m_addedBridgesDotStack.pop();
}

void GameStack::AddInGameStack(Observer_ptr<Dot> dot, uint16_t type)
{
	//ATENTIE DE REZOLVAT!!!!!
	m_stack.push({ dot.GetPointer(), type});
	//type o sa fie player1, player2, bulldozer, mina, deletebridg, addedbridge
}

void GameStack::AddInDeletedBridgesDotStack(Peg dot)
{
	m_deletedBridgesDotStack.push(dot);
}

void GameStack::AddInAddedBridgesDotStack(Peg dot)
{
	m_addedBridgesDotStack.push(dot);
}

void GameStack::Clear()
{
	while (!m_stack.empty())
	{
		m_stack.pop();
	}
}
