#pragma once

#include <cstdint>
#include <iostream>
#include <stack>
#include "Board.h"
#include "Dot.h"
//#include "ObjectInStack.h"

namespace twixt {
	class Player {
	public:
		Player(uint8_t remainingDots, uint8_t remainingBridges);
		Player(const Player& other);
		Player(Player&& other) noexcept;

		~Player();

		uint8_t getRemainingDots() const;
		uint8_t getRemainingBridges() const;

		void setRemainingDots(uint8_t);
		void setRemainingBridges(uint8_t);

		bool hasRemainingDots();
		bool hasRemainingBridges();

		void addDot(Dot* dot);

	private:
		std::stack<Dot*> existingDots;
		uint8_t m_remainingDots;
		uint8_t m_remainingBridges;
	};
}
