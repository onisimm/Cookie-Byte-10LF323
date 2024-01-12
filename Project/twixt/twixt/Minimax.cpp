#include "Minimax.h"

uint16_t twixt::Minimax::evaluate(std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> bridgeToEvaluate)
{
    int score = 1;
    const int LONGEST_PATH_VALUE = 10;
    const int EXISTING_BRIDGES_VALUE = 5;

    score += (longestPath(bridgeToEvaluate.first) + longestPath(bridgeToEvaluate.second)) * LONGEST_PATH_VALUE;
    score += (bridgeToEvaluate.first.GetPointer()->getExistingBridges().size() + bridgeToEvaluate.second.GetPointer()->getExistingBridges().size()) * EXISTING_BRIDGES_VALUE;


    return score;
}

std::pair<twixt::Observer_ptr<twixt::Peg>,twixt::Observer_ptr<twixt::Peg>> twixt::Minimax::minimax(Dot::DotStatus status)
{
    uint16_t maximumScore = 0;
    std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>> maximumBridge{ nullptr, nullptr };
    for (int i = 0; i < copyOfBoard.get().getSize(); i++)
        for (int j = 0; j < copyOfBoard.get().getSize(); j++)
        {
            if (i>=0 && j>=0 && i<copyOfBoard.get().getSize() && j< copyOfBoard.get().getSize()&& copyOfBoard.get().getMatrixDot(i, j)->getStatus() == status)
            {
               scorePossibleBridges(Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(i, j).get())));
                canBlock(Observer_ptr<Dot>(copyOfBoard.get().getMatrixDot(i, j).get()).To<Peg>());
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
    for (int i = centralDot.GetPointer()->getCoordI() - 2; i <= centralDot.GetPointer()->getCoordI() + 2; i++)
        for (int j = centralDot.GetPointer()->getCoordJ() - 2; j <= centralDot.GetPointer()->getCoordJ() + 2; j++)
        {
            if (copyOfBoard.get().getMatrixDot(i, j)->getStatus() == centralDot.GetPointer()->returnTheOtherPlayer())
            {
                opponentPlayerDots.push_back(Observer_ptr<Peg>(dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(i, j).get())));
            }
        }
    if(opponentPlayerDots.size() >= 2)
    {
        for (int i = 0; i < opponentPlayerDots.size() - 1; i++)
            for (int j = i + 1; j < opponentPlayerDots.size(); j++)
            {
                if ((abs((int)opponentPlayerDots[i].GetPointer()->getCoordI() - (int)opponentPlayerDots[j].GetPointer()->getCoordI()) == 1 && abs((int)opponentPlayerDots[i].GetPointer()->getCoordJ() - (int)opponentPlayerDots[j].GetPointer()->getCoordJ()) == 2) ||
                    (abs((int)opponentPlayerDots[i].GetPointer()->getCoordI() - (int)opponentPlayerDots[j].GetPointer()->getCoordI()) == 2 && abs((int)opponentPlayerDots[i].GetPointer()->getCoordJ() - (int)opponentPlayerDots[j].GetPointer()->getCoordJ()) == 1) ||
                    !existsBridgeBetween(opponentPlayerDots[i], opponentPlayerDots[j]))
                {
                    Observer_ptr<Peg> dotToBlock = blockOpponent(centralDot, opponentPlayerDots[i], opponentPlayerDots[j]);
                    if (dotToBlock != nullptr && !existsBridgeBetween(dotToBlock,centralDot) && copyOfBoard.get().checkObstructingBridges(*dotToBlock.GetPointer(),*centralDot.GetPointer()))
                    {
                        uint16_t newScore = 5;
                        auto it = mapBridges.find({ centralDot, dotToBlock });
                        if (it != mapBridges.end())
                        {
                            newScore = it->second;

                        }
                        newScore += (longestPath(opponentPlayerDots[i]) + longestPath(opponentPlayerDots[j])) * OPPONENT_LONGEST_PATH_VALUE;
                        mapBridges[{centralDot, dotToBlock}] = newScore;
                    }
                }

            }
    }
}

twixt::Observer_ptr<twixt::Peg> twixt::Minimax::blockOpponent(Observer_ptr<Peg> centralDot, Observer_ptr<Peg> firstOpponentDot, Observer_ptr<Peg> secondOpponentDot)
{
    std::array<std::pair<int, int>, 8> positions{ { { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } } };

    int i = centralDot.GetPointer()->getCoordI();
    int j = centralDot.GetPointer()->getCoordJ();

    for (auto& [newI, newJ] : positions)
    {
        newI += i;
        newJ += j;
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
            if (copyOfBoard.get().getMatrixDot(newY, newX)->getStatus() == dot.GetPointer()->getStatus() && dot.GetPointer()->getStatus() != Dot::DotStatus::Clear && copyOfBoard.get().checkObstructingBridges(*dynamic_cast<Peg*>(copyOfBoard.get().getMatrixDot(newY, newX).get()), *dot.GetPointer()) && !existsBridgeBetween(Observer_ptr<Dot>(copyOfBoard.get().getMatrixDot(newX, newY).get()).To<Peg>(),dot ))
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
    for (auto& bridges : copyOfBoard.get().getBridges())
    {
        if (bridges.get()->isPillarInBridge(firstPeg) && bridges.get()->isPillarInBridge(secondPeg))
            return true;
    }
    return false;
}

twixt::Minimax::Minimax(Board& board) : copyOfBoard{board}
{
}

void twixt::Minimax::suggestMove(Dot::DotStatus status)
{
    std::pair<Observer_ptr<Peg>, Observer_ptr<Peg>>myBridge = minimax(status);
    if (myBridge != std::make_pair(nullptr, nullptr))
    {
        std::cout << "It is recommended to create the bridge between " << myBridge.first.GetPointer()->getCoordI() << " " << myBridge.first.GetPointer()->getCoordJ() << " and " << myBridge.second.GetPointer()->getCoordI() << " " << myBridge.second.GetPointer()->getCoordJ() << ".\n";
    }
    else
    {
        std::cout << " -> In this case there are no suggestions.\n";
    }
}
