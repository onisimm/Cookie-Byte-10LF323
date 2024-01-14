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
		std::stack<Peg> m_dotBridgesDestroyed;
		void destoryRandomDot(Board& board);

	public:
		__declspec(dllexport) Bulldozer(Board& board);
		__declspec(dllexport) Bulldozer(const Bulldozer& Bulldozer);
		__declspec(dllexport) Bulldozer() = default;
		__declspec(dllexport) ~Bulldozer()override
		{}

		__declspec(dllexport) Bulldozer& operator=(const Bulldozer& Bulldozer);
		__declspec(dllexport) bool flipCoin(Board& board);
		__declspec(dllexport) bool exists();
		__declspec(dllexport) std::stack<std::pair<size_t, size_t>> getPreviousPosition() const;
		__declspec(dllexport) std::stack<Peg>& getPegDestroyed();
		__declspec(dllexport) std::stack<Peg>& getPegBridgeDestroyed();
		__declspec(dllexport) void setToPreviousPosition(Board& board);
	};
}

#include "Peg.h"
#endif