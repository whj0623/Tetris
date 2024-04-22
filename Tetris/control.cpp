#include "control.h"



enum input
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	SPACEBAR = 32
};
int score = 0;
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
			,{0,0,0,0}
			,{1,1,1,1}
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
			,{0,0,0,0}
			,{1,1,1,1}
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

bool crashcheck(int board[20][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 1)
			{
				if (i == 19 || (i + 1 <= 19 && board[i + 1][j] == 2))
					return true;
			}
		}
	}
	return false;
}


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
			if (board[i][j] == 1)
				std::cout << "¡à";
			else if (board[i][j] == 2)
				std::cout << "¡á";
			else if (board[i][j] == 3)
				std::cout << "¢É";
			else
				std::cout << "  ";
		}
	}
}

Block moveblock(char input, Block block)
{
	int tempboard[20][10] = { 0 };
	Block tempblock = block;
	int count2 = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] != 1)
			{
				tempboard[i][j] = board[i][j];
				if (board[i][j] == 2)
					count2++;
			}
		}
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
	case SPACEBAR:
		for (int i = 0; i < 20; i++)
			tempblock = moveblock(DOWN, tempblock);
		break;
	}

	int check = 0;
	int check2 = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tempboard[i][j] == 1)
				check++;
			else if (tempboard[i][j] == 2)
				check2++;
		}
	}
	if (check == 4 && check2 == count2)
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
				std::cout << "¡à";
			else
				std::cout << "  ";
		}
	}
}

void eraseLine()
{
	for (int i = 0; i < 20; i++)
	{
		int count = 0;
		for (int j = 0; j < 10; j++)
		{
			
			if (board[i][j] == 2)
				count++;
			if (count == 10)
			{
				for (int k = i; k > 0; k--)
				{
					for (int l = 0; l < 10; l++)
						board[k][l] = board[k - 1][l];
				}
				score += 100;
			}
		}
	}
}
void MakeShadow(Block Shadow)
{
	
}

void Resetgame()
{
	score = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
			board[i][j] = 0;
	}
}

bool control::gamestart()
{
	Resetgame();
	
	scr.gamescreen();
	
	
	clock_t start, end;
	Block curblock, nextblock,Shadow;
	nextblock.setcoord(7, 6);
	curblock.setcoord(36, 4);
	

	char input;
	draw();
	start = clock();
	while (true)
	{
		scr.gotoxy(55, 13);
		std::cout << "   Á¡¼ö : " << score;
		addblock(curblock, board);
		
		drawnextblock(nextblock);
		draw();
		if (_kbhit())
		{
			input = _getch();
			if (input == -32)
				input = _getch();
			curblock = moveblock(input,curblock);
			
			if (input == SPACEBAR)
			{
				if (crashcheck(board))
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
					curblock.setcoord(36, 6);
					eraseLine();
				}
				continue;
			}
		}
		Shadow = curblock;
		draw();
		end = clock();
		if (end - start >= 1000)
		{
			curblock = moveblock(DOWN, curblock);
			draw();
			start = end;
		}
		if (end - start >= 950)
		{
			if (crashcheck(board))
			{
				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (board[i][j] == 1)
							board[i][j] = 2;
					}
				}
				if (curblock.gety() <= 6)
				{
					if (screen::gameover())
						return true;
					else
						return false;
				}
				curblock = nextblock;
				nextblock.setshape(rand() % 7);
				curblock.setcoord(36, 6);
				eraseLine();
			}
		}
	}
}
