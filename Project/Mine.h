#pragma once

#ifndef MINE_H
#define MINE_H
#include "Dot.h" 
#include <vector>



namespace twixt {
	class Mine : public Dot
	{
	private:
		std::vector<Dot*> m_explodedDots;
		bool m_triggered = false;
	public:
		Mine() {}
		~Mine() = default;
		Mine(const Mine& newMine);

		//setter
		//void setPreviousMine(Mine* previousMine);
		void setTrigger(bool);
		void setExplodedDots(Dot* explodedDot);

		//getter
		bool getTrigger();
		std::vector<Dot*> getExplodedDots();


	};
}

#endif // !MINE_H