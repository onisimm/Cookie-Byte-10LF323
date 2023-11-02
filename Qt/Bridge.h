#pragma once

#include <cstdint>
#include <iostream>

class Bridge
{
public:
    // Constructors
    Bridge(std::string first_dot, std::string second_dot);
    Bridge(const Bridge& newBridge);

    // Destructor
    ~Bridge();

    // Getters
    std::string getFirst_dot();
    std::string getSecond_dot();

    // Setters
    void setFirst_dot(std::string);
    void setSecond_dot(std::string);

    Bridge& operator=(const Bridge& newBridge);

private:
    std::string m_first_dot;
    std::string m_second_dot;
};
