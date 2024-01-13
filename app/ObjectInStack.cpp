#include "ObjectInStack.h"

ObjectInStack::ObjectInStack(Dot* dot, uint8_t type): m_dot{dot}, m_type{type}
{}

ObjectInStack& ObjectInStack::operator=(const ObjectInStack & newObject)
{
	m_dot = newObject.m_dot;
	m_type = newObject.m_type;
	return *this;
}

Dot* ObjectInStack::getDot() const
{
	return m_dot;
}

uint8_t ObjectInStack::getType() const
{
	return m_type;
}
