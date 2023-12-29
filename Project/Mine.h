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
		Mine* m_newPlacedMine = nullptr;

	public:
		Mine() {}
		~Mine() = default;
		Mine(const Mine& newMine);

		//setter
		void setTrigger(bool);
		void setExplodedDots(Dot* explodedDot);
		void setNewPlacedMine(Mine* newPlacedMine);

		//getter
		bool getTrigger();
		std::vector<Dot*> getExplodedDots();
		Mine* getNewPlacedMine() const;

	};
}

#endif // !MINE_H