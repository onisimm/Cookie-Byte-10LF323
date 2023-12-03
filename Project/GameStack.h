#pragma once
#include <iostream>
#include "Dot.h"
#include<stack>
using namespace twixt;


class GameStack
{
private:
	std::stack<std::pair<Dot*,uint8_t>> m_gameStack;
	uint8_t m_mode;
public:
	GameStack(){}
	GameStack(uint8_t mode);
};

