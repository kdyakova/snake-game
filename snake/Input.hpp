#pragma once
#include <conio.h>
#include<utility>

class Input
{
public:
	virtual std::pair<int, int> getInput()=0;
};
