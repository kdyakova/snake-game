#pragma once
#include "Input.hpp"
#include <conio.h>
#include<utility>

class GameInput :public Input
{
public:
	virtual std::pair<int, int> getInput();
};

