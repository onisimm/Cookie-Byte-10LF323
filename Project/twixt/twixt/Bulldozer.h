#pragma once

#ifndef BULLDOZER_H
#define BULLDOZER_H

#include"Board.h"

#include <random>
#include <stack>

namespace twixt {
	class Bulldozer : public Dot
	{
	private:
		std::pair<size_t, size_t> position;
		std::stack<std::pair<size_t, size_t>> m_previousPosition;
		std::stack<Peg> m_dotDestroyed;
		void destoryRandomDot(Board& board);

	public:
		Bulldozer(Board& board);
		Bulldozer(const Bulldozer& Bulldozer);
		Bulldozer() = default;
		~Bulldozer()override
		{}

		Bulldozer& operator=(const Bulldozer& Bulldozer);
		bool flipCoin(Board& board);
		bool exists();
		std::stack<std::pair<size_t, size_t>> getPreviousPosition() const;
		std::stack<Peg> getPegDestroyed() const;
		void setToPreviousPosition(Board& board);
	};
}

#include "Peg.h"
#endif