#pragma once
class Output
{
public:
	virtual void gotoxy(int column, int line)=0;
	virtual void fillscreen(int s_col, int s_row, int e_col, int e_row, char ch)=0;
};
