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
	};
}