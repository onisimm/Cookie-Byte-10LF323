#pragma once
#include <vector>
#include "Dot.h" 

namespace twixt {
	class Mine
	{
	private:
		std::vector<Dot> m_explodedDots;
		Mine* m_previousMine;
	public:
		Mine() : m_previousMine{ nullptr } {}
		~Mine();

		//setter
		void setPreviousMine(Mine* previousMine);
		void setExplodedDots(Dot explodedDot);
	};
}

