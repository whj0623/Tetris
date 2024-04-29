#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "maingame.h"



class screen
{
public:
    static void gameOver();
    static void titleScreen();
    static void gameScreen();
    static void shopScreen();
    static void gotoxy(short x, short y);
    static void textColor(short font, short background);
    static void drawTitle();
    static short gamePause();
    static void drawSelect(short select, short color);
};

