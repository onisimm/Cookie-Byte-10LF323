#include "Player.h"

namespace twixt {
	Player::Player(std::string name, Color color, uint8_t remainingDots) :
		m_name{ name }, m_color{ color }, m_remainingDots{ remainingDots } {}

	Player::Player(const Player& newPlayer) :
		m_name{ newPlayer.m_name }, m_color{ newPlayer.m_color }, m_remainingDots{ newPlayer.m_remainingDots } {}

	// Implementarea move constructorului
	twixt::Player::Player(Player&& other) noexcept : m_name(std::move(other.m_name)), m_color(other.m_color), m_remainingDots(other.m_remainingDots) {
		// Setăm membrii altui obiect pe nullptr sau valorile implicite
		other.m_name.clear();
		other.m_color = Color::NoColor;
		other.m_remainingDots = 0;

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

	uint8_t Player::getRemainingDots() const
	{
		return m_remainingDots;
	}

	void Player::setName(std::string name) 
	{
		m_name = name;
	}

	void Player::setColor(Color color) 
	{
		m_color = color;
	}

	void Player::setRemainingDots(uint8_t remainingDots)
	{
		m_remainingDots = remainingDots;
	}

	std::pair<Dot*, uint8_t> Player::turn(Board& board)
	{
		std::cout << "Enter position: ";

		size_t i, j;
		std::cin >> i >> j;
		bool didMineExplode = false;

		if (m_color == Color::Red)
		{
			if (j != 0 && j != (board.getSize() - 1))
			{
				board.changeDotStatus(i, j, Dot::DotStatus::Player1, didMineExplode);
				if (!didMineExplode)
				{
					m_remainingDots--;
					return { board.getDot(i, j), uint8_t(board.getDot(i, j)->getStatus()) };
				}
				return { board.getDot(i, j), uint8_t(Dot::DotStatus::Mines) };
				
			
			}
			else {
				std::cout << "Not possible! Try again!\n";
				return turn(board);
			}
		}
		else
		{
			if (i != 0 && i != (board.getSize() - 1))
			{
				board.changeDotStatus(i, j, Dot::DotStatus::Player2, didMineExplode);
				if (!didMineExplode)
				{
					m_remainingDots--;
					return { board.getDot(i, j), uint8_t(board.getDot(i, j)->getStatus()) };
				}
				return { board.getDot(i, j), uint8_t(Dot::DotStatus::Mines) };
				
			}
			else {
				std::cout << "Not possible! Try again!\n";
				return turn(board);
			}
		}
	}

	bool Player::hasRemainingDots()
	{
		return m_remainingDots > 0;
	}

	std::istream& operator>>(std::istream& in, Player& player) 
	{
		in >> player.m_name;
		player.setName(player.m_name);
		return in;
	}
}