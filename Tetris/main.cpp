#pragma once
#include "control.h"
#include "screen.h"

bool continue_game;
int choice;

int main()
{
	
	srand(time(NULL));
	while (true)
	{
		system("mode con cols=120 lines=50");
		screen::titlescreen();
		if (choice == 0)
		{
			control::gameStart();
			while (continue_game)
				control::gameStart();
		}
		else
			break;
		//else if (choice == 1)
		
	}
}