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
int level = 0;
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

bool control::crashcheck(int board[20][10])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j]%7 == 1 || board[i][j] == 999 || board[i][j] == 1000)
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
	if (a == 999)
	{
		std::cout << "δ";
		return ;
	}
	else if (a == 1000)
	{
		std::cout << "Δ";
		return;
	}
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
		else
			std::cout << "  ";
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

void control::drawholdblock(Block holdblock, bool holdIsEmpty)
{
	if (holdIsEmpty)
		return;
	screen::textColor(9 + holdblock.getshape(), 0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			screen::gotoxy(holdblock.getx() + j * 2, holdblock.gety() + i);

			if (blocks[holdblock.getshape()][0][i][j])
				std::cout << "□";
			else
				std::cout << "  ";

		}
	}
	screen::textColor(WHITE, 0);
}

void control::eraseLine()
{
	bool erasecheck = false;
 	int pickup = lines % 10;
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
				score += (100 + level*15)*(combo+1);
				erasecheck = true;
				lines++;
				if (pickup + 1 >= 10 && inventory[2] == 1)
				{
					pickup = 0;
					int index = rand() % 2;
					inventory[index]++;
					screen::gotoxy(66 + index * 20, 28);
					std::cout << " X     ";
					screen::gotoxy(66 + index * 20, 28);
					std::cout << " X " << inventory[index];
					
				}
				if (level < lines / 10)
					level = lines / 10 >= 10 ? 10 : lines / 10;
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


bool gameOverCheck()
{
	for (int i = 1; i < 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] % 7 == 2)
				return true;
		}
	}
	return false;
}

void control::moveItem(char input, COORD * item)
{
	
	if (input == RIGHT)
	{
		if (item->X < 9 && board[item->Y][item->X + 1] % 7 != 2)
			item->X++;
	}
	else if (input == LEFT)
	{
		if (item->X > 0 && board[item->Y][item->X - 1] % 7 != 2)
			item->X--;
	}
	else if (input == DOWN)
	{
		if (item->Y <= 18 && board[item->Y + 1][item->X] % 7 != 2)
			item->Y++;
	}
}
void control::useItem(int index)
{
	
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] % 7 == 1)
				board[i][j] = 0;
		}
	}
	char input;
	COORD* p_item;
	COORD item;
	int pushed[20] = { 0 };
	int k = -1;
	
	p_item = &item;
	inventory[index - 1]--;
	item.X = 5, item.Y = 3;
	
	screen::gotoxy(66 + (index - 1) * 20, 28);
	std::cout << " X     ";
	screen::gotoxy(66 + (index - 1) * 20, 28);
	std::cout << " X " << inventory[index-1];
	clock_t start, end;
	start = clock();
	while (true)
	{
		if (index == 1)
			board[item.Y][item.X] = 999;
		else
			board[item.Y][item.X] = 1000;
		draw();
		if (_kbhit())
		{
			input = _getch();
			board[item.Y][item.X] = 0;
			if (input == -32)
			{
				input = _getch();
				moveItem(input, p_item);
			}
			else if (input == SPACEBAR)
			{
				for (int i = 0; i < 20; i++)
					moveItem(DOWN, p_item);
				if (index == 1)
				{
					for (int i = item.Y - 2; i <= item.Y + 2; i++)
					{
						for (int j = item.X - 2; j <= item.X + 2; j++)
						{
							if ((i <= 19 && i >= 0) && (j <= 9 && j >= 0))
								board[i][j] = 0;
						}
					}
				}
				else
				{
					board[item.Y][item.X] = 1000;
					draw();
					board[item.Y][item.X] = 0;
					Sleep(500);
					for (int i = 19; i >= item.Y; i--)
					{
						if (board[i][item.X] % 7 == 2)
							pushed[++k] = board[i][item.X];
					}
					for (int i = 19; i >= item.Y; i--)
						board[i][item.X] = 0;
					for (int i = 19; i >= item.Y + 1; i--)
						board[i][item.X] = pushed[19 - i];
					if (k > -1)
					{
						board[18 - k][item.X] = 1000;
						draw();
						board[18 - k][item.X] = 0;
						Sleep(500);
					}
					eraseLine();
				}
				return;
			}
		}
		
		end = clock();
		draw();
		if (end - start >= 1000)
		{
			board[item.Y][item.X] = 0;
			moveItem(DOWN, p_item);
			draw();
			start = end;
		}
		if (end - start >= 900)
		{
			if (crashcheck(board))
			{
				if (index == 1)
				{
					for (int i = item.Y - 2; i <= item.Y + 2; i++)
					{
						for (int j = item.X - 2; j <= item.X + 2; j++)
						{
							if ((i <= 19 && i >= 0) && (j <= 9 && j >= 0))
								board[i][j] = 0;
						}
					}
				}
				else
				{
					board[item.Y][item.X] = 1000;
					draw();
					board[item.Y][item.X] = 0;
					Sleep(500);
					for (int i = 19; i >= item.Y; i--)
					{
						if (board[i][item.X] % 7 == 2)
							pushed[++k] = board[i][item.X];
					}
					for (int i = 19; i >= item.Y; i--)
						board[i][item.X] = 0;
					for (int i = 19; i >= item.Y + 1; i--)
						board[i][item.X] = pushed[19 - i];
					if (k > -1)
					{
						board[18 - k][item.X] = 1000;
						draw();
						board[18 - k][item.X] = 0;
						Sleep(500);
					}
					eraseLine();
				}
				return;
			}
		}
	}
}

