#include "Bridge.h"


twixt::Bridge::Bridge(const Bridge& bridge) : m_firstPillar{bridge.m_firstPillar}, m_secondPillar{bridge.m_secondPillar}
{
}

twixt::Bridge::Bridge(Observer_ptr<Peg> firstPillar, Observer_ptr<Peg> secondPillar) : m_firstPillar{firstPillar}, m_secondPillar{secondPillar}
{}

twixt::Bridge::~Bridge()
{}

twixt::Bridge& twixt::Bridge::operator=(const Bridge& bridge)
{
	if (this != &bridge)
	{
		m_firstPillar = bridge.m_firstPillar;
		m_secondPillar = bridge.m_secondPillar;
	}
	return *this;
}

bool twixt::Bridge::operator==(const Bridge& bridge) const
{
	// TODO == regarding the direction of the bridge
	if (m_firstPillar.GetPointer()->getCoordI() != bridge.getFirstPillar().GetPointer()->getCoordI())
		return false;
	if (m_secondPillar.GetPointer()->getCoordI() != bridge.getSecondPillar().GetPointer()->getCoordI())
		return false;
	return true;
}

void twixt::Bridge::setPillars(std::unique_ptr<Peg> first, std::unique_ptr<Peg> second)
{
	m_firstPillar = first.get();
	m_secondPillar = second.get();
}

void twixt::Bridge::setFirstPillar(std::unique_ptr<Peg> pillar)
{
	m_firstPillar = pillar.get();
}

void twixt::Bridge::setSecondPillar(std::unique_ptr<Peg> pillar)
{
	m_secondPillar = pillar.get();
}

twixt::Observer_ptr<twixt::Peg> twixt::Bridge::getFirstPillar() const
{
	return m_firstPillar;
}

twixt::Observer_ptr<twixt::Peg> twixt::Bridge::getSecondPillar() const
{
	return m_secondPillar;
}

std::pair<twixt::Observer_ptr<twixt::Peg>, twixt::Observer_ptr<twixt::Peg>> twixt::Bridge::getPillars() const
{
	return std::make_pair(m_firstPillar, m_secondPillar);
}

bool twixt::Bridge::isPillarInBridge(Observer_ptr<Peg> peg) const
{
	if (peg == m_firstPillar || peg == m_secondPillar)
		return true;
	return false;
}


twixt::Observer_ptr<twixt::Peg> twixt::Bridge::returnTheOtherPillar(Observer_ptr<Peg> peg)
{
	if (peg.GetPointer() == m_firstPillar.GetPointer())
	{
		return m_secondPillar;
	}
	return m_firstPillar;
}
