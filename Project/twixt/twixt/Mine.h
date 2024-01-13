#pragma once

#ifndef MINE_H
#define MINE_H
#include "Dot.h" 
#include <vector>

namespace twixt {
	class Peg;
	class Mine : public Dot
	{
	private:
		std::vector<std::unique_ptr<Dot>> m_explodedDots;
		std::vector<std::unique_ptr<Peg>> m_explodedBridgesTheOtherDot;

		bool m_triggered = false;
		Observer_ptr<Mine> m_newPlacedMine = nullptr;

	public:
		Mine() {}
		~Mine() = default;
		Mine(const Mine& newMine);

		//setter
		void setTrigger(bool);
		void setExplodedDots(std::unique_ptr<Dot>& explodedDot);
		void setNewPlacedMine(Observer_ptr<Mine> newPlacedMine);

		//getter
		bool getTrigger();
		std::vector<std::unique_ptr<Dot>>& getExplodedDots();
		std::vector<std::unique_ptr<Peg>>& getExplodedBridgesTheOtherDot();
		Observer_ptr<Mine> getNewPlacedMine() const;

	};
}

#endif // !MINE_H