#include "control.h"



enum input
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	SPACEBAR = 32
};

int board[20][10] = { 0 };
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
			{0,1,1,0}
			,{0,1,0,0}
			,{0,1,0,0}
			,{0,0,0,0}
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
void addblock(Block block, int board[20][10])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (blocks[block.getshape()][block.getturn()][i][j]&& block.gety() - 6 + i >= 0 && block.gety() - 6 + i < 20 &&
				block.getx() - 33 + j >= 0 && block.getx() - 33 + j < 10)
				board[block.gety() - 6 + i][block.getx() - 33 + j] = 1;
		}
	}
}
void control::draw()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scr.gotoxy(j * 2 + 32, i + 6);
			if (board[i][j] == 1 || board[i][j] == 2)
				std::cout << "бр";
			else
				std::cout << "  ";
		}
	}
}

Block moveblock(char input, Block block)
{
	int tempboard[20][10] = { 0 };
	Block tempblock = block;
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		if (board[i][j] != 1)
			tempboard[i][j] = board[i][j];
	}

	switch (input)
	{
	case UP:
		tempblock.Turn();
		addblock(tempblock, tempboard);
		break;
	case LEFT:
		tempblock.setcoord(tempblock.getx() - 1, tempblock.gety());
		addblock(tempblock, tempboard);
		break;
	case RIGHT:
		tempblock.setcoord(tempblock.getx() + 1, tempblock.gety());
		addblock(tempblock, tempboard);
		break;
	case DOWN:
		tempblock.setcoord(tempblock.getx(), tempblock.gety()+1);
		addblock(tempblock, tempboard);
		break;
	}
	int count = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tempboard[i][j] == 1)
				count++;
		}
	}
	if (count == 4)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 10; j++)
				board[i][j] = tempboard[i][j];
		}
		return tempblock;
	}
	return block;
}
void drawnextblock(Block nextblock)
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			scr.gotoxy(nextblock.getx() +j * 2, nextblock.gety() + i);
			if (blocks[nextblock.getshape()][0][i][j])
				std::cout << "бр";
			else
				std::cout << "  ";
		}
	}
}
bool crashcheck()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 1)
			{
				if (i + 1 <= 19 && board[i + 1][j] == 2)
					return true;
			}
		}
	}
	return false;
}

void control::gamestart()
{
	
	scr.gamescreen();
	clock_t start, end;
	Block curblock, nextblock;
	nextblock.setcoord(7, 6);
	curblock.setcoord(38, 6);
	addblock(curblock,board);
	
	char input;
	draw();
	start = clock();
	while (true)
	{
		drawnextblock(nextblock);
		
		if (_kbhit())
		{
			input = _getch();
			if (input == -32)
				input = _getch();
			curblock = moveblock(input,curblock);
		}
		draw();
		end = clock();
		if (end - start >= 1000)
		{
			curblock = moveblock(DOWN, curblock);
			draw();
			start = end;
		}
		
		if (!crashcheck || curblock.gety() >=  23)
		{
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (board[i][j] == 1)
						board[i][j] = 2;
				}
			}
			curblock = nextblock;
			nextblock.setshape(rand() % 7);
			curblock.setcoord(38, 6);
		}
		
	}
}
