#pragma once

#ifndef GAMESTACK_H
#define GAMESTACK_H

#include <iostream>
#include "../DLL/Dot.h"
#include "../DLL/Bulldozer.h"
#include<stack>




using namespace twixt;
const uint16_t DELETEBRIDGE = 5;
const uint16_t ADDBRIDGE = 6;

class GameStack
{
private:
	// facem un stack de Dot* pentru a face o copie a ultimei mutari, nu trebuie sa point-am la adresa, ci ne trb copie
	std::stack<std::pair<Dot*, uint16_t>> m_stack;
	uint16_t m_mode;
	std::stack<Peg> m_deletedBridgesDotStack;
	std::stack<Peg> m_addedBridgesDotStack;
public:
	GameStack() = default;
	GameStack(uint16_t mode);
	////Add move constructor
	// GameStack(GameStack&& other) noexcept;
	//getter
	std::stack<std::pair<Dot*, uint16_t>> getGameStack() const;
	std::stack<Peg> getDeletedBridgesDotStack() const;
	std::stack<Peg> getAddedBridgesDotStack() const;
	void popGameStack();
	void popDeletedBridgesStack();
	void popAddedBridgesStack();

	void AddInGameStack(Observer_ptr<Dot>, uint16_t);
	void AddInDeletedBridgesDotStack(Peg);
	void AddInAddedBridgesDotStack(Peg);
	void Clear();
};

#endif // !GAMESTACK_H