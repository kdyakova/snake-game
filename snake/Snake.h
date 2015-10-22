#pragma once
#include<list>
#include <utility> 
#include <string>
#include "GameOutput.h"
using namespace std;
class Snake
{
public:
	Snake(int x,int y);
	void DisplaySnake();
	bool SnakeMach();
	bool SnakeMach(int x, int y);
	~Snake();
	pair<int, int> GetHead();
	void Eat(pair<int,int>);
	void Move(pair<int, int>);
	string GetCauseOfDeath();
	void SetCauseOfDeath(string);
	int GetEatenFood();
private:
	list<pair<int,int> > m_body;
	Output* outP;
	int m_foodEaten;
	string m_causeOfDeath;
};

