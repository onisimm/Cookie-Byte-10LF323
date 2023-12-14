#include "Bridge.h"


twixt::Bridge::Bridge(const Bridge& bridge)
{
}

twixt::Bridge::Bridge(Dot* firstDot, Dot* secondDot) :m_firstPillar{ firstDot }, m_secondPillar{ secondDot }
{}

twixt::Bridge::~Bridge()
{
}

void twixt::Bridge::setPillars(Dot* first, Dot* second)
{
	m_firstPillar = first;
	m_secondPillar = second;
}

void twixt::Bridge::setFirstPillar(Dot* pillar)
{
	m_firstPillar = pillar;
}

void twixt::Bridge::setSecondPillar(Dot* pillar)
{
	m_secondPillar = pillar;
}

twixt::Dot* twixt::Bridge::getFirstPillar() const
{
	return m_firstPillar;
}

twixt::Dot* twixt::Bridge::getSecondPillar() const
{
	return m_secondPillar;
}

std::pair<twixt::Dot*, twixt::Dot*> twixt::Bridge::getPillars() const
{
	return std::make_pair(m_firstPillar, m_secondPillar);
}

bool twixt::Bridge::isPillarInBridge(Dot* dot)
{
	if (dot == m_firstPillar || dot == m_secondPillar)
		return true;
	return false;
}

void twixt::Bridge::deleteBridge()
{
	m_firstPillar->removeBridgeFromExisting(this);
	m_secondPillar->removeBridgeFromExisting(this);
	delete this;
}

twixt::Dot* twixt::Bridge::returnTheOtherPillar(Dot* dot)
{
	if (dot == m_firstPillar)
		return m_secondPillar;
	return m_firstPillar;
}
