#include "control.h"
#include "Object.h"
#include "screen.h"

int main()
{
	srand(time(NULL));
	system("mode con cols=110 lines=40");
	screen a;
	control control;
	while (true)
	{
		if (a.titlescreen() == 0)
			control.gamestart();
		else
			break;
	}
}