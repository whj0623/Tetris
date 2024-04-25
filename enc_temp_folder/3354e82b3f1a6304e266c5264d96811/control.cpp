#include "control.h"

enum color
{
	BLUE = 9,
	GREEN,
	SKYBLUE,
	RED,
	PINK,
	YELLOW,
	WHITE
};

enum input
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	SPACEBAR = 32,
	ESC = 27
};

int gold = 0;
int earn_gold = 0;
int inventory[4] = { 0 };
int choice = 0;
int score = 0;
int lines = 0;
int combo = 0;
int board[20][10] = { 0 };
bool continue_game = false;
bool nowUseItem[2] = { false };
const bool blocks[8][4][4][4]=
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
	},
	{
		{
			
			{1}
			
		},
		{
			{1}
		},
		{
			{1}
		},
		{
			{1}
		}
	}
};

bool control::crashcheck(int board[20][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j]%7 == 1)
			{
				if (i == 19 || (i + 1 <= 19 && board[i + 1][j]%7 == 2))
					return true;
			}
		}
	}
	return false;
}


void control::addblock(Block block, int board[20][10])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (blocks[block.getshape()][block.getturn()][i][j]&& block.gety() - 6 + i >= 0 && block.gety() - 6 + i < 20 &&
				block.getx() - 33 + j >= 0 && block.getx() - 33 + j < 10)
				board[block.gety() - 6 + i][block.getx() - 33 + j] = 1 + 7 * block.getshape();
		}
	}
}
void control::drawblock(int a)
{
	screen::textColor(9 + a/7, 0);
	switch (a%7)
	{
	case 1:
		std::cout << "□";
		break;
	case 2:
		std::cout << "■";
		break;
	case 3:
		if (inventory[3] == 1)
			std::cout << "▨";
		break;
	default:
		std::cout << "  ";
		break;
	}
	screen::textColor(WHITE, 0);
}

void control::draw()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			screen::gotoxy(j * 2 + 32, i + 6);
			drawblock(board[i][j]);
		}
	}
}

Block control::moveblock(char input, Block block)
{
	int tempboard[20][10] = { 0 };
	Block tempblock = block;
	int count2 = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j]%7 != 1)
			{
				tempboard[i][j] = board[i][j];
				if (board[i][j]%7 == 2 )
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
			if (tempboard[i][j]%7 == 1 )
				check++;
			else if (tempboard[i][j]%7 == 2 )
				check2++;
		}
	}
	if ((check == 4 && check2 == count2) || (tempblock.getshape() == 7 && (check == 1 && check2 == count2)))
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

void control::drawnextblock(Block nextblock[])
{
	for (int k = 0; k < 4; k++)
	{
		screen::textColor(9 + nextblock[k].getshape(), 0);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				screen::gotoxy(nextblock[k].getx() + j * 2, nextblock[k].gety() + i);

				if (blocks[nextblock[k].getshape()][0][i][j])
					std::cout << "□";
				else
					std::cout << "  ";

			}
		}
		screen::textColor(WHITE, 0);
	}
}

void control::eraseLine()
{
	bool erasecheck = false;
	for (int i = 0; i < 20; i++)
	{
		int count = 0;
		for (int j = 0; j < 10; j++)
		{
			
			if (board[i][j]%7 == 2)
				count++;
			if (count == 10)
			{
				for (int k = i; k > 0; k--)
				{
					for (int l = 0; l < 10; l++)
						board[k][l] = board[k - 1][l];
				}
				score += 100*(combo+1);
				erasecheck = true;
				lines++;
			}
		}
	}
	if (erasecheck)
		combo++;
	else
		combo = 0;
}

void control::Resetgame()
{
	score = 0;
	lines = 0;
	combo = 0;
	earn_gold = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
			board[i][j] = 0;
	}
}

void control::MakeShadow(int color)
{
	int x[8] = { 0 };
	int y[8] = { 0 };
	int k = -1;
	int l = -1;
	int count = 4;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] % 7 == 1)
			{
				x[++k] = j;
				y[++l] = i;
			}
			
		}
		
	}
	while (count == 4)
	{
		count = 0;
		for (int i = 0; i < 4; i++)
		{
			if (y[i] + 1 <= 19 && board[y[i] + 1][x[i]] % 7 != 2)
				count++;
		}
		if (count == 4)
		{
			for (int j = 0; j < 4; j++)
				y[j]++;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (board[y[i]][x[i]] % 7 != 1)
			board[y[i]][x[i]] = color * 7 + 3;
	}
}
void control::eraseShadow()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] % 7 == 3)
				board[i][j] = 0;
		}
	}
}

