#pragma once

#include <cstdint>
#include <iostream>
#include <stack>
#include "../DLL/Board.h"
#include "../DLL/Dot.h"

namespace twixt {
	enum class PlayerType {
		Player1,
		Player2
	};

	class Player {
	public:
		Player(uint8_t remainingDots, uint8_t remainingBridges);
		Player(const Player& other);
		Player(Player&& other) noexcept;

		~Player();

		uint8_t getRemainingDots() const;
		uint8_t getRemainingBridges() const;
		PlayerType getPlayerType() const;

		void setRemainingDots(uint8_t);
		void setRemainingBridges(uint8_t);
		void setPlayerType(PlayerType playerType);

		bool hasRemainingDots();
		bool hasRemainingBridges();

	private:
		uint8_t m_remainingDots;
		uint8_t m_remainingBridges;
		PlayerType m_playerType;
	};
}
