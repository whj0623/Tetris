#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "maingame.h"


class shop
{
public:
	static void shorteraction();
	static void buyItem(short index);
	static void showItem(short index,short x , short y);
	static void showItemInformation(short index);
	static void drawSelect(short index,short color);
};

