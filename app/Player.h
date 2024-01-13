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
		//enum
		enum class Color : uint8_t {
			Red,
			Black,
			NoColor
		};

		// Constructors
		Player() = default;
		Player(std::string name, Color color, uint16_t remainingDots);
		Player(const Player& other);//copy constructor
		Player(Player&& other) noexcept; // move constructor

		// Destructor
		~Player();

		// Getters
		std::string getName() const;
		Color getColor() const;
		uint16_t getRemainingDots() const;

		// Setters
		void setName(std::string);
		void setColor(Color);
		void setRemainingDots(uint16_t);

		std::pair<Dot*, uint16_t> turn(Board& board);
		bool hasRemainingDots();

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
		uint16_t m_remainingDots;
	};
}
