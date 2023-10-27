#include "Player.cppm"

namespace twixt {
	Player::Player(std::string name, std::string color) :
		m_name{ name }, m_color{ color } {}
	Player::Player(const Player& newPlayer) :
		m_name{ newPlayer.m_name }, m_color{ newPlayer.m_color } {}
	Player::~Player() {}
	std::string Player::getName() {
		return m_name;
	}
	std::string Player::getColor() {
		return m_color;
	}
	void Player::setName(std::string name) {
		m_name = name;
	}
	void Player::setColor(std::string color) {
		m_color = color;
	}
}