//dot.h

#pragma once



#ifndef DOT_H
#define DOT_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <unordered_set>


namespace twixt {
    class Mine;
    class Bridge;
    class Dot {
    public:

        enum class DotStatus : uint8_t
        {
            Player1, // occupied by player 1
            Player2, // occupied by player 2
            Clear, // not occupied yet
            Bulldozer, //occupied by a bulldozer
            Mines //occupied by a mine
        };

        // Constructors
        Dot(); // default
        Dot(size_t, size_t);
        Dot(const Dot& newDot); // copy constructor
        Dot(Dot&& other) noexcept; // Add move constructor

        // Destructor 
        virtual ~Dot();

        // Getters
        size_t getCoordI() const;
        size_t getCoordJ() const;
        DotStatus getStatus() const;

        // Setters
        void setCoordI(size_t);
        void setCoordJ(size_t);
        void setStatus(const DotStatus&);

        // Operators overload
        Dot& operator=(const Dot& newDot); // = overload
        Dot& operator=(Dot&& other) noexcept;  // Add move assignment operator
        bool operator==(const Dot& otherDot) const; // == overload 
        // ? friend std::ostream& operator<<(std::ostream& os, const Dot& dot); // << overload

    protected:

        DotStatus m_status : 3;
        size_t m_i, m_j; // coordinates;
    };
}

#include "Mine.h"
#include "Bridge.h"

#endif // !DOT_H