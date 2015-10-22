#include "Game.h"


Game::Game()
{
	board = new Board(60, 20);
	snake = new Snake(20, 10);
	outPut = new GameOutput;
}
Game::Game(int m, int n)
{
	board = new Board(m, n);
	snake = new Snake(m / 3, n / 2);
}

Game::~Game()
{
	delete board;
	delete snake;
	delete outPut;
}

void Game::Menu()
{
	cout << "SNAKE GAME!" << endl;
	cout << "You change direction the snake using the arrows" << endl;
	cout << "Your snake eats '*'  "<< endl;
	cout << "When your snake eats one it becomses longer" << endl;
	cout << "Your snake will die if it hits a wall or itself" << endl;
	cout << "To start the game type 'start'" << endl;
	string str;
	cin >> str;
	if (str == "start")
		Begin();
}
void Game::Begin()
{
	outPut->gotoxy(0, 0);
	Change change;
	board->DisplayBoard();
	snake->DisplaySnake();
	Food* f = new Food(board, snake);
	f->DisplayFood();
	GameGoOn(f, change);
	delete f;
}

void Game::GameGoOn(Food* f, Change& change)
{
	int Time = 400;
	int a = 1;
	while (!lose)
	{
		change.Move(board, snake, f);
		lose = change.isGameOver();
		if (snake->GetEatenFood() == a)
		{
			Time -= (a + 3);
			a++;
		}
		Sleep(Time);
	}
	if (lose)
	{
		GameOver();
	}
}
void Game::GameOver()
{
	outPut->gotoxy(snake->GetHead().first + 1, snake->GetHead().second + 1);
	cout << "X";
	GameOverMessage();
	string str;
	cout << "type repeat to try again or exit to exit the game" << endl;
	cin >> str;
	if (str == "repeat")
		Reset(str);
}


void Game::GameOverMessage()
{
	int x = (board->GetM() - 40) / 2;
	int y = (board->GetN() - 7) / 2;
	if (board->GetM() > 40 )
	{
		x = (board->GetM() - 40) / 2;
	}
	else
	{
		x = 1;
	}
	if (board->GetN() > 7)
	{
		y = (board->GetN() - 7) / 2;
	}
	else
	{
		y = 1;
	}
	outPut->fillscreen(x, y, x + 40, y + 7, '#');
	outPut->gotoxy(x + 14, y + 2);
	cout << " GAME OVER! ";
	outPut->gotoxy(x + 5, y + 3);
	cout << " You hit yourself in " << snake->GetCauseOfDeath() << "! ";
	outPut->gotoxy(x + 7, y + 4);
	cout << " You have eaten " << snake->GetEatenFood() << " food! ";
	outPut->gotoxy(0, board->GetN() + 2);
}
void  Game::Reset(string& command)
{
	outPut->gotoxy(0, board->GetN() + 2);
	cout << "You have started a new game!                     \n      ";
	outPut->gotoxy(0, 0);
	board = new Board(board->GetM(), board->GetN());
	snake = new Snake(board->GetM() / 3, board->GetN() / 2);
	lose = false;
	Begin();

}