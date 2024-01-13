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
		__declspec(dllexport) Mine() {}
		__declspec(dllexport) ~Mine() = default;
		__declspec(dllexport) Mine(const Mine& newMine);

		//setter
		__declspec(dllexport) void setTrigger(bool);
		__declspec(dllexport) void setExplodedDots(std::unique_ptr<Dot>& explodedDot);
		__declspec(dllexport) void setNewPlacedMine(Observer_ptr<Mine> newPlacedMine);

		//getter
		__declspec(dllexport) bool getTrigger();
		__declspec(dllexport) std::vector<std::unique_ptr<Dot>>& getExplodedDots();
		__declspec(dllexport) std::vector<std::unique_ptr<Peg>>& getExplodedBridgesTheOtherDot();
		__declspec(dllexport) Observer_ptr<Mine> getNewPlacedMine() const;

	};
}

#endif // !MINE_H