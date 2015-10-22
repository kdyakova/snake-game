#include "Change.h"


Change::Change()
{
	m_direction = make_pair(1, 0);
	lose = false;
	m_input = new GameInput;
}


Change::~Change()
{
	delete m_input;
}

void Change::DirectionChange()
{
	pair<int, int> p = m_input->getInput();
	if (p.first != -m_direction.first &&
			p.second != -m_direction.second) 

	{
		m_direction.first = p.first;
		m_direction.second = p.second;
	}
}
void Change::Move(Boardd*board, Snake*snake, Food* food)
{
	this->DirectionChange();
	if (snake->GetHead().first == food->GetFoodPlace().first
		&& snake->GetHead().second == food->GetFoodPlace().second)
	{
		snake->Eat(m_direction);
		food->NewPlace(board, snake);
		food->DisplayFood();
	}
	else if (snake->GetHead().first < 0
		|| snake->GetHead().second < 0
		|| snake->GetHead().first >= board->GetM()
		|| snake->GetHead().second >= board->GetN()
		|| snake->SnakeMach())
	{
		lose = true;
		if (snake->GetCauseOfDeath() == "")
			snake->SetCauseOfDeath("a wall");
	}
	else
		snake->Move(m_direction);
}
bool Change::isGameOver()
{
	return lose;
}

