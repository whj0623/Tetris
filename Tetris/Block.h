#pragma once
#include <Windows.h>


class Block 
{
private:
	short turn = 0;
	short shape = 0;
	short x;
	short y;
	
public :
	Block()
	{
		shape = rand() % 7;
	}
	void setcoord(short _x, short _y)
	{
		x = _x, y = _y;
	}
	short getx()
	{
		return x;
	}
	short gety()
	{
		return y;
	}
	void setshape(short _shape)
	{
		shape = _shape;
	}
	short getshape()
	{
		return shape;
	}
	short getturn()
	{
		return turn;
	}
	void Turn()
	{
		turn++;
		if (turn == 4)
			turn = 0;
	}
};

