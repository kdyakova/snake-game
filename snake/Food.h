#pragma once
#include <utility>	//pair
#include <stdlib.h>	//srand, rand
#include <time.h>	//time
#include"Board.h"
#include "Snake.h"
#include "GameOutput.h"
class Food
{
public:
	Food(Boardd* board,Snake* snake);
	~Food();
	void DisplayFood();
	std::pair<int, int> GetFoodPlace();
	void NewPlace(Boardd* board, Snake* snake);
private:
	std::pair<int, int> foodPlace;
	Output* outP;
};

