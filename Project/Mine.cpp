#include "Mine.h"


twixt::Mine::Mine(const Mine& newMine) : m_explodedDots{ newMine.m_explodedDots } {}

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