void control::gameStart()
{
	inventory[0] = 10;
	inventory[1] = 10;
	inventory[2] = 1;
	inventory[3] = 1;
	Resetgame();
	screen::gameScreen();
	clock_t start, end;
	Block curblock, nextblock[4], holdblock,tempblock;
	bool holdIsEmpty = true;
	bool usedHoldTHisTurn = false;
	for (int i = 0; i < 4; i++)
		nextblock[i].setcoord(6, 6 + i * 4);
	curblock.setcoord(36, 6);
	holdblock.setcoord(19, 6);
	char input;
	draw();
	start = clock();
	while (true)
	{
		
		PrintScore();
		addblock(curblock, board);
		MakeShadow(curblock.getshape());
		drawnextblock(nextblock);
		drawholdblock(holdblock,holdIsEmpty);
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
					usedHoldTHisTurn = false;
					for (int i = 0; i < 20; i++)
					{
						for (int j = 0; j < 10; j++)
						{
							if (board[i][j] % 7 == 1)
								board[i][j] = 2 + curblock.getshape() * 7;
						}
					}
					curblock = nextblock[0];
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
							nextblock[i] = nextblock[i + 1];
						else
							nextblock[i].setshape(rand() % 7);
						nextblock[i].setcoord(6, 6 + i * 4);
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
			{
				if (inventory[input - '0' - 1] > 0)
				{
					
					eraseShadow();
					useItem(input - '0');
					
					curblock.setcoord(36, 6);
					continue;
				}
			}
			else if ((input == 'a' || input == 'A' )&& !usedHoldTHisTurn)
			{
				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 10; j++)
					{
						if (board[i][j] % 7 == 1)
							board[i][j] = 0;
					}
				}
				if (!holdIsEmpty)
				{
					tempblock.setshape(curblock.getshape());
					curblock.setshape(holdblock.getshape());
					holdblock.setshape(tempblock.getshape());
				}
				else
				{
					holdblock.setshape(curblock.getshape());
					curblock = nextblock[0];
					for (int i = 0; i < 4; i++)
					{
						if (i != 3)
							nextblock[i] = nextblock[i + 1];
						else
							nextblock[i].setshape(rand() % 7);
						nextblock[i].setcoord(6, 6 + i * 4);
					}
				}
				curblock.setcoord(36, 6);
				holdIsEmpty = false;
				usedHoldTHisTurn = true;
				continue;
			}
		}
		draw();
		end = clock();
		int speed = 1000 - level * 80;
		if (end - start >= speed)
		{
			curblock = moveblock(DOWN, curblock);
			draw();
			start = end;
		}
		if (end - start >= speed - 30)
		{
			if (crashcheck(board))
			{
				usedHoldTHisTurn = false;
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
						nextblock[i].setshape(rand() % 7);
					nextblock[i].setcoord(6, 6 + i * 4);
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