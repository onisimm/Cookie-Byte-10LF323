#pragma once

#ifndef PEG_H
#define PEG_H
#include "Dot.h"



namespace twixt {
	class Bridge;
	class Peg : public Dot
	{
	private:
		std::vector<Observer_ptr<Bridge>> m_existingBridges;
	public:
		Peg();
		Peg(const Peg& newPeg);
		~Peg();
		std::vector<Observer_ptr<Bridge>> getExistingBridges();

		Peg& operator=(const Peg& newPeg);
		bool operator==(const Peg& newPeg);

		void setExistingBridges(const std::vector<Observer_ptr<Bridge>>& existingBridges);

		void addBridge(Observer_ptr<Bridge> myBridge);

		bool isPegInPath(std::vector<std::pair<Observer_ptr<Peg>, size_t>> path) const;

		//void deleteAllBridgesForAPeg();
		void removeBridgeFromExisting(Observer_ptr<Bridge> bridge);

		Dot::Status returnTheOtherPlayer();

		Observer_ptr<Bridge> getBridgeFromPegs(Observer_ptr<Peg> secondDot);


	};
}

#endif