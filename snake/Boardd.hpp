#pragma once
#include <iostream>
class Boardd
{
public:
	virtual int GetM()=0;
	virtual int GetN()=0;

	virtual void DisplayBoard()=0;
private:
	int m_m, m_n;
};
