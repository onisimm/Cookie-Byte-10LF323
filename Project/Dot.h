//dot.h

#pragma once



#ifndef DOT_H
#define DOT_H

#include <cstdint>
#include <vector>
#include <iostream>

namespace twixt {
    class Mine;
    class Dot {
    public:
        // Constructors
        Dot(); // default

        Dot(const Dot& newDot); // copy constructor
        // Add move constructor
        Dot(Dot&& other) noexcept;

        // Add move assignment operator
        Dot& operator=(Dot&& other) noexcept;

        // Destructor 
        ~Dot();

        enum class DotStatus : uint8_t
        {
            Player1, // occupied by player 1
            Player2, // occupied by player 2
            Clear, // not occupied yet
            Bulldozer, //occupied by a bulldozer
            Mines //occupied by a mine
        };

        // Getters
        int getCoordI() const;
        int getCoordJ() const;
        DotStatus getStatus() const;
        const std::vector<Dot*>& getPossibleBridges() const;
        const std::vector<Dot*>& getExistingBridges() const;

        // Setters
        void setCoordI(int);
        void setCoordJ(int);
        void setStatus(const DotStatus&);

        // Operators overload
        Dot& operator=(const Dot& newDot); // = overload
        bool operator==(const Dot& otherDot) const; // == overload 
        friend std::ostream& operator<<(std::ostream& os, const Dot& dot); // << overload

        void addPossibleBridge(Dot* possibleBridgeDot); // add a possible bridge between this and possibleBridgeDot
        void clearPossibleBridges(); // clear all the possibleBridges

        void buildBridge(Dot* connectionDot); // build a bridge between this and connectionDot
        void clearExistingBridges(); // clear all the existingBridges
        const bool& checkExistingBridge(Dot* dotToCheck) const; // check if there's a bridge between this dot and dotToCheck

        bool isDotInPath(std::vector<std::pair<Dot*, int>> path) const;

        void deleteAllBridgesForADot();

        void allocationMine();
        Mine* getMine() const;
     
    private:
    
        DotStatus m_status : 3;
        int m_i, m_j; // coordinates

        std::vector<Dot*> m_possibleBridges;
        std::vector<Dot*> m_existingBridges;
        Mine* m_mine;
    };
}

#include "Mine.h"
#endif // !DOT_H