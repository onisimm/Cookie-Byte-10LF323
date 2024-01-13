#include "Player.h"

namespace twixt {
	Player::Player(std::string name, Color color, uint16_t remainingDots, uint16_t remainingBridges) :
		m_name{ name }, m_color{ color }, m_remainingDots{ remainingDots }, m_remainingBridges{ remainingBridges } {}

	Player::Player(const Player& newPlayer) :
		m_name{ newPlayer.m_name }, m_color{ newPlayer.m_color }, m_remainingDots{ newPlayer.m_remainingDots }, m_remainingBridges{ newPlayer.m_remainingBridges } {}

	// Implementarea move constructorului
	twixt::Player::Player(Player&& other) noexcept : m_name(std::move(other.m_name)), m_color(other.m_color), m_remainingDots(other.m_remainingDots), m_remainingBridges(other.m_remainingBridges) {
		// Setăm membrii altui obiect pe nullptr sau valorile implicite
		other.m_name.clear();
		other.m_color = Color::NoColor;
		other.m_remainingDots = 0;
		other.m_remainingBridges = 0;

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

	uint16_t Player::getRemainingDots() const
	{
		return m_remainingDots;
	}

	uint16_t Player::getRemainingBridges() const
	{
		return m_remainingBridges;
	}

	void Player::setName(std::string name)
	{
		m_name = name;
	}

	void Player::setColor(Color color)
	{
		m_color = color;
	}

	void Player::setRemainingDots(uint16_t remainingDots)
	{
		m_remainingDots = remainingDots;
	}

	void Player::setRemainingBridges(uint16_t remainingBridges)
	{
		m_remainingBridges = remainingBridges;
	}

	std::pair<Observer_ptr<Dot>, uint16_t> Player::turn(Board& board)
	{
		std::cout << "Enter position: ";

		size_t i, j;
		std::cin >> i >> j;
		bool didMineExplode = false;

		if (m_color == Color::Red)
		{
			if (j != 0 && j != (board.getSize() - 1))
			{
				board.placePiece(i, j, Dot::DotStatus::Player1, didMineExplode);
				if (!didMineExplode)
				{
					m_remainingDots--;
					return { Observer_ptr<Dot>(board.getDot(i, j).get()), uint16_t(board.getDot(i, j)->getStatus()) };
				}
				return { Observer_ptr<Dot>(board.getDot(i, j).get()), uint16_t(Dot::DotStatus::Mines) };
			}
			else 
			{
				std::cout << "Not possible! Try again!\n";
				return turn(board);
			}
		}
		else
		{
			if (i != 0 && i != (board.getSize() - 1))
			{
				board.placePiece(i, j, Dot::DotStatus::Player2, didMineExplode);
				if (!didMineExplode)
				{
					m_remainingDots--;
					return { Observer_ptr<Dot>(board.getDot(i, j).get()), uint16_t(board.getDot(i, j)->getStatus()) };
				}
				return { Observer_ptr<Dot>(board.getDot(i, j).get()), uint16_t(Dot::DotStatus::Mines) };

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

	bool Player::hasRemainingBridges()
	{
		return m_remainingBridges > 0;
	}

	Player& Player::operator=(const Player& otherPlayer)
	{
		this->m_color = otherPlayer.m_color;
		this->m_name = otherPlayer.m_name;
		this->m_remainingBridges = otherPlayer.m_remainingBridges;
		this->m_remainingDots = otherPlayer.m_remainingDots;
		return*this;
	}

	std::istream& operator>>(std::istream& in, Player& player)
	{
		in >> player.m_name;
		player.setName(player.m_name);
		return in;
	}
}