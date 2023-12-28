
#ifndef PLAYER_H
#define PLAYER_H
#include <cstdint>
#include <iostream>
#include <stack>
#include "Board.h"
#include "Dot.h"
#include "ObjectInStack.h"

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
		Player() {};
		Player(std::string name, Color color, int remainingDots);
		Player(const Player& other);//copy constructor
		Player(Player&& other) noexcept; // move constructor

		// Destructor
		~Player();

		// Getters
		std::string getName() const;
		Color getColor() const;
		int getRemainingDots() const;

		// Setters
		void setName(std::string);
		void setColor(Color);
		void setRemainingDots(int);

		ObjectInStack turn(Board& board);
		bool hasRemainingDots();

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
		std::stack<Dot*> existingDots;
		int m_remainingDots;
	};
}

#endif
