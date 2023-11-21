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
			Black
		};

		// Constructors
		Player() {};
		Player(std::string name, Color color);
		Player(const Player& newPlayer); // copy constructor

		// Destructor
		~Player();
		
		// Getters
		std::string getName() const;
		Color getColor() const;

		// Setters
		void setName(std::string);
		void setColor(Color);

		void turn(Board& board);

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
		std::stack<Dot*> existingDots;
	};
}

#endif