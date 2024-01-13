#pragma once

#include "Observer_ptr.h"

namespace twixt {
	class Peg;
	class Bridge
	{
	private:
		Observer_ptr<Peg> m_firstPillar;
		Observer_ptr<Peg> m_secondPillar;

	public:
		Bridge() = default;
		Bridge(const Bridge& bridge);
		Bridge(Observer_ptr<Peg> firstPillar, Observer_ptr<Peg> secondPillar);
		~Bridge();

		Bridge& operator=(const Bridge& bridge);
		bool operator==(const Bridge& bridge) const;

		//setter
		void setPillars(std::unique_ptr<Peg> first, std::unique_ptr<Peg> second);
		void setFirstPillar(std::unique_ptr<Peg> peg);
		void setSecondPillar(std::unique_ptr<Peg> peg);

		//getter
		Observer_ptr<Peg> getFirstPillar() const;
		Observer_ptr<Peg> getSecondPillar() const;
		std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> getPillars() const;

		bool isPillarInBridge(Observer_ptr<Peg> peg) const;
		Observer_ptr<Peg> returnTheOtherPillar(Observer_ptr<Peg> peg);
	};
}

#include "Peg.h"
