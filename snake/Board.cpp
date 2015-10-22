#include "Board.h"

 Board::Board(int m, int n) :m_m(m), m_n(n)
{

}


Board::~Board()
{
}


int Board::GetM()
{
	return m_m;
}
int Board::GetN()
{
	return m_n;
}
void Board::DisplayBoard()
{
	for (int i = 0; i <= m_n + 1; i++)
	{
		for (int j = 0; j <= m_m + 1; j++)
		{
			if (i == 0 || i == m_n + 1 || j == 0 || j == m_m + 1)
				std::cout << (char) 178;
			else
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
}