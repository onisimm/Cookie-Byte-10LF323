#include "Minimax.h"
#include "..//DLL//Dot.h"
#include "..//DLL//Peg.h"

uint16_t twixt::Minimax::evaluate(std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> bridgeToEvaluate)
{
    int score = 1;
    const int LONGEST_PATH_VALUE = 10;
    const int EXISTING_BRIDGES_VALUE = 5;

    score += (longestPath(bridgeToEvaluate.first) + longestPath(bridgeToEvaluate.second)) * LONGEST_PATH_VALUE;
    score += (bridgeToEvaluate.first.GetPointer()->getExistingBridges().size() + bridgeToEvaluate.second.GetPointer()->getExistingBridges().size()) * EXISTING_BRIDGES_VALUE;


    return score;
}

std::pair<twixt::Observer_ptr<twixt::Peg>,twixt::Observer_ptr<twixt::Peg>> twixt::Minimax::minimax(Dot::Status status)
{
    uint16_t maximumScore = 0;
    std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> maximumBridge{ nullptr, nullptr };
    for (int row = 0; row < copyOfBoard.get().getSize(); row++)
        for (int column = 0; column < copyOfBoard.get().getSize(); column++)
        {
            if (row>=0 && column>=0 && row<copyOfBoard.get().getSize() && column< copyOfBoard.get().getSize()&& copyOfBoard.get().getMatrixDot(row, column)->getStatus() == status)
            {
               scorePossibleBridges(Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(row, column).get())));
                canBlock(Observer_ptr<Dot>(copyOfBoard.get().getMatrixDot(row, column).get()).To<Peg>());
            }
        }
    for (auto& it : mapBridges)
    {
        maximumScore = std::max(maximumScore, it.second);
        if (maximumScore == it.second)
            maximumBridge = { it.first.first, it.first.second };
    }
    return maximumBridge;
}

void twixt::Minimax::canBlock(Observer_ptr<Peg> centralDot)
{
    const int OPPONENT_LONGEST_PATH_VALUE = 7;
    std::vector<Observer_ptr<Peg>> opponentPlayerDots;
    for (int row = centralDot.GetPointer()->getCoordI() - 2; row <= centralDot.GetPointer()->getCoordI() + 2; row++)
        for (int column = centralDot.GetPointer()->getCoordJ() - 2; column <= centralDot.GetPointer()->getCoordJ() + 2; column++)
        {
            if(row >= 0 && row < copyOfBoard.get().getSize() && column >= 0 && column < copyOfBoard.get().getSize())
            {
                if (copyOfBoard.get().getMatrixDot(row, column)->getStatus() == centralDot.GetPointer()->returnTheOtherPlayer())
                {
                    opponentPlayerDots.push_back(Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(row, column).get())));
                }
            }
        }
    if(opponentPlayerDots.size() >= 2)
    {
        for (int row = 0; row < opponentPlayerDots.size() - 1; row++)
            for (int column = row + 1; column < opponentPlayerDots.size(); column++)
            {
                if ((abs((int)opponentPlayerDots[row].GetPointer()->getCoordI() - (int)opponentPlayerDots[column].GetPointer()->getCoordI()) == 1 && abs((int)opponentPlayerDots[row].GetPointer()->getCoordJ() - (int)opponentPlayerDots[column].GetPointer()->getCoordJ()) == 2) ||
                    (abs((int)opponentPlayerDots[row].GetPointer()->getCoordI() - (int)opponentPlayerDots[column].GetPointer()->getCoordI()) == 2 && abs((int)opponentPlayerDots[row].GetPointer()->getCoordJ() - (int)opponentPlayerDots[column].GetPointer()->getCoordJ()) == 1) ||
                    !existsBridgeBetween(opponentPlayerDots[row], opponentPlayerDots[column]))
                {
                    Observer_ptr<Peg> dotToBlock = blockOpponent(centralDot, opponentPlayerDots[row], opponentPlayerDots[column]);
                    if (dotToBlock != nullptr && !existsBridgeBetween(dotToBlock,centralDot) && copyOfBoard.get().checkObstructingBridges(*dotToBlock.GetPointer(),*centralDot.GetPointer()))
                    {
                        uint16_t newScore = 5;
                        auto it = mapBridges.find({ centralDot, dotToBlock });
                        if (it != mapBridges.end())
                        {
                            newScore = it->second;

                        }
                        newScore += (longestPath(opponentPlayerDots[row]) + longestPath(opponentPlayerDots[column])) * OPPONENT_LONGEST_PATH_VALUE;
                        mapBridges[{centralDot, dotToBlock}] = newScore;
                    }
                }

            }
    }
}

