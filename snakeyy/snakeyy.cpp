#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

//initializing variables
bool snakeGame;
const int width = 50;
const int height = 25;
//user variables
int x, y;
int speed = 1;
int tailX[100], tailY[100];
int tailLength = 0;
//tail co-ordinates
int fposX, fposY, sposX, sposY; 

//target variables 
int targetX, targetY;

//game variables
int score;
enum direction {STOP=0, UP, DOWN, LEFT, RIGHT};
direction dir;


void gamesetup()
{
		snakeGame = true;
		dir = STOP;

		srand(time(0));

		x = rand() % width;
		y = rand() % height;
	
		targetX = rand() % width;
		targetY = rand() % height;

		if (targetX == 0 || targetY == 0 || targetX == width-1 || targetY == height-1)
		{
			targetX = rand() % width;
			targetY = rand() % height;
		}
		//same position error

		while (x == targetX && y == targetY)
			{
				x = rand() % width;
				y =	rand() % height;

				targetX = rand() % width;
				targetY = rand() % height;

			}

		score = 0;

}

void window()
{
	//we need to clear the previous window first, or it'll just spawn again and again without the first one being deleted
		system("cls");
	//for loop to draw borders of the game board 
		//top border
		for (int i = 0;i < width;i++)
		{
			cout << "#";
		}
		cout << endl;
		//body
		for (int k = 0;k < height - 2;k++)
		{
			for (int j = 0;j < width;j++)
			{
				if (j == 0 || j == width - 1)
					cout << "*";
				else if (k == y && j == x)
				{
					cout << "S";
				}
				
				else if (k == targetY && j == targetX)
				{
					cout << "O";
				}
				else
				{
					bool tail = false;
					for (int m = 0;m < tailLength;m++)
					{
						if (j == tailX[m] && k == tailY[m])
						{
							cout << "s";
							tail == true;
						}
					}
					if (!tail)
					{
						cout << " ";
					}
				}
					
				
			}
			cout << endl;
		}
		//bottom border
		for (int i = 0;i < width;i++)
		{
			cout << "#";
		}

		cout << endl << endl;
		cout << "Your Score: " << score;
	
}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
			case 'a':
				if (dir != RIGHT)
				{
					dir = LEFT;
				}
				else
					snakeGame = false;
				break;
			case 'w':
				if (dir != DOWN)
				{
					dir = UP;
				}
				else
					snakeGame = false;
				break;
			case 's':
				if (dir != UP)
				{
					dir = DOWN;
				}
				else
					snakeGame = false;
				break;s
			case 'd':
				if (dir != LEFT)
				{
					dir = RIGHT;
				}
				else
					snakeGame = false;
				break;
			case '0':
				snakeGame = false;
				break;					

		}
	}
}

void program()
{
	//tail position
	fposX = tailX[0];
	fposY = tailY[0];
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < tailLength; i++)
	{
		sposX = tailX[i];
		sposY = tailY[i];
		tailX[i] = fposX;
		tailY[i] = fposY;
		fposX = sposX;
		fposY = sposY;
	}

	//moving the snake
	switch (dir)
	{
	case LEFT:
		x -= speed;
		break;
	case RIGHT:
		x += speed;
		break;
	case UP:
		y -= speed;
		break;
	case DOWN:
		y += speed;
		break;
	}

	//snake hits border
	if (x == 0 || x == width || y == 0 || y == height)
	{
		snakeGame = false;    
	}
	//snake hits tail
	for (int i = 0;i < tailLength;i++)
	{
		if (x == tailX[i] && y == tailY[i])
		{
			snakeGame = false;
		}
	}

	//snake hits target
	if (x == targetX && y == targetY)
	{
		targetX = rand() % width;
		targetY = rand() % height;
		
		if (targetX == 0 || targetY == 0 || targetX == width-1 || targetY == height-1)
		{
			targetX = rand() % width;
			targetY = rand() % height;
		}
		
		score++;
		tailLength++;
	}
}

int main()
{
	gamesetup();

	while (snakeGame == true)
	{
		window();
		input();
		program();
		Sleep(40);

	}
}