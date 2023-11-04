#include<cstdint>

#include<iostream>;


namespace twixt {
	class Bridge {
	public:
		// Constructors 
		Bridge(std::string first_dot, std::string second_dot);
		Bridge(const Bridge& newBridge); // copy constructor

		// Destructor
		~Bridge();

		// Getters
		std::string getFirst_dot();
		std::string getSecond_dot();

		// Setters
		void setFirst_dot(std::string);
		void setSecond_dot(std::string);

		// Operator Overload
		Bridge& operator=(const Bridge& newBridge); // = overload

	private:
		std::string m_first_dot;
		std::string m_second_dot;
	};
}