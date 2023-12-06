#pragma once

#ifndef MINE_H
#define MINE_H
#include "Dot.h" 
#include <vector>



namespace twixt {
	class Mine
	{
	private:
		std::vector<Dot> m_explodedDots;
		Mine* m_previousMine;
		bool m_triggered = false;
	public:
		Mine() : m_previousMine{ nullptr } {}
		~Mine();
		Mine(const Mine& newMine);

		//setter
		void setPreviousMine(Mine* previousMine);
		void setTrigger(bool);
		void setExplodedDots(Dot* explodedDot);

	};
}

#endif // !MINE_H