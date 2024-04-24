#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "control.h"


class screen
{
public:
    static void gameOver();
    static void titleScreen();
    static void gameScreen();
    static void shopScreen();
    static void gotoxy(short x, short y);
    static void textColor(int font, int background);
    static void drawTitle();
    static int gamePause();
};

