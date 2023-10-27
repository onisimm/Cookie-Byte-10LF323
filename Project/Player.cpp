#include "Player.cppm"

namespace twixt {
	Player::Player(std::string name, std::string color) :
		m_name{ name }, m_color{ color } {}
	Player::Player(const Player& newPlayer) :
		m_name{ newPlayer.m_name }, m_color{ newPlayer.m_color } {}
	Player::~Player() {}
}