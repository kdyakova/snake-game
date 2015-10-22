#include "GameOutput.h"
#include <iostream>

void GameOutput::gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
		);
}

void GameOutput::fillscreen(int s_col, int s_row, int e_col, int e_row,char ch)
{
	while (s_row != e_row)
	{
		gotoxy(s_col, s_row);
		int col = s_col;
		while (col != e_col)
		{
			std::cout << ch;
			col++;
		}
		s_row++;
	}
}