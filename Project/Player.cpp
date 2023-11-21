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

	void Player::turn(Board& board) 
	{
		std::cout << "Enter position: ";

		int i, j;
		std::cin >> i >> j;

		if (m_color == Color::Red)
		{
			if (j != 0 && j != (board.getSize() - 1))
			{
				board.changeDotStatus(i, j, Dot::DotStatus::Player1);

				//Added the Dot in the player's stack:
				//existingDots.push(&(board.getMatrixDot(i,j))); 
			}
			else {
				std::cout << "Not possible! Try again!\n";
				turn(board);
			}
		}
		else 
		{
			if (i != 0 && i != (board.getSize() - 1))
			{
				board.changeDotStatus(i, j, Dot::DotStatus::Player2);

				//Added the Dot in the player's stack
				//existingDots.push(&(board.getMatrixDot(i, j)));
			}
			else {
				std::cout << "Not possible! Try again!\n";
				turn(board);
			}
		}

		
	}

	std::istream& operator>>(std::istream& in, Player& player) 
	{
		in >> player.m_name;
		player.setName(player.m_name);
		return in;
	}
}