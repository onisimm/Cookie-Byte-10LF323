#include"Bridge.h"


namespace twixt {
	Bridge::Bridge(std::string first_dot, std::string second_dot) :
		m_first_dot{ first_dot }, m_second_dot{ second_dot } {}

	Bridge::Bridge(const Bridge& newBridge) :
		m_first_dot{ newBridge.m_first_dot }, m_second_dot{ newBridge.m_second_dot } {}
	
    Bridge::~Bridge() {}

	Bridge& Bridge::operator=(const Bridge& other) {
		// Copy
		m_first_dot = other.m_first_dot;
		m_second_dot = other.m_second_dot;
		return *this;

	}
	
	std::string Bridge::getFirst_dot()  {
		return m_first_dot;

	}

	std::string Bridge::getSecond_dot() {
		{
			return m_second_dot;
		} 
	}
	void Bridge::setFirst_dot(std::string first_dot) {
		m_first_dot = first_dot;
	}

	void Bridge::setSecond_dot(std::string second_dot) {
		m_second_dot = second_dot;
	}
}
