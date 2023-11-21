
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
			Black
		};

		// Constructors
		Player(std::string name, Color color);
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

// Implementarea move constructorului
 twixt::Player::Player(Player&& other) noexcept: m_name(std::move(other.m_name)),m_color(std::move(other.m_color)) {
	// Setăm membrii altui obiect pe nullptr sau valorile implicite, în funcție de tipul lor.
	other.m_name.clear();
	// other.m_color rămâne cu o valoare validă, dar nu ar trebui accesată în continuare în obiectul sursă.
}
/*namespace twixt {
	class Player {
	public:
		//enum
		enum class Color : uint8_t {
			Red,
			Black
		};

		// Constructors
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

		void turn(Board& board) const;

		friend std::istream& operator>>(std::istream& in, Player& player);

	private:
		std::string m_name;
		Color m_color;
	};
}*/