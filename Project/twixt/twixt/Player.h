
#ifndef PLAYER_H
#define PLAYER_H
#include <cstdint>
#include <iostream>
#include <stack>
#include "Board.h"
#include "Dot.h"

namespace twixt {
	class Player {
	public:
		//enum
		enum class Color : uint8_t {
			Red,
			Black,
			NoColor
		};

		// Constructors
		Player() = default;
		Player(std::string name, Color color, uint16_t remainingDots, uint16_t remainingBridges);
		Player(const Player& other);//copy constructor
		Player(Player&& other) noexcept; // move constructor

		// Destructor
		~Player();

		// Getters
		std::string getName() const;
		Color getColor() const;
		uint16_t getRemainingDots() const;
		uint16_t getRemainingBridges() const;

		// Setters
		void setName(std::string);
		void setColor(Color);
		void setRemainingDots(uint16_t);
		void setRemainingBridges(uint16_t);

		std::pair<Observer_ptr<Dot>, uint16_t> turn(Board& board);
		bool hasRemainingDots();
		bool hasRemainingBridges();

		Player& operator=(const Player& otherPlayer);

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
		uint16_t m_remainingDots;
		uint16_t m_remainingBridges;
	};
}

#endif
