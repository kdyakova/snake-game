#include "GameInput.h"
#include <Windows.h>

std::pair<int, int> GameInput::getInput()
{
	if (GetAsyncKeyState(VK_UP)) return std::make_pair(0, -1);
	else if (GetAsyncKeyState(VK_DOWN)) return std::make_pair(0, 1);
	else if (GetAsyncKeyState(VK_LEFT)) return std::make_pair(-1,0);
	else if (GetAsyncKeyState(VK_RIGHT)) return std::make_pair( 1,0);
	return std::make_pair(0, 0);
}