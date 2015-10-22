#pragma once
#include "Snake.h"
#include "Food.h"
#include "Board.h"
#include "GameInput.h"
class Change
{
public:
	Change();
	~Change();
	void DirectionChange( );
	void Move(Boardd*, Snake*, Food*);
	bool isGameOver();
private:
	std::pair<int, int> m_direction;
	Input* m_input;
	bool lose;
};

