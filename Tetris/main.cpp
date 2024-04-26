#pragma once
#include "control.h"
#include "screen.h"
#include "shop.h"


int main()
{
	srand((short)time(NULL));
	while (true)
	{
		system("mode con cols=120 lines=50");
		screen::titleScreen();
		if (choice == 0)
		{
			control::gameStart();
			while (continue_game)
				control::gameStart();
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