void control::PrintScore()
{
	screen::gotoxy(55, 13);
	std::cout << "  점수		: " << score;
	screen::gotoxy(55, 15);
	std::cout << "  지운 줄	: " << lines;
	screen::gotoxy(55, 17);
	std::cout << "  콤보		: " << combo;
}
void control::itemInfo()
{
	int x = 55, y = 19;
screen::gotoxy(x, y++);
std::cout << "     "; screen::textColor(0, 15); std::cout << "  "; screen::textColor(0, 0); std::cout << "    ";
screen::gotoxy(x, y++);
std::cout << "    "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 4); std::cout << " "; screen::textColor(0, 6); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
screen::gotoxy(x, y++);
std::cout << "    "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "    ";
screen::gotoxy(x, y++);
std::cout << "    "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "    ";
screen::gotoxy(x, y++);
std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
screen::gotoxy(x, y++);
std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "  ";
screen::gotoxy(x, y++);
std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "  ";
screen::gotoxy(x, y++);
std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "  "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "  ";
screen::gotoxy(x, y++);
std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
screen::gotoxy(x, y++);
std::cout << "    "; screen::textColor(0, 15); std::cout << "   "; screen::textColor(0, 0); std::cout << "    ";
screen::textColor(15, 0); std::cout << " X " << inventory[0];

x = 75, y = 19;
screen::gotoxy(x, y++);
std::cout << "    "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "    ";
screen::gotoxy(x, y++);
std::cout << "    "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "    ";
screen::gotoxy(x, y++);
std::cout << "   "; screen::textColor(0, 8); std::cout << "     "; screen::textColor(0, 0); std::cout << "   ";
screen::gotoxy(x, y++);
std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "   ";
screen::gotoxy(x, y++);
std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "   ";
screen::gotoxy(x, y++);
std::cout << "  "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "  ";
screen::gotoxy(x, y++);
std::cout << "  "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "  ";
screen::gotoxy(x, y++);
std::cout << " "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << " ";
screen::gotoxy(x, y++);
std::cout << " "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << "  "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << " ";
screen::gotoxy(x, y++);
std::cout << " "; screen::textColor(0, 8); std::cout << "         "; screen::textColor(0, 0); std::cout << " ";

screen::textColor(15, 0); std::cout << " X " << inventory[1];
}
Block curblock, nextblock[4];
void control::useItem(int index)
{
	nowUseItem[index - 1] = true;
	Block item;
	item.setshape(7);
	item.setcoord(36, 6);
	curblock = item;
}
bool gameOverCheck()
{
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] % 7 == 2)
				return true;
		}
	}
	return false;
}

void control::gameStart()
{
	Resetgame();
	screen::gameScreen();
	itemInfo();
	clock_t start, end;

	for (int i = 0; i < 4; i++)
		nextblock[i].setcoord(7, 6 + i * 4);
	curblock.setcoord(36, 6);
	char input;
	draw();
	start = clock();
	while (true)
	{
		PrintScore();
		addblock(curblock, board);
		MakeShadow(curblock.getshape());
		drawnextblock(nextblock);
		draw();
		if (_kbhit())
		{
			eraseShadow();
			input = _getch();
			if (input == -32)
				input = _getch();
			curblock = moveblock(input, curblock);
			MakeShadow(curblock.getshape());
			if (input == SPACEBAR)
			{
				if (crashcheck(board))
				{					
					if (nowUseItem[0])
					{
						nowUseItem[0] = false;

					
					}
					else
					{
						for (int i = 0; i < 20; i++)
						{
							for (int j = 0; j < 10; j++)
							{
								if (board[i][j] % 7 == 1)
									board[i][j] = 2 + curblock.getshape() * 7;
							}
						}
					}
					curblock = nextblock[0];
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
							nextblock[i] = nextblock[i + 1];
						else
							nextblock[3].setshape(rand() % 7);
						nextblock[i].setcoord(7, 6 + i * 4);
					}
					curblock.setcoord(36, 6);
					eraseLine();
				}
				continue;
			}
			else if (input == ESC)
			{
				int pause_choice = screen::gamePause();
				if (pause_choice == 0)
				{
					screen::gameScreen();
					continue;
				}
				else if (pause_choice == 1)
				{
					continue_game = true;
					break;
				}
				else
				{
					continue_game = false;
					break;
				}
			}
			else if (input == '1' || input == '2')
				useItem(input - '0');
		}
		draw();
		end = clock();
		int speed = 1000 - (lines/10)*100;
		if (speed < 300)
			speed = 300;
		if (end - start >= speed)
		{
			curblock = moveblock(DOWN, curblock);
			draw();
			start = end;
		}
		if (end - start >= speed - 50)
		{
			if (crashcheck(board))
			{
				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (board[i][j]%7 == 1)
							board[i][j] = 2 + curblock.getshape()*7;
					}
				}
			    if (gameOverCheck())
				{
					earn_gold += score / 100;
					gold += earn_gold;
					screen::gameOver();
					return;
				}
				curblock = nextblock[0];
				for (int i = 0; i < 4; i++)
				{
					if (i != 3)
						nextblock[i] = nextblock[i + 1];
					else
						nextblock[3].setshape(rand() % 7);
					nextblock[i].setcoord(7, 6 + i * 4);
				}
				curblock.setcoord(36, 6);
				eraseLine();
			}
		}
	}
}


/*
남은 작업:

	1. 아이템,상점 구현

추가적인 작업:
	
	2. 홀드 기능 구현
	3. 타이틀 화면 보수
	
*/