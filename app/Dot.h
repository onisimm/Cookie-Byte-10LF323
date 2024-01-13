#pragma once

#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>

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
            Bulldozer, // occupied by a bulldozer
            Mines, // occupied by a mine
            Exploded // exploded after a mine exploded
        };

        Dot();
        Dot(size_t, size_t);
        Dot(const Dot& newDot);
        Dot(Dot&& other) noexcept;

        virtual ~Dot();

        size_t getCoordI() const;
        size_t getCoordJ() const;
        DotStatus getStatus() const;
      
        void setCoordI(size_t);
        void setCoordJ(size_t);
        void setStatus(const DotStatus&);
      
        Dot& operator=(const Dot& newDot); // = overload
        Dot& operator=(Dot&& other) noexcept;  // Add move assignment operator
        bool operator==(const Dot& otherDot) const; // == overload 

    protected:
        DotStatus m_status : 3;
        size_t m_i, m_j; // coordinates;
    };
}

#include "Mine.h"
#include "Bridge.h"