twixt::Observer_ptr<twixt::Peg> twixt::Minimax::blockOpponent(Observer_ptr<Peg> centralDot, Observer_ptr<Peg> firstOpponentDot, Observer_ptr<Peg> secondOpponentDot)
{
    std::array<std::pair<int, int>, 8> positions{ { { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } } };

    int row = centralDot.GetPointer()->getCoordI();
    int column = centralDot.GetPointer()->getCoordJ();

    for (auto& [newI, newJ] : positions)
    {
        newI += row;
        newJ += column;
        if (newI >= 0 && newI < copyOfBoard.get().getMatrix().size() && newJ >= 0 && newJ < copyOfBoard.get().getMatrix().size()) // check boundaries
        {
            if (copyOfBoard.get().getMatrix()[newI][newJ]->getStatus() == centralDot.GetPointer()->getStatus())
            {
                if (doIntersect(*centralDot.GetPointer(), *copyOfBoard.get().getDot(newI, newJ), *firstOpponentDot.GetPointer(), *secondOpponentDot.GetPointer()))
                {
                    return Observer_ptr<Dot>(copyOfBoard.get().getDot(newI, newJ).get()).To<Peg>();
                }
            }
        }
    }
    return nullptr;
}

uint16_t twixt::Minimax::longestPath(Observer_ptr<Peg> dot)
{
    Observer_ptr<Peg> newDot;
    uint16_t maximLength = 0;

    //Creating path vector: pair of dot in path and position of existing bridges for the dot.
    std::vector<std::pair<Observer_ptr<Peg>, size_t>> path;
    path.push_back({dot, 0 });

    while (!path.empty())
    {
        auto& [checkDot, position] = path[path.size() - 1];
        if (position < checkDot.GetPointer()->getExistingBridges().size())
        {
            newDot = checkDot.GetPointer()->getExistingBridges()[position].GetPointer()->returnTheOtherPillar(checkDot);
            if (!newDot.GetPointer()->isPegInPath(path))
            {
                path[path.size() - 1].second++;
                path.push_back({ newDot, 0 });
                checkDot = path[path.size() - 1].first;
                maximLength = std::max(maximLength, (uint16_t)path.size());
            }
            else
            {
                path[path.size() - 1].second++;
            }
        }
        else
        {
            path.pop_back();
        }
    }
    return maximLength;
}

void twixt::Minimax::scorePossibleBridges(Observer_ptr<Peg> dot)
{
    std::array<std::pair<int, int>, 8> positions{ { { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } } };

    int y = dot.GetPointer()->getCoordI();
    int x = dot.GetPointer()->getCoordJ();

    for (auto pair : positions)
    {
        auto [newY, newX] = pair;
        newY += y;
        newX += x;

        if (newY >= 0 && newY < copyOfBoard.get().getSize() && newX >= 0 && newX < copyOfBoard.get().getSize()) // check boundaries
        {
            if (copyOfBoard.get().getMatrixDot(newY, newX)->getStatus() == dot.GetPointer()->getStatus() && dot.GetPointer()->getStatus() != Dot::Status::Empty && copyOfBoard.get().checkObstructingBridges(*dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY, newX).get()), *dot.GetPointer()) && !existsBridgeBetween(Observer_ptr<Dot>(copyOfBoard.get().getMatrixDot(newX, newY).get()).To<Peg>(),dot ))
            {
                if (dot.GetPointer()->getBridgeFromPegs(Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY, newX).get()))) == nullptr
                    && mapBridges.find({ Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY,newX).get())),dot }) == mapBridges.end()
                    && mapBridges.find({ dot, Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY,newX).get())) }) == mapBridges.end())

                    mapBridges[std::make_pair(Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY, newX).get())), dot)] = evaluate({ Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY,newX).get())),dot });
            }
        }
    }
}

bool twixt::Minimax::existsBridgeBetween(Observer_ptr<Peg> firstPeg, Observer_ptr<Peg> secondPeg)
{
    return std::any_of(copyOfBoard.get().getBridges().begin(), copyOfBoard.get().getBridges().end(), [&](auto& bridge) {
        return bridge->isPillarInBridge(firstPeg) && bridge->isPillarInBridge(secondPeg);
        });
}

twixt::Minimax::Minimax(Board& board) : copyOfBoard{board} {}

std::pair<twixt::Observer_ptr<twixt::Peg>, twixt::Observer_ptr<twixt::Peg>> twixt::Minimax::suggestMove(Dot::Status status)
{
    std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>>myBridge = minimax(status);
    return myBridge ; 
}
