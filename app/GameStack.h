#pragma once
#include <iostream>
#include "Dot.h"
#include<stack>
using namespace twixt;
#define DELETEBRIDGE 5

class GameStack
{
private:
	std::stack<std::pair<Dot*, uint8_t>> m_stack;
	uint8_t m_mode;
	std::stack<Dot*> m_deletedBridgesDotStack;
public:
	GameStack() = default;
	GameStack(uint8_t mode);

	//getter
	std::stack<std::pair<Dot*, uint8_t>> GetGameStack() const;
	std::stack<Dot*> GetDeletedBridgesDotStack() const;
	void popGameStack();
	void popDeletedBridgesStack();

	void AddInGameStack(Dot*, uint8_t);
	void AddInDeletedBridgesDotStack(Dot*);
	void Clear();
};

