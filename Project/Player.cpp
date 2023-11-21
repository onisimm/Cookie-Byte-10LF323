#include "Player.h"

namespace twixt {
	Player::Player(std::string name, Color color) :
		m_name{ name }, m_color{ color } {}

	Player::Player(const Player& newPlayer) :
		m_name{ newPlayer.m_name }, m_color{ newPlayer.m_color } {}
	// Implementarea move constructorului
	twixt::Player::Player(Player&& other) noexcept : m_name(std::move(other.m_name)), m_color(other.m_color) {
		// Setăm membrii altui obiect pe nullptr sau valorile implicite
		other.m_name.clear();
		other.m_color = Color::NoColor;

	}

	Player::~Player() {}

	std::string Player::getName() const
	{
		return m_name;
	}

	Player::Color Player::getColor() const
	{
		return m_color;
	}

	void Player::setName(std::string name) 
	{
		m_name = name;
	}

	void Player::setColor(Color color) 
	{
		m_color = color;
	}

	void Player::turn(Board& board) const
	{
		std::cout << "Pozitia aleasa este: ";

		int i, j;
		std::cin >> i >> j;

		Dot::DotStatus status;

		if (m_color == Color::Red)
			status = Dot::DotStatus::Player1;
		else 
			status = Dot::DotStatus::Player2;

		board.changeDotStatus(i, j, status);
	}

	std::istream& operator>>(std::istream& in, Player& player) 
	{
		in >> player.m_name;

		std::string color;
		in >> color;

		if (color == "red") 
		{
			player.m_color = Player::Color::Red;
		}

		if (color == "black") 
		{
			player.m_color = Player::Color::Black;
		}

		player.setName(player.m_name);
		return in;
	}
}