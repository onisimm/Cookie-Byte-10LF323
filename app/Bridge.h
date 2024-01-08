#pragma once

#ifndef BRIDGE_H
#define BRIDGE_H

#include "Peg.h"

namespace twixt {
	class Peg;
	class Bridge
	{
	private:
		Peg* m_firstPillar;
		Peg* m_secondPillar;
	public:
		Bridge() = default;
		Bridge(const Bridge& bridge);
		Bridge(Peg* firstPillar, Peg* secondPillar);
		~Bridge();

		Bridge& operator=(const Bridge& bridge);

		//setter
		void setPillars(Peg* first, Peg* second);
		void setFirstPillar(Peg* peg);
		void setSecondPillar(Peg* peg);

		//getter
		Peg* getFirstPillar() const;
		Peg* getSecondPillar() const;
		std::pair<Peg*, Peg*> getPillars() const;

		bool isPillarInBridge(Peg* peg);
		void deleteBridge();
		Peg* returnTheOtherPillar(Peg* peg);
		void rebuiltBridge();
	};
}

#endif // BRIDGE_H
