#pragma once
#include "Dot.h"

namespace twixt {
	class Bridge
	{
	private:
		Dot* m_firstPillar;
		Dot* m_secondPillar;
	public:
		Bridge();
		Bridge(const Bridge& bridge);
		~Bridge();
	};
}


