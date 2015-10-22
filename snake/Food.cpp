#include "Food.h"

Food::Food(Boardd* board, Snake* snake)
{
	int x, y;
	srand(time(NULL));
	do
	{
		x = rand() % board->GetM();
		y = rand() % board->GetN();
	}
	while (!snake->SnakeMach(x,y));
	foodPlace = make_pair(x, y);
	outP = new GameOutput;
}
void Food::NewPlace(Boardd* board, Snake* snake)
{
	int x, y;
	srand(time(NULL));
	do
	{
		x = rand() % board->GetM();
		y = rand() % board->GetN();
	} while (!snake->SnakeMach(x, y));
	foodPlace = make_pair(x, y);
}
void Food::DisplayFood()
{
	outP->gotoxy(foodPlace.first + 1, foodPlace.second + 1);
	printf("*");
}
pair<int, int> Food::GetFoodPlace()
{
	return foodPlace;
}
Food::~Food()
{
	delete outP;
}
