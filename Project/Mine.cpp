#include "Mine.h"

twixt::Mine::~Mine()
{
	delete m_previousMine;
}

void twixt::Mine::setPreviousMine(Mine* previousMine)
{
	m_previousMine = previousMine;
}

void twixt::Mine::setExplodedDots(Dot explodedDot)
{
	m_explodedDots.push_back(explodedDot);
}
