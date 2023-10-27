module;

#include <cstdint>

export module Player.cppm;

import <iostream>;

namespace twixt {
	export class Player {
	private:
		std::string m_name, m_color;
	};
}