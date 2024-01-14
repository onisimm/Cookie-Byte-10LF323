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
		__declspec(dllexport) Bridge() = default;
		__declspec(dllexport) Bridge(const Bridge& bridge);
		__declspec(dllexport) Bridge(Observer_ptr<Peg> firstPillar, Observer_ptr<Peg> secondPillar);
		__declspec(dllexport) ~Bridge();

		__declspec(dllexport) Bridge& operator=(const Bridge& bridge);
		__declspec(dllexport) bool operator==(const Bridge& bridge) const;

		//setter
		__declspec(dllexport) void setPillars(std::unique_ptr<Peg> first, std::unique_ptr<Peg> second);
		__declspec(dllexport) void setFirstPillar(std::unique_ptr<Peg> peg);
		__declspec(dllexport) void setSecondPillar(std::unique_ptr<Peg> peg);

		//getter
		__declspec(dllexport) Observer_ptr<Peg> getFirstPillar() const;
		__declspec(dllexport) Observer_ptr<Peg> getSecondPillar() const;
		__declspec(dllexport) std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> getPillars() const;

		__declspec(dllexport) bool isPillarInBridge(Observer_ptr<Peg> peg) const;
		__declspec(dllexport) Observer_ptr<Peg> returnTheOtherPillar(Observer_ptr<Peg> peg);
	};
}

#include "Peg.h"
