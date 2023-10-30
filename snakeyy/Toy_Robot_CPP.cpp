#include <iostream>
#include <conio.h>

using namespace std;

enum myEnum {UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3};

int place(int x, int y, myEnum e)
{
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if(i == x && j == y)
            {
                cout<<" x ";
            }
            else
                cout<<"  ";
        }
    }
}

int move(int x, int y, myEnum e)
{
    switch(e)
    {
        case LEFT:
            if(x == 0)
                break;
            else
                x = x - 1;
                break;

        case RIGHT:
            if(x == 4)
                break;
            else
                x = x + 1;
                break;

        case UP:
            if(y == 0)
                break;
            else
                y = y - 1;
                break;

        case DOWN:
            if(y == 4)
                break;
            else
                y = y + 1;
                break;
        
    }
}

int right(myEnum e)
{
    if(e < 3)
    {
        e = e + 1;
    }
    else
        e = 0;
}

int left(myEnum e)
{
    if(e > 0)
    {
        e = e - 1;
    }
    else
        e = 3;
}

int report(int x, int y, myEnum e)
{
    cout<<"x = "<< x << endl;
    cout<<"y = "<< y << endl;
    cout<<"facing -> "<< e << endl;
}

int main()
{
    place(2, 3);
}