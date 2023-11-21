
#include <cstdint>
#include <iostream>
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
		Player(std::string name, Color color);
		Player(const Player& other);//copy constructor
		Player(Player&& other) noexcept; // move constructor

		// Destructor
		~Player();

		// Getters
		std::string getName() const;
		Color getColor() const;

		// Setters
		void setName(std::string);
		void setColor(Color);

		void turn(Board& board) const;

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
	};
}

/*
// Implementarea move constructorului
twixt::Player::Player(Player&& other) noexcept : m_name(std::move(other.m_name)), m_color(other.m_color) {
	// Setăm membrii altui obiect pe nullptr sau valorile implicite
	other.m_name.clear();
	other.m_color = Color::NoColor;

}
*/