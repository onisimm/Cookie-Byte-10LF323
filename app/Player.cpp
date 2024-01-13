#include "Player.h"

namespace twixt {
	Player::Player(uint8_t remainingDots, uint8_t remainingBridges) :
		m_remainingDots{ remainingDots }, 
		m_remainingBridges{ remainingBridges } {}

	Player::Player(const Player& newPlayer) : 
		m_remainingDots{ newPlayer.m_remainingDots }, 
		m_remainingBridges{ newPlayer.m_remainingBridges } {}

	Player::Player(Player&& other) noexcept
	{
		m_remainingDots = other.m_remainingDots;
		m_remainingBridges = other.m_remainingBridges;
	}

	Player::~Player() {}

	uint8_t Player::getRemainingDots() const
	{
		return m_remainingDots;
	}

	uint8_t Player::getRemainingBridges() const
	{
		return m_remainingBridges;
	}

	PlayerType Player::getPlayerType() const
	{
		return m_playerType;
	}

	void Player::setRemainingDots(uint8_t remainingDots)
	{
		m_remainingDots = remainingDots;
	}

	void Player::setRemainingBridges(uint8_t remainingBridges)
	{
		m_remainingBridges = remainingBridges;
	}

	void Player::setPlayerType(PlayerType playerType)
	{
		m_playerType = playerType;
	}

	bool Player::hasRemainingDots()
	{
		return m_remainingDots > 0;
	}

	bool Player::hasRemainingBridges()
	{
		return m_remainingBridges > 0;
	}
}