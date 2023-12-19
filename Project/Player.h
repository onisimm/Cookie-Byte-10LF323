
#ifndef PLAYER_H
#define PLAYER_H
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
		Player(std::string name, Color color, uint8_t remainingDots);
		Player(const Player& other);//copy constructor
		Player(Player&& other) noexcept; // move constructor

		// Destructor
		~Player();

		// Getters
		std::string getName() const;
		Color getColor() const;
		uint8_t getRemainingDots() const;

		// Setters
		void setName(std::string);
		void setColor(Color);
		void setRemainingDots(uint8_t);

		std::pair<Dot*, uint8_t> turn(Board& board);
		bool hasRemainingDots();

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
		uint8_t m_remainingDots;
	};
}

#endif
