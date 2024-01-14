#pragma once

#ifndef PEG_H
#define PEG_H
#include "Dot.h"
#include <algorithm>



namespace twixt {
	class Bridge;
	class Peg : public Dot
	{
	private:
		std::vector<Observer_ptr<Bridge>> m_existingBridges;
	public:
		__declspec(dllexport) Peg();
		__declspec(dllexport) Peg(const Peg& newPeg);

		__declspec(dllexport) ~Peg();
		__declspec(dllexport) std::vector<Observer_ptr<Bridge>> getExistingBridges();


		__declspec(dllexport) Peg& operator=(const Peg& newPeg);
		__declspec(dllexport) bool operator==(const Peg& newPeg);

		__declspec(dllexport) void setExistingBridges(const std::vector<Observer_ptr<Bridge>>& existingBridges);

		__declspec(dllexport) void addBridge(Observer_ptr<Bridge> myBridge);

		__declspec(dllexport) bool isPegInPath(std::vector<std::pair<Observer_ptr<Peg>, size_t>> path) const;

		__declspec(dllexport) void removeBridgeFromExisting(Observer_ptr<Bridge> bridge);

		__declspec(dllexport) Dot::Status returnTheOtherPlayer();

		__declspec(dllexport) Observer_ptr<Bridge> getBridgeFromPegs(Observer_ptr<Peg> secondDot);


	};
}

#endif