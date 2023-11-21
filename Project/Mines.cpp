#include "Mines.h"

twixt::Mines::Mines() : Dot()
{
	m_status = DotStatus::Mines;
}

twixt::Mines::Mines(const Mines& newMine)
{
	m_status = newMine.m_status;
}

twixt::Mines::~Mines() {}

