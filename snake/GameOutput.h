#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Output.hpp"
class GameOutput :public Output
{
public:
	virtual void gotoxy(int column, int line);
	virtual void fillscreen(int s_col, int s_row, int e_col, int e_row, char ch);
};
