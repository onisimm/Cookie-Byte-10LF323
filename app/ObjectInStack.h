#pragma once

#include "Dot.h"

using namespace twixt;

class ObjectInStack
{
private:
	Dot* m_dot;
	uint8_t m_type;
public:
	ObjectInStack(Dot*, uint8_t type);
	ObjectInStack();

	ObjectInStack& operator=(const ObjectInStack& newObject);

	//getter
	Dot* getDot() const;
	uint8_t getType() const;

};

