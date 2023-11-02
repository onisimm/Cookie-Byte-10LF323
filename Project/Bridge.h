#include<cstdint>

#include<iostream>;


namespace twixt {
	class Bridge {
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
		Bridge& operator=(const Bridge& newBridge);
		//Getters
		std::string getFirst_dot();
		std::string getSecond_dot();
		//Setters
		void setFirst_dot(std::string);
		void setSecond_dot(std::string);
	};
}