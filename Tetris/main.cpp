#include "control.h"
#include "screen.h"

int main()
{
	srand(time(NULL));
	system("mode con cols=130 lines=40");
	screen a;
	control control;
	while (true)
	{
		system("mode con cols=130 lines=40");
		int choice = a.titlescreen();
		bool continue_game;
		if (choice == 0)
		{
			continue_game = control.gamestart();
			while (continue_game)
				continue_game = control.gamestart();
		}
		else
			break;
		//else if (choice == 1)
		
	}
}