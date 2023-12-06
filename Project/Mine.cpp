#include "Mine.h"


twixt::Mine::Mine(const Mine& newMine): m_triggered{newMine.m_triggered}
{
	for (auto element : newMine.m_explodedDots)
	{
		Dot* newElement;
		if (Mine* ptrMine = dynamic_cast<Mine*>(element)) {
			newElement = new Mine(*ptrMine);
		}
		else {
			newElement = new Dot(*element);
		}
		m_explodedDots.push_back(newElement);
	}
}

void twixt::Mine::setTrigger(bool trigger)
{
	m_triggered = trigger;
}


void twixt::Mine::setExplodedDots(Dot* explodedDot)
{
	Mine* ptrMine = dynamic_cast<Mine*>(explodedDot);
	if (ptrMine)
	{
		Mine* newMine = new Mine;
		*newMine = *ptrMine;
		m_explodedDots.push_back(newMine);
	}
	else
	{
		Dot* newDot = new Dot;
		*newDot = *explodedDot;
		m_explodedDots.push_back(newDot);
	}
	
}

bool twixt::Mine::getTrigger()
{
	return m_triggered;
}

std::vector<twixt::Dot*> twixt::Mine::getExplodedDots()
{
	return m_explodedDots;
}
