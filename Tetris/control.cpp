#include "control.h"

enum direction
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

const bool blocks[7][4][4][4]=
{
	{
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,1,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,1,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,1,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,1,1,0}
			,{0,0,0,0}
		}
	},
	{
		{
			{0,1,0,0}
			,{0,1,0,0}
			,{0,1,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,1}
			,{0,1,0,0}
			,{0,0,0,0}
		},
		{
			{0,1,1,0}
			,{0,0,1,0}
			,{0,0,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,0,0,1}
			,{0,1,1,1}
			,{0,0,0,0}
		}
	},
	{
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{1,1,0,0}
			,{0,0,0,0}
		},
		{
			{1,0,0,0}
			,{1,1,0,0}
			,{0,1,0,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{1,1,0,0}
			,{0,0,0,0}
		},
		{
			{1,0,0,0}
			,{1,1,0,0}
			,{0,1,0,0}
			,{0,0,0,0}
		}
	},
	{
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,0,1,1}
			,{0,0,0,0}
		},
		{
			{0,0,1,0}
			,{0,1,1,0}
			,{0,1,0,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,0,1,1}
			,{0,0,0,0}
		},
		{
			{0,0,1,0}
			,{0,1,1,0}
			,{0,1,0,0}
			,{0,0,0,0}
		}
	},
	{
		{
			{0,0,0,0}
			,{0,1,0,0}
			,{1,1,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,0,0}
			,{0,1,1,0}
			,{0,1,0,0}
		},
		{
			{0,0,0,0}
			,{0,0,0,0}
			,{1,1,1,0}
			,{0,1,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,0,0}
			,{1,1,0,0}
			,{0,1,0,0}
		}
	},
	{
		{
			{0,0,0,0}
			,{1,1,1,0}
			,{0,0,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,1,0}
			,{0,0,1,0}
			,{0,1,1,0}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,0,0}
			,{0,1,1,1}
			,{0,0,0,0}
		},
		{
			{0,0,0,0}
			,{0,1,1,0}
			,{0,1,0,0}
			,{0,1,0,0}
		}
	},
	{
		{
			{0,0,0,0}
			,{1,1,1,1}
			,{0,0,0,0}
			,{0,0,0,0}
		},
		{
			{0,0,1,0}
			,{0,0,1,0}
			,{0,0,1,0}
			,{0,0,1,0}
		},
		{
			{0,0,0,0}
			,{1,1,1,1}
			,{0,0,0,0}
			,{0,0,0,0}
		},
		{
			{0,0,1,0}
			,{0,0,1,0}
			,{0,0,1,0}
			,{0,0,1,0}
		}
	}
};
screen scr;

void control::draw(Block block)
{
	
	
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			scr.gotoxy(block.getx()+x * 2, block.gety()+y);
			if (blocks[block.getshape()][block.getturn()][y][x])
				std::cout << "бр";
		}
	}
}
void control::deleteblock(Block block)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			scr.gotoxy(block.getx() + x * 2, block.gety() + y);
			if (blocks[block.getshape()][block.getturn()][y][x])
				std::cout << "  ";
		}
	}
}

void control::gamestart()
{
	
	scr.gamescreen();
	bool board[10][20] = { false };
	Block curblock, nextblock;
	nextblock.setcoord(7, 6);
	curblock.setcoord(38, 6);
	char input;
	while (true)
	{
		draw(nextblock);
		draw(curblock);
		Sleep(400);
		deleteblock(curblock);
		if (_kbhit())
		{
			input = _getch();
			if (input == UP)
				curblock.Turn();
			else if (input == LEFT)
			{
				if (curblock.getx() > 31);
				curblock.setcoord(curblock.getx() - 2, curblock.gety());
			}
			else if (input == RIGHT)
			{
				if (curblock.getx() < 40);
				curblock.setcoord(curblock.getx() + 2, curblock.gety());
			}
		}
		curblock.setcoord(curblock.getx(), curblock.gety() + 1);
		if (curblock.gety() == 25)
		{
			deleteblock(nextblock);
			curblock.setshape(nextblock.getshape());
			nextblock.setshape(rand() % 7);
			curblock.setcoord(38, 6);
		}
		
	}
}
