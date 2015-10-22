#pragma once
#include"Board.h"
#include "Snake.h"
#include "Food.h"
#include "Change.h"
class Game
{
public:
	Game();
	Game(int m,int n);
	~Game();
	void Menu();
	void Begin();
private:
	Boardd* board;
	Snake* snake;
	bool lose = false;
	Output* outPut;

	void GameGoOn(Food*,Change&);
	void GameOver();
	void GameOverMessage();
	void Reset(string&);
};

