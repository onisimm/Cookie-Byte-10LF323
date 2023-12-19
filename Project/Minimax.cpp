#include "Minimax.h"

uint16_t twixt::Minimax::evaluate(std::pair<twixt::Dot*, twixt::Dot*> bridgeToEvaluate)
{
    int score = 1;
    const int LONGEST_PATH_VALUE = 10;
    const int EXISTING_BRIDGES_VALUE= 5;

    score += (longestPath(bridgeToEvaluate.first) + longestPath(bridgeToEvaluate.second)) * LONGEST_PATH_VALUE;
    score += (bridgeToEvaluate.first->getExistingBridges().size() + bridgeToEvaluate.second->getExistingBridges().size()) * EXISTING_BRIDGES_VALUE;


    return score;
}

std::pair<twixt::Dot*, twixt::Dot*> twixt::Minimax::minimax(Dot::DotStatus status)
{
    uint16_t maximumScore = 0;
    std::pair<twixt::Dot*, twixt::Dot*> maximumBridge{nullptr, nullptr };
    for (int i = 0; i < copyOfBoard->getSize(); i++)
       for (int j = 0; j < copyOfBoard->getSize(); j++)
       {
           if(copyOfBoard->getMatrixDot(i,j)->getStatus() == status)
              scorePossibleBridges(copyOfBoard->getMatrixDot(i, j));
       }
   for (auto it : mapBridges)
   {
       maximumScore = std::max(maximumScore, it.second);
       if(maximumScore == it.second)
            maximumBridge = it.first;
   }
   return maximumBridge;
}

void twixt::Minimax::canBlock(Dot* centralDot)
{
    const int OPPONENT_LONGEST_PATH_VALUE = 7;
    std::vector<Dot*> opponentPlayerDots;
    for (int i = centralDot->getCoordI() - 2; i <= centralDot->getCoordI() + 2; i++)
        for (int j = centralDot->getCoordJ() - 2; j <= centralDot->getCoordJ() + 2; j++)
        {
            if (copyOfBoard->getMatrixDot(i, j)->getStatus() == centralDot->returnTheOtherPlayer())
            {
                opponentPlayerDots.push_back(copyOfBoard->getMatrixDot(i, j));
            }
        }
    for (int i = 0; i < opponentPlayerDots.size() - 1; i++)
        for (int j = i + 1; j < opponentPlayerDots.size(); j++)
        {
            if ((abs((int)opponentPlayerDots[i]->getCoordI() - (int)opponentPlayerDots[j]->getCoordI()) == 1 && abs((int)opponentPlayerDots[i]->getCoordJ() - (int)opponentPlayerDots[j]->getCoordJ()) == 2) ||
                (abs((int)opponentPlayerDots[i]->getCoordI() - (int)opponentPlayerDots[j]->getCoordI()) == 2 && abs((int)opponentPlayerDots[i]->getCoordJ() - (int)opponentPlayerDots[j]->getCoordJ()) == 1))
            {
                Dot* dotToBlock = blockOpponent(centralDot, opponentPlayerDots[i], opponentPlayerDots[j]);
                if (dotToBlock != nullptr)
                {
                    mapBridges[{centralDot, dotToBlock}] += (longestPath(opponentPlayerDots[i]) + longestPath(opponentPlayerDots[j])) * 7;
                }
            }

        }
}

twixt::Dot* twixt::Minimax::blockOpponent(Dot* centralDot, Dot* firstOpponentDot, Dot* secondOpponentDot)
{
    std::vector<std::pair<int, int>> positions{ { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } };

    int i = centralDot->getCoordI();
    int j = centralDot->getCoordJ();

    for (auto& [newI, newJ] : positions)
    {
        newI += i;
        newJ += j;
        if (newI >= 0 && newI < copyOfBoard->getMatrix().size() && newJ >= 0 && newJ < copyOfBoard->getMatrix().size()) // check boundaries
        {
            if (copyOfBoard->getMatrix()[newI][newJ]->getStatus() == centralDot->getStatus())
            {
                if (copyOfBoard->checkPossibleObstructingBridges(*copyOfBoard->getDot(i, j), *copyOfBoard->getDot(newI, newJ)))
                {
                    return copyOfBoard->getDot(newI, newJ);
                }
            }
        }
    }
    return nullptr;
}

uint16_t twixt::Minimax::longestPath(Dot* dot)
{
    Dot* newDot;
    uint16_t maximLength = 0;

    //Creating path vector: pair of dot in path and position of existing bridges for the dot.
    std::vector<std::pair<Dot*, size_t>> path;
    path.push_back({ dot, 0 });

    while (!path.empty())
    {
        auto [checkDot, position] = path[path.size() - 1];
        if (position < checkDot->getExistingBridges().size())
        {
            newDot = checkDot->getExistingBridges()[position]->returnTheOtherPillar(checkDot);
            if (!newDot->isDotInPath(path))
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

void twixt::Minimax::scorePossibleBridges(Dot* dot)
{
        std::vector<std::pair<int, int>> positions{ { -2, -1 }, { -1, -2 }, { 1, -2 }, { 2, -1 }, { 2, 1 }, { 1, 2 }, { -1, 2 }, { -2, 1 } };

        int y = dot->getCoordI();
        int x = dot->getCoordJ();

        for (auto pair : positions)
        {
            auto [newY, newX] = pair;
            newY += y;
            newX += x;

            if (newY >= 0 && newY <copyOfBoard->getSize() && newX >= 0 && newX < copyOfBoard->getSize()) // check boundaries
            {
                if (copyOfBoard->getMatrixDot(newY,newX)->getStatus() == dot->getStatus() && dot->getStatus() != Dot::DotStatus::Clear)
                {
                    if (dot->getBridgeFromDots(copyOfBoard->getMatrixDot(newY, newX))==nullptr 
                        && mapBridges.find({ copyOfBoard->getMatrixDot(newY,newX),dot }) == mapBridges.end())
                        mapBridges[std::make_pair(copyOfBoard->getMatrixDot(newY, newX), dot)] = evaluate({ copyOfBoard->getMatrixDot(newY,newX),dot });
                    //de verificat: daca nu exista bridge-ul iontre cele 2 dot-uri, atunci se poate 
                }
            }
        }
}

twixt::Minimax::Minimax(Board* board)
{
    copyOfBoard = board;
}

void twixt::Minimax::suggestMove(Dot::DotStatus status)
{
    std::pair<twixt::Dot*, twixt::Dot*>myBridge = minimax(status);
    if (myBridge != std::make_pair(nullptr, nullptr))
    {
        std::cout << "It is recommended to create the bridge between " << myBridge.first->getCoordI() << " " << myBridge.first->getCoordJ() << " and " << myBridge.second->getCoordI() << " " << myBridge.second->getCoordJ() << ".\n";
    }
    else
    {
        std::cout << " -> In this case there is no suggestion.\n";
    }
}
