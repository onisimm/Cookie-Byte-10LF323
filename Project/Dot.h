#pragma once
#include <cstdint>
#include <vector>

namespace twixt {
    class Dot {
    public:
        // Constructors
        Dot(); // default

        Dot(const Dot& newDot); // copy constructor

        // Destructor 
        ~Dot();

        enum class DotStatus : uint8_t {
            Player1, // occupied by player 1
            Player2, // occupied by player 2
            Clear // not occupied yet
        };

        // Getters
        int getCoordX();
        int getCoordY();
        DotStatus getStatus() const;

        // Setters
        void setCoordX(int);
        void setCoordY(int);
        void setStatus(DotStatus);

        // Operators overload
        Dot& operator=(const Dot& newDot); // = overload

        void addPossibleBridge(Dot* possibleBridge);
        const std::vector<Dot*>& getPossibleBridges() const;

    private:
        DotStatus m_status : 2;
        int m_x, m_y; // coordinates
        std::vector<Dot*> m_possibleBridges;
    };
}