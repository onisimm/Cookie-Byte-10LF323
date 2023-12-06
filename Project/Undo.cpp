#include "Undo.h"

twixt::Undo::Undo(GameStack gameStack) : m_undoGameStack{ gameStack } {}

void twixt::Undo::pressed(Board board)
{
	twixt::Dot lastDot = *m_undoGameStack.GetGameStack().top().first;
	int type = m_undoGameStack.GetGameStack().top().second;

	switch (type)
	{


	}
}
