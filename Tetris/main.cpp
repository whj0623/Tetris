#include "control.h"
#include "screen.h"

int main()
{
	srand(time(NULL));
	system("mode con cols=110 lines=40");
	screen a;
	control control;
	while (true)
	{
		int choice = a.titlescreen();
		if (choice == 0)
			control.gamestart();
		//else if (choice == 1)
		else
			break;
	}
}