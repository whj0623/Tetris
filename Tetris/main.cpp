#pragma once
#include "maingame.h"
#include "screen.h"
#include "shop.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

int main()
{
	PlaySound((LPCWSTR)"Tetris.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
	srand((short)time(NULL));
	while (true)
	{
		system("mode con cols=120 lines=50");
		screen::titleScreen();
		if (choice == 0)
		{
			maingame::gameStart();
			while (continue_game)
				maingame::gameStart();
		}
		else if (choice == 1)
		{
			system("cls");
			screen::shopScreen();
			shop::interaction();
		}
		else 
		{ 
			system("cls");
			break;
		}
	}
}