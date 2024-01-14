#include "GameStack.h"

GameStack::GameStack(uint16_t mode) : m_mode{ mode }
{}

//GameStack::GameStack(GameStack && other) noexcept
//   : m_stack(std::move(other.m_stack)),m_mode(std::move(other.m_mode)), m_deletedBridgesDotStack(std::move(other.m_deletedBridgesDotStack)), m_addedBridgesDotStack(std::move(other.m_addedBridgesDotStack))
//{}
   

std::stack<std::pair<Dot*, uint16_t>> GameStack::getGameStack() const
{
	return m_stack;
}

std::stack<Peg> GameStack::getDeletedBridgesDotStack() const
{
	return m_deletedBridgesDotStack;
}

std::stack<Peg> GameStack::getAddedBridgesDotStack() const
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
	m_stack.push({ dot.GetPointer(), type});
	// type 0 = player1
	// type 1 = player2
	// type 2 = bulldozer
	// type 3 = mina
	// type 4 = deleteBridge
	// type 4 = addeBridge
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
