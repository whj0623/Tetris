#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "control.h"

class shop
{
public:
	static void interaction();
	static void buyItem(int index);
	static void showItem(int index,int x , int y);
	static void showItemInformation(int index);
	static void drawSelect(int index,int color);
};

