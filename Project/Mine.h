#pragma once
#include <vector>
#include "Dot.h" 

namespace twixt {
	//class Dot;
	class Mine
	{
	protected:
		//std::vector<Dot*> m_explodedDots;
		Mine* m_previousMine;
	public:
		Mine() : m_previousMine{ nullptr } {}
		~Mine();
		Mine(const Mine& newMine);

		//setter
		void setPreviousMine(Mine* previousMine);
		//void setExplodedDots(Dot* explodedDot);
	};
}