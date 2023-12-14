#include "Minimax.h"

int twixt::Minimax::evaluate()
{
    return 0;
}

int twixt::Minimax::minimax(Dot::DotStatus status, int depth)
{
    return 0;
}

bool twixt::Minimax::canBlock(Dot* centralDot)
{
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
                    //modifica score-ul pt acest Dot
                }
            }

        }
    return false;
}

twixt::Dot* twixt::Minimax::blockOpponent(Dot* centralDot, Dot* firstOpponentDot, Dot* secondOpponentDot)
{
    return nullptr;
}
