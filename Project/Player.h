
#include <cstdint>
#include <iostream>
#include "Board.h"


namespace twixt {
	class Player {
	public:
		//enum
		enum class Color : uint8_t {
			Red,
			Black
		};

		//Constructor
		Player(std::string name, Color color);
		//Copy constructor
		Player(const Player& newPlayer);
		//Destructor
		~Player();
		
		//Getters
		std::string getName();
		Color getColor();
		//Setters
		void setName(std::string);
		void setColor(Color);

		void turn(Board board, int i, int j);

		friend std::istream& operator>>(std::istream& in, Player& player);
	private:
		std::string m_name;
		Color m_color;
	};
}