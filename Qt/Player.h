#pragma once

#include <cstdint>
#include <iostream>

class Player
{
private:
    std::string m_name, m_color;
public:
    //Constructors
    Player(std::string name, std::string color);
    Player(const Player& newPlayer);

    //Destructor
    ~Player();

    //Getters
    std::string getName();
    std::string getColor();

    //Setters
    void setName(std::string);
    void setColor(std::string);

    friend std::istream& operator>>(std::istream& in, Player& player);
};
