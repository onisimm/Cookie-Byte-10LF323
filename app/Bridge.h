#pragma once

#ifndef BRIDGE_H
#define BRIDGE_H

#include "Dot.h"

namespace twixt {
	class Bridge
	{
	private:
		Dot* m_firstPillar;
		Dot* m_secondPillar;
	public:
		Bridge() = default;
		Bridge(const Bridge& bridge);
		Bridge(Dot* firstDot, Dot* secondDot);
		~Bridge();

		Bridge& operator=(const Bridge& bridge);

		//setter
		void setPillars(Dot* first, Dot* second);
		void setFirstPillar(Dot* pillar);
		void setSecondPillar(Dot* pillar);

		//getter
		Dot* getFirstPillar() const;
		Dot* getSecondPillar() const;
		std::pair<Dot*, Dot*> getPillars() const;

		bool isPillarInBridge(Dot* dot);
		void deleteBridge();
		Dot* returnTheOtherPillar(Dot* dot);
		void rebuiltBridge();
	};
}

#endif // BRIDGE_H
