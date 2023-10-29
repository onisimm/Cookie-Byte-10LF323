module;

#include <cstdint>

export module Player.cppm;

import <iostream>;


namespace twixt {
	export class Player {
	private:
		std::string m_name, m_color;
	public:
		//Constructor
		Player(std::string name, std::string color);
		//Copy constructor
		Player(const Player& newPlayer);
		//Destructor
		~Player();
		//Getters
		std::string getName();
		std::string getColor();
		//Setters
		void setName(std::string);
		void setColor(std::string);
		friend std::istream& operator>>(std::istream& in, Player& player);
	};
}