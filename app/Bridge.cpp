#include "Bridge.h"
#include <utility>

twixt::Bridge::Bridge(const Bridge& bridge) : m_firstPillar{ bridge.m_firstPillar }, m_secondPillar{ bridge.m_secondPillar } {}

twixt::Bridge::Bridge(Peg* firstPillar, Peg* secondPillar) : m_firstPillar{ firstPillar }, m_secondPillar{ secondPillar } {}

twixt::Bridge::~Bridge() {}

twixt::Bridge& twixt::Bridge::operator=(const Bridge& bridge)
{
	m_firstPillar = bridge.m_firstPillar;
	m_secondPillar = bridge.m_secondPillar;
	return *this;
}

void twixt::Bridge::setPillars(Peg* first, Peg* second)
{
	m_firstPillar = first;
	m_secondPillar = second;
}

void twixt::Bridge::setFirstPillar(Peg* pillar)
{
	m_firstPillar = pillar;
}

void twixt::Bridge::setSecondPillar(Peg* pillar)
{
	m_secondPillar = pillar;
}

twixt::Peg* twixt::Bridge::getFirstPillar() const
{
	return m_firstPillar;
}

twixt::Peg* twixt::Bridge::getSecondPillar() const
{
	return m_secondPillar;
}

std::pair<twixt::Peg*, twixt::Peg*> twixt::Bridge::getPillars() const
{
	return std::make_pair(m_firstPillar, m_secondPillar);
}

bool twixt::Bridge::isPillarInBridge(Peg* peg)
{
	if (peg == m_firstPillar || peg == m_secondPillar)
		return true;
	return false;
}

void twixt::Bridge::deleteBridge()
{
	m_firstPillar->removeBridgeFromExisting(this);
	m_secondPillar->removeBridgeFromExisting(this);
	delete this;
}

twixt::Peg* twixt::Bridge::returnTheOtherPillar(Peg* peg)
{
	if (peg == m_firstPillar)
	{
		return m_secondPillar;
	}
	return m_firstPillar;
}

void twixt::Bridge::rebuiltBridge()
{
	m_firstPillar->addBridge(m_secondPillar);
	delete this;
}
