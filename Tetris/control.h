#pragma once
#include "screen.h"
#include "control.h"
#include "Object.h"
#include "Block.h"
#include <time.h>
#include <conio.h>

class control
{
private:
	int score = 0;
public: 
	void gamestart();
	void draw(Block block);
};

