#pragma once

#include "Dot.h"
#include <vector>

class Board
{
public:
    // Constructors
    Board();
    Board(uint32_t size);
    Board(const Board& newBoard);

    // Destructor
    ~Board();

    Board& operator=(const Board& newBoard);

    void addPossibleBridges(std::vector<std::vector<std::vector<std::pair<int, int>>>>& possible, int x, int y, Dot::DotStatus status);

private:
    std::vector<std::vector<std::vector<std::pair<int, int>>>> m_possibleBridgesPlayer1, m_possibleBridgesPlayer2;
    std::vector<std::vector<Dot>> m_matrixDot;
};
