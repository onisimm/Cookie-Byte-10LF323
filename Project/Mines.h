#pragma once
#include <iostream>
#include <vector>
#include "Dot.h"
namespace twixt {
	class Mines : public Dot
	{
	public:
		//constructors
		Mines(); //constructor
		Mines(const Mines& newMine); //copy constructor
		~Mines(); //destructor
	};
}

