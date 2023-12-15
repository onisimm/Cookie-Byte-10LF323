#include "Minimax.h"

int twixt::Minimax::evaluate(Bridge* bridgeToEvaluate)
{
    int score = 0;
    const int LONGEST_PATH_VALUE = 10;
    const int EXISTING_BRIDGES_VALUE= 5;

    score += (longestPath(bridgeToEvaluate->getFirstPillar()) + longestPath(bridgeToEvaluate->getSecondPillar())) * LONGEST_PATH_VALUE;
    score += (bridgeToEvaluate->getFirstPillar()->getExistingBridges().size() + bridgeToEvaluate->getSecondPillar()->getExistingBridges().size()) * EXISTING_BRIDGES_VALUE;


    return 0;
}

int twixt::Minimax::minimax(Dot::DotStatus status)
{



    return 0;
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
            if ((abs(opponentPlayerDots[i]->getCoordI() - opponentPlayerDots[j]->getCoordI()) == 1 && abs(opponentPlayerDots[i]->getCoordJ() - opponentPlayerDots[j]->getCoordJ()) == 2) ||
                (abs(opponentPlayerDots[i]->getCoordI() - opponentPlayerDots[j]->getCoordI()) == 2 && abs(opponentPlayerDots[i]->getCoordJ() - opponentPlayerDots[j]->getCoordJ()) == 1))
            {
                Dot* dotToBlock = blockOpponent(centralDot, opponentPlayerDots[i], opponentPlayerDots[j]);
                if (dotToBlock != nullptr)
                {
                    //mapBridges[centralDot->getBridgeFromDots(dotToBlock)] += (longestPath(opponentPlayerDots[i]) + longestPath(opponentPlayerDots[j])) * 7;
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
                /*if (copyOfBoard->doIntersect(*copyOfBoard->getDot(i, j), *copyOfBoard->getDot(newI, newJ), *firstOpponentDot, *secondOpponentDot))
                {
                    return copyOfBoard->getDot(newI, newJ);
                }*/
            }
        }
    }
    return nullptr;
}

int twixt::Minimax::longestPath(Dot* dot)
{
    return 0;
}
