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
        __declspec(dllexport)  Dot(); // default
        __declspec(dllexport)  Dot(size_t, size_t);
        __declspec(dllexport)  Dot(const Dot& newDot); // copy constructor
        __declspec(dllexport)  Dot(Dot&& other) noexcept; // Add move constructor

        // Destructor 
        __declspec(dllexport)  virtual ~Dot();

        // Getters
        __declspec(dllexport)  size_t getCoordI() const;
        __declspec(dllexport)  size_t getCoordJ() const;
        __declspec(dllexport)  Status getStatus() const;

        // Setters
        __declspec(dllexport) void setCoordI(size_t);
        __declspec(dllexport) void setCoordJ(size_t);
        __declspec(dllexport)  void setStatus(const Status&);

        // Operators overload
        __declspec(dllexport) Dot& operator=(const Dot& newDot); // = overload
        __declspec(dllexport) Dot& operator=(Dot&& other) noexcept;  // Add move assignment operator
        __declspec(dllexport)  virtual bool operator==(const Dot& otherDot) const; // == overload 

    protected:
        Status m_status = Status::Empty;
        size_t m_i, m_j; // coordinates;
    };
}

#include "Mine.h"
#include "Bridge.h"
