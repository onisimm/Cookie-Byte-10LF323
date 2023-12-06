#include "Mine.h"

twixt::Mine::~Mine()
{
	delete m_previousMine;
}

twixt::Mine::Mine(const Mine& newMine) : m_previousMine{ newMine.m_previousMine }, m_explodedDots{ newMine.m_explodedDots } {}

void twixt::Mine::setPreviousMine(Mine* previousMine)
{
	m_previousMine = previousMine;
}

void twixt::Mine::setTrigger(bool trigger)
{
	m_triggered = trigger;
}


void twixt::Mine::setExplodedDots(Dot* explodedDot)
{
	m_explodedDots.push_back(*explodedDot);
}
