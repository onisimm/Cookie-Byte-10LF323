#include "Mine.h"

twixt::Mine::Mine(const Mine& newMine) : Dot(newMine), m_triggered{ newMine.m_triggered }, m_newPlacedMine{ newMine.m_newPlacedMine }
{
	for (auto& element : newMine.m_explodedDots)
	{
		m_explodedDots.resize(m_explodedDots.size() + 1);
		Mine* ptrMine = dynamic_cast<Mine*>(element.get());
		if (ptrMine)
		{
			m_explodedDots[m_explodedDots.size() - 1].reset(new Mine(*ptrMine));
		}
		else 
		{
			m_explodedDots[m_explodedDots.size() - 1].reset(new Peg(*dynamic_cast<Peg*>(element.get())));
		}
	}
	for (auto& element : newMine.m_explodedBridgesTheOtherDot)
	{
		m_explodedBridgesTheOtherDot.resize(m_explodedBridgesTheOtherDot.size() + 1);
		m_explodedBridgesTheOtherDot[m_explodedBridgesTheOtherDot.size() - 1].reset(new Peg(*element.get()));

	}
}


void twixt::Mine::setTrigger(bool trigger)
{
	m_triggered = trigger;
}

void twixt::Mine::setExplodedDots(std::unique_ptr<Dot>& explodedDot)
{
	Mine* ptrMine = dynamic_cast<Mine*>(explodedDot.get());
	if (ptrMine)
	{
		m_explodedDots.resize(m_explodedDots.size() + 1);
		m_explodedDots[m_explodedDots.size() - 1].reset(new Mine(*ptrMine));
	}
	else
	{
		m_explodedDots.resize(m_explodedDots.size() + 1);
		m_explodedDots[m_explodedDots.size() - 1].reset(new Peg(*dynamic_cast<Peg*>(explodedDot.get())));
		for (auto bridge : dynamic_cast<Peg*>(explodedDot.get())->getExistingBridges())
		{
			m_explodedBridgesTheOtherDot.resize(m_explodedBridgesTheOtherDot.size() + 1);
			m_explodedBridgesTheOtherDot[m_explodedBridgesTheOtherDot.size() - 1].reset(new Peg(*bridge.GetPointer()->returnTheOtherPillar(Observer_ptr<Peg>(dynamic_cast<Peg*>(explodedDot.get()))).GetPointer()));
		}

	}

}

void twixt::Mine::setNewPlacedMine(Observer_ptr<Mine> newPlacedMine)
{
	m_newPlacedMine = newPlacedMine.GetPointer();
}

bool twixt::Mine::getTrigger()
{
	return m_triggered;
}

std::vector<std::unique_ptr<twixt::Dot>>& twixt::Mine::getExplodedDots()
{
	return m_explodedDots;
}

std::vector<std::unique_ptr<twixt::Peg>>& twixt::Mine::getExplodedBridgesTheOtherDot()
{
	return m_explodedBridgesTheOtherDot;
}

twixt::Observer_ptr<twixt::Mine> twixt::Mine::getNewPlacedMine() const
{
	return m_newPlacedMine;
}