#include "Player.h"

namespace twixt {
	Player::Player(std::string name, Color color) :
		m_name{ name }, m_color{ color } {}
	Player::Player(const Player& newPlayer) :
		m_name{ newPlayer.m_name }, m_color{ newPlayer.m_color } {}
	Player::~Player() {}
	std::string Player::getName() {
		return m_name;
	}
	Player::Color Player::getColor() {
		return m_color;
	}
	void Player::setName(std::string name) {
		m_name = name;
	}
	void Player::setColor(Color color) {
		m_color = color;
	}
	void Player::turn(Board board, int i, int j)
	{
		//make matrix status => 
	}
	std::istream& operator>>(std::istream& in, Player& player) {
		in >> player.m_name;
		std::string color;
		in >> color;
		if (color == "red") {
			player.m_color = Player::Color::Red;
		}
		if (color == "black") {
			player.m_color = Player::Color::Black;
		}
		player.setName(player.m_name);
		return in;
	}
}