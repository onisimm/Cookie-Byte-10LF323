export module Bridge;

#include<cstdint>

export module Bridge.cppm;

import<iostream>;

namespace twixt {
	export class Bridge {
	private:
		std::string m_first_dot;
		std::string m_second_dot;


	public:
		//Constructor
		Bridge(std::string first_dot, std::string second_dot);
		//Copy constructor
		Bridge(const Bridge& newBridge);
		//Destructor
		~Bridge();
		
	};
}