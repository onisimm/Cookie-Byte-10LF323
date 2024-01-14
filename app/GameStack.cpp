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
	if(type == 0 || type == 1 || type == 5 || type == 6)
		m_stack.push({ new Peg(*dot.To<Peg>()), type});
	if(type == 3)
		m_stack.push({ new Bulldozer(*dot.To<Bulldozer>()), type });
	if(type == 4)
		m_stack.push({ new Mine(*dot.To<Mine>()), type });
	// type 0 = player1
	// type 1 = player2
	// type 3 = bulldozer
	// type 4 = mina
	// type 5 = deleteBridge
	// type 6 = addeBridge
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
