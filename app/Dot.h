#pragma once

#include <cstdint>
#include <vector>
#include <iostream>
#include <unordered_set>
#include "Observer_ptr.h"


namespace twixt {
    class Mine;
    class Bridge;

    class Dot {
    public:
        enum class Status : uint16_t
        {
            Player1, // occupied by player 1
            Player2, // occupied by player 2
            Empty, // not occupied yet
            Bulldozer, // occupied by a bulldozer
            Mine, // occupied by a mine
            Exploded, // exploded after a mine exploded
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
        Status getStatus() const;

        // Setters
        void setCoordI(size_t);
        void setCoordJ(size_t);
        void setStatus(const Status&);

        // Operators overload
        Dot& operator=(const Dot& newDot); // = overload
        Dot& operator=(Dot&& other) noexcept;  // Add move assignment operator
        virtual bool operator==(const Dot& otherDot) const; // == overload 

    protected:
        Status m_status = Status::Empty;
        size_t m_i, m_j; // coordinates;
    };
}

#include "Mine.h"
#include "Bridge.h"
