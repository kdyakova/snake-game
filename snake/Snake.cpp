#include "Snake.h"

Snake::Snake(int x, int y)
{
	m_body.push_back(make_pair(x,y));
	m_causeOfDeath = "";
	m_foodEaten = 0;
	outP = new GameOutput;
}


Snake::~Snake()
{
	delete outP;
}
void Snake::Eat(pair<int,int> direction)
{
	m_body.push_front(make_pair(
		m_body.front().first + direction.first,
		m_body.front().second + direction.second));
	m_foodEaten++;
	this->DisplaySnake();
}
void Snake::Move(pair<int, int> direction)
{
	m_body.push_front(make_pair(
		m_body.front().first + direction.first,
		m_body.front().second + direction.second));
	outP->gotoxy(m_body.back().first+1,
		m_body.back().second+1);
	printf(" ");
	m_body.pop_back();
	this->DisplaySnake();
}
void Snake::DisplaySnake()
{
	for (auto it = m_body.begin(); it != m_body.end(); it++)
	{
		outP->gotoxy((*it).first+1, (*it).second+1);
		if (it == m_body.begin())
			printf("@");
		else
		printf("O");
	}
}


bool Snake::SnakeMach(int x, int y)
{
	for (auto it = m_body.begin(); it != m_body.end(); it++)
	{
		if ((*it).first == x && (*it).second == y)
			return false;
	}
	return true;
}
bool Snake::SnakeMach()
{	
	if (m_body.size() < 4)
		return false;
	else
	{
		auto it = (m_body.begin())++;
		for (it++; it != m_body.end(); it++)
		{
			if ((*it).first == m_body.front().first &&
				(*it).second == m_body.front().second)
			{
				m_causeOfDeath = "yourself";
				return true;
			}
		}
		return false;
	}
}
pair<int,int> Snake::GetHead()
{
	return m_body.front();
}

string Snake::GetCauseOfDeath()
{
	return m_causeOfDeath;
}
void Snake::SetCauseOfDeath(string str)
{
	m_causeOfDeath = str;
}

int Snake::GetEatenFood()
{
	return m_foodEaten;
}