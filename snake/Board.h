#pragma once
#include <iostream>
#include "Boardd.hpp"
class Board:public Boardd
{
public:
	Board(int m,int n);
	 ~Board();
	 int GetM();
	 int GetN();

	 void DisplayBoard();
private:
	int m_m, m_n;
};

